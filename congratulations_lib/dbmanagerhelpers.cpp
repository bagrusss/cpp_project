//вспомогательные функции - обертки над sqlite3

#include "dbmanager.h"

#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>

//подключится к БД
bool DBManager::connect() {
    std::string dbFile = SettingsDBManager::getDBFile();
    if (sqlite3_open(dbFile.c_str(), &database) == SQLITE_OK)
        return true;
    return false;
}

//выполнить произвольный запрос, возвращающий результирующее множество
std::vector<std::vector<std::string>>& DBManager::executeQuery (const std::string& query) {
    qDebug() << QString::fromStdString(query);
    auto *results = new std::vector<std::vector<std::string>>();
    sqlite3_stmt* statement;
    if (sqlite3_prepare_v2(database, query.c_str(), query.size(), &statement, NULL) == SQLITE_OK) {
        int columns = sqlite3_column_count(statement);
        int result = 0;
        while (true) {
            result = sqlite3_step(statement);
            if (result == SQLITE_ROW) {
                std::vector<std::string> values;
                for (int columnNumber = 0; columnNumber < columns; ++columnNumber) {
                    values.push_back((char*) sqlite3_column_text(statement, columnNumber));
                }
                results->emplace_back(std::move(values));
            }
            else break;
        }
        sqlite3_finalize(statement);

    }
    qDebug() << sqlite3_errmsg(database);
    qDebug() << QString::fromStdString(query);
    return *results;

}

//выполнить произвольный запрос, не требующий результата
bool DBManager::executeQueryWithoutResult (const std::string& query) {
    qDebug() << QString::fromStdString(query);
    sqlite3_stmt* statement;
    if (sqlite3_prepare_v2(database, query.c_str(), query.size(), &statement, NULL) != SQLITE_OK) {
        qDebug() << QString::fromStdString(sqlite3_errmsg(database));
        return false;
    }

    if (sqlite3_step(statement) != SQLITE_DONE) {
        qDebug() << QString::fromStdString(sqlite3_errmsg(database));
        return false;
    }

    if (sqlite3_finalize(statement) != SQLITE_OK)
        return false;
    return true;
}

//создать таблицу, если еще не создана
bool DBManager::createTable(const std::string&& tableName,
                 const std::vector<std::pair<std::string, std::string>>&& columns ) {
    std::string sqlStmt = "select 1 from sqlite_master where type = 'table' and name ='" + tableName + "'";
    sqlite3_stmt* statement;
    if (sqlite3_prepare_v2(database, sqlStmt.c_str(),0, &statement, NULL) != SQLITE_OK) {
        return false;
    }
    if (sqlite3_step(statement) == SQLITE_ROW) //если вернулось не пустое множество
        return true;

    sqlStmt = "CREATE TABLE " + tableName + " (id integer primary key";
    for (auto iter = columns.begin(); iter != columns.end(); ++iter) {
        sqlStmt += ", " + iter->first + " " + iter->second;
    }
    sqlStmt += ");";

    return executeQueryWithoutResult(sqlStmt);

}

//закрыть соединение
void DBManager::close() {
    sqlite3_close(database);
}



bool DBManager::insert(const std::string&& tableName,
            const std::vector<std::string>&& columnNames,
            const std::vector<std::vector<std::string>>&& valueNames) {
   //connect();

    std::string query = "INSERT OR REPLACE INTO table (columns) VALUES values;";
    std::string columnsList = columnNames[0];
    std::vector<std::string>::const_iterator iter = columnNames.begin();
    for (++iter; iter != columnNames.end(); ++iter) {
        columnsList += ", " + *iter;
    }
    std::string valuesList;
    for (std::vector<std::vector<std::string>>::const_iterator rowIter = valueNames.begin(); rowIter != valueNames.end();) {
        std::string row = "('" + rowIter->at(0) + "'";
        std::vector<std::string>::const_iterator columnIter = rowIter->begin();
        for (++columnIter; columnIter != rowIter->end(); ++columnIter) {
            row += ", '" + *columnIter + "'";
        }
        row +=")";
        if (++rowIter != valueNames.end())
            row += ", ";
        valuesList += row;
    }

    //qDebug() << QString::fromStdString(valuesList);
    boost::replace_all(query, "table", tableName);//.c_str());
    boost::replace_all(query, "columns", columnsList);//.c_str());
    boost::replace_all(query, "values", valuesList);//.c_str());
    bool resultFlag = executeQueryWithoutResult(query); //, ??
    qDebug() << QString::fromStdString(query);
    //close();
    return resultFlag;
}

bool DBManager::updateHelper(const std::string&& tableName,
                             const std::vector<std::pair<std::string, std::string>>&& valueNames,
                             const std::string&& whereClause) {
    std::string query = "UPDATE table SET values " + whereClause + ";";
    std::string valuesList;
    for (auto rowIter = valueNames.begin(); rowIter != valueNames.end(); ++rowIter) {
        std::string row = rowIter->first + " = " + "'" + rowIter->second + "'";
        if (rowIter + 1 != valueNames.end())
            row += ",";
        valuesList += row;
    }


    boost::replace_all(query, "table", tableName);
    boost::replace_all(query, "values", valuesList);
    //qDebug() << QString::fromStdString(query);
    return executeQueryWithoutResult(query);

}

bool DBManager::update(const std::string&& tableName,
            const std::vector<std::pair<std::string, std::string>>&& valueNames,
            int id) {

    return updateHelper(std::move(tableName),
                        std::move(valueNames),
                        "WHERE id = " + boost::lexical_cast<std::string>(id));


}

bool DBManager::deleteBy(const std::string&& column,
                         const std::string&& tableName,
                         const std::list<int>&& idNames) {
    //connect();

    std::string query = "DELETE FROM table WHERE " + column + " IN (id_list);" ;
    std::string deletedIds;
    for (std::list<int>::const_iterator iter = idNames.begin(); iter != idNames.end(); ) {
        //qDebug() << *iter;
        deletedIds += boost::lexical_cast<std::string>(*iter);
        if (++iter != idNames.end())
            deletedIds += ", ";
    }

    boost::replace_all(query, "table", tableName);
    boost::replace_all(query, "id_list", deletedIds);
    //qDebug() << QString::fromStdString(query);
    bool resultFlag = executeQueryWithoutResult(query);
    //close();
    return resultFlag;
}



std::vector<std::vector<std::string>>& DBManager::select (const std::string&& tableName,
                                                          const std::vector<std::string>&& columnNames,
                                                          std::string where_clause) {
    std::string query = "SELECT columns FROM table " + where_clause + ";";
    std::string columnsList = columnNames[0];
    for (size_t iter = 1; iter < columnNames.size(); ++iter) {
        columnsList += ", " + columnNames[iter];
    }

    boost::replace_all(query, "table", tableName);
    boost::replace_all(query, "columns", columnsList);
    qDebug() << QString::fromStdString(query);
    //connect();
    std::vector<std::vector<std::string>>& result = executeQuery(query);
    //close();
    return result;

}

//не закрывает соединение!!!
/*void DBManager::attachDB(const std::string& dbPath, const std::string& dbName) {
    //connect();
    std::string attachQuery = "ATTACH DATABASE '" + dbPath + "' AS " + dbName + ";";
    qDebug() << QString::fromStdString(attachQuery);
    executeQueryWithoutResult(attachQuery);
}*/

/*void DBManager::detachDB(const std::string& dbName) {
    //connect();
    std::string detachQuery = "DETACH DATABASE '" + dbName + "' ;";
    //qDebug() << QString::fromStdString(attachQuery);
    executeQueryWithoutResult(detachQuery);
}*/


bool DBManager::insertWithSubquery(const std::string&& insertTableName,
                                   const std::vector<std::string>&& insertColumnNames,
                                   const std::string&& selectTableName,
                                   const std::vector<std::string>&& selectColumnNames,
                                   const std::string&& whereClause) {
   //connect();

    std::string query = "INSERT OR REPLACE INTO insert_table (insert_columns) SELECT select_columns FROM select_table " + whereClause +" ;";
    std::string insertColumnsList = insertColumnNames[0];
    std::vector<std::string>::const_iterator iter = insertColumnNames.begin();
    for (++iter; iter != insertColumnNames.end(); ++iter) {
        insertColumnsList += ", " + *iter;
    }
    std::string selectColumnsList = selectColumnNames[0];
    iter = selectColumnNames.begin();
    for (++iter; iter != selectColumnNames.end(); ++iter) {
        //qDebug() << QString::fromStdString(*iter);
        selectColumnsList += ", " + *iter;
    }

    //qDebug() << QString::fromStdString(valuesList);
    boost::replace_all(query, "insert_table", insertTableName);//.c_str());
    boost::replace_all(query, "select_table", selectTableName);
    boost::replace_all(query, "insert_columns", insertColumnsList);//.c_str());
    boost::replace_all(query, "select_columns", selectColumnsList);//.c_str());
    bool resultFlag = executeQueryWithoutResult(query); //, ??
    qDebug() << QString::fromStdString(query);
    //close();
    return resultFlag;
}

#include <yaml-cpp/yaml.h>
#include <iostream>
#include <string>
#define SETTINGS_FILE "/opt/Qt5.1.1/Tools/QtCreator/bin/congratulations_lib/config.yaml"
class Test {
YAML::Node config;
public:
Test(): config(YAML::LoadFile(SETTINGS_FILE)) {}
void print() {
    for (YAML::const_iterator iter=config["settings-groups"].begin(); 
         iter != config["settings-groups"].end(); ++iter) {
         //std::cout << iter->first.as<std::string>() << std::endl ;
         YAML::const_iterator iter2=iter->second.begin();
         ++iter2;
         for ( 
              ;iter2 !=iter->second.end(); ++iter2) {
              
              //std::cout << (iter2->second)["type"].as<std::string>() <<' ';
              YAML::Node values = (iter2->second)["values"];
              if (values)
                   for( int i = 0; i < values.size(); ++i)
                       std::cout << config["time-dictionary"][values[i].as<std::string>()]["title"];
                       //std::cout << values[i].as<std::string>();
         }
        //std::cout << iter->first.as<std::string>();//.as<std::string>();
    }
   //std::cout << config["time-dictionary"].size();//(int)config["time-dictionary"]["one-day"]["number"].as<int>();
}

};

int main() {
    Test test;
    test.print();
    
    return 0;
}

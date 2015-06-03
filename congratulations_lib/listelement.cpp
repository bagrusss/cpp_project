#include "listelement.h"

void createSettingsEntry (const YAML::Node& settingsNode,
                          const YAML::Node& timeNode,
                          ListSettingsEntry& listEntry) {
    std::string text = settingsNode["title"].as<std::string>();
    listEntry.text = QString::fromStdString(text);
    const YAML::Node& values = settingsNode["values"];
    for (YAML::const_iterator iter = values.begin(); iter != values.end(); ++iter) {
        //qDebug() << QString::fromStdString(iter->as<std::string>());
        std::string optionTitle;
        if (timeNode[iter->as<std::string>()])
            optionTitle = timeNode[iter->as<std::string>()]["title"].as<std::string>();
        else
             optionTitle = iter->as<std::string>();
        listEntry.optionsList.append(QString::fromStdString(optionTitle));
    }
    int selectedOption = settingsNode["selected-value-index"].as<int>();
    if (selectedOption >= listEntry.optionsList.size())
        selectedOption = 0;
    listEntry.selectedOption = selectedOption;

}

void createSettingsEntry (const YAML::Node& settingsNode, OffOnSettingsEntry& listEntry) {
    std::string text = settingsNode["title"].as<std::string>();
    listEntry.text = QString::fromStdString(text);
    listEntry.isOn = settingsNode["is-on"].as<bool>();
}

void saveChangedSettings(YAML::Node settingsNode, const ListSettingsEntry& listEntry) {
    YAML::Node changedNode;
    if (settingsNode["general-settings"][listEntry.name]) {
        changedNode = settingsNode["general-settings"][listEntry.name];
    }
    else if (settingsNode["system-settings"][listEntry.name]) {
        changedNode = settingsNode["system-settings"][listEntry.name];
    }
    changedNode["selected-value-index"] = listEntry.selectedOption;
}

void saveChangedSettings(YAML::Node settingsNode, const OffOnSettingsEntry& listEntry) {
    YAML::Node changedNode;
    if (settingsNode["system-settings"][listEntry.name]) {
        changedNode = settingsNode["system-settings"][listEntry.name];
    }
    else if (settingsNode["general-settings"][listEntry.name]) {
        changedNode = settingsNode["general-settings"][listEntry.name];
    }
    changedNode["is-on"] = listEntry.isOn;
}

//
// Created by drportier on 3-2-23.
//

#include "iniParser.h"

ini::INIParser::INIParser() {
    this->data = std::map<std::string, std::string>();
}

void ini::INIParser::ReadFile(const std::string &filename) {
    std::ifstream file(filename);
    if(!file.is_open())
        return;

    std::string line, section;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == ';')
            continue;

        if (line[0] == '[') {
            unsigned long end = line.find(']');
            if (end != std::string::npos)
                section = line.substr(1, end - 1);
        }
        else {
            unsigned long sep = line.find('=');
            if (sep != std::string::npos) {
                std::string key = line.substr(0, sep);
                std::string val = line.substr(sep + 1);
                data.insert(std::make_pair(section + '.' + key, val));
            }
        }
    }
}

void ini::INIParser::WriteFile(const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open())
        return;

    std::string section;
    bool isFirstSection = true;
    unsigned long sep = 0;
    for (auto& it : data) {
        if (it.first.contains('.')) {
            sep = it.first.find('.');
            std::string newSection = it.first.substr(0, sep);
            if (newSection != section) {
                section = newSection;
                if (isFirstSection) {
                    isFirstSection = false;
                    file << '[' << section << ']' << std::endl;
                } else {
                    file << std::endl << '[' << section << ']' << std::endl;
                }
            }
        }
        file << it.first.substr(sep + 1) << '=' << it.second << std::endl;
        sep = 0;
    }
}

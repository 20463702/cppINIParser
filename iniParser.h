//
// Created by drportier on 3-2-23.
//

#ifndef INIPARSERLIB_INIPARSER_H
#define INIPARSERLIB_INIPARSER_H

#include <fstream>
#include <string>
#include <map>

namespace ini {

    class INIParser {
    private:

    public:
        std::map<std::string, std::string> data;

    public:
        INIParser();
        void ReadFile(const std::string& filename);
        void WriteFile(const std::string& filename);
    };

} // ini

#endif //INIPARSERLIB_INIPARSER_H

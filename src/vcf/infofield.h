//
// Created by Sakkayaphab Piwluang on 22/1/20.
//

#ifndef FORGE_INFOFIELD_H
#define FORGE_INFOFIELD_H

#include <string>

class InfoField {
private:
public:
    std::string getKey();
    void setKey(std::string key);
    std::string getValue();
    void setValue(std::string value);

private:
    std::string key;
    std::string value;
public:
    InfoField();
};


#endif //FORGE_INFOFIELD_H

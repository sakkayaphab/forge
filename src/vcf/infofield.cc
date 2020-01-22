//
// Created by Sakkayaphab Piwluang on 22/1/20.
//

#include "infofield.h"


InfoField::InfoField() {

}

std::string InfoField::getKey()  {
    return key;
}

void InfoField::setKey(std::string key) {
    InfoField::key = key;
}

std::string InfoField::getValue() {
    return value;
}

void InfoField::setValue(std::string value) {
    InfoField::value = value;
}

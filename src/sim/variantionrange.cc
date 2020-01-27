//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "variantionrange.h"

VariantionRange::VariantionRange() {

}

void VariantionRange::setMaxLength(int64_t max) {
    VariantionRange::maxlength = max;
}

void VariantionRange::setMinLength(int64_t min) {
    VariantionRange::minlength = min;
}

void VariantionRange::setNumber(int number) {
    VariantionRange::number = number;
}

int64_t VariantionRange::getMaxLength() {
    return VariantionRange::maxlength;
}

int64_t VariantionRange::getMinLength() {
    return VariantionRange::minlength;
}

int VariantionRange::getNumber() {
    return VariantionRange::number;
}

void VariantionRange::setTextRange(std::string textrange) {
    textrange.erase(remove_if(textrange.begin(), textrange.end(), isspace), textrange.end());
    std::vector<std::string> splited = VariantionRange::split(textrange, '-');
    if (splited.size()!=2) {
        std::cerr << "range error : " << textrange << std::endl;
        exit(1);
    }
    VariantionRange::setMinLength(convertStringToInt64(splited.at(0)));
    VariantionRange::setMaxLength(convertStringToInt64(splited.at(1)));
}

void VariantionRange::setTextNumber(std::string number) {
    VariantionRange::setNumber(convertStringToInt(number));
}

std::vector<std::string> VariantionRange::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int64_t VariantionRange::convertStringToInt64(std::string text) {
    int64_t value = std::strtoll(text.c_str(), NULL, 0);
    return value;
}

int VariantionRange::convertStringToInt(std::string text) {
    int64_t value = std::stoi(text.c_str(), NULL, 0);
    return value;
}
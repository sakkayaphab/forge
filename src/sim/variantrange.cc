//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "variantrange.h"

VariantRange::VariantRange() {

}

void VariantRange::setMaxLength(int64_t max) {
    VariantRange::maxlength = max;
}

void VariantRange::setMinLength(int64_t min) {
    VariantRange::minlength = min;
}

void VariantRange::setNumber(int number) {
    VariantRange::number = number;
}

int64_t VariantRange::getMaxLength() {
    return VariantRange::maxlength;
}

int64_t VariantRange::getMinLength() {
    return VariantRange::minlength;
}

int VariantRange::getNumber() {
    return VariantRange::number;
}

void VariantRange::setTextRange(std::string textrange) {
    textrange.erase(remove_if(textrange.begin(), textrange.end(), isspace), textrange.end());
    std::vector<std::string> splited = VariantRange::split(textrange,'-');
    if (splited.size()!=2) {
        std::cerr << "range error : " << textrange << std::endl;
        exit(1);
    }
    VariantRange::setMinLength(convertStringToInt64(splited.at(0)));
    VariantRange::setMaxLength(convertStringToInt64(splited.at(1)));
}

std::vector<std::string> VariantRange::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int64_t VariantRange::convertStringToInt64(std::string text) {
    int64_t value = std::strtoll(text.c_str(), NULL, 0);
    return value;
}
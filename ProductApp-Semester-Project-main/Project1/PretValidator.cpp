//
// Created by vale on 28/05/2023.
//

#include "PretValidator.h"
bool PretValidator::isInteger(const std::string &value) {
    for (char c : value) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}




bool PretValidator::isInteger(int value) {
    std::string strValue = std::to_string(value);
    return isInteger(strValue);
}




bool PretValidator::validate(int pret) {
    return pret >= 0 && isInteger(pret);
}
//
// Created by vale on 28/05/2023.
//

#include "CodValidator.h"
#include "CodValidator.h"
#include "FileRepo.h"
#include <cctype>
FileRepo repo("file.txt");

bool CodValidator::apartine(int cod) {
    for(auto enti:repo.getAll()){
        if(enti.getId() == cod) {
            return false;
        }

    }
    return true;
}

bool CodValidator::isInteger(const std::string& value) {
    for (char c : value) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}



bool CodValidator::isInteger(int value)  {
    std::string strValue = std::to_string(value);
    return isInteger(strValue);
}


bool CodValidator::validate(int cod) {
    if(cod>=0 && apartine(cod) && isInteger(cod)){
        return true;
    }
    return false;
}


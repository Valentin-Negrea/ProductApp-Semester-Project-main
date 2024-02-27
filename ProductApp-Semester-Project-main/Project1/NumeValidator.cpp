//
// Created by vale on 28/05/2023.
//

#include "NumeValidator.h"
#include <cstring>
#include <iostream>
using namespace std;


bool NumeValidator::isString(const char* value) {
    for (const char* p = value; *p != '\0'; ++p) {
        if (!std::isdigit(*p)) {
            return true;
        }
    }
    return false;
}



bool NumeValidator::validate(const char* nume) {
    return nume != nullptr && strlen(nume) > 0 && isString(nume);
}
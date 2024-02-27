//
// Created by vale on 28/05/2023.
//

#ifndef LAB9_10_PRETVALIDATOR_H
#define LAB9_10_PRETVALIDATOR_H


using namespace std;
#include <iostream>
class PretValidator {
public:
    static bool validate(int pret);
    static bool isInteger(int value);
    static bool isInteger(const std::string& value);
};


#endif //LAB9_10_PRETVALIDATOR_H

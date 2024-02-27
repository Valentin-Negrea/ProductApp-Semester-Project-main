//
// Created by vale on 28/05/2023.
//

#ifndef LAB9_10_CODVALIDATOR_H
#define LAB9_10_CODVALIDATOR_H

#include <iostream>
using namespace  std;
class CodValidator {
public:
    static bool validate(int cod);
    static bool apartine(int cod);
    static bool isInteger(int value);
    static bool isInteger(const std::string& value);

};


#endif //LAB9_10_CODVALIDATOR_H

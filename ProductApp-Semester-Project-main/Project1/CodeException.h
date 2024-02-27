//
// Created by vale on 28/05/2023.
//

#ifndef LAB9_10_CODEEXCEPTION_H
#define LAB9_10_CODEEXCEPTION_H
#include <iostream>

using namespace std;
class CodException : public std::exception {
private:
    std::string message;

public:
    explicit CodException(const std::string& errorMessage) : message(errorMessage) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
#endif //LAB9_10_CODEEXCEPTION_H

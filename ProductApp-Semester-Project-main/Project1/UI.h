#pragma once
#include "EntitateService.h"
#include "Colectie.h"
class Ui
{
private:
    EntitateService service;
    void print_menu();
public:
    Ui(EntitateService &otherService);
    ~Ui() = default;

    int start();

};

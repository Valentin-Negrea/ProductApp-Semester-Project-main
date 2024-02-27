#pragma once
#include "EntitateRepo.h"
#include <vector>
#include <iostream>

using namespace std;
class EntitateService
{
private:
    EntitateRepository repo;
public:
    EntitateService() = default;
    ~EntitateService() = default;

    EntitateService(EntitateRepository &otherRepo);

    void addEntitate(const Entitate &e);
    vector<Entitate> getAll();

    vector<Entitate> sortarePret();

    void deleteEntitate(int id);
    void filtrareNume(char* nume);

    static bool valideazaCod(int cod);
    static bool valideazaNume(const char* nume);
    static bool valideazaPret(int pret);
};

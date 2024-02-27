#pragma once
#include <vector>
#include "Entitate.h"

using namespace std;
class EntitateRepository
{
private:
    vector<Entitate> entitati;
public:
    EntitateRepository() = default;
    ~EntitateRepository() = default;

    void addEntitate(const Entitate &e);
    vector<Entitate> getAll();
    void deleteEntitate(int id);

    void filtrareNume(char* nume);
    int getSize();
};

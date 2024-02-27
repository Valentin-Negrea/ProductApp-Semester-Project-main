#include <vector>
#include "EntitateRepo.h"
#include <cstring>
using namespace std;
void EntitateRepository::addEntitate(const Entitate &e)
{
    this->entitati.push_back(e);
}
vector<Entitate> EntitateRepository::getAll()
{
    return this->entitati;
}
void EntitateRepository::deleteEntitate(int id)
{
    for(int i=0;i<this->entitati.size();i++)
    {
        if(this->entitati[i].getId() == id)
        {
            this->entitati.erase(this->entitati.begin() + i);
            break;
        }
    }
}
void EntitateRepository::filtrareNume(char* nume)
{
    for(int i = 0; i < this->entitati.size(); )
    {
        if(strcmp(this->entitati[i].getNume(), nume) != 0)
        {
            this->entitati.erase(this->entitati.begin() + i);
        }
        else
        {
            i++;
        }
    }
}
int EntitateRepository::getSize()
{
    return this->entitati.size();
}


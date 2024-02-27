#include <iostream>
#include <vector>
#include "EntitateService.h"
#include "CodValidator.h"
using namespace std;

EntitateService::EntitateService(EntitateRepository &otherRepo)
{
    this->repo = otherRepo;
}
void EntitateService::addEntitate(const Entitate &e)
{
    this->repo.addEntitate(e);
}
vector<Entitate> EntitateService::getAll()
{
    return this->repo.getAll();
}
vector<Entitate> EntitateService::sortarePret()
{
    vector<Entitate> lista = this->repo.getAll();

    for(int i=0;i<lista.size()-1;i++)
    {
        for(int j=i+1;j<lista.size();j++)
        {
            if(lista[i].getPret() > lista[j].getPret())
            {
                swap(lista[i],lista[j]);
            }
        }
    }
    return lista;
}
void EntitateService::deleteEntitate(int id)
{
    this->repo.deleteEntitate(id);
}
void EntitateService::filtrareNume(char* nume)
{
    this->repo.filtrareNume(nume);
}
bool EntitateService::valideazaCod(int cod) {
    if(CodValidator::validate(cod)){
        return true;
    }
    return false;
}


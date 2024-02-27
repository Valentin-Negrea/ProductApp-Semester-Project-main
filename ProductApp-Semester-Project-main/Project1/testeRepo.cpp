#include "EntitateRepo.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
void repoAsserts()
{
    EntitateRepository repo;
    Entitate e1(1,"paine",10);
    Entitate e2(2,"orez",5);
    Entitate e3(3,"ovaz",2);
    repo.addEntitate(e1);
    repo.addEntitate(e2);
    repo.addEntitate(e3);

    vector<Entitate> lista = repo.getAll();

    assert(lista.size()==3);
    assert(lista[0].getId() == 1);
    assert(strcmp(lista[1].getNume(),"orez")==0);
    assert(lista[2].getPret() == 2);

    cout<<"Teste repository trecute cu succes!"<<endl;
}

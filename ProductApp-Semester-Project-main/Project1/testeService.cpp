#include "EntitateService.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

void serviceAsserts()
{
    EntitateRepository repo;
    EntitateService service(repo);

    Entitate e1(1,"paine",6);
    Entitate e2(2,"sandwich",15);
    Entitate e3(3,"ciocolata",5);
    service.addEntitate(e1);
    service.addEntitate(e2);
    service.addEntitate(e3);

    vector<Entitate> lista = service.getAll();
    assert(lista.size() == 3);
    assert(lista[0].getId() == 1);
    assert(lista[1].getPret() == 15);
    assert(strcmp(lista[2].getNume(),"ciocolata") == 0);

    cout<<"Teste service trecute cu succes!"<<endl;
}

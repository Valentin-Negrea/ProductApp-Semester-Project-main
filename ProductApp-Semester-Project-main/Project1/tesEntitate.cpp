#include <iostream>
#include <cstring>
#include <cassert>
#include "Entitate.h"
using namespace std;

void asserts()
{
    Entitate c1;
    assert(c1.getId()==0);
    assert(c1.getPret()==0);
    c1.setId(1);
    c1.setPret(5);
    c1.setNume("paine");
    assert(strcmp(c1.getNume(),"paine")==0);

    Entitate c2(c1);
    Entitate c3 = c1;

    assert(c2.getId()==1);
    assert(c2.getPret()==5);
    assert(strcmp(c2.getNume(),"paine")==0);

    assert(c3.getId()==1);
    assert(c3.getPret()==5);
    assert(strcmp(c3.getNume(),"paine")==0);

    assert(c1==c2);

    Entitate c4(2,"mancare",5);
    assert(c4.getId()==2);
    assert(c4.getPret()==5);
    assert(strcmp(c4.getNume(),"mancare")==0);

    cout<<"Teste trecute cu succes!"<<endl;


}

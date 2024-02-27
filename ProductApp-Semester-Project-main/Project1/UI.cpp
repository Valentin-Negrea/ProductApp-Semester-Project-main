#include "UI.h"
#include <vector>
#include <iostream>
#include <cstring>
#include "CodeException.h"
using namespace std;
Ui::Ui(EntitateService &otherService)
{
    this->service = otherService;
}
void Ui::print_menu()
{
    cout<<"1.Adauga produs."<<endl;
    cout<<"2.Afisati produse"<<endl;
    cout<<"3.Stergere Entitate dupa ID"<<endl;
    cout<<"4.Sortare cresc pret."<<endl;
    cout<<"5.Filtrare Nume"<<endl;
    cout<<"6.Inventar bani tonomat"<<endl;
    cout<<"7.Cumpara produs"<<endl;
    cout<<"8.Exit"<<endl;
}
int Ui::start()
{
    Colectie c;
    while(true)
    {
        print_menu();
        int optiune;
        cout<<"Introduceti optiune: ";
        cin>>optiune;

        if(optiune == 1) {
            int id, pret;
            char nume[251];
            cout << "Introduceti id,nume,pret: ";
            cin >> id >> nume >> pret;
            try {
                if (!EntitateService::valideazaCod(id)) {
                    throw CodException("Codul este deja sau este mai mic decat zeri.");
                }

                Entitate e(id, nume, pret);
                this->service.addEntitate(e);
            }catch (const CodException& e){
                cout<<"Eroare la adaugarea entitatii: "<<e.what()<<endl;
            }
        }
        else if(optiune == 2)
        {
            vector<Entitate> lista = this->service.getAll();
            for(int i=0;i<lista.size();i++)
            {
                cout<<"ID: "<<lista[i].getId()<<" Nume: "<<lista[i].getNume()<<" Pret: "<<lista[i].getPret()<<endl;
            }
        }
        else if(optiune == 3)
        {
            int id;
            cout<<"Introduceti id-ul entitatii pe care o stergeti: ";
            cin>>id;
            this->service.deleteEntitate(id);
        }
        else if(optiune == 4)
        {
            vector<Entitate> lista = this->service.sortarePret();
            for(int i=0;i<lista.size();i++)
            {
                cout<<"ID: "<<lista[i].getId()<<" Nume: "<<lista[i].getNume()<<" Pret: "<<lista[i].getPret()<<endl;
            }
        }
        else if(optiune == 5)
        {
            char nume[251];
            cout<<"Introduceti numele produselor pe care le pastrati: ";
            cin>>nume;
            this->service.filtrareNume(nume);
        }
        else if(optiune == 6)
        {
            c.afis();
        }
        else if(optiune == 7)
        {
            char produs[251];
            int suma;
            cout<<"Introduceti numele produsului dorit si suma pe care o introduceti: ";
            cin>>produs>>suma;
            vector<Entitate> produse = this->service.getAll();
            int ok=0,poz=0;
            for(int i=0;i<produse.size();i++)
            {
                if(strcmp(produse[i].getNume(),produs) == 0)
                {
                    ok = 1;
                    poz = i;
                }
            }
            if(ok == 0)
            {
                cout<<"Tonomatul nu dispune de acest produs!"<<endl;
            }
            else
            {
                int rest = suma - produse[poz].getPret();
                int *bancnote = c.getBancnote();
                int *nrBancnote = c.getNrBancnote();
                int lungime = c.size();

                int restBancnote[250];
                int l=0;

                while(rest)
                {
                    for(int i=lungime-1;i>=0;i--)
                    {
                        if(bancnote[i] <= rest)
                        {
                            restBancnote[l++] = bancnote[i];
                            rest -= bancnote[i];
                            i++;
                        }
                    }
                }
                cout<<"Restul dvs: "<<endl;
                for(int i=0;i<l;i++)
                {
                    cout<<restBancnote[i]<<"Ron"<<" ";
                }
                cout<<endl;
                for(int i=0;i<l;i++)
                {
                    c.remove(restBancnote[i]);
                }
            }
        }
        else if(optiune == 8)
        {
            return 0;
        }
        else
        {
            cout<<"Optiune incorecta!Reincercati!"<<endl;
        }
    }
    return 0;
}

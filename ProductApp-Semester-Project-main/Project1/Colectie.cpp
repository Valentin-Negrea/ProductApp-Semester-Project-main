#include <iostream>
#include "Colectie.h"
using namespace std;
Colectie::Colectie()
{
    bancnote = new int[8];
    bancnote[0]=1;
    bancnote[1]=5;
    bancnote[2]=10;
    bancnote[3]=20;
    bancnote[4]=50;
    bancnote[5]=100;
    bancnote[6]=200;
    bancnote[7]=500;
    nrBancnote = new int[8];
    nrBancnote[0]=100;
    nrBancnote[1]=100;
    nrBancnote[2]=100;
    nrBancnote[3]=100;
    nrBancnote[4]=100;
    nrBancnote[5]=100;
    nrBancnote[6]=100;
    nrBancnote[7]=100;
    bancnoteDistincte = 8;
    capacitate = 8;

}
int *Colectie::getBancnote()
{
    return this->bancnote;
}
int *Colectie::getNrBancnote()
{
    return this->nrBancnote;
}

void Colectie::add(int bancnota)
{
    bool exist = false;
    int poz;
    for(int i=0;i<bancnoteDistincte;i++)
    {
        if(bancnota==bancnote[i])
        {
            exist = true;
            poz=i;
        }
    }
    if(exist)
    {
        nrBancnote[poz]++;
    }
    else
    {
        if(bancnoteDistincte+1 > capacitate)
        {
            capacitate *=2;

            int* aux1 = new int[capacitate];
            for(int i=0;i<bancnoteDistincte;i++)
            {
                aux1[i]=bancnote[i];
            }
            delete[] bancnote;
            bancnote = aux1;

            int* aux2 = new int[capacitate];
            for(int i=0;i<bancnoteDistincte;i++)
            {
                aux2[i]=nrBancnote[i];
            }
            delete[] nrBancnote;
            nrBancnote = aux2;

        }
        bancnote[bancnoteDistincte]=bancnota;
        nrBancnote[bancnoteDistincte]=1;
        bancnoteDistincte++;

    }
}

bool Colectie::search(int bancnota)
{
    for(int i=0;i<bancnoteDistincte;i++)
    {
        if (bancnota==bancnote[i])
        {
            return true;
        }
    }
    return false;
}

int Colectie::size()
{
    return bancnoteDistincte;
}

int Colectie::numarBancnote(int bancnota)
{
    for(int i=0;i<bancnoteDistincte;i++)
    {
        if(bancnota==bancnote[i])
        {
            return nrBancnote[i];
        }
    }
    return 0;
}

void Colectie::destroy()
{
    delete[] bancnote;
    delete[] nrBancnote;
    bancnoteDistincte=1;
}

int Colectie::getAt(int poz)
{
    return bancnote[poz];
}

bool Colectie::remove(int bancnota)
{
    bool exist = false;
    int poz;
    for(int i=0;i<bancnoteDistincte;i++)
    {
        if(bancnota == bancnote[i])
        {
            exist = true;
            poz=i;
        }
    }
    if(exist)
    {
        if(nrBancnote[poz]>1)
        {
            nrBancnote[poz]--;
        }
        else
        {
            for(int i=poz;i<bancnoteDistincte;i++)
            {
                bancnote[i]=bancnote[i+1];
                nrBancnote[i]=nrBancnote[i+1];

            }
            bancnoteDistincte--;
        }
        return true;
    }
    return false;
}
void Colectie::afis()
{
    cout<<"ATM-ul dispunde de urmatoarele bancnote: "<<endl;
    for(int i=0;i<bancnoteDistincte;i++)
    {
        cout<<bancnote[i]<<" ron x"<<nrBancnote[i]<<endl;
    }
}

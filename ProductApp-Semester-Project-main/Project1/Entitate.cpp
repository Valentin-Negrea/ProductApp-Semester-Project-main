#include "Entitate.h"
#include <cstring>
Entitate::Entitate()
{
    this->id = 0;
    this->pret = 0;
    this->nume = nullptr;
}
Entitate::~Entitate()
{
    delete[] this->nume;
}
Entitate::Entitate(int id,char  *nume,int pret)
{
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->id = id;
    this->pret = pret;
}
Entitate::Entitate(const Entitate &e)
{
    this->nume = new char[strlen(e.nume)+1];
    strcpy(this->nume,e.nume);
    this->id = e.id;
    this->pret = e.pret;
}
int Entitate::getId()
{
    return this->id;
}
int Entitate::getPret()
{
    return this->pret;
}
char *Entitate::getNume()
{
    return this->nume;
}
void Entitate::setId(int id)
{
    this->id = id;
}
void Entitate::setPret(int pret)
{
    this->pret = pret;
}
void Entitate::setNume(char *nume)
{
    if(this->nume)
    {
        delete[] this->nume;
    }
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}
bool Entitate::operator==(const Entitate &e)
{
    return ((strcmp(this->nume,e.nume)==0) && (this->id == e.id) && (this->pret == e.pret));
}
Entitate &Entitate::operator=(const Entitate &e)
{
    if(this == &e)
    {
        return *this;
    }
    this->id = e.id;
    this->pret = e.pret;
    this->nume = new char[strlen(e.nume)+1];
    strcpy(this->nume,e.nume);
    return *this;

}

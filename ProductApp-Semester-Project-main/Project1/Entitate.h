
#pragma once

class Entitate
{
private:
    int id;
    char *nume;
    int pret;
public:
    Entitate();
    ~Entitate();

    Entitate(int id,char *nume,int pret);
    Entitate(const Entitate &e);

    int getId();
    char *getNume();
    int getPret();

    void setId(int id);
    void setNume(char *nume);
    void setPret(int pret);

    bool operator==(const Entitate &e);
    Entitate &operator=(const Entitate &e);



};

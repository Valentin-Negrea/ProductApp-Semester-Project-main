
#pragma once

class Colectie
{
private:
    int* bancnote;
    int* nrBancnote;
    int bancnoteDistincte;
    int capacitate;
public:
    Colectie();
    void add(int bancnota);
    bool search(int bancnota);
    bool remove(int bancnota);
    int size();
    int numarBancnote(int bancnota);
    void destroy();
    int getAt(int poz);
    void afis();

    int *getBancnote();
    int *getNrBancnote();
};

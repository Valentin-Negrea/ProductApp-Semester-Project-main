//
// Created by vale on 28/05/2023.
//

#include "FileRepo.h"
#include <utility>
#include <iostream>


void FileRepo::loadFile() {
    ifstream f(myfile);
    int cod, pret;
    char nume[100];

    while(f >> cod >> nume >> pret)
    {
        Entitate p(cod, nume, pret);
        EntitateRepository::addEntitate(p);
    }
    f.close();
}

FileRepo::FileRepo(string myfile) {
    this->myfile = std::move(myfile);
    loadFile();
}

void FileRepo::saveToFile() {
    ofstream g(myfile);
    for(int i = 0; i < this->getSize(); i++){
        g << this->getAll()[i].getId() << ' ';
        g << this->getAll()[i].getNume() << ' ';
        g << this->getAll()[i].getPret() << '\n';
    }
}

void FileRepo::addProdus(Entitate produs) {
    EntitateRepository::addEntitate(produs);
    this->saveToFile();
}

void FileRepo::deleteAtPos(int pos) {
    EntitateRepository::deleteEntitate(pos);
    this->saveToFile();
}

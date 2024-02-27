#pragma once
#include "EntitateRepo.h"
#include <fstream>
using namespace std;

class FileRepo: public EntitateRepository {
private:
    string myfile;
    void loadFile();
    void saveToFile();
public:
    FileRepo() = default;



    explicit FileRepo(string myfile);
    void addProdus(Entitate produs);
    // sterge elementul de pe o pozitie
    void deleteAtPos(int pos);
};

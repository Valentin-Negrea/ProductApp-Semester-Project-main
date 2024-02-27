#include <iostream>
#include "tesEntitate.h"
#include "testeRepo.h"
#include "testeService.h"
#include "UI.h"
#include "FileRepo.h"
using namespace std;

int main()
{
    asserts();
    repoAsserts();
    serviceAsserts();
    FileRepo repo("file.txt");
    EntitateService service(repo);
    Ui Ui(service);
    Ui.start();
    return 0;
}

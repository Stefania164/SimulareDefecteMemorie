#include "Afisare.h"
using namespace std;

int main()
{
    int n = 16, m = 16;
    bool mem[16][16];
    elem elem[10];
    int TM[72];
    double gradul_acoperire = 0, gradul_redundanta = 0;
    readFromFile(elem);
    //afisareTestFisier(elem);
    calcTM(elem, TM);
    afisareFisier(TM);
    undiscovedErrors(TM);
    return 0;
}
#pragma once

#include <fstream>
#include <iomanip>
#include "Afisare.h"

#define r0      1
#define r1      2
#define w0     -1
#define w1     -2
#define C       0
#define D       1
#define K       10
#define r       0
#define ntw1    2
#define tw1     2
#define ntw0    1
#define tw0     1

struct elem {
    int sens;   // = {C -> 0, D -> 1}
    int no = 0; // = numarul de operatii
    int op[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  // = { w0 -> -1, w1 -> -2, r0 -> 1, r1-> 2}
};

void readFromFile(elem elem[10]);

void calcTM(elem elem[K], int TM[24]);

void parcurgereCrescatoare(bool mem[][16], int n, int m, elem elem, int poz);

void parcurgereDescrescatoare(bool mem[][16], int n, int m, elem elem, int poz);

void afisareTestFisier(elem elem[K]);

void calculeTest(int TM[24], double& gradul_acoperire, double& gradul_redundanta);

void calculeTestSimplu(int TM[24], double& gradul_acoperire, double& gradul_redundanta);

void afisareFisier(int TM[24]);

void undiscovedErrors(int TM[24], int mod);
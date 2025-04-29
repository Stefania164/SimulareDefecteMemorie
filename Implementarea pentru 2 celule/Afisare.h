#pragma once

#include <conio.h>
#include <iostream>
#include "Test.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define BGWHITE   "\033[47m"


void afisareMatrice(bool mem[][16], int n, int m);

void afisareLinieCrescator(bool mem[][16], int n, int m, bool copy[][16], int line, bool& ok);

void afisareLinieDescrescator(bool mem[][16], int n, int m, bool copy[][16], int line, bool& ok);
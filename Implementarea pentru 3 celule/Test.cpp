#include "Test.h"
using namespace std;

//vectorul corespunzator tabelului pentru 3 celule din anexe
int CF[72] = {  0,  0,  0,
               12, 12, 12,
                3,  3,  3,
               15, 15, 15,
                6,  6,  6,
               18, 18, 18,
                9,  9,  9,
               21, 21, 21,
                1,  1,  1,
                7,  7,  7,
                4,  4,  4,
               10, 10, 10,
               13, 13, 13,
               19, 19, 19,
               16, 16, 16,
               22, 22, 22,
                2,  2,  2,
                5,  5,  5,
                8,  8,  8,
               11, 11, 11,
               14, 14, 14,
               17, 17, 17,
               20, 20, 20,
               23, 23, 23 };

// se citeste din fisier testul, caracter cu caracter
void readFromFile(elem elem[10])
{
    int counter = 0;
    //ifstream inputFile("test.txt");
    //ifstream inputFile("MATS.txt");
    //ifstream inputFile("MATSp.txt");
    //ifstream inputFile("MATSpp.txt");
    //ifstream inputFile("Marching_1_0.txt");
    ifstream inputFile("MarchA.txt");
    //ifstream inputFile("MarchB.txt");
    //ifstream inputFile("MarchC.txt");
    //ifstream inputFile("MarchX.txt");
    //ifstream inputFile("MarchY.txt");
    //ifstream inputFile("MarchLA.txt");
    //ifstream inputFile("MarchSRp.txt");
    //ifstream inputFile("SS2CF.txt");
    //ifstream inputFile("MT-2CFs.txt");
    //ifstream inputFile("MarchLR.txt");
    //ifstream inputFile("MarchM.txt");
    //ifstream inputFile("MarchU.txt");
    //ifstream inputFile("MarchG.txt");
    //ifstream inputFile("MarchSS.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
    }

    char ch;
    char next;
    while (inputFile.get(ch)) {
        if (ch == '<' || ch == '(' || ch == ';' || ch == ' ')
            continue;
        if (ch == 'C' || ch == 'c')
            elem[counter].sens = C;
        if (ch == 'D' || ch == 'd')
            elem[counter].sens = D;
        if (ch == 'I' || ch == 'i')
            elem[counter].sens = C;
        if (ch == ')')
        {
            elem[counter].no++;
            counter++;
        }
        if (ch == ',')
            elem[counter].no++;
        if (ch == 'r')
        {
            next = inputFile.peek();
            if (next == '0')
                elem[counter].op[elem[counter].no] = r0;
            else if (next == '1')
                elem[counter].op[elem[counter].no] = r1;
        }
        if (ch == 'w')
        {
            next = inputFile.peek();
            if (next == '0')
                elem[counter].op[elem[counter].no] = w0;
            else if (next == '1')
                elem[counter].op[elem[counter].no] = w1;
        }
        if (ch == '>')
            break;
    }
    inputFile.close();
}

//functie pentru atunci cand elem.sens == C
void parcurgereCrescatoare(bool mem[][16], int n, int m, elem elem, int poz)
{
    bool ok = 1;
    bool copy[16][16];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copy[i][j] = mem[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            for (int nop = 0; nop < elem.no; nop++)
            {
                copy[i][j] = mem[i][j];
                if (elem.op[nop] == r0)
                {
                    if (mem[i][j] != 0)
                    {
                        cout << "Eroare de memorie! " << "Element March: " << poz << " Operatia" << elem.op[nop] << endl;
                        exit(1);
                    }
                }
                else if (elem.op[nop] == r1)
                {
                    if (mem[i][j] != 1)
                    {
                        cout << "Eroare de memorie! " << "Element March: " << poz << " Operatia" << elem.op[nop] << endl;
                        exit(1);
                    }
                }
                else if (elem.op[nop] == w0)
                {
                    mem[i][j] = 0;
                }
                else if (elem.op[nop] == w1)
                {
                    mem[i][j] = 1;
                }
            }
        }
        afisareLinieCrescator(mem, n, m, copy, i, ok);
    }
    afisareMatrice(mem, n, m);
}

//functie pentru atunci cand elem.sens == D
void parcurgereDescrescatoare(bool mem[][16], int n, int m, elem elem, int poz)
{
    bool ok = 1;
    bool copy[16][16];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copy[i][j] = mem[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            for (int nop = 0; nop < elem.no; nop++)
            {
                copy[i][j] = mem[i][j];
                if (elem.op[nop] == r0)
                {
                    if (mem[i][j] != 0)
                    {
                        cout << "Eroare de memorie! " << "Element March: " << poz << " Operatia" << elem.op[nop] << endl;
                        exit(1);
                    }
                }
                else if (elem.op[nop] == r1)
                {
                    if (mem[i][j] != 1)
                    {
                        cout << "Eroare de memorie! " << "Element March: " << poz << " Operatia: " << elem.op[nop] << endl;
                        exit(1);
                    }
                }
                else if (elem.op[nop] == w0)
                {
                    mem[i][j] = 0;
                }
                else if (elem.op[nop] == w1)
                {
                    mem[i][j] = 1;
                }
            }
        }
        afisareLinieDescrescator(mem, n, m, copy, i, ok);
    }
    afisareMatrice(mem, n, m);
}

//afisarea pe ecran a memoriei pas cu pas, urmarind testul
void afisareTestFisier(elem elem[K])
{
    bool mem[16][16];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            mem[i][j] = 0;
    }

    for (int i = 0; i < K; i++)
    {
        if (elem[i].sens == C)
        {
            parcurgereCrescatoare(mem, 16, 16, elem[i], i);
        }
        else if (elem[i].sens == D)
        {
            parcurgereDescrescatoare(mem, 16, 16, elem[i], i);
        }
    }
}

//calculul tabelului de frecvente
void calcTM(elem elem[K], int TM[24])
{
    int su[3] = { 0, 0, 0 }, sc[3] = { 0, 0, 0 };
    for (int i = 0; i < 24; i++)
    {
            TM[i] = 0;
    }
    int tip_op, O;
    int s_c;
    for (int noel = 1; noel < K; noel++)
    {
        if (elem[noel].sens == C)
        {
            for (int c = 0; c <= 2; c++)
            {
                for (int nop = 0; nop < elem[noel].no; nop++)
                {
                    tip_op = elem[noel].op[nop];
                    switch (tip_op)
                    {
                    case r0:
                    case r1:
                        O = r;
                        break;
                    case w0:
                        if (sc[c] == 0)
                        {
                            O = ntw0;
                        }
                        else
                        {
                            O = tw0;
                            su[c] = 0;
                        }
                        break;
                    case w1:
                        if (sc[c] == 1)
                        {
                            O = ntw1;
                        }
                        else
                        {
                            O = tw1;
                            su[c] = 1;
                        }
                        break;
                    default:
                        break;
                    }
                    s_c = (sc[0] << 2) + (sc[1] << 1) + sc[2];  //calculul starii curente
                    TM[int(s_c) * 3 + c]++; //elementul de la pozitia respectiva este incrementat cu 1
                    sc[c] = su[c]; //starea curenta de la pozitia c devine starea urmatoare de la pozitia c
                    s_c = (sc[0] << 2) + (sc[1] << 1) + sc[2]; //calculul starii curente
                }
            }
        }
        else if (elem[noel].sens == D)
        {
            for (int c = 2; c >= 0; c--)
            {
                for (int nop = 0; nop < elem[noel].no; nop++)
                {
                    tip_op = elem[noel].op[nop];
                    switch (tip_op)
                    {
                    case r0:
                    case r1:
                        O = r;
                        break;
                    case w0:
                        if (sc[c] == 0)
                        {
                            O = ntw0;
                        }
                        else
                        {
                            O = tw0;
                            su[c] = 0;
                        }
                        break;
                    case w1:
                        if (sc[c] == 1)
                        {
                            O = ntw1;
                        }
                        else
                        {
                            O = tw1;
                            su[c] = 1;
                        }
                    default:
                        break;
                    }
                    s_c = (sc[0] << 2) + (sc[1] << 1) + sc[2];
                    TM[int(s_c) * 3 + c]++;
                    sc[c] = su[c];
                    s_c = (sc[0] << 2) + (sc[1] << 1) + sc[2];
                }
            }
        }
        else
            break;
    }
}

//calcule performante test
void calculeTest(int TM[24], double& gradul_acoperire, double& gradul_redundanta)
{
    int counterG0 = 0, sum = 0;
    for (int i = 0; i < 24; i++)
    {
        if (TM[i] > 0)
        {
            counterG0++;
            sum += TM[i] - 1;
        }
    }
    gradul_acoperire = (double(counterG0) / 24) * 100;
    gradul_redundanta = (double(sum) / 24) * 100;
}

//afisarea tabelului de frecvente intr-un fisier
void afisareFisier(int TM[24])
{
    std::ofstream outFile("REZTabel.txt");

    if (!outFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    for (int i = 0; i < 24; i++)
    {
        bitset<3> bits = i / 3;
        if (i % 3 == 0)
        {
            outFile << "******************************************" << endl;
            outFile << bits;
        }
        int s[3] = { 0, 0, 0 };
        s[2] = bits.test(0);
        s[1] = bits.test(1);
        s[0] = bits.test(2);
        switch (i % 3)
        {
        case 0:
            outFile << "\t**\tc1|w" << (s[0] ^ 1) << "\t**\t" << setw(2) << TM[i] << "\t**" << endl;
            break;
        case 1:
            outFile << "\t**\tc2|w" << (s[1] ^ 1) << "\t**\t" << setw(2) << TM[i] << "\t**" << endl;
            break;
        case 2:
            outFile << "\t**\tc3|w" << (s[2] ^ 1) << "\t**\t" << setw(2) << TM[i] << "\t**" << endl;
            break;
        }
    }
    outFile << "******************************************";
    outFile.close();
}

//functia care afiseaza lista de defecte nedetectate si perfomanta testului intr-un fisier
void undiscovedErrors(int TM[24])
{
    std::ofstream outFile("error_detection.txt");

    if (!outFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    int ue[24], count = 0;
    for (int i = 0; i < 24; i++)
    {
        if (TM[i] == 0)
        {
            ue[count] = i;
            count++;
        }
    }
    if (count == 0)
        outFile << "Toate erorile sunt detectate." << endl;
    else
    {
        bool firstError = true;
        for (int j = 0; j < 72; j++)
        {
            for (int i = 0; i < count; i++)
            {
                if (ue[i] == CF[j])
                {
                    if (firstError == true)
                    {
                        outFile << "Erorile nedetectate sunt: ";
                        firstError = false;
                    }
                    else
                        outFile << ", ";
                    outFile << "F" << j + 1;
                }
            }
        }
    }
    double gradul_acoperire = 0, gradul_redundanta = 0;
    calculeTest(TM, gradul_acoperire, gradul_redundanta);
    outFile << endl << endl << "Gradul de acoperire = " << gradul_acoperire << "%" << endl;
    outFile << "Gradul de redundanta = " << gradul_redundanta << "%" << endl;  
}
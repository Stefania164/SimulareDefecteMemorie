#include "Afisare.h"
using namespace std;

int main()
{
    int n = 16, m = 16;
    bool mem[16][16];
    elem elem[10];
    int TM[24];
    double gradul_acoperire = 0, gradul_redundanta = 0;
    readFromFile(elem);
    afisareTestFisier(elem);
    calcTM(elem, TM);
    afisareFisier(TM);
    system("cls");
    char key = _getch();
    cout << "Doriti varianta restransa sau cea extinsa? (0 - restransa; 1 - extinsa)" << endl;
    int mod;
    cin >> mod;
    while (mod != 0 && mod != 1)
    {
        cout << "Reintroduceti una dintre valorile date (0 - restransa; 1 - extinsa)" << endl;
        cin >> mod;
    }
    undiscovedErrors(TM, mod);
    return 0;
}
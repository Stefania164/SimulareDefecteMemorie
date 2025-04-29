#include "Afisare.h"
using namespace std;

//functie pentru afisarea matricei la apasarea tastei m
void afisareMatrice(bool mem[][16], int n, int m)
{
    char key = _getch();
    system("cls");
    if (key == 'm' || key == 'M')
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mem[i][j] << " ";
            }
            cout << endl;
        }
    }
}

//functie pentru afisarea matricei la apasarea tastei l; folosita in parcurgerea crescatoare
void afisareLinieCrescator(bool mem[][16], int n, int m, bool copy[][16], int line, bool& ok)
{
    if (ok == 1)
    {
        char key = _getch();
        system("cls");
        if (key == 'l' || key == 'L')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i < line)
                    {
                        cout << mem[i][j] << " ";
                    }
                    else
                    {
                        if (i == line)
                            cout << BGWHITE << BLACK << mem[i][j] << " " << RESET;
                        else
                            cout << copy[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            if (key == 'm' || key == 'M')
                ok = 0;
        }
    }
}

//functie pentru afisarea matricei la apasarea tastei l; folosita in parcurgerea descrescatoare;
void afisareLinieDescrescator(bool mem[][16], int n, int m, bool copy[][16], int line, bool& ok)
{
    if (ok == 1)
    {
        char key = _getch();
        system("cls");
        if (key == 'l' || key == 'L')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i > line)
                    {
                        cout << mem[i][j] << " ";
                    }
                    else
                    {
                        if (i == line)
                            cout << BGWHITE << BLACK << mem[i][j] << " " << RESET;
                        else
                            cout << copy[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            if (key == 'm' || key == 'M')
                ok = 0;
        }
    }
}
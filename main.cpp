#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void lepesek(int j,int &x0,int &y0)
{
    switch (j)
        {
        case 1: {x0 -= 2; y0--; } break;
        case 2: {x0--; y0 -= 2; } break;
        case 3: {x0++; y0 -= 2; } break;
        case 4: {x0 += 2; y0--; } break;
        case 5: {x0 += 2; y0++; } break;
        case 6: {x0++; y0 += 2; } break; 
        case 7: {x0--; y0 += 2; } break;
        case 8: {x0 -= 2; y0++; } break;
        }
}

void feldolgoz(int n, int** v, int x0, int y0, int x1, int y1,int x,int y)
{ 
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            v[i][j] = 0; 
        }
    }
    for (i = x - 1, j = y - 1; (i < n && j < n); i++, j++)
    {
        v[i][j] = -1;
    }
    for (i = x - 1, j = y - 1; (i >= 0 && j >= 0); i--, j--)
    {
        v[i][j] = -1;
    }
    for (i = x - 1, j = y - 1; (i < n && j >= 0); i++, j--)
    {
        v[i][j] = -1;
    }
    for (i = x - 1, j = y - 1; (i >= 0 && j < n); i--, j++)
    {
        v[i][j] = -1;
    }
    v[x0 - 1][y0 - 1] = 1;
}
bool megfelelo(int n, int ** v, int x0, int y0)
{
    if ((x0 - 1 >= 0 && y0 - 1 >= 0) && (x0 - 1 < n && (y0 - 1 < n)))
    {
        if (v[x0 - 1][y0 - 1] == 0)
            return true; 
    }
    return false;
}

void kiir(int n, int **v)
{ 

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << setw(3) << v[i][j];
        }
        cout << endl << endl;
    }
    cout << endl;
    exit(0);
}

void utvonalak(int n, int **v, int x0, int y0, int x1, int y1, int szam)
{
    int j, segedx, segedy;
    for (j = 1; j <= 8; j++)
    {
        segedx = x0;
        segedy = y0; 
        lepesek(j,x0,y0);
        if (megfelelo(n, v, x0, y0))
        { 
            v[x0 - 1][y0 - 1] = szam;
            szam++;
            if (x0 == x1 && y0 == y1)
            { 
                kiir(n, v);
                v[x1 - 1][y1 - 1] = 0;
                szam--; 
            }
            else
            {
                utvonalak(n, v, x0, y0, x1, y1, szam);
                szam--; 
            }
        }
        if (j == 8)
        {
            v[segedx - 1][segedy - 1] = 0; 
        }
        x0 = segedx;
        y0 = segedy; 
    }
}

int main()
{
    int n;
    cout << "Matrix merete:";
    cin >> n;
    int x,y,x0, y0, x1, y1, szam = 2;
    int** v;
    v = new int* [n];
    for (int i = 0; i < n; i++) {
        v[i] = new int[n];
    }
    cout << "A lo kiindulasanak x koordinataja:";
    cin >> x0;
    cout << "A lo kiindulasanak y koordinataja:";
    cin >> y0;
    cout << "A lo erkezesenek x koordinataja:";
    cin >> x1;
    cout << "A lo erkezesenek y koordinataja:";
    cin >> y1;
    cout << "A futo x koordinataja:";
    cin >> x;
    cout << "A futo y koordinataja:";
    cin >> y;
    cout << "Backtracking:"<<endl;
    feldolgoz(n, v, x0, y0, x1, y1,x,y);
    utvonalak(n, v, x0, y0, x1, y1, szam);
    return 0;
}

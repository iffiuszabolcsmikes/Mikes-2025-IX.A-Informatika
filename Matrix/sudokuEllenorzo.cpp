#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 9;

int sudoku[N][N];

void beolvas()
{
    ifstream f;
    f.open("sud.in");
    if(!f)
    {
        cout << "Nem sikerult megnyitni a file-t!" << endl;
        return;
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            f >> sudoku[i][j];

    f.close();
}

void kiir()
{
    for(int i = 0; i < N; i++)
    {
        if(i == 3 || i == 6)
        {

            cout << "----------------------" << endl;
        }

        for(int j = 0; j < N; j++)
        {
            if(j == 3 || j == 6)
                cout << "| ";
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool sorhiba(int i)
{
    int szamjegyek[10] = {0};
    for(int j = 0; j < N; j++)
    {
        szamjegyek[sudoku[i][j]]++;
    }
    for(int k = 1; k < 10; k++)
      if(szamjegyek[k] != 1)
        return true;

    return false;
}
bool oszlophiba(int j)
{
    int szamjegyek[10] = {0};
    for(int i = 0; i < N; i++)
    {
        szamjegyek[sudoku[i][j]]++;
    }
    for(int k = 1; k < 10; k++)
      if(szamjegyek[k] != 1)
        return true;

    return false;
}

bool hiba3x3(int x, int y)
{
    int szamjegyek[10] = {0};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            szamjegyek[sudoku[x + i][y + j]]++;
        }
    }
    for(int k = 1; k < 10; k++)
      if(szamjegyek[k] != 1)
        return true;
    return false;
}

bool ellenoriz()
{
    bool helyes = true;
    //sor hiba
    for(int i = 0; i < N; i++)
    {
        if(sorhiba(i))
        {
            cout << i << ". sorhiba" << endl;
            helyes = false;
        }
    }

    //oszlop hiba
    for(int j = 0; j < N; j++)
    {
        if(oszlophiba(j))
        {
            cout << j << ". oszlophiba" << endl;
            helyes = false;
        }
    }
    //3x3 hiba
    for(int i = 0; i < N; i += 3)
    {
        for(int j = 0; j < N; j += 3)
        {
            if(hiba3x3(i, j))
            {
                cout << i << ". " << j << ". 3x3 hiba" << endl;
                helyes = false;
            }
        }
    }

    return helyes;
}

int main()
{
    beolvas();
    kiir();
    if(ellenoriz())
        cout << "helyes" << endl;
    return 0;
}

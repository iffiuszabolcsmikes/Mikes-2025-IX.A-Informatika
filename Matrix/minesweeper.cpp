#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;
const int M = 100;

int mine[N][M] = {0};
int n = 0;
int m = 0;
int mineCount = 0;

void beolvas()
{
    ifstream f;
    f.open("mine.in");
    if(!f)
    {
        cout << "Nem sikerult megnyitni a file-t!" << endl;
        return;
    }
    f >> n >> m >> mineCount;
    while(mineCount > 0)
    {
        int i, j;
        f >> i >> j;
        mine[i][j] = -1;
        mineCount--;
    }
    f.close();
}

void kiir()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mine[i][j] < 0)
                cout << setw(2) << "#";
            else
                cout << setw(2) << mine[i][j];
        }
        cout << endl;
    }
}

void kitolt()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //ha nem bomba
            if(mine[i][j] != -1)
            {
                int darab = 0;
                if(i-1 >= 0 && j-1 >= 0 && mine[i-1][j-1] == -1) darab++;
                if(i-1 >= 0 && mine[i-1][j] == -1) darab++;
                if(i-1 >= 0 && j+1 < m && mine[i-1][j+1] == -1) darab++;
                if(j-1 >= 0 && mine[i][j-1] == -1) darab++;
                if(j+1 < m && mine[i][j+1] == -1) darab++;
                if(i+1 < n && j-1 >= 0 && mine[i+1][j-1] == -1) darab++;
                if(i+1 < n && mine[i+1][j] == -1) darab++;
                if(i+1 < n && j+1 < m && mine[i+1][j+1] == -1) darab++;

                mine[i][j] = darab;
            }
        }
    }
}

int veletlen(int a, int b)
{
    return rand()%(b - a + 1) + a;
}

void general()
{
    n = veletlen(9, 30);
    m = veletlen(9, 30);
    mineCount = n*m/5;
    while(mineCount > 0)
    {
        int i = veletlen(0, n - 1);
        int j = veletlen(0, m - 1);
        if(mine[i][j] == 0)
        {
            mine[i][j] = -1;
            mineCount--;
        }
    }
}

int main()
{
    srand(time(0));
    //beolvas();
    //kiir();
    general();
    kitolt();
    kiir();
    return 0;
}




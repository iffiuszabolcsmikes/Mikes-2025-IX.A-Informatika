#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int N = 100;
const int M = 100;

void kiir(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << setw(3) << tomb[i][j];
        }
        cout << endl;
    }
}

void kiirHaromszog(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << setw(3) << tomb[i][j];
        }
        cout << endl;
    }
}

void feltolt0(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tomb[i][j] = 0;
        }
    }
}

void feltoltVeletlen(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tomb[i][j] = rand() % 10;
        }
    }
}

void feltoltSakk(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tomb[i][j] = i % 2 == j % 2;
        }
    }
}

void feltoltVizszintesCsik(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i += 2)
    {
        for(int j = 0; j < m; j++)
        {
            tomb[i][j] = 1;
        }
    }
}

void feltoltFuggolegesCsik(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j += 2)
        {
            tomb[i][j] = 1;
        }
    }
}

void feltoltKigyo(int tomb[][M], int n, int m)
{
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < m; j++)
            {
                tomb[i][j] = k;
                k++;
            }
        }
        else
        {
            for(int j = m - 1; j >= 0; j--)
            {
                tomb[i][j] = k;
                k++;
            }

        }
    }
}

void feltoltSpiral(int tomb[][M], int n, int m)
{
    int k = 0;
    for(int h = 0; h < m / 2; h++)
    {
        for(int j = h; j < m - h; j++)
            tomb[h][j] = k++;
        for(int i = h + 1; i < n - h; i++)
            tomb[i][m - 1 - h] = k++;
        for(int j = m - 1 - h; j >= h; j--)
            tomb[n - 1 - h][j] = k++;
        for(int i = n - 2 - h; i > h; i--)
            tomb[i][h] = k++;
    }
}

void kiirFoatlo(int tomb[][M], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << tomb[i][i] << " ";

    }
    cout<<endl;
}

void kiirMellekatlo(int tomb[][M], int n)
{
     for(int i = 0; i < n; i++)
    {
        cout << tomb[i][n - 1 - i] << " ";

    }
    cout<<endl;
}

void kiirSzorzotabla(int tomb[][M], int n)
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
}

 void kiirSorOsszeg(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        int osszeg = 0;
        for(int j = 0; j < m; j++)
        {
            osszeg += tomb[i][j];
        }
        cout << "sor " << i << ": " << osszeg << endl;
    }
}

void kiirOszlopOsszeg(int tomb[][M], int n, int m)
{
    for(int j = 0; j < m; j++)
    {
        int osszeg = 0;
        for(int i = 0; i < n; i++)
        {
            osszeg += tomb[i][j];
        }
        cout << "oszlop " << j << ": " << osszeg << endl;
    }
}

void kiirFoatloOsszeg(int tomb[][M], int n)
{
    int osszeg = 0;
    for(int i = 0; i < n; i++)
    {
        osszeg += tomb[i][i];
    }

    cout << "foatlo osszege: " << osszeg << endl;
}

void kiirMellekatloOsszeg(int tomb[][M], int n)
{
    int osszeg = 0;
    for(int i = 0; i < n; i++)
    {
        osszeg += tomb[i][n - 1 - i];
    }

    cout << "mellekatlo osszege: " << osszeg << endl;
}

void sorCsere(int tomb[][M], int m, int a, int b)
{
    for(int j = 0; j < m; j++)
    {
        int okszia = tomb[a][j];
        tomb[a][j] = tomb[b][j];
        tomb[b][j] = okszia;
    }
}

void oszlopCsere(int tomb[][M], int n, int a, int b)
{
    for(int i = 0; i < n; i++)
    {
        int okszia = tomb[i][a];
        tomb[i][a] = tomb[i][b];
        tomb[i][b] = okszia;
    }
}

void forditBalra90(int bemenet[][M], int n, int m, int kimenet[][M])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            kimenet[m - 1 - j][i] = bemenet[i][j];
        }
    }
}

void forditJobbra90(int bemenet[][M], int n, int m, int kimenet[][M])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            kimenet[j][n - 1 - i] = bemenet[i][j];;
        }
    }
}

void fordit180(int bemenet[][M], int n, int m, int kimenet[][M])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            kimenet[n - 1 - i][m - 1 - j] = bemenet[i][j];
        }
    }
}

void tukorkepVizzszintes(int bemenet[][M], int n, int m, int kimenet[][M])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            kimenet[i][m - 1 - j] = bemenet[i][j];
        }
    }
}

void tukorkepFuggoleges(int bemenet[][M], int n, int m, int kimenet[][M])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            kimenet[n - 1 - i][j] = bemenet[i][j];
        }
    }
}

void tukorkepFoatlo(int bemenet[][M], int n, int m, int kimenet[][M])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            kimenet[j][i] = bemenet[i][j];
        }
    }
}

void tukorkepMellekatlo(int bemenet[][M], int n, int m, int kimenet[][M])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            kimenet[n - 1 - j][n - 1 - i] = bemenet[i][j];
        }
    }
}

int melyikSorbanVanAMax(int tomb[][M], int n, int m)
{
    int maxi = 0;
    int maxj = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(tomb[maxi][maxj] < tomb[i][j])
            {
                maxi = i;
                maxj = j;
            }
        }
    }
    return maxi;
}

int maxSorOsszeg(int tomb[][M], int n, int m)
{
    int max=0;
    for(int i = 0; i < n; i++)
    {
        int ossz=0;
        for(int j = 0; j < m; j++)
        {
            ossz+=tomb[i][j];
        }
        if(ossz> max)
        {
            max = ossz;
        }
    }
    return max;
}

void nullaz(int tomb[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            tomb[i][j] = 0;
}

void feltoltCeltabla(int tomb[][M], int n, int m)
{
    nullaz(tomb, n, m);

    for(int k = 0; k < n / 2 - 1; k += 2)
    {
        for(int i = k; i < n - k; i++)
        {
            //elso oszlop
            tomb[i][k] = 1;
            //utolso oszlop
            tomb[i][m - 1 - k] = 1;
        }
    }

    for(int k = 0; k < m / 2 - 1; k += 2)
    {
        for(int j = k; j < m - k; j++)
        {
            //elso sor
            tomb[k][j] = 1;
            //utolso sor
            tomb[n - 1 - k][j] = 1;
        }
    }
}

void feltoltCeltabla2(int tomb[][M], int n, int m)
{
    int okszia;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int felso = i;
            int bal = j;
            int also = n - 1 - i;
            int jobb = m - 1 - j;

            okszia= min(min(felso, also), min(bal, jobb));

            tomb[i][j] = okszia % 2;
        }
    }
}

int main()
{
    srand(time(0));
    int tomb[N][M] = {0};
    int forditott[N][M];
    int n = 4, m = 4;
    cout << "veletlen" << endl;
    feltoltVeletlen(tomb, n, m);
    kiir(tomb, n, m);
    cout << "sakk" << endl;
    feltoltSakk(tomb, n, m);
    kiir(tomb, n, m);
    cout << "vizszintes" << endl;
    feltolt0(tomb, n, m);
    feltoltVizszintesCsik(tomb, n, m);
    kiir(tomb, n, m);
    cout << "fuggoleges" << endl;
    feltolt0(tomb, n, m);
    feltoltFuggolegesCsik(tomb, n, m);
    kiir(tomb, n, m);
    cout << "kigyo" << endl;
    feltolt0(tomb, n, m);
    feltoltKigyo(tomb, n, m);
    kiir(tomb, n, m);
    cout << "haromszog kiiras" << endl;
    kiirHaromszog(tomb, n, m);
    cout << "spiral" << endl;
    feltoltSpiral(tomb, n, m);
    kiir(tomb, n, m);
    cout << "szorzotabla" << endl;
    kiirSzorzotabla(tomb, n);

    cout << "#######################" << endl;
    feltoltVeletlen(tomb, n, m);
    kiir(tomb, n, m);
    cout<< "foatlo" << endl;
    kiirFoatlo(tomb, n);
    cout<< "mellekatlo" << endl;
    kiirMellekatlo(tomb, n);
    cout << "sorosszegek" << endl;
    kiirSorOsszeg(tomb, n, m);
    cout << "oszloposszegek" << endl;
    kiirOszlopOsszeg(tomb, n, m);
    cout << "foatlo osszeg" << endl;
    kiirFoatloOsszeg(tomb, n);
    cout << "mellekatlo osszeg" << endl;
    kiirMellekatloOsszeg(tomb, n);
    cout << "sorcsere elott" << endl;
    kiir(tomb, n, m);
    sorCsere(tomb, m, 1, 2);
    cout << "sorcsere utan" << endl;
    kiir(tomb, n, m);
    cout << "oszlopcsere elott" << endl;
    kiir(tomb, n, m);
    oszlopCsere(tomb, n, 1, 2);
    cout << "oszlopcsere utan" << endl;
    kiir(tomb, n, m);
    forditJobbra90(tomb, n, m, forditott);
    cout << "jobbra 90" << endl;
    kiir(forditott, m, n);
    forditBalra90(tomb, n, m, forditott);
    cout << "balra 90" << endl;
    kiir(forditott, m, n);
    fordit180(tomb, n, m, forditott);
    cout << "180 fok" << endl;
    kiir(forditott, n, m);
    tukorkepVizzszintes(tomb, n, m, forditott);
    cout << "tukorkep" << endl;
    kiir(forditott, n, m);
    tukorkepFuggoleges(tomb, n, m, forditott);
    cout << "tukorkep fuggoleges" << endl;
    kiir(forditott, n, m);
    tukorkepFoatlo(tomb, n, m, forditott);
    cout << "tukorkep foatlo szerint" << endl;
    kiir(forditott, m, n);
    tukorkepMellekatlo(tomb, n, m, forditott);
    cout << "tukorkep mellekatlo szerint" << endl;
    kiir(forditott, n, m);

    cout << "melyik sorban van a max elem: ";
    cout << melyikSorbanVanAMax(tomb, n, m) << endl;
cout << "melyik a legnagyobb sor osszeg: ";
    cout << maxSorOsszeg(tomb, n, m) << endl;

    n = 40;
    m = 35;
    //feltoltCeltabla(tomb, n, m);
    feltoltCeltabla2(tomb, n, m);
    kiir(tomb, n, m);

    return 0;
}

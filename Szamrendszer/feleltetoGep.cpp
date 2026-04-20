#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int osszead_bin(int x2, int y2)
{
    int ossz2 = 0;
    int megyTovabbAz1 = 0;
    int helyiErtek = 1;
    while(x2 != 0 || y2 != 0)
    {
        int uszx = x2 % 10;
        int uszy = y2 % 10;
        int uszossz2;

        int tmp = uszx + uszy + megyTovabbAz1;

        if(tmp >= 2)
            megyTovabbAz1 = 1;
        else
            megyTovabbAz1 = 0;

        if(tmp % 2 == 0)
            uszossz2 = 0;
        else
            uszossz2 = 1;

        ossz2 += uszossz2 * helyiErtek;

        helyiErtek *= 10;

        x2 /= 10;
        y2 /= 10;
    }
    ossz2 += megyTovabbAz1 * helyiErtek;
    return ossz2;
}

int atalakit_2_10(int x2)
{
    int x10 = 0;
    int helyiErtek = 1;
    while(x2 != 0)
    {
        int usz = x2 % 10;  //utolso szamjegy
        x10 +=  usz * helyiErtek;
        helyiErtek *= 2; //helyiErtekt novelem a kovetkezo kitevore
        x2 /= 10; //levagjuk az utolso szamjegyet
    }
    return x10;
}

int atalakit_10_2(int x10)
{
    int x2 = 0;
    int helyiErtek = 1;
    while(x10 != 0)
    {
        int usz = x10 % 2;
        x2 += usz * helyiErtek;
        helyiErtek *= 10;
        x10 /= 2;
    }
    return x2;
}

int atalakit_n_10(int xn, int n)
{
    int x10 = 0;
    int helyiErtek = 1;
    while(xn != 0)
    {
        int usz = xn % 10;  //utolso szamjegy
        x10 +=  usz * helyiErtek;
        helyiErtek *= n; //helyiErtekt novelem a kovetkezo kitevore
        xn /= 10; //levagjuk az utolso szamjegyet
    }
    return x10;
}

int atalakit_10_n(int x10, int n)
{
    int xn = 0;
    int helyiErtek = 1;
    while(x10 != 0)
    {
        int usz = x10 % n;
        xn += usz * helyiErtek;
        helyiErtek *= 10;
        x10 /= n;
    }
    return xn;
}
int atalakit_n_m(int xn, int n, int m)
{
    int xm = 0;
    int helyiErtek = 1;
    while(xn != 0)
    {
        int usz = xn % 10;  //utolso szamjegy
        xm +=  usz * helyiErtek;
        helyiErtek *= n; //helyiErtekt novelem a kovetkezo kitevore
        xn /= 10; //levagjuk az utolso szamjegyet
    }
    return xm;
}

int veletlenSzam(int kezd, int veg)
{
    return rand() % (veg - kezd + 1) + kezd;
}

int pontszam = 1; //hivatalbol ;)
int sorszam = 1;

void atalakitosFeladat(int n, int m)
{
    int x10, xn, xm, valasz;

    cout << sorszam << ". feladat" << endl;
    sorszam++;
    x10 = veletlenSzam(10, 20);
    xn = atalakit_10_n(x10, n);
    xm = atalakit_10_n(x10, m);
    cout << xn << "(" << n << ")->?(" << m << ")" << endl;
    cout << "valasz: ";
    cin >> valasz;
    if(valasz == xm)
    {
        cout << "helyes" << endl;
        pontszam++;
    }
    else
    {
        cout << "helytelen" << endl;
        cout << "a helyes valasz: " << xm << endl;
    }
}

void osszeadosFeladat(int n)
{
    cout << sorszam << ". feladat" << endl;
    sorszam++;
    int valasz;
    int x10 = veletlenSzam(10, 20);
    int y10 = veletlenSzam(10, 20);
    int xn = atalakit_10_n(x10, n);
    int yn = atalakit_10_n(y10, n);
    int ossz = atalakit_10_n(x10 + y10, n);

    cout << xn << "(" << n << ") + " << yn << "(" << n << ") = ?(" << n << ")" << endl;
    cout << "valasz: ";
    cin >> valasz;
    if(valasz == ossz)
    {
        cout << "helyes" << endl;
        pontszam++;
    }
    else
    {
        cout << "helytelen" << endl;
        cout << "a helyes valasz: " << ossz << endl;
    }
}

void cheatSheet()
{
    cout << setw(6) << "(10)";
    cout << setw(6) << "(2)";
    cout << setw(6) << "(4)";
    cout << setw(6) << "(8)" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << setw(6) << i;
        cout << setw(6) << atalakit_10_2(i);
        cout << setw(6) << atalakit_10_n(i, 4);
        cout << setw(6) << atalakit_10_n(i, 8) << endl;
    }
}

int main()
{
    srand(time(0));

    cheatSheet();

    atalakitosFeladat(2, 10);
    atalakitosFeladat(10, 2);
    atalakitosFeladat(2, 4);
    atalakitosFeladat(4, 2);
    atalakitosFeladat(2, 8);
    atalakitosFeladat(8, 2);

    int n;
    n = veletlenSzam(3, 9);
    while(n == 4 || n == 8);
        n = veletlenSzam(3, 9);
    atalakitosFeladat(10, n);

    int m;
    m = veletlenSzam(3, 9);
    while(m == 4 || m == 8 || n == m)
        m = veletlenSzam(3, 9);
    atalakitosFeladat(m, 10);

    osszeadosFeladat(2);

    cout << "A jegyed: " << pontszam << endl;

    return 0;
}

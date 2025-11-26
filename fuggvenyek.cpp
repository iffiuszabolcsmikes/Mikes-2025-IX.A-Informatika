#include <iostream>

using namespace std;

int osszeg(int a, int b)
{
    return a + b;
}

int kulonbseg(int a, int b)
{
    return a - b;
}

int szorzat(int a, int b)
{
    return a * b;
}

int hanyados(int a, int b)
{
    return a / b;
}

int maradek(int a, int b)
{
    return a % b;
}

//visszateriti a kisebbik szamot
int kisebb(int a, int b)
{
    if(a < b) return a;
    else return b;
}

int hatvany(int a, int k)
{
    int szorzat = 1;
    while(k != 0)
    {
        if(k % 2 == 0)
        {
            a = a * a;
            k = k / 2;
        }
        else
        {
            szorzat = szorzat * a;
            k--;
        }
    }
    return szorzat;
}

bool paros(int szam)
{
    return szam % 2 == 0;
}

int main()
{
    int a = 2, b =10;
    cout << a << " " << b << endl;
    cout << "osszeg " << osszeg(a, b) << endl;
    cout << "kulonbseg " << kulonbseg(a, b) << endl;
    cout << "szorzat " << szorzat(a, b) << endl;
    cout << "hanyados " << hanyados(a, b) << endl;
    cout << "maradek " << maradek(a, b) << endl;
    cout << "kisebb " << kisebb(a, b) << endl;
    cout << a << "^" << b << "=" << hatvany(a, b) << endl;

    if(paros(4))
    {
        cout << "paros" << endl;
    }
    else
    {
        cout << "paratlan" << endl;
    }
    return 0;
}


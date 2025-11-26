#include <iostream>

using namespace std;

//visszateriti a szam fordittottjat (pl.: 123 -> 321)
int megfordit(int szam)
{
    int forditott = 0;
    while(szam != 0)
    {
        forditott = forditott * 10 + szam % 10;
        szam = szam / 10;
    }
    return forditott;
}

bool tukorSzam(int szam)
{
    return szam == megfordit(szam);
}

bool prim(int szam)
{
    if(szam < 2)
    {
        return false;
    }

    for(int i = 2; i * i <= szam; i++)
    {
        if(szam % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool tukorPrim(int szam)
{
    return tukorSzam(szam) && prim(szam);
}

int main()
{
    for(int i = 0; i < 10000; i++)
    {
        if(tukorPrim(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}



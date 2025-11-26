#include <iostream>

using namespace std;

int utolsoSzamjegy(int szam)
{
    return szam % 10;
}

int levagUtolsoSzamjegy(int szam)
{
    return szam / 10;
}

int szamjegySzam(int szam)
{
    if(szam == 0)
    {
        return 1;
    }
    int db = 0;
    while(szam != 0)
    {
        szam = levagUtolsoSzamjegy(szam);
        db++;
    }
    return db;
}

int hatvany(int a, int k)
{
    int szorzat = 1;
    while(k != 0)
    {
        if(k % 2 == 0)
        {
            a *= a;
            k /= 2;
        }
        else
        {
            szorzat *= a;
            k--;
        }
    }
    return szorzat;
}

bool armstrong(int szam)
{
    int eredeti = szam;
    int ossz = 0;
    int k = szamjegySzam(szam);
    while(szam != 0)
    {
        ossz += hatvany(utolsoSzamjegy(szam), k);
        szam = levagUtolsoSzamjegy(szam);
    }
    return ossz == eredeti;
}

int main()
{
    for(int i = 1; i < 100000; i++)
    {
        if(armstrong(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}


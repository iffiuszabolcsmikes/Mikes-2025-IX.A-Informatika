#include <iostream>

using namespace std;

int szamjegySzam(int szam)
{
    if(szam == 0)
    {
        return 1;
    }
    int db = 0;
    while(szam != 0)
    {
        db++;
        szam = szam / 10;
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

bool armstrong(int szam)
{
    int eredeti = szam;
    int ossz = 0;
    int k = szamjegySzam(szam);
    while(szam != 0)
    {
        ossz = ossz + hatvany(szam % 10, k);
        szam = szam / 10;
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

#include <iostream>

using namespace std;

//visszateriti a szam szamjegyeinek darabszamat
int szamjegyekSzama( int szam)
{
    if(szam == 0)
        return 1;

    int db = 0;
    while(szam != 0)
    {
        szam = szam / 10;
        db++;
    }
    return db;
}

//visszateriti a szam szamjegyeinek osszeget
int szamjegyekOsszege( int szam)
{
    int osszeg = 0;
    while(szam != 0)
    {
        osszeg = osszeg + szam % 10;
        szam = szam / 10;
    }
    return osszeg;
}

//visszateriti a szam legkisebb szamjegyet
int legkisebbSzamjegy(int szam)
{
    int min = szam % 10;
    while(szam != 0)
    {
        if(szam % 10 < min)
        {
            min = szam % 10;
        }
        szam = szam / 10;
    }
    return min;
}

//visszateriti a szam legnagyobb szamjegyet
int legnagyobbSzamjegy(int szam)
{
    int max = szam % 10;
    while(szam != 0)
    {
        if(szam % 10 > max)
        {
            max = szam % 10;
        }
        szam = szam / 10;
    }
    return max;
}

//visszateriti a szam utolso szamjegyet
int utolsoSzamjegy(int szam)
{
    return szam % 10;
}

//visszateriti a szam elso szamjegyet
int elsoSzamjegy(int szam)
{
    while(szam <-9 || szam >9)
    {
        szam = szam / 10;
    }
    return szam;
}

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

int main()
{
    int szam;
    cout << "szam: ";
    cin >> szam;
    cout << "szamjegyek szama: " << szamjegyekSzama(szam) << endl;
    cout << "szamjegyek osszege: " << szamjegyekOsszege(szam) << endl;
    cout << "legkisebb szamjegy: " << legkisebbSzamjegy(szam) << endl;
    cout << "legnagyobb szamjegy: " << legnagyobbSzamjegy(szam) << endl;
    cout << "elso szamjegy: " << elsoSzamjegy(szam) << endl;
    cout << "utolso szamjegy: " << utolsoSzamjegy(szam) << endl;
    cout << "forditott: " << megfordit(szam) << endl;
    return 0;
}

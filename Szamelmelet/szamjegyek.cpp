#include <iostream>

using namespace std;

//visszateriti egy szam utolso szamjegyet
int utolsoSzamjegy(int szam)
{
    return szam % 10;
}

//levagja egy szam utolso szamjegyet es visszateriti
int levagUtolsoSzamjegy(int szam)
{
    return szam / 10;
}

//visszateriti a szam szamjegyeinek darabszamat
int szamjegySzam(int szam)
{
    if(szam == 0) return 1;
    int db = 0;
    while(szam != 0)
    {
        db++;
        szam = levagUtolsoSzamjegy(szam);
    }
    return db;
}

//visszateriti a szam szamjegyeinek osszeget
int szamjegyOssz(int szam)
{
    int ossz = 0;
    while(szam != 0)
    {
        ossz += utolsoSzamjegy(szam);
        szam = levagUtolsoSzamjegy(szam);
    }
    return ossz;
}

//visszateriti a legkisebb szamjegyet
int legkisebbSzamjegy(int szam)
{
    int minszj = 9;
    while(szam != 0)
    {
        int uszj = utolsoSzamjegy(szam);
        if(uszj < minszj)
        {
            minszj = uszj;
        }
        szam = levagUtolsoSzamjegy(szam);
    }
    return minszj;
}

//visszateriti a legnagyobb szamjegyet
int legnagyobbSzamjegy(int szam)
{
    int maxszj = 0;
    while(szam != 0)
    {
        int uszj = utolsoSzamjegy(szam);
        if(uszj > maxszj)
        {
            maxszj = uszj;
        }
        szam = levagUtolsoSzamjegy(szam);
    }
    return maxszj;
}

//visszateriti az elso szamjegyet
int elsoSzamjegy(int szam)
{
    while(szam > 9)
    {
        szam = levagUtolsoSzamjegy(szam);
    }
    return szam;
}

//visszateriti a szam fordittottjat (pl.: 123 -> 321)
int megfordit(int szam)
{
    int forditott = 0;
    while(szam != 0)
    {
        forditott = forditott * 10 + utolsoSzamjegy(szam);
        szam = levagUtolsoSzamjegy(szam);
    }
    return forditott;
}

int main()
{
    int szam;
    szam = 321654;
    cout << szam << endl;
    cout << "utolso szamjegy: " << utolsoSzamjegy(szam) << endl;
    cout << "utolso szamjegy levagva: " << levagUtolsoSzamjegy(szam) << endl;
    cout << "szamjegyeinek darabszama: " << szamjegySzam(szam) << endl;
    cout << "szamjegyeinek osszege: " << szamjegyOssz(szam) << endl;
    cout << "legkisebb szamjegye: " << legkisebbSzamjegy(szam) << endl;
    cout << "legnagyobb szamjegye: " << legnagyobbSzamjegy(szam) << endl;
    cout << "elso szamjegye: " << elsoSzamjegy(szam) << endl;
    cout << "forditottja: " << megfordit(szam) << endl;
    return 0;
}

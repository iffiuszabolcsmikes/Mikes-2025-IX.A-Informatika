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

int szamjegyOssz(int szam)
{
    int ossz = 0;
    while(szam != 0)
    {
        ossz = ossz + utolsoSzamjegy(szam);
        szam = levagUtolsoSzamjegy(szam);
    }
    return ossz;
}

bool harshad(int szam)
{
    return szam % szamjegyOssz(szam) == 0;
}


int main()
{
    for(int i = 1; i < 1000; i++)
    {
        if(harshad(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}

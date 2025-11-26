#include <iostream>

using namespace std;

int szamjegyOssz(int szam)
{
    int ossz = 0;
    while(szam != 0)
    {
        ossz = ossz + szam % 10;
        szam = szam / 10;
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

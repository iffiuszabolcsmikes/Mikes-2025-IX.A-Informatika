#include <iostream>

using namespace std;

int osztokOsszege(int szam)
{
    int ossz = 0;
    for(int i = 1; i < szam; i++)
    {
        if(szam % i == 0)
        {
            ossz = ossz + i;
        }
    }
    return ossz;
}

bool tokeletes(int szam)
{
    return szam == osztokOsszege(szam);
}

int main()
{
    for(int i = 0; i < 100000000; i++)
    {
        if(tokeletes(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}

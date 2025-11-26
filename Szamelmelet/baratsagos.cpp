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

int main()
{
    for(int i = 0; i < 10000; i++)
    {
        int ossz = osztokOsszege(i);
        if(osztokOsszege(ossz) == i && i != ossz)
            cout << i << " " << ossz << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int szamjegyekNegyzetOsszege(int szam)
{
    int ossz = 0;
    while(szam > 0)
    {
        ossz = ossz + (szam % 10) * (szam % 10);
        szam = szam / 10;
    }
    return ossz;
}

bool boldog(int szam) {
    while(szam != 1 && szam != 4)
    {
        szam = szamjegyekNegyzetOsszege(szam);
    }
    return szam == 1;
}

int main() {
    for(int i = 1; i < 100; i++)
    {
        if(boldog(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}

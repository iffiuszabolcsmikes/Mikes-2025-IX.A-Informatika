#include <iostream>

using namespace std;

bool primSzam(int szam)
{
    if(szam < 2)
        return false;

    for(int i = 2; i * i <= szam; i++)
    {
        if(szam % i == 0)
            return false;
    }
    return true;
}

int main()
{
    for(int i = 0; i < 10000; i++)
    {
        if(primSzam(i) && primSzam(i + 6))
            cout << i << " " << i + 6 << endl;
    }
    return 0;
}

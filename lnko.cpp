#include <iostream>

using namespace std;

int lnko(int a, int b)
{
    int maradek;
    while(b > 0)
    {
        maradek = a % b;
        a = b;
        b = maradek;
    }
    return a;
}

int main()
{
    int a = 98, b = 56;
    cout << "lnko(" << a << ", " << b << ") = " << lnko(a, b) << endl;
    return 0;
}

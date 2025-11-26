#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c, delta;
    cout << "ax^2+bx+c=0" << endl;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;

    if(a == 0)
    {
        //elsofoku egyenlet
        if(b == 0)
        {
            cout << "Az egyenletnek nincs megoldasa" << endl;
        }
        else
        {
            cout << "x=" << -c / b;
        }
    }
    else
    {
        //masodfoku egyenlet
        delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "Az egyenletnek nincs valos megoldasa" << endl;
        }
        else if(delta > 0)
        {
            cout << "Az egyenletnek ket valos megoldasa van:" << endl;
            cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
        }
        else
        {
            cout << "Az egyenletnek egy valos megoldasa van:" << endl;
            cout << "x=" << -b / (2 * a) << endl;
        }

    }
    return 0;
}

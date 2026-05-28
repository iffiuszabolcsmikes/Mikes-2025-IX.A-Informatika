#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream beAllmony("be.txt");
    ofstream kiAllmony("ki.txt");
    if(!beAllmony)
    {
        cout << "Hiba! Nem sikerult megnyitni a be.txt allomanyt!" << endl;
        return 1;
    }
    if(!kiAllmony)
    {
        cout << "Hiba! Nem sikerult megnyitni a ki.txt allomanyt!" << endl;
        return 1;
    }

    int x;
    while(beAllmony >> x)
    {
        kiAllmony << x*x << endl;
    }

    return 0;
}

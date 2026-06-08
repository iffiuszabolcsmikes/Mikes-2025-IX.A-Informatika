#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void feltolt(int tomb[], int n)
{
    srand(time(0));

    for(int i = 0; i < n; i++)
    {
        tomb[i] = rand()%100;
    }
}

void kiir(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << setw(3) << i <<".";

    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << setw(3) << tomb[i] << " ";

    }
    cout << endl;
}

void kivalaszt(int tomb[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int maxind = i;
        for(int j = i + 1; j < n; j++)
        {
            if(tomb[j] < tomb[maxind])
            {
                maxind = j;
            }
        }
        //csere
        int tmp = tomb[i];
        tomb[i] = tomb[maxind];
        tomb[maxind] = tmp;
    }
}

int main()
{
    int tomb[100];
    int n = 20;
    feltolt(tomb, n);
    kiir(tomb, n);
    kivalaszt(tomb, n);
    kiir(tomb, n);

    return 0;
}

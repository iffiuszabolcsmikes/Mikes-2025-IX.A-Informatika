#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void feltolt(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
    {
        tomb[i] = rand() % 100;
    }
}

void kiir(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
        cout << setw(2) << i <<".|";
    cout << endl;

    for(int i = 0; i < n; i++)
        cout << setw(2) << tomb[i] << " |";
    cout << endl;
}

void csere(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void buborekRendezes(int tomb[], int n)
{
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = 0; i < n - j - 1; i++)
        {
            if(tomb[i] > tomb[i + 1])
            {
                csere(tomb[i], tomb[i+1]);
            }
        }
    }
}

void kivalasztRendezes(int tomb[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minind  = i;
        for(int j = i + 1; j < n; j++)
        {
            if(tomb[j] < tomb[minind])
            {
                minind  = j;
            }
        }
        if(i != minind)
        {
            csere(tomb[i], tomb[minind]);
        }
    }
}

void beszurRendezes(int tomb[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int tmp = tomb[i];
        int j = i - 1;
        while(j >= 0 && tomb[j] > tmp)
        {
            tomb[j + 1] = tomb[j];
            j--;
        }
        tomb[j + 1] = tmp;
    }
}

int main()
{
    srand(time(0));

    int tomb[100];
    int n = 20;

    cout << endl << "kivalasztasos rendezes:" << endl;
    feltolt(tomb, n);
    kiir(tomb, n);
    cout << endl;
    kivalasztRendezes(tomb, n);
    kiir(tomb, n);

    cout << endl << "buborekos rendezes:" << endl;
    feltolt(tomb, n);
    kiir(tomb, n);
    cout << endl;
    buborekRendezes(tomb, n);
    kiir(tomb, n);

    cout << endl << "beszurasos rendezes:" << endl;
    feltolt(tomb, n);
    kiir(tomb, n);
    cout << endl;
    beszurRendezes(tomb, n);
    kiir(tomb, n);

    return 0;
}

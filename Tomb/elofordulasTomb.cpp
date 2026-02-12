#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void feltolt( int tomb[], int n)
{
    srand(time(0));

    for(int i = 0 ; i < n ; i++)
    {
        tomb[i] = rand() % 10;
    }
}

void kiir( int tomb[], int n)
{
    for(int i = 0 ; i < n ; i++ )
    {
        cout << tomb[i] << ", ";
    }
    cout << endl;
}

void elofordulas(int tomb[], int n, int darab[])
{
    for(int i = 0 ; i < n ; i++)
    {
        darab[tomb[i]]++;
    }
}

void kiirElofordulas(int tomb[], int n)
{
    int darab[10] = {0};  //0-9 szamjegyek
    //eleinte minden lehetseges ertekbol 0 darab van
    elofordulas(tomb, n, darab);

    cout << "Elofordulasok szama:"<< endl;
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << i << " ertekbol " << darab[i] << " van" << endl;;
    }
}


//kiirja egy tomb azon elemeit melyek tobbszor foirdulnak elo, de minden elemet csak egyszer
void kiirTobbszorElofordulok(int tomb[], int n)
{
    int darab[10] = {0};  //0-9 szamjegyek
    //eleinte minden lehetseges ertekbol 0 darab van
    elofordulas(tomb, n, darab);

    cout << "Tobbszor elofordulo ertekek:";
    for(int i = 0 ; i < 10 ; i++)
    {
        if(darab[i] > 1)
            cout << i << " ";
    }
    cout << endl;
}
//!vigyazat csak az elso legnagyobbat teriti vissza, lehet tobb legnagyobb
int legtobszorEloforduloElem(int tomb[], int n)
{
    int darab[10] = {0};  //0-9 szamjegyek
    //eleinte minden lehetseges ertekbol 0 darab van
    elofordulas(tomb, n, darab);
    int maxi = 0;
    for(int i = 1 ; i < 10 ; i++)
    {
        if (darab[i] > darab[maxi])
        {
            maxi = i;
        }
    }
    return maxi;
}
int legelsoLegkissebb(int tomb[], int n)
{
    feltolt(tomb, n);
    int miniElso = 0;
    for (int i = 0; i < 9; i++)
    {
        if (tomb[i] < tomb[miniElso])
        {
            miniElso = i;
        }
    }
    return miniElso;
}
int legutolsoLegnagyobb(int tomb[], int n)
{
    feltolt(tomb, n);
    int maxUtolso = 0;
    for (int i = 0; i < 9 ; i++)
    {
        if (tomb[i] > tomb[maxUtolso])
        {
            maxUtolso = i;
        }
    }
    return maxUtolso;
}

int minElso(int tomb[], int n)
{
    //keressuk meg az elso minimumot
    int minIndex = 0;
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] < tomb[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

int maxUtolso(int tomb[], int n)
{
    //keressuk meg az utolso maximumot
    int maxIndex = 0;
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] >= tomb[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void csere(int &a, int &b)
{
    //csereljuk meg oket
    int tmp = a;
    a = b;
    b = tmp;
}

void csereMinElsoMaxUtolso(int tomb[], int n)
{
    int minIndex = minElso(tomb, n);
    int maxIndex = maxUtolso(tomb, n);
    csere(tomb[minIndex], tomb[maxIndex]);
}

int main()
{
    int tomb[10];
    int n = 9;
    feltolt(tomb, n);
    kiir(tomb, n);
    kiirTobbszorElofordulok(tomb, n);
    kiirElofordulas(tomb, n);
    cout<< "Legtobbszor elofordulo elem " << legtobszorEloforduloElem(tomb, n) << endl;
    cout<< "Legkissebb legelso elem " << legelsoLegkissebb(tomb, n) << endl;
    cout<< "Legnagyobb legutolso elem " << legtobszorEloforduloElem(tomb, n) << endl;
    return 0;
}

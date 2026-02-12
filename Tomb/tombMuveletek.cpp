#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void feltolt(int tomb[], int n)
{
    srand(time(0));

    for(int i = 0; i < n; i++)
    {
        tomb[i] = rand()%10;
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

int legnagyobbElem(int tomb[], int n)
{
    int max = tomb[0];
    for(int i = 0; i < n; i++)
    {
        if(max < tomb[i])
        {
            max = tomb[i];
        }
    }
    return max;
}

int legkisebbElem(int tomb[], int n)
{
    int min = tomb[0];
    for(int i = 0; i < n; i++)
    {
        if(min > tomb[i])
        {
            min = tomb[i];
        }
    }
    return min;
}

int osszeg(int tomb[], int b)
{
    int osszeg = 0;
    for(int i = 0; i < b; i++)
    {
        osszeg = osszeg + tomb[i];
    }
    return osszeg;
}

int szorzat(int tomb[], int b)
{
    int szorzat = 1;
    for(int i = 0; i < b; i++)
    {
        szorzat = szorzat * tomb[i];
    }
    return szorzat;
}

bool eleme(int tomb[], int n, int keresettElem)
{
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] == keresettElem)
        {
            return true;
        }
    }
    return false;
}

int elemIndexe(int tomb[], int n, int keresettElem)
{
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] == keresettElem)
        {
            return i;
        }
    }
    return -1;
}
void kiirVissza(int tomb[], int n)
{
    for(int i = n - 1 ; i >= 0; i--)
    {
        cout << tomb[i] << " ";
    }
    cout << endl;
}

int elofordulas(int tomb[], int n, int keresettElem)
{
    int db = 0;
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] == keresettElem)
        {
            db = db + 1;
        }
    }
    return db;
}

int atlag(int tomb[], int n)
{
    return osszeg(tomb, n) / n;
}

int parosokSzama(int tomb[], int n)
{
    int db = 0;
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] % 2 == 0)
        {
            db = db + 1;
        }
    }
    return db;
}

void torolElem(int tomb[],int &n, int index)
{
    for(int i = index; i + 1 < n; i++)
    {
        tomb[i] = tomb[i + 1];
    }
    n--;
}

void beszur(int tomb[], int &n, int index, int ujErtek)
{
    for(int i = n; i > index; i--)
    {
        tomb[i] = tomb[i - 1];
    }
    tomb[index] = ujErtek;
    n++;
}

void csere(int &a,int &b)
{
    int temp;   //temporary
    temp = a;
    a = b;
    b = temp;
}

bool csokeno(int tomb[], int n)
{
    for(int i = 0 ; i + 1 < n; i++)
    {
        if(tomb[i] < tomb[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool novekvo(int tomb[], int n)
{
    for(int i = 0 ;  i + 1 < n ; i++)
    {
        if(tomb[i] > tomb[i+1])
        {
            return false;
        }
    }
    return true;
}

void feltoltNovekvo(int tomb[], int n)
{
    int ertek = 0;
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        tomb[i] = ertek;
        ertek = ertek + rand() % 10;
    }
}

void feltoltCsokkeno(int tomb[], int n)
{
    int ertek = rand() % 10;
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        tomb[i] = ertek;
        ertek = ertek - rand() % 10;
    }
}

int main()
{
    int tomb[100];
    int n = 20, keresettElem = 5, index = 3,besz = 67;
    feltolt(tomb, n);
    kiir(tomb, n);
    kiirVissza(tomb, n);
    kiir(tomb, n);
    cout <<"legnagyobb elem: " << legnagyobbElem(tomb, n) << endl;
    cout <<"legkissebb elem: " << legkisebbElem(tomb, n) << endl;
    cout <<"osszeguk: " << osszeg(tomb, n) << endl;
    cout <<"atlaguk: " << atlag(tomb, n) << endl;
    cout <<"szorzatuk: " << szorzat(tomb, n) << endl;
    cout <<"a keresett elem " << keresettElem << " benne van vagy nem: " << eleme(tomb, n, keresettElem) << endl;
    cout <<"a keresett elem " << keresettElem << " indexe: " << elemIndexe(tomb, n, keresettElem) << endl;
    cout <<"a keresett elem elofordul: " << elofordulas(tomb, n, keresettElem) << endl;
    cout <<"parosok szama: " << parosokSzama(tomb, n) << endl;
    torolElem(tomb, n, index);
    n--;
    beszur(tomb, n, index, besz);
    kiir(tomb, n);
    cout << "csere" << endl;
    csere(tomb[0], tomb[n - 1]);
    kiir(tomb, n);
    cout<<"csokkeno: " << csokeno(tomb, n) << endl;
    cout<<"novekvo: " << novekvo(tomb, n) << endl;
    feltoltCsokkeno(tomb, n);
    kiir(tomb, n);
    cout << "csokkeno sorrend" << endl;
    csokeno(tomb, n);
    kiir(tomb, n);
    return 0;
}

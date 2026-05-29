#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

const int N=5;
const int M=10;

void feltolt (int matrix[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matrix[i][j]=rand()%100;
        }
    }
}

void kiir (int matrix[][M], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<< setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int sormax(int matrix[][M], int i, int m)
{
    int maxj=0;
    for(int j = 1; j < m; j++)
    {
        if( matrix[i][j] > matrix[i][maxj])
        {
            maxj=j;
        }
    }
    return maxj;
}

int oszlopmin(int matrix[][M], int n, int j)
{
    int mini=0;
    for(int i = 1; i < n; i++)
    {
        if( matrix[i][j] < matrix[mini][j])
        {
            mini=i;
        }
    }
    return mini;
}

 void dominansElem(int matrix[][M], int n, int m)
 {
     for(int i = 1; i < n; i++)
     {
         int j = sormax(matrix,i,m);
         if(i == oszlopmin(matrix,n,j))
            cout << i << ", " << j << " " << matrix[i][j] << " ";
     }
 }

int main()
{
    int matrix[N][M];
    srand(time(0));
    int n= 5;
    int m= 10;
    feltolt(matrix, n, m);
    kiir( matrix, n, m);
    dominansElem(matrix, n, m);
    return 0;
}

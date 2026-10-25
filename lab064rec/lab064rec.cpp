#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int n, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < n - 1)
        Create(a, n, Low, High, i + 1);
}

void Print(int* a, const int n, int i)
{
    cout << setw(4) << a[i];
    if (i < n - 1)
        Print(a, n, i + 1);
    else
        cout << endl;
}

int MaxIndex(int* a, const int n, int i, int imax)
{
    if (i < n)
    {
        if (a[i] > a[imax])
            imax = i;
        return MaxIndex(a, n, i + 1, imax);
    }
    else
        return imax;
}

int FindZero(int* a, const int n, int i)
{
    if (i < n)
    {
        if (a[i] == 0)
            return i;
        else
            return FindZero(a, n, i + 1);
    }
    else
        return -1;
}

int Product(int* a, const int right, int i)
{
    if (i < right)
        return a[i] * Product(a, right, i + 1);
    else
        return 1;
}

int Gather(int* a, int* t, const int n, int i, int k)
{
    if (i < n)
    {
        t[k] = a[i];
        return Gather(a, t, n, i + 2, k + 1);
    }
    else
        return k;
}

void CopyArray(int* from, int* to, const int n, int i)
{
    to[i] = from[i];
    if (i < n - 1)
        CopyArray(from, to, n, i + 1);
}

void Rearrange(int* a, const int n)
{
    int* t = new int[n];
    int k = Gather(a, t, n, 0, 0);
    Gather(a, t, n, 1, k);
    CopyArray(t, a, n, 0);
    delete[] t;
}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = ";
    cin >> n;
    if (n <= 0)
    {
        cout << "n must be positive" << endl;
        return 1;
    }

    int* a = new int[n];
    Create(a, n, -5, 5, 0);
    Print(a, n, 0);

    int imax = MaxIndex(a, n, 0, 0);
    cout << "max = " << a[imax] << ", index = " << imax << endl;

    int z1 = FindZero(a, n, 0);
    int z2 = -1;
    if (z1 != -1)
        z2 = FindZero(a, n, z1 + 1);

    if (z2 == -1)
        cout << "fewer than two zeros" << endl;
    else if (z2 == z1 + 1)
        cout << "no elements between zeros" << endl;
    else
        cout << "product = " << Product(a, z2, z1 + 1) << endl;

    Rearrange(a, n);
    Print(a, n, 0);

    delete[] a;
    return 0;
}
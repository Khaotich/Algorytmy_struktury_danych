#include <iostream>
#include <algorithm>

using namespace std;

inline int partition(int n, int t[])
{
    int k = -1;
    int pivot = t[n / 2];
    for (;;)
    {
        do --n; while (t[n] > pivot);
        do ++k; while (t[k] < pivot);
        if (k < n) swap(t[k], t[n]);
        else return k;
    }
}

int kty(int n, int t[], int k)
{
    // zwraca k-ty w kolejości rosnącej element tablicy t[0..k]
    // tablica t początkowo jest nieposortowana
    if (n > 1)
    {
        int n1 = partition(n, t);
        if (k < n1)
            return kty(n1, t, k);
        else
            return kty(n - n1, t + n1, k - n1);
    }
    else
        return t[0];
}

void wypisz(int t[], int n)
{
    for (int i = 0; i < n; i++)
        cout << t[i] << ' ';
    cout << endl;
}

int main()
{
    int t[] = { 10, 20, 13, 21, 23, 24, 22, 11, 12, 10, 423, 41, 214, 34, 14, 123, 1, 2, 13, 131, 23, 1, 3113, 1313, 113, 1313 };
    int t1[] = { 10, 20, 13, 21, 23, 24, 22, 11, 12, 10, 423, 41, 214, 34, 14, 123, 1, 2, 13, 131, 23, 1, 3113, 1313, 113, 1313 };
    int n = sizeof(t) / sizeof(int);
    int k = 17;

    sort(t, t + n);
    double x1 = t[k];
    double x2 = kty(n, t1, k);
    
    wypisz(t, n);
    cout << k << "-ty element posortowanej tablicy = " << x1 << endl;
    cout << "rezultat wywołania kty(t," << k << ") = " << x2 << endl;
}
#include <iostream>

using namespace std;

// zadanie 3.a
double pow_recursion(double x, int n)
{
    if (n == 0) // jeśli wykładnik jest równy zero, to zwracamy 1
    {
        return 1;
    }
    else if (n % 2 == 0) // jeśli wykładnik jest parzysty, to redukujemy problem do połowy
    {
        double tmp = pow_recursion(x, n / 2);
        return tmp * tmp;
    }
    else // jeśli wykładnik jest nieparzysty, to redukujemy problem do potęgi parzystej
    {
        double tmp = pow_recursion(x, (n - 1) / 2);
        return x * tmp * tmp;
    }
}

// zadanie 3.b
double pow_normal(double x, int n)
{
    double result = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }

    return result;
}

int main()
{
    cout << pow_recursion(12, 5) << "\n";
    cout << pow_normal(12, 5);
}
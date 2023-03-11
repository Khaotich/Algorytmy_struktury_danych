#include <iostream>

using namespace std;

double f(double x)
{
    return 5 * x * x + 3 * x - 5;
}

double bisection(double a, double b)
{
    if (f(a) * f(b) < 0)
    {
        const double eps = 0.001;
        double c = 0;
        while (abs(a - b) > eps)
        {
            c = (a + b) / 2;     // środek przedziału
            if (f(a) * f(c) < 0) // miejsce zerowe jest w lewej połowie przedziału
            {
                b = c;
            }
            else // miejsce zerowe jest w prawej połowie przedziału
            {
                a = c;
            }
        }

        return c;
    }
    else
    {
        cout << "Nie ma miejsca zerowego między a i b!" << endl;
        return NULL;
    }
}

int main()
{
    cout << bisection(0, 1) << endl;
}
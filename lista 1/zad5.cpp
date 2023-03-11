#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double oblicz(vector<double> a, double x)
{
	double result = 0;
	int counter = 0;
	for (int i = a.size() - 1; i > 0; --i)
	{
		result += a[i];
		result *= x;
		counter++;
	}

	result += a[0];
	cout << "Liczba mnożeń " << counter << endl;
	return result;
}

int main()
{
	cout << fixed << setprecision(2) << oblicz({4, 5, 3, 0, 0, 18}, 10) << endl;
}
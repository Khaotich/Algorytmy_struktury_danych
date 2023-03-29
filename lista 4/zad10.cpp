#include <iostream>
#include <fstream>

using namespace std;

int find_missing_number(fstream& file)
{
	int result = 0;
	int line = 0;
	int i = 1;

	while (file >> line)
	{
		result += i - line;
		++i;
	}

	result += line;
	return result;
}

int main()
{
	fstream file("spis.txt");
	cout << find_missing_number(file);
}
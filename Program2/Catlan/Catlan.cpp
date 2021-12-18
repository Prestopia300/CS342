// Project2_CS342.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Catlan computes a recursive function of the mathmatical Catlan formulia

#include <iostream>
using namespace std;
#include <cstdlib>

long int Catlan(int num);

int main(int argc, char* argv[])
{

	if (argc > 1)
	{
		long int num = atoi(argv[1]);

		cout << "Catlan(" << num << "): " << Catlan(num) << endl;
	}
	else
		cout << "Pass the value of n from command line argument" << endl;

	return 0;
}

long int Catlan(int n) {
	if (n < 0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 1;
	}
	else
	{
		long int res = 0;
		for (int i = 0; i < n; i++)
		{
			res += Catlan(i) * Catlan(n - 1 - i);
		}
		return res;
	}
}
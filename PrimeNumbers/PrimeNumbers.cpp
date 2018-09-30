#include "pch.h"
#include <iostream>

using namespace std;

int convertToBinary(unsigned long int RamNumber)
{
	unsigned long int binNumber = 0;
	int j = 1;
	while (RamNumber != 0)
	{
		binNumber = binNumber + (RamNumber % 2) * j;
		RamNumber /= 2;
		j *= 10;
	}
	return binNumber;
}

bool isPrime(unsigned long int primeNumber)
{
	bool primality = true;
	for (int j = 2; j <= sqrt(primeNumber); j++)
	{
		if (!(primeNumber % j))
			primality = false;
	}
	return primality;
}

bool isSuperPrime(unsigned long int number)
{
	bool superPrimality = true;
	while (number != 0)
	{
		if (!isPrime(number))
			superPrimality = false;
		number /= 10;
	}
	return superPrimality;
}

int main()
{
	unsigned long int number = 0, maxNumber = 0;
	//maxNumber--;
	maxNumber = 100000;

	for (int i = 1; i <= maxNumber; i+=2)
	{
		if (isSuperPrime(i))
			cout << i << '\t' << convertToBinary(i) << endl;
	}

	system("pause");
	return 0;
}

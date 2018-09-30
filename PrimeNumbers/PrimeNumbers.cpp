#include "pch.h"
#include <iostream>
//#include <ctime>

using namespace std;

void convertToBinary(unsigned long int decNumber)
{
	short int binNumber[32] = {0};
	short int j = 31;
	while (decNumber != 0)
	{
		binNumber[j] = decNumber % 2;
		decNumber /= 2;
		j--;
	}

	for (int i = ++j; i <= 31; i++)
		cout << binNumber[i];
}

/*bool isPrime(unsigned long int primeNumber)
{
	bool primality = true;
	for (int j = 2; j <= sqrt(primeNumber); j++)
	{
		if (!(primeNumber % j))
			primality = false;
	}
	return primality;
}*/

/*long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

long long mul(long long a, long long b, long long m) {
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long long t = mul(a, b / 2, m);
		return (2 * t) % m;
	}
	return (mul(a, b - 1, m) + a) % m;
}

long long pows(long long a, long long b, long long m) {
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		long long t = pows(a, b / 2, m);
		return mul(t, t, m) % m;
	}
	return (mul(pows(a, b - 1, m), a, m)) % m;
}

bool isPrime(long long x) {
	if (x == 2)
		return true;
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		long long a = (rand() % (x - 2)) + 2;
		if (gcd(a, x) != 1)
			return false;
		if (pows(a, x - 1, x) != 1)
			return false;
	}
	return true;
}*/

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
	unsigned long int i = 0, maxNumber = 0;
	int counter = 0;
	maxNumber--;

	for (i = 1; i <= maxNumber; i++)
	{
		if (isSuperPrime(i))
		{
			counter++;
			cout << counter << '\t' << i << '\t';
			convertToBinary(i);
			cout << endl;
		}
	}

	system("pause");
	return 0;
}

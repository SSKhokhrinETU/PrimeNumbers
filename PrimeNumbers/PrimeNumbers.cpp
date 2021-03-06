#include "pch.h"
#include <iostream>

using namespace std;

const unsigned long long int MAX_NUMBER = 4294967295; //2^32-1

int n = 0;
unsigned long long int numbers[150] = {0};

void convertToBinary(unsigned long long decNumber)
{
	short int binNumber[32] = {0};
	short int j = 31;
	while (decNumber != 0)
	{
		binNumber[j] = decNumber % 2;
		decNumber /= 2;
		j--;
	}

	for (int i = 0; i <= 31; i++)
		cout << binNumber[i];
}

bool isPrime(unsigned long long int number)
{
	bool primality = true;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (!(number % i))
			primality = false;
	}
	return primality;
}

int recursiveSearcher(unsigned long long int number)
{
	int counter = 0;
	unsigned long long int i = 0, temp = 0;
	for (i = 0; i < 10; i++)
	{
		temp = number * 10 + i;
		if (isPrime(temp))
		{
			if (temp != 0) {
				counter++;
				numbers[n++] = temp;
				counter += recursiveSearcher(temp);
			}
		}
	}
	return counter;
}

int main()
{
	int counter = 0;
	counter = recursiveSearcher(0);

	for (int i = 0; i < counter - 1; i++) 
	{
		for (int j = 0; j < counter - i - 1; j++) 
		{
			if (numbers[j] > numbers[j + 1]) 
			{
				numbers[j] += numbers[j + 1];
				numbers[j + 1] = numbers[j] - numbers[j + 1];
				numbers[j] -= numbers[j + 1];
			}
		}
	}
	for (int i = 0; i < counter; i++)
	{
		printf("%3d", i + 1);
		printf("%12d", numbers[i]);
		cout << '\t' << '\t';
		convertToBinary(numbers[i]);
		cout << endl;
	}

	return 0;
}

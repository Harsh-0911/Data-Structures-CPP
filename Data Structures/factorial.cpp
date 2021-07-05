#include<iostream>
using namespace std;

// recursive approach
int factorial(int number) 
{
	if (number == 1)
	{
		return 1;
	}
	else 
	{
		return (number * factorial(number-1));
	}
}

int main() 
{
	int number, fact, i, fact_r;
	fact = 1;
	cout << "Enter number : ";
	cin >> number;
	
	// itertive approach
	for (i=1; i<=number; i++)
	{
		fact = fact * i;
	}
	cout << "Factorial Using Iterative Approach : " << fact << endl;
	
	// recursive approach
	fact_r = factorial(number);
	cout << "Factorial Using Recursive Approach : " << fact_r << endl;
		
	return 0;
}

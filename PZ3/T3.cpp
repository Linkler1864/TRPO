#include <iostream>
using namespace std;
int main()
{
	int first_number, second_number, am_dev1 = 0, am_dev2 = 0, i;
	cout << "Enter 2 numbers" << endl;
	cin >> first_number >> second_number;
	for (i = 1;i <= sqrt(first_number);i++)
	{
		if (first_number % i == 0)
		{
			if (i != sqrt(first_number))
				am_dev1 = am_dev1 + 2;
			else am_dev1++;
		}
	}
	for (i = 1;i <= sqrt(second_number);i++)
	{
		if (second_number % i == 0)
		{
			if (i != sqrt(second_number))
				am_dev2 = am_dev2 + 2;
			else am_dev2++;
		}
	}
	if (am_dev1 == 2)
		cout << "The first number is prime" << endl;
	else
		cout << "The first number is composable" << endl;
	if (am_dev2 == 2)
		cout << "The second number is prime" << endl;
	else
		cout << "The second number is composable" << endl;
	while (first_number != second_number)
	{
		if (first_number > second_number)
			first_number -= second_number;
		else second_number -= first_number;
	}
	cout << "Greatest common devisor of numbers is " << first_number
}

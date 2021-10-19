#include <iostream>
using namespace std;
int main()
{
	int first_number = 0, second_number = 1, copy, n, i;
	double fact = 1;
	cout << "Enter number" << endl;
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cout << first_number << ' ';
		copy = first_number + second_number;
		first_number = second_number;
		second_number = copy;
		fact = fact / (i + 1);
	}
	cout << endl << "n!= " << 1 / fact;
}


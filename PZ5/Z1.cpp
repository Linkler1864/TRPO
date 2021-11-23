#include <iostream>
using namespace std;

string intToString(int integer)
{
	string string;
	int numberOfDigits=0, copy, digits=1;
	copy = integer;
	while (copy > 0) {
		numberOfDigits++;
		copy /= 10;
	}
	while (numberOfDigits>0)
	{
		digits = pow(10, numberOfDigits-1);
		string+= (char) (integer/digits  + 48);
		integer = integer % digits;
		numberOfDigits--;
	}
	return(string);
}

int main()
{
	int number;
	string str;
	cout << "Enter number" << endl;
	cin >> number;
	str = intToString(number);
	for (int i = 0;i < str.length();i++)
		cout << str[i];
}
#include <iostream>
using namespace std;

string ToString(int integer)
{
	string string;
	int numberOfDigits = 0, copy, digits = 1;
	if (integer < 0)
		string += '-';
	integer = fabs(integer);
	copy = integer;
	while (copy > 0) {
		numberOfDigits++;
		copy /= 10;
	}
	while (numberOfDigits > 0)
	{
		digits = pow(10, numberOfDigits - 1);
		string += (char)(integer / digits + 48);
		integer = integer % digits;
		numberOfDigits--;
	}
	return(string);
}

string ToString(float realnumber)
{
	string string;
	if (realnumber < 0)
		string += '-';
	realnumber = fabs(realnumber);
	int numberOfDigitsBeforeDot = 0, numberOfDigitsAfterDot = 0, copy, digits = 1;
	float copy2;
	copy = (int)realnumber;
	while (copy > 0) {
		numberOfDigitsBeforeDot++;
		copy /= 10;
	}
	if (numberOfDigitsBeforeDot == 0)
		string += '0';
	copy = (int)realnumber;
	while (numberOfDigitsBeforeDot > 0)
	{
		digits = pow(10, numberOfDigitsBeforeDot - 1);
		string += (char)(copy / digits + 48);
		copy = copy % digits;
		numberOfDigitsBeforeDot--;
	}
	copy2 = realnumber - (int)realnumber;
	while ((int)copy2 - copy2 < 0)
	{
		numberOfDigitsAfterDot++;
		copy2 *= 10;
	}
	copy = (int)copy2;
	if (numberOfDigitsAfterDot != 0)
	{
		string += '.';
		while (numberOfDigitsAfterDot > 0)
		{
			digits = pow(10, numberOfDigitsAfterDot - 1);
			string += (char)(copy / digits + 48);
			copy = copy % digits;
			numberOfDigitsAfterDot--;
		}
	}
	return(string);
}

string ToString(int integer, int numberOfElements)
{
	string string;
	int numberOfDigits = 0, copy, digits = 1;
	if (integer < 0)
		string += '-';
	integer = fabs(integer);
	copy = integer;
	while (copy > 0) {
		numberOfDigits++;
		copy /= 10;
	}
	if (numberOfDigits < numberOfElements)
		numberOfElements = numberOfDigits;
	while (numberOfElements>0)
	{
		digits = pow(10, numberOfDigits - 1);
		string += (char)(integer / digits + 48);
		integer = integer % digits;
		numberOfDigits--;
		numberOfElements--;
	}
	return(string);
}

int main()
{
	int intnumber, numberOfElements;
	float realnumber;
	string str;

	cout << "Enter integer number" << endl;
	cin >> intnumber;
	str = ToString(intnumber);
	for (int i = 0;i < str.length();i++)
		cout << str[i];
	cout << endl;
	cout << "Enter real number" << endl;
	cin >> realnumber;
	realnumber = abs(realnumber);
	str = ToString(realnumber);
	for (int i = 0;i < str.length();i++)
		cout << str[i];
	cout << endl;

	cout << "Enter integer number and number of elements" << endl;
	cin >> intnumber>> numberOfElements;
	str = ToString(intnumber, numberOfElements);
	for (int i = 0;i < str.length();i++)
		cout << str[i];
}
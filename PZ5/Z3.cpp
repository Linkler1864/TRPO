#include <iostream>
using namespace std;

int numberOfElementInArray(char* array, char element, int size)
{
	int k = 0;
	for (int i = 0;i < size;i++)
		if (array[i] == element)
			k++;
	return k;
}
int numberOfElementInArray(int* array, int element, int size)
{
	int k = 0;
	for (int i = 0;i < size;i++)
		if (array[i] == element)
			k++;
	return k;
}

int main()
{
	int size, element;
	char type, element2;
	cout << "Enter type of array (int - 1(default), char - 2)" << endl;
	cin >> type;
	if (type == '2')
	{
		cout << "Enter size of array" << endl;
		cin >> size;
		char* array2 = new char[size];
		for (int i = 0;i < size;i++)
			cin >> array2[i];
		cout << "Enter element" << endl;
		cin >> element2;
		cout << numberOfElementInArray(array2, element2, size) << endl;
		delete[] array2;
	}
	else
	{
		cout << "Enter size of array" << endl;
		cin >> size;
		int* array = new int[size];
		for (int i = 0;i < size;i++)
			cin >> array[i];
		cout << "Enter element" << endl;
		cin >> element;
		cout << numberOfElementInArray(array, element, size) << endl;
		delete[] array;
	}
}
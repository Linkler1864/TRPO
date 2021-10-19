#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cout << "Enter a, b" << endl;
	cin >> a >> b;
	cout << "S=" << a * b << " P=" << 2 * (a + b) << endl;
	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}
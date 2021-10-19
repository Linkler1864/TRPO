#include <iostream>
using namespace std;
int main()
{
	int n, i = 0, k = 0, a[100];
	cout << "Enter number n" << endl;
	cin >> n;
	if (n == 0) cout << 0;
	else
	{
		if (n < 0)
			cout << '-';
		n = abs(n);
		while (n != 1)
		{
			a[i] = n % 2;
			k++;
			n = n / 2;
			i++;
		}
		a[k] = 1;
		for (k;k >= 0;k--)
			cout << a[k];
	}
}
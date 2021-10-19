#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int x;
	cin >> x;
	if (((x % 10) == 1) || ((x % 10) == 0))
		cout << "Black ";
	else if (((x % 10) == 2) || ((x % 10) == 3))
		cout << "Blue ";
	else if (((x % 10) == 5) || ((x % 10) == 4))
		cout << "Green ";
	else if (((x % 10) == 6) || ((x % 10) == 7))
		cout << "Red ";
	else cout << "Yellow";
	switch (x % 12) {
	case 4: cout << "rat"; break;
	case 5: cout << "bull"; break;
	case 6: cout << "tiger"; break;
	case 7: cout << "cat"; break;
	case 8: cout << "dragon"; break;
	case 9: cout << "snake"; break;
	case 10: cout << "horse"; break;
	case 11: cout << "goat"; break;
	case 0: cout << "monkey"; break;
	case 1: cout << "rooster"; break;
	case 2: cout << "dog"; break;
	case 3: cout << "pig"; break;
	}
}
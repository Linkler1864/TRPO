#include <iostream>

using namespace std;

struct dateOfBirth
{
	int month;
	int day;
	int year;
};
struct student {
	string name;
	int group;
	dateOfBirth dob;
};

void studentsInput(student* students, int number)
{
	for (int i = 0;i < number;i++)
	{
		cout << "Student " << i + 1 << ':' << endl;
		cout << "Name: ";
		cin >> students[i].name;
		cout << "Date of birth:" << endl;
		cout << "Month: ";
		cin >> students[i].dob.month;
		cout << "Day: ";
		cin >> students[i].dob.day;
		cout << "Year: ";
		cin >> students[i].dob.year;
		cout << "Group: ";
		cin >> students[i].group;
	}
	cout << endl;
}

void studentsOutput(student* students, int number)
{
	for (int i = 0;i < number;i++)
	{
		cout << students[i].name <<endl;
	}
	cout << endl;
}

string commonName(student* students, int number)
{
	int* names = new int[number];
	for (int i = 0;i < number;i++)
		names[i] = 1;
	for (int i = 0;i < number;i++)
	{
		for (int j = 0;j < number;j++)
			if ((students[i].name == students[j].name) && (i != j))
				names[i]++;
	}
	int indexMax = 0;
	for (int i = 0;i < number;i++)
		if (names[i] > names[indexMax])
			indexMax = i;
	return (students[indexMax].name);
}
void sort(student* students, int number)
{
	for (int i=0;i<number-1;i++)
		for (int j = i;j < number;j++)
			if (students[i].group > students[j].group)
				swap(students[i], students[j]);
			
}

int* findAge(student* students, int number)
{
	int* age = new int[number];
	for (int i = 0;i < number;i++)
		age[i] = 2021 - students[i].dob.year;
	return age;
}

void studentsPrint(student* students, int number, int* age)
{
	for (int i=0;i<number;i++)
		cout<< students[i].name << ' ' <<age[i]<<" years old "<< students[i].dob.month << '.' << students[i].dob.day << '.' << students[i].dob.year << ' ' << students[i].group << endl;
	cout << endl;
}

double findMediumAge(int* age, int number)
{
	double mediumAge = 0;
	for (int i = 0;i < number; i++)
		mediumAge += age[i];
	mediumAge /= number;
	return mediumAge;
}

int main()
{
	int n;
	cout << "Enter number of students"<<endl;
	cin >> n;
	student* students = new student[n];
	studentsInput(students, n);
	studentsOutput(students, n);
	cout << "The most common name is " << commonName(students, n) << endl;
	sort(students, n);
	cout << "Sorted by group list:" << endl;
	studentsOutput(students, n);
	int* age = findAge(students, n);
	studentsPrint(students, n, age);
	double mediumAge=findMediumAge(age, n);
	cout << "Meduim age is " << mediumAge;
}


#include <iostream>
#include <iomanip>
using namespace std;

int** Matrix_create(int raw, int col)
{
	int i, j;
	int** a = new int* [raw];
	srand(time(0));
	for (i = 0;i < raw;i++)
		a[i] = new int[col];
	for (i = 0;i < raw;i++)
		for (j = 0;j < col;j++)
			a[i][j] = rand() % 201 - 100;
	return (a);
}

void Matrix_print(int raw, int col, int** arr)
{
	int i, j;
	for (i = 0;i < raw;i++)
	{
		for (j = 0;j < col;j++)
			cout <<setw(5)<< arr[i][j] << ' ';
		cout << endl;
	}
}

void Matrix_delete(int raw, int** arr)
{
	for (int i = 0;i < raw;i++)
		delete[]arr[i];
	delete[]arr;
}

int* Array_create (int _size)
{
	int* a = new int[_size];
	srand(time(0));
	for (int i = 0;i < _size;i++)
		a[i] = rand() % 201 - 100;
	return(a);
}

void Array_print(int* a, int _size)
{
	int i;
	for (i = 0;i < _size;i++)
		cout << a[i] << ' ';
}

int Array_summ(int* a, int _size)
{
	int summ=0;
	for (int i = 0;i < _size;i++)
		summ += a[i];
	return(summ);
}

int* Array_sort(int* arr, int arrsize)
{
	int r;
	for (int i = 0;i < arrsize - 1;i++)
		for (int j = i + 1;j < arrsize;j++)
			if (arr[i] > arr[j])
			{
				r = arr[i];
				arr[i] = arr[j];
				arr[j] = r;
			}
	return (arr);
}

int** Matrix_multiplicate(int raw, int col, int col2, int** a, int** b, int** c)
{
	for (int i = 0;i < raw;i++)
		for (int j = 0;j < col2;j++)
			c[i][j] = 0;
	for (int i = 0;i < raw;i++)
		for ( int j = 0;j < col2;j++)
			for (int k = 0;k < col;k++)
				c[i][j] += a[i][k] * b[k][j];
	return(c);
}

void Median_search(int* a, int _size)
{
	int r, i, j, k;
	for (i = 0;i < _size - 1;i++)
		for (j = i + 1;j < _size;j++)
			if (a[i] == a[j])
			{
				for (k = j;k < _size - 1;k++)
					a[k] = a[k + 1];
				_size--;
			}
	a = Array_sort(a, _size);
	cout << endl;
	cout << "Median = " << a[_size / 2];
}

int* Matrix_to_array(int raw, int col, int** mat)
{
	int i, j, *a;
	a = Array_create(col * raw);
	for (i = 0;i < raw;i++)
		for (j = 0;j < col;j++)
			a[i + j] = mat[i][j];
	return (a);
}

int main()
{
	int task_number,raw_count1,col_count1, **matrix1, **matrix2, **matrix3, *array, size, raw_count2, col_count2;
	cout << "Enter task number"<<endl;
	cin >> task_number;
	switch (task_number)
	{
	case 1:
		cout<<"Enter n,m"<<endl;
		cin >> raw_count1 >> col_count1;
		matrix1=Matrix_create(raw_count1, col_count1);
		Matrix_print(raw_count1, col_count1, matrix1);
		Matrix_delete(raw_count1, matrix1);
		break;
	case 2:
		cout << "Enter size of array" << endl;
		cin >> size;
		array = Array_create(size);
		Array_print(array, size);
		cout << "Summ = " << Array_summ(array, size) << endl;
		cout << "Mean value = " << Array_summ(array, size) / size << endl;
		delete[]array;
		break;
	case 3:
		cout << "Enter n,m of the first matrix" << endl;
		cin >> raw_count1 >> col_count1;
		matrix1 = Matrix_create(raw_count1, col_count1);
		Matrix_print(raw_count1,col_count1,matrix1);
		cout << "Enter n,m of the second matrix" << endl;
		cin >> raw_count2 >> col_count2;
		matrix2 = Matrix_create(raw_count2, col_count2);
		Matrix_print(raw_count2, col_count2, matrix2);
		matrix3 = Matrix_create(raw_count1, col_count2);
		if (col_count1 == raw_count2)
		{
			matrix3 = Matrix_multiplicate(raw_count1, col_count1, col_count2, matrix1, matrix2, matrix3);
			cout << "Result = " << endl;
			Matrix_print(raw_count1, col_count2, matrix3);
		}
		else cout << "Impossible";
		Matrix_delete(raw_count1, matrix1);
		Matrix_delete(raw_count2, matrix2);
		Matrix_delete(raw_count1, matrix3);
		break;
	case 4:
		cout << "Enter size of array" << endl;
		cin >> size;
		array = Array_create(size);
		Array_print(array, size);
		Median_search(array, size);
		delete[]array;
		break;
	case 5:
		cout << "Enter n,m of matrix" << endl;
		cin >> raw_count1 >> col_count1;
		matrix1 = Matrix_create(raw_count1, col_count1);
		Matrix_print(raw_count1, col_count1, matrix1);
		array = Matrix_to_array(raw_count1, col_count1, matrix1);
		array = Array_sort(array, raw_count1 * col_count1);
		cout << "Median = " << array[col_count1 * raw_count1 / 2] << endl;;
		delete[]array;
		Matrix_delete(raw_count1, matrix1);
		break;
	}
	
}
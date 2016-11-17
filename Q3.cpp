#include<iostream>

using namespace std;


void printTriple(int product, int arr[], int arrSize)
{
	int i, j, check = 0;
	for (i = 0; i < arrSize; i++)
	{
		for (j = 0; j < arrSize; j++)
		{
			if (arr[i] * arr[j] == product)
			{
				cout << "[ " << arr[i] << "," << arr[j] << "]" << endl;
				check = 1;
			}
		}
	}
	if (check == 0)
	{
		cout << "there is no number to make product" << endl;
	}
	else
	{
		check = 1;
	}
}


void main()
{
	int product;
	int arrSize = 0;
	int a[10] = { 5, 8, 9, 7, 1, 2, 4, 3, 6, 12};
	arrSize = sizeof(a)/sizeof(int);
	cout << "arr = ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (;;)
	{
		cout << "input number : ";
		cin >> product;
		printTriple(product, a, arrSize);
	}
	
}
#include<iostream>

using namespace std;

void main()
{
	int first = -1;
	int last = -1;
	int count = 0;
	int a[20] = { 1,2,3,4,5,6,7,8,12,10,11,12,13,14,15,16,17,12,19,20 };
	for (int i = 0; i < 20; i++)
	{
		if (*(a+i) == 12)
		{
			if (count == 0)
			{
				first = i;
				count++;
			}
			else
			{
				last = i;
			}
		}
	}
	cout << "First Occurrence : " << first << " Last Occurrence : " << last << endl;
}
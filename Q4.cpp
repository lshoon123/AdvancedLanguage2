#include<iostream>

using namespace std;

void main()
{
	char word[99];
	char new1[10] = "";
	char new2[10][10] = {};
	int i = 0, check = 0, count = 0, ischar=0, check2=0;
	int lenth = 0, trans, line=0, change =0;
	int k;
	cin.getline(word,99);
	while (word[i] != NULL)
	{
		if (word[i] == ' ' && new1[0] != NULL)
		{
			lenth = strlen(new1);
			for (int j = 0; j < lenth; j++)
			{
				trans = new1[j];
				if (trans < 65 || (trans>90 && 97>trans) || trans > 122)
				{
					ischar++;
				}
			}
			if (ischar == 0)
			{
				count++;
				if (line == 0)
				{
					for (int j = 0; j < lenth; j++)
					{
						new2[line][j] = new1[j];
					}
					line++;
				}
				else
				{
					for (int k = 0; k < line; k++)
					{
						for (int e = 0; e < lenth; e++)
						{
							if (new2[k][e] == new1[e])
							{
								check2++;
							}
						}
						if (check2 == lenth)
						{
							count -= 1;
							check2 = 0;
							break;
						}
						else
						{
							change++;
						}
						check2 = 0;
					}
					if (change == 1)
					{
						for (int e = 0; e < lenth; e++)
						{
							new2[line][e] = new1[e];
						}
						change = 0;
						line++;
					}
				}
			}
			else
			{
				ischar = 0;
			}
			check = 0;
			for (int j = 0; j < lenth; j++)
			{
				new1[j] = NULL;
			}
		}
		else if(word[i] != ' ')
		{
			new1[check] = word[i];
			check++;
		}
		i++;
	}
	cout << count << endl;
}
/*
k = word[i];
if ((k >= 65 && k <= 90) || (k >= 97 && k <= 122))
{
	new1[check] = word[i];
	check++;
}
else
{

}*/
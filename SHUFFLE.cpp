#include<iostream>

using namespace std;


void CheckStar(char *words, int length, int *star)
{
	int i,j = 0;
	for (i = 0; i < length; i++)
	{
		if (words[i] == '*')
		{
			star[j] = i;
			j++;
		}
	}
}

void suffle(char *words, int *star, int length, char *newWords, int length_star)
{
	int end_newWords=0, savepoint=0;
	int j;
	if (length_star == 0)
	{
		for (int i = 0; i < length; i++)
		{
			newWords[i] = words[i];
		}
	}
	for (int i = 0; i < length_star; i++)
	{
		if (star[i] == 0 && length_star == 1)// * exists in front of array
		{
			for (j = 0; j < length;j++)
			{
				newWords[j] = words[j+1];
			}
			newWords[j-1] = words[0];
		}
		else// * is not in front of array
		{
			if (star[0] != 0 && length_star == 1) // * is one
			{
				for (j = star[0]+1; j < length; j++)
				{
					newWords[j-star[0]-1] = words[j];
				}
				newWords[j - star[0] - 1] = words[star[0]];
				int j_count = j - star[0];
				for (int k = 0; k < star[0];k++)
				{
					newWords[j_count] = words[k];
					j_count++;
				}
			}
			else// * more than 2
			{
				
				int k = 0;
				if (star[i] ==0)// * exists in front of input
				{
						for (k = star[i]; k < star[i + 1] - 1; k++)
						{
							newWords[k] = words[k + 1];
						}
						newWords[k] = words[i];
						end_newWords = k+1;
						savepoint = end_newWords-1;
				}
				else // else case
				{
					if (star[i]==star[length_star-1]) // * is last time
					{
						for (k = star[i]+1; k < length; k++)
						{
							newWords[end_newWords] = words[k];
							end_newWords++;
						}
						newWords[end_newWords] = words[star[i]];
						for (k = star[i-1]+1; k < star[i]; k++)
						{
							newWords[end_newWords+1] = words[k];
							end_newWords++;
						}
					}
					else
					{
						if (i-1 >= 0)
						{
							for (k = star[i] + 1; k < star[i + 1]; k++)
							{
								newWords[end_newWords] = words[k];
								words[k] = words[end_newWords];
								end_newWords++;
							}
							newWords[end_newWords] = words[star[i]];
							savepoint = end_newWords;
							for (k = star[i - 1]; k < star[i]; k++)
							{
								newWords[end_newWords] = words[k];
								end_newWords++;
							}
						}
						else
						{
							for (k = star[i] + 1; k < star[i + 1]; k++)
							{
								newWords[end_newWords] = words[k];
								end_newWords++;
							}
							newWords[end_newWords] = words[star[i]];
							savepoint = end_newWords;
							end_newWords++;
							for (k = 0; k < star[i]; k++)
							{
								words[end_newWords] = words[k];
								newWords[end_newWords] = words[k];
								end_newWords++;
							}
						}
					}
				}
				
			}
		}
		end_newWords = savepoint+1;
	}
	
}

void main()
{
	char *words;
	char *newWords;
	int *star;
	int length=0;
	for (;;)
	{
		newWords = new char();
		words = new char();
		star = new int(-1);
		cout << "input words. if you enter ""break"" the program will be stop" << endl;
		cin >> words;
		length = strlen(words);
		CheckStar(words, length, star);
		int length_star = 0;
		int i = 0;
		while(star[i] >=0 && star[i]<length)
		{
			length_star++;
			i++;
		}
		
		if (!strcmp(words, "break"))
		{
			break;
		}
		suffle(words, star, length, newWords, length_star);
		for (int i = 0; i < length; i++)
		{
			cout << newWords[i];
		}
		cout << endl;
	}
	
	delete []star;
	delete []words;
	delete []newWords;
}
#include<iostream>

using namespace std;


int CheckStar(char *words, int length)
{
	int *star = new int(-1);
	int i,j = 0;
	for (i = 0; i < length; i++)
	{
		if (words[i] == '*')
		{
			star[j] = i;
			j++;
		}
	}
	return *star;
}

void suffle(char *words, int *star, int length, char *newWords)
{
	int j;
	if (*star == -1)
	{
		for (int i = 0; i < length; i++)
		{
			newWords[i] = words[i];
		}
	}
	for (int i = 0; i < sizeof(star)/4; i++)
	{
		if (star[i] == 0)// * exists in front of array
		{
			for (j = 0; j < length;j++)
			{
				newWords[j] = words[j+1];
			}
			newWords[j-1] = words[0];
		}
		else// * is not in front of array
		{
			if (star[0] != 0 && sizeof(star) == 1) // * is one
			{
				for (j = 0; j <= star[0]; j++)
				{
					newWords[j] = words[j];
				}
				newWords[0] = words[i];
			}
		}
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
		star = new int();
		cout << "input words. if you enter ""break"" the program will be stop" << endl;
		cin >> words;
		length = strlen(words);
		*star = CheckStar(words, length);
		if (!strcmp(words, "break"))
		{
			break;
		}
		suffle(words, star, length, newWords);
		for (int i = 0; i < length; i++)
		{
			cout << newWords[i];
		}
		cout << endl;
	}
	
	delete star;
	delete words;
	delete newWords;
}
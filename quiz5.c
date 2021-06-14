#include<stdio.h>
int wordCount(char *);
int isLetter(char);
int main(int argc, char *argv[])
{
	char *sentence="There are 55 elephants and 55 pigs.";
	printf("Total %d words in the sentence.\n",wordCount(sentence));
}
int wordCount(char *sentence)
{
	int word = 0;
	while(*sentence!='\0')
	{
		int count=0;
		
		while
		(*(sentence++) != ' '&& isLetter(*sentence))
		{
			count++;
		}
		if(count>0)
		{
			word++;
		}
		
	}
	return word;
}

int isLetter(char c)
{
	if(c>='A'&&c<='z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



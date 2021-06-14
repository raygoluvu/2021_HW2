#include <stdio.h>
void reverse(char *str)
{
	int len=0,i=0;
	while(str[i++]!= '\0')
	{
		len++;
	}
	
	for(i=len-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}

	
	
}
int main()
{
	reverse("abc def");
}

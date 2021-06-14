#include <stdio.h>
void reverse(char *str)
{
	if(*str!='\0')
	{
		reverse(++str);
		printf("%c",*(str-1));
	}

	
	
}
int main()
{
	reverse("abc def");
}

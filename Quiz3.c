#include <stdio.h>

int main()
{
	int num,count=0;
	printf("Please input a number: ");
	scanf("%d",&num);
	for(int i=1;i<=num/2;i++)
	{
		int total=i;
		for(int j=i+1; ;j++)
		{
			if(total+j<num)
			{
				total+=j;
			}
			else if(total+j==num)
			{
				printf("%d to %d\n",i,j);
				count++;
			}
			else
			{
				break;
			}
		}
	}
	
	
	
	printf("Total %d set(s) of %d",count ,num);
}

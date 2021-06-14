#include <stdio.h>
#include <math.h>
int main()
{
	int start,end;
	printf("Input the start number: ");
	scanf("%d",&start);
	printf("Input the end number: ");
	scanf("%d",&end);
	
	for(int i=start;i<=end;i++)
	{
		int p=0;
		int num=i;
		int total=0;
		
		while(num>0)
		{
			p++;
			num/=10;	
		}
		num = i;
	
		while(num>0)
		{
			total+=pow(num%10,p);
			num/=10;
		} 
		if(total==i)
		{
			printf("%d\n",i);
		}
		
		
	}
}

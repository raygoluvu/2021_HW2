#include<stdio.h>


int format1(char*s)//是否為前括號 
{
	if(*s=='{'||*s=='['||*s=='(')
	{
		return 1;
	}
	return 0;
}

int format2(char*s)//是否為後括號 
{
	if(*s=='}'||*s==']'||*s==')')
	{
		return 1;
	}
	return 0;
}



int function(char*s)//判斷結果函式 
{
	
	char *start = s;//指向首項 
	char *left = NULL;//指向目前最靠右之左括號 找到右括號後與其配對 
	
	while(*s != '\0')
	{
		if(format1(s))//左括號 
		{
			left = s;//指向左括號 
		}
		
		else if(format2(s))//遇到最左邊的右括號 
		{
			if(left==NULL)//left目前無指向 
			{
				left = s;//從目前位置往前找 
				while(!format1(--left))//找到左括號為止 
				{
					if(left==start)//已經找到首項仍沒有 
					{
						return 0;//不符合 
					}
				}
			}
			
			if(*s-*left>0 && *s-*left<=2)//判斷此左括號與右括號是否成對 
			{
				*s = 0;		//值歸零 
				*left = 0; //值歸零
				left = NULL; //指標暫時指向空 
			}
			else
			{
				return 0;//不成對,不符合 
			}
		}
		
		else//非括號值 
		{
			return 0;
		}
		s++;
	}
	
	
	if(left==NULL)//所有括號皆成對 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	
	
int main(int argc, char *argv[])
{
	char s[100]={};
	printf("Enter:");
	scanf("%s",s);
	
	if(function(s))
	{
		printf("GOOD!");
	}
	else
	{
		printf("BAD:(");
	}
}

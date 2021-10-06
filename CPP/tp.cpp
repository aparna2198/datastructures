#include<stdio.h>
int main(void)
{
	int x=10, y=10 , c;
	while(1)
	{
	
	printf("\n enter ur choice\n 1: add \n 2: sub \n 3: mul \n 4: div ");
	scanf("%d",&c);
	switch(c)
	{
			case 1:printf("%d",x+y);
		
		case 2: printf("%d",x-y);
		
		case 3: printf("%d",x*y);
		break;
		case 4: printf("%d",x%y);
		break;
	}
	
}
	return 0;
}

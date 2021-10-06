//i post pre increment  observations
#include<stdio.h>
int main()
{
	int i=1;
	
		for(int s=0;s<5;s++)
	{
	i=i--;//if assigned to a variable than printed prefix it will increment 2 3 4 5 
   // i=i--;// post fix assigned to a value than printed same value const will be prined no chance;
	printf("i++ = %d \n",i);

	}
	/*//if printed directly
	printf("i++ = %d \n",i++);// 1
	printf("i++ = %d \n",i++);// 2 since got incremented above 
	printf("++i = %d",i++);// i got incremnted abive again here so 3;
	for(int s=0;s<5;s++)
	{
	++i;// if incrmented at one line then printed incremnted value will print both ways i++ or ++i same value 2 3 4 ..
	printf("i++ = %d",i);

	}
	*/
}
	

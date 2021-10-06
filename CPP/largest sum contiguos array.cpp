#include<stdio.h>


/*int max(int a[],int size)// as a parameter you can except a[]the array but while sending you have to only send the name of the array which is a
{
int max_so_far,max_ending_here=0;
for(int i=0;i<size;i++)
{
	max_ending_here=max_ending_here+a[i];
	if(max_ending_here<0)
	max_ending_here=0;
	if(max_so_far<max_ending_here)
	max_so_far=max_ending_here;
}
return max_so_far;
}*/
int max(int a[],int size)
{
	int max_so_far=0,max_for_now=0;
	for(int i=0;i<size;i++ )
	{
			max_for_now=max_for_now+a[i];
			if(max_for_now<0)
			 max_for_now=0;
			if(max_for_now>max_so_far)
			{
				max_so_far=max_for_now;
			}
			
	}
	return max_so_far;
}
int main()
{ int size,x;
	printf("enter the no of elements you want to enter");
	scanf("%d",&size);
	int a[size];
	for(int i=0;i<size;i++)
	{
	printf("enter the element no %d",i);
	scanf("%d",&a[i]);
	x=max(a,size);//argument send only a since its understood its an array
    }
    for(int s=0;s<size;s++)
    {
    	printf("\n list you entered %d",a[s]);
	}
	printf("max number %d",x);
}

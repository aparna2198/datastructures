#include<stdio.h>
/*algorithm implies take two variables i and count
loop until count is less than nth position of ugly number
increment i evertime of the loop
increment count only when ugly fucntion returns 1
keep on incrementing i untill n>count and upuntill count is greater 
than n increment count only when ugly fucntion returns 1
 */

int max(int a,int b)
{
	while(a%b==0)//perfect divisible
	a=a/b;
	return a;
}

int ugly(int no)
{
	no=max(no,2);//max(300,2);no=150 1
	no=max(no,3);//max(150,3) no=75
	no=max(no,5);//max(75,5) no 1
	return (no==1)?1:0; //so returned 1 meaning number is ugly
}

int nth(int n)
{ // suppose n=7
	int i=1;
	int count=1;//ugly no count
	while(n>count)// count tell 1 to 149
	{
		i++;//2 3 4 5 6 7 8
		if(ugly(i))// ugly of 2
		count++;//increase the count if number is ugly meaning if(1)
	//2 3 4  5 6 
	}
	return i;
}

int main()
{int c;
printf("enter the pos");
scanf("%d",&c);
unsigned no=nth(c);
printf("%d thn ugly no is %d",c,no);
return 0;
	
}

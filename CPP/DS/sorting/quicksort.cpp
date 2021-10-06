#include<iostream>
using namespace std;
void swap (int *a,int *b)
{
//cout<<a<<"\t in fun "<<b<<endl;
int	temp=*a;
	*a=*b;
	*b=temp;
//	cout<<a<<"\t in fun "<<b<<endl;
}
int patition(int l, int h,int a[])
{     int temp;
	int pivot=a[l];
	int i =l;
	int j = h+1;
	while(i<j)
	{
		do{
			i++;
		  }while(a[i]<=pivot);
		do{
			j--;
		  }while(a[j]>pivot);
		if(i<j)
		{
		 swap(&a[i],&a[j]);
		}
	}
	
  a[l]=a[j];
  a[j]=pivot;
	return j;
}
void quicksort(int a[],int l,int h)
{int j;
	if(l<h)// at least two  elements present
	{
		j=patition(l,h,a);
		quicksort(a,l,j-1);
		quicksort(a,j+1,h);
	}
}

int main()
{
int a[] ={0, 89, 70, 100,7};
int n  =sizeof(a)/sizeof(int);
quicksort(a,0,n-1);// send aay to be sorted its left index and right index
for(int i=0;i<n;i++)
{
	cout<<a[i]<<"\t";
}	
	return 0;
}

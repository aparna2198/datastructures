#include<iostream>
using namespace std;
void merge(int ar[],int l, int mid , int r)
{    int temp[r-l+1];
	int i=l,j=mid+1,k=0;
while(i<=mid  && j<=r)
{
	if(ar[i]<=ar[j])
	temp[k++]=ar[i++];
	else
	temp[k++]=ar[j++];
}
while(i<=mid)
temp[k++]=ar[i++];
while(j<=r)
temp[k++]=ar[j++];
for(int i=l;i<=r;i++)
{
ar[i]=temp[i-l];	
}	
}
void mergesort(int ar[],int l,int r)
{ if(l<r)// at least two elements
{
    int mid=(l+r)/2;
	mergesort(ar,l,mid);
    mergesort(ar,mid+1,r);
    merge(ar,l,mid,r);
}
}

int main()
{
int ar[] ={0, 89, 70, 100,7};
int n  =sizeof(ar)/sizeof(int);
mergesort(ar,0,n-1);// send array to be sorted its left index and right index
for(int i=0;i<n;i++)
{
	cout<<ar[i]<<"\t";
}	
	return 0;
}


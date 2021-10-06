#include<iostream>
using namespace std;

// time complexity O(n^2) too  slow

// select the minimum element and swap to particular position
/*find the smallest el
2 loop 
1 i loop to select particular element say 0 th 
2 j loop the ith  element selected compare it with j=i+1 element see if i+1 is smaller than the selected i element
if so take action bcoz the smallest should be on lower index
action is take that j=i+1 index in the imin varible repeat this for 4 3 2 1 decreasing times
i loop to select particular ele and j loop to compare thta element to other and take action*/
void ss(int ar[],int n)
{int i ,j;
	for(i=0;i<n-1;i++)//n-1 the last element is getting sorted else the last elemeny is not sorted so false ->  (this for loop to select each index and consider imin also should be n-1 but when 4 out of 5 elements are sorted the 5th is sorted by default)
	{
	int imin =i;// ith position element from i till n-1 are candidates
	for( j=i+1;j<n;j++)// eg i=0 0th element u selected and now j loop start from 1 and compare till last n-1
	{cout<<"\n j"<< j;
	if(ar[j]<ar[imin])//meaning the 1 element is smaller so swap
	imin=j;// take the index
	}	

	int temp=ar[i];
	ar[i]=ar[imin];
	ar[imin]=temp;
//		cout<<"\n i"<<i<<"\t j"<<j;
	cout<<"\n ar[i]"<<ar[i]<<"\t ar[imin]"<<ar[imin]<<"\t temp"<<temp;
	}
}
int main()
{
int ar[] ={5,4,3,2,1};
ss(ar,5);
for(int i=0;i<5;i++)
{
	cout<<ar[i]<<"\t";
	}	
	return 0;
}

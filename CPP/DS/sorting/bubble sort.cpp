#include<iostream>
using namespace std;

//ftime complexity O(n^2) too  slow
// best case omega(n)
// avg O(n^2) 
// worse case O(n^2) 

/* scan the array from left to right each scand one pass on the array
compare particular position with the adjacent position is the current position 
greater than the adjacent position then swap else dont
each scan one element will get rightly placed*/
void bs(int ar[], int n)
{int temp;
// k loop for n passes 
// i loop for 1 pass 1 element compare with n-1 elements and place to the right position  
 for(int k=0;k<n-1;k++)
 {// in order to place alll the elements to the correct position we need to run this k loop n-1 times
 //int flag =0;
	for(int i=0;i<n-k-1;i++)// n-k-1 instead of n-1 bcoz once the elements are getting places rightly the looping 
	//should be less so starting from 5 next round 
	{// if only this is considered only one passs is done and one element is palced to the correct position
		if(ar[i]>ar[i+1])
		{
		temp=ar[i];
		ar[i]=ar[i+1];
		ar[i+1]=temp;
	//	flag =1;
	}
	/* for sorted arrays
		if(flag==0)
		break;*/// if sorted array is passed then this for will execute only once
	}
}
}
int main()
{
int ar[] ={1,2,3,4,5,0};
bs(ar,6);
for(int i=0;i<6;i++)
{
	cout<<ar[i]<<"\t";
	}	
	return 0;
}

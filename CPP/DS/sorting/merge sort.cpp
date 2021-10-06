#include<iostream>
using namespace std;
// ***time complexity worst case (nlogn) fast
// *** space complexity O(n) sapce depends ont the size of the input n

//divide and conquer algo
// recursive
// divide an conquer

// stable - relative order of the  record with same key(property on which u are sorting) must preserve i
/*eg (1,2) (2,5) (4,8) (2,3) sort this with x value increasing
so in stable it will give(1,2) (2,5) (2,3) (4,8)
(2,5) (2,3) equalkeys(x=2) relative order same as original list*/
// approach divide the array into two possible equal halfs
//not in space takes extra space
#include<iostream>
using namespace std;
void merge(int ar[],int l, int mid , int r)
{ // this fucntion is basicsally mergeing two sorted list that means whatever arrays
// the two arrays are considered to be sorted
int temp[r-l+1];// temporary array of length n but since the merging is changing accordingly the array length will also change
	int i=l,j=mid+1,k=0;// i pointint to startt of left list j pointing to start of right list
	
while(i<=mid  && j<=r)
{
	if(ar[i]<=ar[j])
	temp[k++]=ar[i++];
	else
	temp[k++]=ar[j++];
}                                                                                                                                                                                           
// this below two while loops when one of the array get exhausted and the other remain

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
    int mid=(l+r)/2;// find mid of the array
	mergesort(ar,l,mid);// again send the array left index right index which is  now mid
    mergesort(ar,mid+1,r);//again send the array left index which is mid+1 right index which is  now end
    // keep on recursive mergesorting the array until there is only one element left  in the array
    // since only one element is there it is considered to be sorted now starr mergeing the sorted array 
    merge(ar,l,mid,r);// sendig ar left index mid and right index;
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
/*
breakdown the entire array up until only one element is left is left in the array
one element is always considered to be sorted so now left sorted right sorted now call merge function
merge fucntion taken two sorted array and merges example
                               8 7 6 5 (5 6 7 8)
/                                   \                       \ (merge)(5 6 7 8)
8 7<-(7,8)                       6 5<-(5,6)// copy this sorted element back to
/ \ \(m)(7,8)                     /  \ \(m)(5,6)  // copy this sorted element back to 
8   7                            6  5        // sorted single elements  8   7   6  5 now perform respective merge operation
*/

#include<iostream>
 using namespace std;
 int search(int ar[], int l , int h, int key)
 {  if(l>h) return -1;
 	int mid=(l+h)/2;
 	if(key==ar[mid])
 	{
 		return mid;
	}
	if(ar[l]<=ar[mid])// considering the ar[l...mid] is sorted
	{if(key>=ar[l] && key<=ar[mid])
    return search(ar,l,mid-1,key);
	return search(ar,mid+1,h,key);
	
	}
	if(key>=ar[mid] && key<=ar[h])
		return search(ar,mid+1,h,key);
	  return search(ar,l,mid-1,key); 
 }
 /*int search( int ar[],int l , int h,int key)
 {
 	if(l>h)
	return -1;
 	int mid=(l+h)/2;
 	if(ar[mid]== key)
 	{
 		return mid;
	}
    if(ar[l]<=ar[mid])
	{
		if(ar[l]<=key && key<ar[mid])// when the data lies between the low index and the middle
		return search(ar,l,mid-1,key);
	    return search(ar,mid+1,h,key);
	}
  
		if(ar[mid]<=key && key<=ar[h])
		return search(ar,mid+1,h,key);
		return search(ar,l,mid-1,key);
	 }*/
 int main()
 {
 	 int ar[]={1,3,4,9,10,56,89};
 	 int i=search(ar,0,6,10);
 	 if(i!=-1)
 	 cout<<"found at \t"<< i<<endl;
 	 else
 	 cout<<"not found";
 	 
 }

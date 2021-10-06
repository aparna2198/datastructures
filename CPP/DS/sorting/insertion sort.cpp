#include<iostream>
using namespace std;
// inplace sorting algo 

//**time complexity**
// best case when array is sorted the while loop wont execute only so omega (n)
// worst case O(n^2)
// average case i/2 shifts O(n^2)

//# of comparision and shifts is lot less than bubble and selection sort not more effecient but better than bubble and selection in practical scenario many intuitive methoda availaible
/*works ont the basis that divide the arrayinto two parts sorted ans unsorted and then move the unsorted elements none by one to the sorted category
initially move one element to the sorted part one elemnt is always comsidered to be sorted and further one by one move the other  unsorted ones till the list of unsorted ones become empty
*/
void is(int a[],int n)
{
for(int i=1;i<n;i++)// since i=0 is considered to be sorted	
{
	int value=a[i];
	int hole=i;
    while(hole>0 && value<a[hole-1])// check if there are elements on the left if yes then check if the i(hole) 
	//a[hole]index vlaue is smaller than the i-1(hole -1) a[hole-1]
	{ // if both true then shift that big value up until hole 
	//is greater than zero and that hole value greater than hole -1
	a[hole]=a[hole-1];
	hole=hole-1;
	}
	// move that smaller value collected to the hole 
	a[hole]=value;
}
}
int main()
{
int ar[] ={1,2,3,4,5,0};
is(ar,6);
for(int i=0;i<6;i++)
{
	cout<<ar[i]<<"\t";
}	
	return 0;
}

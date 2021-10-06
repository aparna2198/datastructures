#include<iostream>
using namespace std;
void swap(int * a, int * b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
class heap{
	

	int *hp;
	int cap;
	int size;

		public:	
heap(int a)
{ 
 size=0;
 cap =a;
 hp =new int[cap];// new / data ka type/ kkitna chiye 
}
	int parent(int i)
	{
		return (i-1)/2;// here the mistake i did was i did not put the bracketr so division was done first then -
	}
		int left(int i)
	{
		return (2*i+1);
	}
		int right(int i)
	{
		return (2*i+1);
	}

	void insert(int );// TO INSERT THE DATA
	void heapify(int );// to make that data reach the right place keeping in mind child iisalways greater than root
int extractmin();// remove the minimum element that is root and replace with size -1 element
	void deletekey(int);/// delete the element
int getmin(){return hp[0];}// get the root taht is smallest element
	void decreasekey(int ,int);//replace the root with the minimum element
};


void heap::insert(int data)
{	if(size==cap)
	{    
		cout<<"\n overflow cannot insert \t"<<data;
		return ;
	}
	else
	{
       	 //3elements 0 1 2  4
	int i =size;//4-1= 3rd index
	//cout<<"\n size"<<size;
	size++;
    hp[i]=data;//
 
   // cout<<"\n"<<hp[i]<<"\t  inserted"<<endl;
    //cout<<"\n parent i"<<hp[parent(i)]<<endl;
    //cout<<"\n i"<<i<<endl;
    while(i!=0 && hp[parent(i)]>hp[i] )
    {//  cout<<"\n before swap \t parent"<<hp[parent(i)]<< "\t child "<<hp[i]<<endl;
    	swap(&hp[parent(i)],&hp[i]);
    //	cout<<"\n after swap \t parent"<<hp[parent(i)]<< "\t child "<<hp[i]<<endl;
    	i=parent(i);
	}
}
}

void heap:: decreasekey(int i , int val)
{   hp[i]=val;
	while(i!=0 && hp[parent(i)]> hp[i])
	{
		swap(&hp[parent(i)], &hp[i]);
		i=parent(i);
	}
}

int heap:: extractmin()
{
	if(size<=0)
	{cout<<"\n underflow \n";
	
	}
	if(size==1)
	{
	 cout<<hp[--size];	// one element so at zero element 
	}
	int root=hp[0];//since root is removed we have to put something in the root
	hp[0]=hp[size-1];// put the last element in the array
	size--;//now since root is removed the size has to be decreased
	heapify(0);//now size-1 is moved we got to make the tree  elements to follow the root< child everywhere
	return root;
}

void heap:: deletekey(int i)
{
	decreasekey(i, INT_MIN);// say - infinity  place it at the root since its the smallest
	extractmin();//remove that - infinity at root and replace that root with size -1 value 
}
void heap::heapify(int i )// parameter root node
{        //0
       //1   2
    // this function basically 
	//makes sure that the root 
	//is less than both its child
	int l=left(i);
	int r = right(i);
	int smallest= i;
	if(l<size  && hp[l]<hp[i])
	{
		smallest=l;
	}
	if(r<size && hp[r]<hp[i])
	{
		smallest = r;
	}
	if(smallest!= i)
	{
		swap(&hp[i],&hp[smallest]);
		heapify(smallest); // because now the smallest is the root so always send the root to the heapify fucntionn 
	}
}
int main()
{  //78 29 3 6 2 84
	heap h(7);
	h.insert(78);
	h.insert(29);
	h.insert(3);
	h.insert(6);
    h.insert(2);
    h.insert(7);
    h.insert(84);
   
   //h.decreasekey(6,0);
	 cout<<h.getmin()<<endl;
}

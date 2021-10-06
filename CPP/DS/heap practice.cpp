#include<iostream>
using namespace std;
void swap(int * a , int *b)
{
	int temp= *a;
	*a=*b;
	*b=temp;
}
class heap{
	int cap;
	int size;
	int *hp;
	public:
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i )
	{
		return (2*i+1);
	}
	int right(int i)
	{
		return ( 2* i+2);
	}
	heap (int a)
	{
		size=0;
		cap=a;
		hp=new int[cap];

	}
	void extractmin();
	void decreasekey(int , int);
		int getmin(){return hp[0];}
	void insert(int);
	void deletekey(int);
	void heapify(int);

   	
	
};

void heap:: insert(int data)
{ //cout<<"\n c"<< cap<<"\t s"<<size;
	if(size == cap)
	{
		cout<<"\n over flow not insreted \t"<< data<<endl;
	}
	
	int i=size;
	hp[i]=data;
	size++;
	cout<<"\n"<< data<<"\t inserted"<<endl;
	if(i!=0 && hp[parent(i)]>hp[i])
	{
		swap(&hp[parent(i)],&hp[i]);
		i=parent(i);
	}
}
void heap::decreasekey(int i,int val)
{
	hp[i]=val;// asssuming the val is less coampred to what i existing
	if(i!=0 && hp[parent(i)]> hp[i] )
	{
		swap(&hp[parent(i)],& hp[i] );
		i=parent(i);
	}
}
void heap::extractmin()
{
int root= hp[0];
hp[0]=hp[size-1];
size--;
heapify(0);
}

void heap::heapify(int i)
{
	int  l= left(i);
	int  r= right(i);
	int smallest=i;
	if( l<size && hp[l]<hp[i])
	{
		smallest=l;
	}
	if( r<size && hp[r]<hp[i])
	{
		smallest= r;
	}
	if(smallest!= i)
	{  	//cout<<"\n smallest "<< smallest;
		swap( & hp[smallest], & hp[i]);
		//cout<<"\n smallest "<< smallest;
		heapify(smallest);// recursive for the smallest again
	}
}
void heap::deletekey(int i)
{
	decreasekey(i,INT_MIN);
	extractmin();
}
int main()
{
	 heap h(4);
	 h.insert(5);
	 h.insert(78);
	 h.insert(55);
	 h.insert(84);
	 h.decreasekey(0,1);
	 h.extractmin();
     cout<<h.getmin();
	 return 0;
}

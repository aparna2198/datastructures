#include<iostream>
using namespace std;
// queue algorithm  and  a data structures also its  linear one elemenet connected to only one element
 // filo
 // 2 ways using static array and dymnamic array
 // static impementation
 #define cap 5
 int queue[cap];
 int front =0;
 int rear=0;
 int isfull()
 {
 	if((rear+1)%cap==front)
 	{
	 return 1;
    }
    else
    return 0;
 }
void enqueue()
{
 	if(isfull())
{
	cout<<"queuue is full"<<endl;
}
else
{
int data;
	cout<<"enter he the data :\t";
	cin>>data;
	queue[rear]=data;
	rear++;// fro insertion ++ for deletion --
}
}
 int isempty()
 {
 	if(rear==front)
 	{
 		return 1;
	 }
	 else
	 return 0;
 }
 
 void dequeue()
 {if(isempty())
 {
 	cout<<"no element  to delete \n";
 }
 else
 {
   	 cout<<queue[front]<<"deleted \n";
   	for(int i=0  ; i<rear-1;i++)
   	{
   	queue[i]=queue[i+1];	
    }
    rear--;// fro insertion ++ for deletion --
 }
 }
 void tra()
 {
 	if(isempty())
 	{
 		cout<<"queue is empty \n";
	}
else
{	cout<<"\n queue elements: \n ";
	/*for(int i=front;i<rear;i++)
	{// less than rear bcoz when we isnert the fourth elements the rear is incremeneted so rear ispointing to the fifth location so less than
	cout<<queue[i]<<endl;
	}*/
	for(int i=rear-1;i>=0;i--)
	{// less than rear bcoz when we isnert the fourth elements the rear is incremeneted so rear ispointing to the fifth location so less than
	cout<<"->"<<queue[i];
	}
}
 }
int main()
{ int ch,data,x;
while(1)
{
	cout<<"\n 1: enqueue \n 2: dequeue \n 3: traverse \n "<<endl;
	cin>> ch;
	switch(ch)
	{
	
	case 1 : enqueue(); 
	break;
	case 2: dequeue();  
	break;
	case 3:tra();
	break;
    default: exit(0);
	break;
}
}
}

#include<iostream>
using namespace std;
#define  capacity  5
int stack[capacity],top=-1;

int isfull()
{
	if(top==capacity-1)
	{
		return 1;// it is full
	}
	else
	{
		return 0;
	}
}
void push(int i)
{
	if(isfull())
	{ 
		cout<<"its full"<<endl;
	}
	else
	{
	top++;// since its -1 set 
	stack[top]=i;	
	cout<<"inserted"<<endl;
	}
}
int isempty()
{
	if(top==-1)
	{
		cout<<"stack is emoty";
	return 1;// is empty	
	}
	else
	{
		return 0;
	}
}

int pop()
{
	if(isempty())
	{
   cout<<"its empty"<<endl;		
	}
	else
	{
		return(stack[top--]);
	}
}

void peek()
{ if(isempty())
{
	cout<<"empty";
	
}
	else
	{
		cout<<stack[top];
	}
}

void traverse()
{
	if(isempty())
	{
		cout<<"lis is empty"<<endl;
	}
	else
	{ for(int i=0;i<top;i++)
		cout<<stack[i]<<endl;
		
		top--;
	}
}

int main()
{
	int c,i;
	while(1)
	{
	
	cout<<"\n 1:push \n 2: pop \n 3: peek \n 4: traverse \n 5: quit "<<endl;
	cin>>c;
	switch(c)
	{
		case 1:cout<<"enter the element "<<endl;
		   cin>> i;
		   push(i);
	    break;
		case 2:i=pop();
		     if(i==0)
		     {
		     	cout<<"its empty"<<endl;
			 }
			 else
			 {
			 	cout<<"\n"<<i<<"deleted"<<endl;
			 }
		break;
		case 3: peek();
	 	break; 
	 	case 4: traverse ();
	 	break;
				 	
	}
}
}

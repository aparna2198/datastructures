#include<iostream>
using namespace std;
//circular queue
#define cap 6 

// creation of queue 
int queue[cap];
int rear=-1;
int front =-1;
void dequeue()
{
	if(front==-1 && rear==-1)
    {// underflow
    	cout<<"queue is empty \n";
	}
	if(front==rear)// u deleting the  alst elemen in the c queue
	{// only one elemet in the queue so make them -1 which is a empty condition
		cout<<queue[front]<<" \t deleted";
		front =rear=-1;
	}
	else if(front == cap -1)//
	{// front has reached the last element
		cout<<queue[front]<<" \t deleted";
		front =0;
	}
    else
    {// normal condition
    	cout<<queue[front]<<" \t deleted";
    	front ++;
	}
}
void enqueue()
 { int data; 
cout<<"enter the elemenet \t";
cin >> data;
	if ((rear+1)%cap==front)// step one overflow condition full condition
	{
		cout<<"queue is full \n";
	}
	if(front =-1 && rear==-1)
	{// quueue is empty u inserting the first element in the queue
		front =rear =0;
		queue[rear]=data;//rear to isnert front to delete
		cout<<"data is inserted \n ";
	}
	else if( rear ==cap -1 && front !=0)
	{// rear has reached the last elemnt but the quueue is stilll emppty
		rear=0;
		queue[rear]=data;
		cout<<"data is inserted \n ";
	} 
	 else
	 {// normal condition when the front is pointing tto 0 and rear has not reached the cap-1  stage
	 	rear++;
	 	queue[rear]=data;
	 	cout<<"data is inserted \n ";
	 }// normal queue only two conditions overflow else insert
}
void tra()
{
	if(front==-1 )
	{
		cout<<"\n queuue is empty \n";
	}
	// if all elements are there 0 to rear front =0 rear 4
/*	if(front ==0 && rear==cap -1)
	{
	cout<<"queue is \n";
	for(int i=0;i<=rear;i++)
	{
	 cout<<"<-"<<queue[i];
	}
	}*/
	else
	{
		if(front<rear)
		{
			for (int i =front ;i<=cap;i++)
		{
		cout<<"<-"<<queue[i];
		}
	    }
		else
		{
		    for(int i=0 ; i<=rear;i++)
		{
			cout<<"<-"<<queue[i];
		}	
		}
		else
		{
				for(int i=front  ; i<=rear;i++)// if front is smaller then traverse the normal
		{
			cout<<"<-"<<queue[i];
		}
		}
	} // if front > rear two for loops o to rear one and the other is  fornt to cap 1	
    }

int main()
{ int ch;
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

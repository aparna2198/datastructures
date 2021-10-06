#include<iostream>
#include<stack>
using namespace std;


struct queue{
	stack<int > s;
	
	void enqueue(int x)
	{//O(1)
		s.push(x);
		cout<<x<<"\t inserted"<<endl;
	}
	int dequeue()
	{
		if(s.empty())
		{
			cout<<"q is empty \n";
		}
		int x=s.top();
		s.pop();
		if(s.empty())
		return x;// thsi means only one element is there
		int item=dequeue();//second element dequeued 
		s.push(x);//since since wasnt the element we wanted to dequeue
		return item;
	}
};
int main()
{queue q;
q.enqueue(11);
q.enqueue(12);
q.enqueue(13);
q.enqueue(14);

cout<<q.dequeue()<<"\t dequeueped"<<endl;;
cout<<q.dequeue()<<"\t dequeueped"<<endl;
	
}

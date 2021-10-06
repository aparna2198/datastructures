#include<iostream>
using namespace std;

struct node{
	int data ;
	node * next;
};
node * head=NULL;
void insert()
{node * temp=new node;
	cout<<"\n enter the data \t";
	cin>>temp->data;
	temp->next=NULL;
	if(head==NULL)
	head=temp;
	else
	{node * t=head;
		while(t->next!=NULL)
		t=t->next;
		t->next=temp;
	}
	cout<<"\n node inserted successfully \n";
}
void del()
{node * r;
	if(head==NULL)
	cout<<"\n list empty \n";
	else
	{r=head;
		cout<<head->data<<"\t deleted"<<endl;
		head=head->next;
	delete r;
	}
}

void print()
{node * r=head;
cout<<"\n list is :\n";
	if(head==NULL)
	cout<<"list is empty"<<endl;
	else
	{
		while(r!=NULL)
		{
			cout<<r->data<<" ";
			r=r->next;
		
		}
	}
}
void swap(int x)
{
	
}
int main()
{
int c,loc;
while(1)
{
printf("\n select \n 1: insert the node \n 2: print the list \n 3:swap \n 4: delete \n");
scanf("%d",&c);

switch (c)
{
	case 1: insert();
	break;
	case 2: print();
	break;
	case 3: printf("\n enter the location to be swapped \n");
	        scanf("%d",&loc);
	 swap(loc);
	break;
	case 4: del();
	break;
}	
}
return 0;
}

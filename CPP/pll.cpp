#include<stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	node*next;
};

node * head;

void insert()
{ 
	node * temp,*t;
	temp=(node *)malloc(sizeof(struct node));
	printf("enter the number");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		t=t->next;
		t->next=temp;
	}
	
}


void print()
{
	node * temp;
	temp=head;
	printf(" \n list is:");
	if (head==NULL)
	{
		printf(" empty");
		
	}
	else
	{
		while(temp!=NULL)
		{
			printf(" \n %d",temp->data);
			temp=temp->next;
		}
		
	}
}
void del()
{
node * r;
	if (head==NULL)
	{
		printf("list is empty");
		
	}
	else
	{ r=head;
	printf("%d",head->data);
	  head=head->next;
	  printf("deleted");
	  free(r);
	}
}
int main()
{
int c;
head =NULL;
while(1)
{
printf("\n select \n 1: insert the node \n 2: print the list \n 3: delete \n");
scanf("%d",&c);

switch (c)
{
	case 1: insert();
	break;
	case 2: print();
	break;
	case 3: del();
	break;
}	
}
return 0;
}

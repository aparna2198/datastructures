//linked list

#include <stdlib.h>
#include <stdio.h>
struct node{
	int data ;
	node* next;
};
node * head;
void insert();
void print();

void insert()
{
 node * temp,*t; // node type 2 variables 
 temp=(node*)malloc(sizeof(struct node))	; // asiign the variable a memory run time memory using mallocck fucntion can do it using  new node fucntion in cpp
 printf("enter the number");// ask fir the elements
 scanf("%d",&temp->data);// take the data &(at address) ]in data part of the node 
 temp->next=NULL;// since this  is the last node its adress part  will be null
 if (head==NULL)
 head =temp;// list  is empty new node created uska adrees put it in head node
 else
 {
 	t=head;// not empty means head node has something take that into other variable say t
 	while(t->next!=NULL)// traverse till t next not null 
 	t=t->next;
 	t->next=temp;
 }
}

void print()
{
	node * temp=head;
	printf("\n list is:");
	while(temp!=NULL)
	{ printf("\n %d  ",temp->data);
	  temp=temp->next;
	}
}


void del()
{
	node * r;
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		r=head;
		printf( "(%d )",head->data);
		head=head->next;
        printf("number succesfully deleted\n ");
	  free(r);
	}
}
int main ()
{   
   int a;
   head =NULL;
   while(1)
   {
 	printf("\n choose \n 1: insert the elements \n 2: print the list \n 3:delete \n");
	scanf("%d", &a);
	switch (a)
	{
	case 1:	insert();
	break;
	case 2: print();
	break;
	case 3: del();
	break;
	}
   } 
}
 




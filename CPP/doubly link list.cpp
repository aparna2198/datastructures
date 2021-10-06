#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	node *prev ,* next;
};
node *start=NULL;

void insert()
{
	node * n;
	n=(node*)malloc(sizeof(struct node));
	printf("enter the number");
	scanf("%d",&n->data);
	n->prev=NULL;
	n->next=NULL;
	  if(start==NULL)
	  {
	  	start=n;
	  }
	  else
	  {
	  	 start->prev=n;
	  	 n->next=start;
	  	  start=n;
	  }
} 


void del()
{ node* r;
	if(start==NULL)
	{
		printf("list is empty");
		
	}
	else
	{ r=start;
	  start=start->next;
	  start->prev=NULL;
     free(r);
	}
}



void print()
{
	node*t;
	t=start;
	if(start==NULL)
	{
		printf("lst is empty");
		
	}
	else
	{
		while(t!=NULL)
		{
			printf("%d",t->data);
			t=t->next;
		}
	}
}

int main()
{
int c;
start =NULL;
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

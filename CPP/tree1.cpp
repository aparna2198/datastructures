
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node *left=NULL;
struct node *right=NULL;
struct node *create(node *root,int);
struct node *insert(node *root,int);
void display_pre_order(node *temp);
void display_in_order(node *temp);
void display_post_order(node *temp);
int main()
{
	int n,n1,x;
	node *head;
	head=NULL;
	do
	{
		printf("\n Enter your choice");
		printf("\n 1. Create");
		printf("\n 2. insert");
		printf("\n 3. Preorder");
		printf("\n 4. Inorder");
		printf("\n 5. Postorder");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\nEnter Value");
				scanf("%d",&x);
				head=create(head,x);
				break;
			case 2:
				printf("\nEnter Value");
				scanf("%d",&x);
				head=insert(head,x);
				break;
			case 3:
				printf("\n List in Preorder");
				display_pre_order(head);
				break;
			case 4:
				printf("\n list in inorder");
				display_in_order(head);
				break;
			case 5:
				printf("\n list in postorder");
				display_post_order(head);
				break;
		}
		printf("\n enter 1 to continue and 0 to exit:");
		scanf("%d",&n1);
		printf("\n******\n\n");
	}
	while(n1==1);
}

struct node *create(node *root,int val)
{
	node *temp=NULL;
	if(root==NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->left=NULL;
		temp->right=NULL;
		temp->data=val;
		printf("\n root node created");
		root=temp;
		return root;
	}
}

struct node *insert(node*root,int val)
{
	node*temp=NULL;
	if(root==NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->left=NULL;
		temp->right=NULL;
		temp->data=val;
		printf("\n Data entered into tree");
		root=temp;
	}
	if (val<root->data)
	{
		root->left=insert(root->left,val);
	}
	else if(val>root->data)
	{
		root->right=insert(root->right,val);
	}
	return root;
}
void display_post_order(node *temp)
{
	if (temp!=NULL)
	{
		display_in_order(temp->left);
		display_in_order(temp->right);
		printf("\n %d",temp->data);
	}
}
void display_in_order(node *temp)
{
	if (temp!=NULL)
	{
		display_in_order(temp->left);
		printf("\n %d",temp->data);
		display_in_order(temp->right);

	}
}
void display_pre_order(node *temp)
{
	if (temp!=NULL)
	{
		printf("%d\n",temp->data);
		display_in_order(temp->left);
		display_in_order(temp->right);

	}
}
37 38 42 51 55 62 75 82 80 94
55 38 37 42 51  75 62 80 82 94
37 51 42 38 62 82 94 80 75
d b f e a c h g

a b d e f c g h

 d f e b h g c a

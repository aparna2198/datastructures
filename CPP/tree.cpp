#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	node * left;
	node * right;
};

node * tree;//pointer to tree

node * insert(node * ,int);
void pre(node*);
void in(node*);
void pos(node *);
node * del(node*,int);
node * deletetree(node*);


int main()
{//node * ptr;
	int c,data;
    tree=NULL;// tree is the node type p ointer var created global null meaning tree is empty
	while(1)
	{
		printf("\n 1: insert \n 2: display_pre \n 3: display_in \n 4: display_post \n 5: delete element\n 6: delete tree");
		scanf("%d",& c);
		switch(c)
		{
			case 1:printf("\n enter the value \n ");
					scanf("%d",& data);
					tree= insert(tree,data);
			break;
			case 2: printf("\n the elements preorder are \n");
			 		pre(tree);
			break;
			case 3: printf("\n the elements inorder are \n") ;
					in(tree);
			break;
			case 4: printf("\n tree elements in posorder \n");
					pos(tree);
			break;
			case 5:printf("\n enter the element you want to delete");
					scanf("%d",&data);
			 		tree=del(tree,data);
			break;
			case 6: tree=deletetree(tree);
			break;
		}
    }
    
}
node * newnode(int data)
{
node * temp= (node*)malloc (sizeof(node));//NEW element  inserted assign memory
temp->data=data;
temp->right=temp->left=NULL;
return temp;
}

node * insert(node * tree,int data)
{
	if(tree==NULL)
	tree=newnode(data);	
	else if(data<tree->data)
	tree->left=insert(tree->left,data);
	else
	tree->right=insert(tree->right,data);
	return tree;
}

/*node * insert(node * tree,int data)
{ 
node * ptr,*nodeptr,*parentptr;
ptr=(node*)malloc(sizeof(node));
ptr->data=data;
ptr->left=NULL;
ptr->right=NULL;
if(tree==NULL)
{
	tree=ptr;
	tree->left=NULL;
	tree->right=NULL;
	printf("\n root node created successfully");
}
else
{
	parentptr=NULL;
	nodeptr=tree;
	while(nodeptr!=NULL)//up until nodeptr is not null tree is not empty follow loop
	{
		parentptr=nodeptr;//whatever there in tree assign to parent previous exiting elements will become parent
        if(data<nodeptr->data)
	    nodeptr=nodeptr->left;
		else
		nodeptr=nodeptr->right;		
	}
	if(data<parentptr->data)
	parentptr->left=ptr;
	else
	parentptr->right=ptr;
	printf("\n element added to the tree");
}
return tree;	
}
*/

void pre(node* tree)
{
	if(tree!=NULL)
	{
		printf(" \n %d",tree->data);
		pre(tree->left);
		pre(tree->right);
	}
	else
	{
		//printf("tree is empty");
	}
}

 void in(node * tree)
{
	if(tree!=NULL)
	{
		in(tree->left);
		printf("\n %d",tree->data);
		in(tree->right);
	}
	else
	{
		//printf("tree is empty");
	}	
}
 void pos(node * tree)
{
	if(tree!=NULL)
	{
		pos(tree->left);
		pos(tree->right);
		printf("\n %d",tree->data);
	}
	else
	{
		//printf("tree is empty");
	}	
}

node * findmin(node * tree)
{
	if(tree==NULL)
	return tree;//tree is empty
	while(tree->left!=NULL)
	tree=tree->left;
	printf("\n %d is the smallest element,tree->data");
	return tree;
}
node * del(node* tree ,int data)
{
	if   (tree==NULL)
	return tree;
	else if(data<tree->data)
	tree->left=del(tree->left,data);//since if one left node is deleted the left tree address will chnage will update the new address int the tree left address
    else if(data>tree->data)
	tree->right=del(tree->right,data);
	else
	{
	 	//got the data to be deleted
	 	//case 1: no child
	 	if(tree->right==NULL&& tree->left==NULL)
	 	{
	 	delete tree;//deallocate memory in c use free function
	 	tree=NULL;
		}
		 //CASE 2: one child
		else if(tree->left==NULL)
		{    node* temp=tree;
			tree=tree->right;
			delete temp;
		} 
		 //case 3:one child
		 else if(tree->right==NULL)
		 {
		 	node * temp=tree;
		 	tree=tree->left;
		 	delete temp;
		 }
		 //case 3: two child
		 else
		{node* temp=findmin(tree->right);
		 tree->data=temp->data;
		 tree->right=del(tree->right,temp->data);
		}
		return tree;
	}	
	printf(" \n item successfully deleted");
}
	
	node * deletetree(node * tree)
	{
	    if(tree!=NULL)
	    {
	    	deletetree(tree->left);
	    	deletetree(tree->right);
	    	delete tree;
		}
		printf("\n tree successfully deleted");
		
	}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	




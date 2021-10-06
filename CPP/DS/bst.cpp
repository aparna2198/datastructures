#include<iostream>
//#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node * left,*right;
};
node * tree;

node *newnode(int x)
{ node * temp;
temp=(node*) malloc(sizeof(node));
temp->data= x;
temp->right=temp->left=NULL;
return temp; 
}


node*insert(node * add,int data)
{
	if(tree==NULL) // when tree is empty
	tree=newnode(data);
	else if(tree->data>data)
	tree->left =insert(tree->left,data);
	else
	tree->right=insert(tree->right,data);
	return tree;
}

void in(node * temp)
{
	if(temp!=NULL)
	{
		in(temp->left);
		cout<<temp->data;
		in(temp->right);
	}
	else
	{
		cout<<"tree is empty"<<endl;
	}
}

int main()
{ 
int data,c;
node * tree=NULL;
while(1)
{ cout<<"enter the choice \n 1: insert \n 2: display \n"<<endl;
cin>>c;
switch(c)
{ 
	case 1:cout<<"enter the data \n";
	      cin>>data;
	      tree=insert(tree,data);
	      break;
	case 2: in(tree);
	    break;    
		case 3: 0;  
}
}
}




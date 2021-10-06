#include<stdio.h>
#include<stdlib.h>
#include<iostream>// will search in standard folder
#include <queue>// will first search in current directory or folder  and then standard folder
// if< queue.h> gives out error as when used <> it directly 
//searched into standard library without even looking at current folder
// when used "iostream" it first searches into current folder if not founf then goes to the standara folder 
// so doesnt get anyy error as if finds itself in standar folder 
// so" goes from currentfoder---> standardfolder  whereas the <> directy goed to standard
#include<stack>
using namespace std;
struct node{
	int data;
	node * left;
	node * right;
};

node * tree;//pointer to tree
void level(node * root)
{
	if(root==NULL)
	return ;
	queue <node*> q;
	q.push(root);// 8 
	
	while(!q.empty())
	{
	node * temp=q.front();// temp 8; 3; 10; 1;6;14; 4;7;13 
	cout<<"\t "<<temp->data;//print 8 ; 3; 10; 1;6;14;4;7;13
	q.pop();// ;10;1 6 ;6 14;14;4 7;7 13;13; 13
	if(temp->left!=NULL)
	q.push(temp->left);// 3;10 1;6 14;14 4;4 7 13 
	if(temp->right!=NULL)
	q.push(temp->right);// 3 10;10 1 6; 1 6 14;6 14;14 4 7;4 7 13
	}
	
	}
/*void levelorder(node * root)
 {
 	 if(root ==NULL) return ;
 	 // since i have included the queue header i can create queue of any type
 	 queue< node*> q;// so i create a queue with pointer to node
     // this queue consists of what types of elements char int etc 
	 //here it is node type element will be puting inside the queue using q varaiable
	 
	 q.push(root);// queue node 8
	 int flag=0;
	 while(!q.empty())
	 {  if(flag==0)
	 {
	 	node * current= q.front();// basically consider this as a parent 
	 	cout<<"\t"<<current->data;// we printing out the parent
	    if(current->left!=NULL)// we queueing its children
	 	{  
		 q.push(current->left);// 8 3 
     	}
	 	if(current->right!=NULL)
	 	{	
		 q.push(current->right);//8 3 10; 
	    }	
	    q.pop();
		flag=1;//8 3 10
		continue;
	 }
	 if(flag==1)
	 {
	 node * current= q.rear();// basically consider this as a parent 
	 cout<<"\t"<<current->data;// we printing out the parent
	    if(current->right!=NULL)
	 	{	
		 q.push(current->right);//8 3 10; 
	    }
		if(current->left!=NULL)// we queueing its children
	 	{  
		 q.push(current->left);// 8 3 
     	}
	 	q.pop();//8 3 10
	 	flag=0;
	 }
	 }// while loop ends print 8 3 10  
}*/

void zigzag(node * root)
{
	if(root == NULL)
	return ;
	stack<node *> s1;
	stack<node *> s2;
	s1.push(root);
	bool ltr=true;
	
	/*onyl when level chnages ill change the bool ltr state upuntil ill only follow if current is empty or not the moment 
	it is empty ill go from right to left making ltr false and ill swap the the cuurent with next next contains childrens in particular level */
	while(!s1.empty())
	{
		node * temp = s1.top();
		s1.pop();// head node popped
		if(temp)
		{  cout<<"\t"<<temp->data;
				if(ltr)
			{	if(temp->right!=NULL)
				s2.push(temp->right);
				if(temp->left!=NULL)
				s2.push(temp->left);
				
			}
			else// while going right to left
			{
			if(temp->left!=NULL)
				s2.push(temp->left);
				if(temp->right!=NULL)
				s2.push(temp->right);
			}
		}
		if(s1.empty())// when one level is done that means stack one is empyt
		// so bascially s1 is for popping and printing and staxk 2 is for storing childrens of that level
		{
		  ltr=!ltr;
		  /* ltr continues unless entire level node are not collected in s2 
		  s2 getting filled with children node one by one based on node  in s1
		  so if s1 has node 1 at top it will fill in node 1 chidlren in s2 and pops node 1 out
		  simillary now node 2 emenet is at the top nand now the it will fill in the node 2 children in s2
		  node 3 at the top and now ode 3 children in the s2 by here ltr is true only since abi tak the s1 was not empty
		  now since node 3 is out s1 is empty all its succeeding nodes are collected in the s2 
		  and now time we so from right to left for the next level so truen ltr as false*/
       // repeat the procedur efo rthe next level eleemnst butr swapping s1 with s2 
          swap(s1,s2);// once level 1 element is printed than s1 empty by that time the childrens node of the next level is stored in s2 so bring it to stack 2 for printing by that time again collect the level 3 children in stack 2			

		}
	}
}

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
		printf("\n 1: insert \n 2: display_pre \n 3: display_in \n 4: display_post \n 5: delete element\n 6: delete tree \n 7:zigzag \n 8:level \n");		scanf("%d",& c);
		switch(c)
		{
			case 1:printf("\n enter the value \n ");
					scanf("%d",& data);
					tree= insert(tree,data);
					cout<<"\n node"<<tree<<endl;
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
			case 7: zigzag(tree);
			break;
			case 8 : level(tree);
			break;
		}
    }
    
}/*
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
*/
 node * insertnode(int data)
 {
 	node * temp=new node;
 	temp->data=data;
 	temp->right=temp->left=NULL;
 	return temp;
 }
 
 node * insert(node *root,int data)
 {
 	if(root==NULL)
 	 root= insertnode(data);
 	else if(data<root->data)
 	root->left=insert(root->left,data);
 	else
 	root->right=insert(root->right,data);
 	return root;
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
		printf("tree is empty");
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
		printf("tree is empty");
	}	
}
void pos(node * tree)
{
	
		if(tree!=NULL)
		{
	 pos(tree->left);
	pos(tree->right);	
	cout<<tree->data<<" ";
		}
}
node * findmin(node * tree)
{
	if(tree==NULL)
	return tree;//tree is empty
	while(tree->left!=NULL)
	tree=tree->left;
	printf("\n %d is the smallest element",tree->data);
	return tree;
}
node * del(node* tree ,int data)
{ cout<<tree->data<<" \t"<<tree<<endl<<endl;;
	if   (tree==NULL)
	return tree;
	else if(data<tree->data)// this tree is always pointing to root
	tree->left=del(tree->left,data);//since if one left node is deleted the left tree address will chnage will update the new address int the tree left address
    else if(data>tree->data)
	tree->right=del(tree->right,data);
	else
	{
	 	//got the data to be deleted
	 	//case 1: no child
	 	if(tree->right==NULL&& tree->left==NULL)
	 	{
	 	delete tree;//deallocate memory in c use free function NOW  tree is a dangling pointer 
	 	tree=NULL;// now its not
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

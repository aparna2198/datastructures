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
node * tree=NULL;

void  mirror(node * ref)
{
	if(ref== NULL)
	return ;
	else
	{
		struct node * temp;
		// for subtrees we use recrusive call;
		mirror(ref->left);
		mirror(ref->right);
		
		temp =ref->left;// temp=2
		ref->left=ref->right;// 
		ref->right=temp;
	}
	/*
	it basically is left node to right node switch done by swap fucntion 
	*/
}

//pointer to tree
/*void zizagtraversal(struct node* root) 
{ 
    // if null then return 
    if (!root) 
        return; 
  
    // declare two stacks 
queue<struct node*> currentlevel; 
queue<struct node*> nextlevel; 
  
    // push the root 
    currentlevel.push(root); 
  
    // check if stack is empty    
    bool lefttoright = true; 
    while (!currentlevel.empty()) { 
  
        // pop out of stack 
        struct node* temp = currentlevel.front(); 
        currentlevel.pop(); 
  
        // if not null 
        if (temp) { 
  
            // print the data in it 
            cout << temp->data << " "; 
  
            // store data according to current 
            // order. 
            if (lefttoright) { 
                if (temp->left) 
                    nextlevel.push(temp->left); 
                if (temp->right) 
                    nextlevel.push(temp->right); 
            } 
            else { 
                if (temp->right) 
                    nextlevel.push(temp->right); 
                if (temp->left) 
                    nextlevel.push(temp->left); 
            } 
        } 
  
        if (currentlevel.empty()) { 
            lefttoright = !lefttoright; 
            swap(currentlevel, nextlevel); 
        } 
    } 
}*/ 
/* algo is
1 take two stacks since they work on last in first out unlike queue last in last out
2  push root into 1st stack 
3 take bool variable lefttoright true will toggle its value evry time when 1st stack is empty
4  see stack is empty no bcoz we pushed the root in it bniw while it up until it is empty
5 print 1st stack and pop that element
6 2nd stack is for childrens of elements stored in 1st stack basically elements of next level 
7 s1 is empty that means one level complete, toggle lefttoright, swap this s2 ele to s1 ele   
8 repeat 
*/

void zigzag(node * root)
{
	if(root==NULL)
	return ;
stack<node *>s1;
stack<node *>s2;
 s1.push(root);
 bool ltr=true;
 while(!s1.empty())
 {
 	node * temp=s1.top();
 	cout<<temp->data<<" ";
 	s1.pop();
     if(ltr)
     {
     	if(temp->left!=NULL)
     	s2.push(temp->left);
     	if(temp->right!=NULL)
     	s2.push(temp->right);
	 }
	 else
	 {      if(temp->right!=NULL)
         	s2.push(temp->right);
     		if(temp->left!=NULL)
     	    s2.push(temp->left);
	 	
	 }
	 
	 if(s1.empty())
	 {
	 	ltr=!ltr;
	 	swap(s1,s2);
	 }
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
/*void levelorder(node * root)
{
	//if my root is null return
if(root==NULL) return ;
 //ill make a queue   consisting of node elements  because ill be storing the node childrens in them

queue<node*> q;

q.push(root);// first i pushes the root node

while(!q.empty())
{// checked if queue is empty or not
node * current= q.front();// took front in current since ill be popping out queue
cout<<current->data<<"  ";
q.pop();
if(current->left!=NULL)
{
q.push(current->left);// left rigth into the queue
}
if(current->right!=NULL)
{
q.push(current->right);
}
}
}*/


void  levelorder(node * root)
{
	if(root==NULL)
	return ;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
	 node * current=q.front();
	 cout<<current->data<<"  ";
	 q.pop();
	 if(current->left!=NULL)
	 q.push(current->left);
	 if(current->right!=NULL)
	 q.push(current->right);
	}
}
node * insert(node * ,int);
void pre(node*);
void in(node*);
void pos(node *);
node * del(node*,int);
node * deletetree(node*);
void interative_pre(node * root)
{
	if(root==NULL)
    cout<<"no elements in the tree";
	stack<node *> s;
	s.push(root);
	while(!s.empty())
	{
		node * temp=s.top();
		cout<<temp->data<<" ";
		s.pop();
		if(temp->right!=NULL)
		s.push(temp->right);
		if(temp->left!=NULL)	
		s.push(temp->left);
	}
}

void interative_pre(node * root)
{
	if(root==NULL)
    cout<<"no elements in the tree";
	stack<node *> s;
	s.push(root->left);
	while(!s.empty())
	{
		node * temp=s.top();
		cout<<temp->data<<" ";
		s.pop();
		if(temp->right!=NULL)
		s.push(temp->right);
		if(temp->left!=NULL)	
		s.push(temp->left);
	}
}

int main()
{//node * ptr;
	int c,data;
    tree=NULL;// tree is the node type p ointer var created global null meaning tree is empty
	while(1)
	{
		printf("\n 1: insert \n 2: display_pre \n 3: display_in \n 4: display_post \n 5: delete element\n 6: delete tree \n 7:level \n 8:zizagtraversal \n 9:mirror \n 10:predorder iterative method");
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
			case 7: levelorder(tree);
			break;
			case 8:zigzag(tree);
			break;
			case 9: mirror(tree);
			break;
			case 10:interative_pre(tree);
			break;
			case 11: interative_in(tree);
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

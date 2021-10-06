 #include<iostream>
 #include<queue>
 using namespace std;
 struct node {
 	int data;
 	node * left ,* right;
 };
 node * root;
 
node * newnode(int data)
{
	node * temp= new node;
	temp->data = data;
	temp->left =temp->right=NULL;
	return temp;
}

node * insert ( node * temp,int data)
{ if(temp==NULL)
  temp=newnode(data);
  else if(data<temp->data)
  temp->left = insert(temp->left,data);
  else
  temp->right=insert(temp->right,data);
  return temp;
}

void levelorder(node * temp)
 {  if (temp==NULL) return ;
 	queue<node *> q;
 	
    q.push(temp);
    
    while(!q.empty())
    { node * i=q.front();
    	cout<<i->data<<"  ";
    	q.pop();
    	if(i->left !=NULL)
    	q.push(i->left);
    	if(i->right !=NULL)
    	q.push(i->right);
	}
 }
 
 
 
 
 
 node * deleteroot(node *)
 {
 	
 }
 node * findmin(node *temp)
 { if(temp==NULL)
 return temp;
 else
 while(temp->left!=NULL)
 {
 	temp=temp->left;
 }
 return temp;	
 }
 
node * del(node * temp  ,int data)
 {
 	 if(temp==NULL) return temp;
 	 else if(temp->right==NULL)
 	 temp->left=del(temp->left,data);
 	 else if(temp->left==NULL)
 	 temp->right= del(temp->right , data);
 	 else
 	 {
 	 	if(temp->left== NULL && temp->right==NULL)
 	 	{
 	 		delete(temp);
		}
		else if(temp->left==NULL)
		{
			node * s=temp;
			temp=temp->right;
			delete(s);
		}
		else if(temp->right==NULL)
		{
			node * s=temp;
			temp=temp->left;
			delete(s);
		}
		else
		{
			node * s=findmin(temp->right);
			temp->data=s->data;
			temp->right=del(temp->right,s->data);
		}
	 }
	 return temp;
 }
 
 
 
 
 
 
 
int main()
{//node * ptr;
	int c,data;
    root=NULL;// root is the node type p ointer var created global null meaning root is empty
	while(1)
	{
		printf("\n 1: insert \n 2: display_pre \n 3: display_in \n 4: display_post \n 5: delete element\n 6: delete root \n 7:level \n 8:zizagtraversal \n");
		scanf("%d",& c);
		switch(c)
		{
			case 1:printf("\n enter the value \n ");
					scanf("%d",& data);
					root= insert(root,data);
			break;
		
			case 5:printf("\n enter the element you want to delete");
					scanf("%d",&data);
			 		root=del(root,data);
			break;
			case 6: root=deleteroot(root);
			break;
			case 7: levelorder(root);
			break;
		
		}
    }
    
}

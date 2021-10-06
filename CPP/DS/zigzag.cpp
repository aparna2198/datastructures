#inclue<iostream>
#include<stack>
using namespace std;

node * zigzag(node * tree)
{
	if(tree==NULL)
	return ;
	stack<node*>s1;
	stack<node*>s2;
	s1.push(tree);
	bool ltr=true;
	while(!s1.empty())
	{
		node * temp=s1.top();
		s1.pop();
		cout<<temp->data;
		if(ltr)
		{
			if(temp->right!=NULL)
			s2.push(temp->right);
			if(temp->left!=NULL)
			s2.push(temp->left);
		}
		else
		{	
		    if(temp->left!=NULL)
			s2.push(temp->left);
			if(temp->right!=NULL)
			s2.push(temp->right);
			
		}
		
		if(s1.empty())// one level is complete
		{
			ltr=!ltr;
			swap(s1,s2);
		}
	}


}

node * findmin(node* tree)
{
	if(tree==NULL)
	return 0;
	while(tree->left!=NULL)
	{
		tree=tree->left;
	}
	return tree;
}
node * del(node * tree,int data)
{
	if(tree==NULL)
	return tree;
	else if(data<tree->data)
	tree->left=del(tree->left,data);
	else if(data>tree->data)
	tree->right=del(tree->right,data);
	else
	{
		//  i found the data and the address of the data now m suppose to delet there are three possibilitis it has no children it has onechidren it has children of children 
		if(tree->right==NULL && tree->left ==NULL)
		{
			delete tree;
			tree=NULL;
		}
		else if(tree->left==NULL)
		{
			node * temp=tree;
			tree=temp->right;
			delete temp;
		}
		else if(tree->right==NULL)
		{
			node * temp= tree;
			tree=temp->left;
			delete temp;
		}
		else
		{
			node * temp=findmin(tree->right);
			tree->data=temp->data;
			tree->right=del(tree->right,temp->data);
		}
		
	}
}

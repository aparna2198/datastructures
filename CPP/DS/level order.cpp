node* levelorder(node*tree)
{
	if(tree==NULL)
	return 0;
	queue<node *>q;
	q.push(tree);
	while(!q.empty())
	{
		node * temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
		q.push(temp->left);
		if(temp->right!=NULL)
		q.push(temp->right);
	}
}

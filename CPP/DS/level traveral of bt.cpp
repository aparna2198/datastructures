#include<stdio.h>
#include<stdlib.h>		// will search in standard folder
#include <queue>		// will first search in current directory or folder  and then standard folder
// if< queue.h> gives out error as when used <> it directly 
//searched into standard library without even looking at current folder
// when used "iostream" it first searches into current folder if not founf then goes to the standara folder 
// so doesnt get anyy error as if finds itself in standar folder 
// so" goes from currentfoder---> standardfolder  whereas the <> directy goed to standard 

using namespace std;

 struct nodeTemp
{
   int data;
   nodeTemp *left;
   nodeTemp *right;
};

 nodeTemp *tree;	
//pointer to tree
void levelorder ( nodeTemp * root)
{
  if (root == NULL)
    return;
  // since i have included the queue header i can create queue of any type
  queue <  int > *q;	// so i create a queue with pointer to nodeTemp

}

nodeTemp *insert (nodeTemp *, int);
void pre (nodeTemp *);
void in (nodeTemp *);
void pos (nodeTemp *);
nodeTemp *del (nodeTemp *, int);
nodeTemp *deletetree (nodeTemp *);
int main ()
{				//nodeTemp * ptr;
  int c, data;
  tree = NULL;			// tree is the nodeTemp type p ointer var created global null meaning tree is empty
  while (1)
    {
      printf
	("\n 1: insert \n 2: display_pre \n 3: display_in \n 4: display_post \n 5: delete element\n 6: delete tree");
      scanf ("%d", &c);
      switch (c)
	{
	case 1:
	  printf ("\n enter the value \n ");
	  scanf ("%d", &data);
	  tree = insert (tree, data);
	  break;
	case 2:
	  printf ("\n the elements preorder are \n");
	  pre (tree);
	  break;
	case 3:
	  printf ("\n the elements inorder are \n");
	  in (tree);
	  break;
	case 4:
	  printf ("\n tree elements in posorder \n");
	  pos (tree);
	  break;
	case 5:
	  printf ("\n enter the element you want to delete");
	  scanf ("%d", &data);
	  tree = del (tree, data);
	  break;
	case 6:
	  tree = deletetree (tree);
	  break;
	}
    }

}

nodeTemp *
newnodeTemp (int data)
{
  nodeTemp *temp = (nodeTemp *) malloc (sizeof (nodeTemp));	//NEW element  inserted assign memory
  temp->data = data;
  temp->right = temp->left = NULL;
  return temp;
}

nodeTemp *
insert (nodeTemp * tree, int data)
{
  if (tree == NULL)
    tree = newnodeTemp (data);
  else if (data < tree->data)
    tree->left = insert (tree->left, data);
  else
    tree->right = insert (tree->right, data);
  return tree;
}

/*nodeTemp * insert(nodeTemp * tree,int data)
{ 
nodeTemp * ptr,*nodeTempptr,*parentptr;
ptr=(nodeTemp*)malloc(sizeof(nodeTemp));
ptr->data=data;
ptr->left=NULL;
ptr->right=NULL;
if(tree==NULL)
{
	tree=ptr;
	tree->left=NULL;
	tree->right=NULL;
	printf("\n root nodeTemp created successfully");
}
else
{
	parentptr=NULL;
	nodeTempptr=tree;
	while(nodeTempptr!=NULL)//up until nodeTempptr is not null tree is not empty follow loop
	{
		parentptr=nodeTempptr;//whatever there in tree assign to parent previous exiting elements will become parent
        if(data<nodeTempptr->data)
	    nodeTempptr=nodeTempptr->left;
		else
		nodeTempptr=nodeTempptr->right;		
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

void
pre (nodeTemp * tree)
{
  if (tree != NULL)
    {
      printf (" \n %d", tree->data);
      pre (tree->left);
      pre (tree->right);
    }
  else
    {
      //printf("tree is empty");
    }
}

void
in (nodeTemp * tree)
{
  if (tree != NULL)
    {
      in (tree->left);
      printf ("\n %d", tree->data);
      in (tree->right);
    }
  else
    {
      //printf("tree is empty");
    }
}

void
pos (nodeTemp * tree)
{
  if (tree != NULL)
    {
      pos (tree->left);
      pos (tree->right);
      printf ("\n %d", tree->data);
    }
  else
    {
      //printf("tree is empty");
    }
}

nodeTemp *
findmin (nodeTemp * tree)
{
  if (tree == NULL)
    return tree;		//tree is empty
  while (tree->left != NULL)
    tree = tree->left;
  printf ("\n %d is the smallest element,tree->data");
  return tree;
}

nodeTemp *
del (nodeTemp * tree, int data)
{
  if (tree == NULL)
    return tree;
  else if (data < tree->data)
    tree->left = del (tree->left, data);	//since if one left nodeTemp is deleted the left tree address will chnage will update the new address int the tree left address
  else if (data > tree->data)
    tree->right = del (tree->right, data);
  else
    {
      //got the data to be deleted
      //case 1: no child
      if (tree->right == NULL && tree->left == NULL)
	{
	  delete tree;		//deallocate memory in c use free function
	  tree = NULL;
	}
      //CASE 2: one child
      else if (tree->left == NULL)
	{
	  nodeTemp *temp = tree;
	  tree = tree->right;
	  delete temp;
	}
      //case 3:one child
      else if (tree->right == NULL)
	{
	  nodeTemp *temp = tree;
	  tree = tree->left;
	  delete temp;
	}
      //case 3: two child
      else
	{
	  nodeTemp *temp = findmin (tree->right);
	  tree->data = temp->data;
	  tree->right = del (tree->right, temp->data);
	}
      return tree;
    }
  printf (" \n item successfully deleted");
}

nodeTemp *
deletetree (nodeTemp * tree)
{
  if (tree != NULL)
    {
      deletetree (tree->left);
      deletetree (tree->right);
      delete tree;
    }
  printf ("\n tree successfully deleted");

}

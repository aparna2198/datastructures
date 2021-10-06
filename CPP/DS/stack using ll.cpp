/*
// C program to Implement a stack 
//using singly linked list 
#include <bits/stdc++.h>  
using namespace std; 
  
// Declare linked list node 
  
struct Node { 
    int data; 
    struct Node* link; 
}; 
struct Node* top; 
  
// Utility function to add an element data in the stack 
 // insert at the beginning 
void push(int data) 
{ 
    // create new node temp and allocate memory 
    struct Node* temp; 
    temp = new Node(); 
  
    // check if stack (heap) is full. Then inserting an element would 
    // lead to stack overflow 
    if (!temp) { 
        cout << "\nHeap Overflow"; 
        exit(1); 
    } 
  
    // initialize data into temp data field 
    temp->data = data; 
  
    // put top pointer reference into temp link 
    temp->link = top; 
  
    // make temp as top of Stack 
    top = temp; 
} 
  
// Utility function to check if the stack is empty or not 
int isEmpty() 
{ 
    return top == NULL; 
} 
  
// Utility function to return top element in a stack 
int peek() 
{ 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(1); 
} 
  
// Utility function to pop top  
// element from the stack 
  
void pop() 
{ 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        cout << "\nStack Underflow" << endl; 
        exit(1); 
    } 
    else { 
        // top assign into temp 
        temp = top; 
  
        // assign second node to top 
        top = top->link; 
  
        // destroy connection between first and second 
        temp->link = NULL; 
  
        // release memory of top node 
        free(temp); 
    } 
} 
  
// Function to print all the  
// elements of the stack  
void display()  
{ 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        cout << "\nStack Underflow"; 
        exit(1); 
    } 
    else { 
        temp = top; 
        while (temp != NULL) { 
  
            // print node data 
            cout <<  temp->data << " "; 
  
            // assign temp link to temp 
            temp = temp->link; 
        } 
    } 
} 
  
// Driver Code 
int main()
{
int c,data;

while(1)
{
cout<<"\n select \n 1: insert the node \n 2: print the list \n 3: delete \n";
cin>>c;

switch (c)
{
	case 1: cout<<"\n enter the element \t";
	        cin>> data;
	 push(data);
	break;
	case 2: display();
	break;
	case 3: pop();
	break;
}	
}
return 0;
}*/
#include<iostream>
#include<stdlib.h>
using namespace std;
// lik list means storing data in the form of nodes
// follow stack rules l ifo and implement using single link list nodes
//a ll operations using top variable
struct node{
	int data;
	node * link;
};
node * top=NULL;// global variable default value is null
void push()
{int data;
	node * temp;
	temp=new node();// suppose temp me 1000 aya now 1000 me i want to place my data therfore temp->data
	if(!temp)
	cout<<"\n overflow \n";
	cout<<"\n enter the node data \n";
	cin>>temp->data;
	temp->link =top;
	top=temp;
		/*if u do this then the node will point iteself there wont be any connection between the node the previous node 
		top=temp;
		temp->link =top;
			*/
	
}
void pop()
{
	node * temp;
	
	if(top==NULL)
	cout<<"\n empty \n";
	else
	{
	temp=top;
	cout<<"deleted \t "<<temp->data;
	top=temp->link ;//left side top was pointing to this node traverse no left side connection
	temp->link=NULL;//right side the node was pointing to the previous node no right side connection
	free(temp);
	} 
}
void tra()
{node * temp;

if(top==NULL)
{	cout<<"\n empty \n";
}
else
{temp=top;
	while(temp!=NULL)
	{
		cout<<"\t"<<temp->data;
		temp=temp->link;// print and traverse
	}
}
}
int main()
{
int c;

while(1)
{
cout<<"\n select \n 1: insert the node \n 2: print the list \n 3: delete \n";
cin>>c;

switch (c)
{
	case 1: push();
	break;
	case 2: tra();
	break;
	case 3: pop();
	break;
}	
}
return 0;
}

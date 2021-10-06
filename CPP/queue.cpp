#include<stdio.h>

struct queue
{
int front,rear;
int c;//capacity
int * array;	
};

node * create( int x)
{
	node *q ;
	q=malloc(sizeof(struct queue));
	q->capacity=x;
	q->front=q->rear=-1;//queue is empty
	q->array=malloc(q->capacity*sizeof(int));
	if(!q->array)
	{
		return (NULL);
	}
	return q;
}

int isfull(queue*q)
{
	return ((q->rear+1)%capacity==q->front);
}

int size()
{
	
}

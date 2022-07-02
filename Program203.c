/* 	*****************PROBLEMS ON Data Structure**************************
					LINKED LIST
STATEMENT: Singly linear linked list (dynamic memory allocation)
Input: 
Output:

p=100
q=200
&p=200
&q=300
p->data =11
p->next =null
*q =100
(*q)->data =11
(*q)->next=null;

**********************************************************************************
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next; //self referntial structure
}; //12 byte size of structure

typedef struct node NODE; //struct node ->NODE
typedef struct node * PNODE; //struct node * ->PNODE
typedef struct node ** PPNODE; //struct node ** ->PPNODE


int main()
{
	PNODE p=NULL;
	PPNODE q=NULL;
	
	p=(PNODE)malloc(sizeof(NODE));
//  p=(struct node *) malloc(sizeof(struct node));

	q=&p;
	
	
	return 0;
}
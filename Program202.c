/* 	*****************PROBLEMS ON Data Structure**************************
					LINKED LIST
STATEMENT: Singly linear linked list
Input: 
Output:

p=100
q=200
&p=200
&q=300
p->data =11
p->next =null
*p =100

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
	NODE obj;
	obj.data=11;
	obj.next=NULL;
	
	PNODE p=NULL;
	p=&obj;
	
	PPNODE q=NULL;
	q=&p;
	
	return 0;
}
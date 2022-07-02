/* 	*****************PROBLEMS ON Data Structure**************************
					LINKED LIST
STATEMENT: Singly linear linked list
Input: 
Output:
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
	PNODE first=NULL; //struct node * first=NULL;
	
	
	return 0;
}
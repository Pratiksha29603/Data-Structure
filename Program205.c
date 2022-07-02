/* 	*****************PROBLEMS ON Data Structure**********************************************
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

********************************************************************************************
*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE; // poniter
typedef struct node ** PPNODE;  // poniter to pointer


void InsertFirst(PPNODE Head, int no)
{
	PNODE newn=NULL;
	
	//step 1: allocate memory
	newn=(PNODE)malloc(sizeof(NODE));
	
	//step 2: initialize the node
	newn->data=no;
	newn->next=NULL;
	
	//step 3: insert node
	if(*Head==NULL) // LL is empty
	{
		*Head=newn; //100
	}
	else      // LL contains atleast one node
	{
		newn->next=*Head; //100
		*Head=newn;  //200
	}
}

void InsertLast(PPNODE Head, int no)
{
	PNODE newn=NULL;
	PNODE temp= *Head;
	//step 1: allocate memory 
	newn=(PNODE)malloc(sizeof(NODE));
	
	//step 2: initialize the node
	newn->data=no;
	newn->next=NULL;
	
	//step 3: insert node
	if(*Head==NULL) // LL is empty
	{
		*Head=newn;
	}
	else      // LL contains atleast one node
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	
}

void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("%d\t",Head->data);
		Head=Head->next;
	}
}

int Count(PNODE Head)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp=*Head;
	
	if(*Head!=NULL) //if LL containts atleast one node
	{
		*Head=(*Head)-> next;
		free(temp);
	}
	
}

void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	if(*Head==NULL) //LL is empty
	{
		return;
	}
	else if((*Head)->next==NULL) // LL contains one node
	{
		free(*Head);
		*Head=NULL;
	}
	else // LL contains more than one node
	{
		while(temp->next->next != NULL)
		{
			temp=temp->next;
			
		}
		free(temp->next);
		temp->next=NULL;
	}
	
}	

int main()
{
	PNODE first=NULL;
	
	int iRet=0;
	InsertFirst(&first,101); //InsertFirst(50,11);
	InsertFirst(&first,51); //InsertFirst(50,51); 50 is address of first
	InsertFirst(&first,21); //InsertFirst(50,21);
	InsertFirst(&first,11); //InsertFirst(50,11);
	
	InsertLast(&first,111); //InsertFirst(50,11);
	Display(first);
	
	iRet=Count(first);
	printf("\n no of elements are:%d\n",iRet);
	
	DeleteFirst(&first);
    Display(first);
    
    iRet = Count(first);
    
    printf("\nNumber of elements are: %d\n", iRet);
	
	DeleteLast(&first);
    Display(first);
    
    iRet = Count(first);
    
    printf("\nNumber of elements are: %d\n", iRet);
	return 0;
}


/*
  void InsertFirst(PPNODE Head, int no);            // he 6 fuction kahich return krt nht mhanun return type void
  void InsertLast(PPNODE Head, int no);		        thevla aahe. aani he 6 function linked list mdhye changes
  void InsertAtPos(PPNODE Head, int no, int pos);	krtat mhanun parameter address pathavla aahe PPNODE ha pointer
											         to pointer aahe.
  
  void DeleteFirst(PPNODE Head);			  //detete krtana data chi grj nste 
  void DeleteLast(PPNODE Head);
  void DeleteAtPos(PPNODE Head, int pos);      // hya fun mdhye position dyavi lagnar
	
  void Display(PNODE Head);
  int Count(PNODE Head);

*/
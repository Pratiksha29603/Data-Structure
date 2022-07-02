/* 	*****************PROBLEMS ON Data Structure**********************************************
					LINKED LIST
STATEMENT: doubly linear linked list (dynamic memory allocation) 
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

 typedef struct node
 {
    int data;
    struct node *next;
    struct node *prev;         //Underline
 }NODE, * PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    //step 1: allocate memory
    PNODE newn = NULL;   
    newn = (PNODE)malloc(sizeof(NODE));
    
    //step 2: initialize the node
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;            //Underline
    
    //step 3: insert node
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        (*Head) -> prev = newn;   //important line for Doubly LinkList
        
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int no)
{
    //step 1: allocate memory
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));
    
    //step 2: initialize the node
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;            //Underline
    
    //step 3: insert node
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp-> next = newn;
        newn-> prev = temp;
    }
}

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

DeleteFirst(PPNODE Head)
{

	PNODE temp=*Head;
	if(*Head!=NULL)//LL contains at least one node
	{
		*Head=(*Head)->next;
		free(temp);
		if(*Head!=NULL)
		{
			(*Head)->prev=NULL;
		}	
	}
}

DeleteFirstX(PPNODE Head)
{
	if(*Head==NULL)
	{
		return;
	}
	else if(*Head->next==NULL)
	{
		free(*Head)
		*Head=NULL;
	}
	else
	{
		*Head=*Head->next;
		free(*Head->prev);
		*Head->prev=NULL;
	}
}

DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	if(*Head==NULL)
	{
		return;
	}
	else if(*Head->next==NULL)
	{
		free(*Head)
		*Head=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
		
	}
}

void InsertAtPos(PPNODE Head, int no, int ipos)
{
	int size=Count(*Head),i=0;
	PNODE temp=*Head;
	
	if((ipos<1)||(ipos>size+1))
	{
		printf("invalid position\n");
		return;
	}
	
	if(ipos==1)
	{
		InsertFirst(Head,no);
	}
	else if(ipos==size+1)
	{
		InsertLast(Head,no);
	}
	else
	{
		newn =(PNODE)malloc(sizeof(NODE));
		
		newn->next=NULL;
		newn->prev=NULL;
		newn->data=no;
		
		for(i=1;i<ipos;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		newn->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
	}
}

DeleteAtPos(PPNODE Head, int pos)
{
	int size=Count(*Head),i=0;
	PNODE temp=*Head;
	if((ipos<1)||(ipos>size))
	{
		printf("invalid position\n");
		return;
	}
	
	if(ipos==1)
	{
		InsertFirst(Head);
	}
	else if(ipos==size+1)
	{
		InsertLast(Head);
	}
	else
	{
		
		for(i=1;i<ipos;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		free(temp->next->prev);
		temp->next->prev=temp;
		
	}
	


}

int main()
{
    PNODE first = NULL;
    int iCnt= 0;
    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);
    
    InsertLast(&first,101);
    
    Display(first);
    
    iCnt= Count(first);
    printf("Number of Elements are: %d\n",iCnt);
    
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
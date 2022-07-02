/* 	*****************PROBLEMS ON Data Structure**********************************************
					LINKED LIST
STATEMENT: Singly linear linked list (dynamic memory allocation) menu driven application
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
}NODE, * PNODE, **PPNODE;

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head -> next;
    }
    
    printf(" NULL\n");
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

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = no;
    newn->next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = no;
    newn->next = NULL;
    
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
        temp->next = newn;
    }
    
}


void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    
    if(*Head != NULL)
    {
        *Head = (*Head)->next;
        free(temp);
    }
    
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) ->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    
}

void InsertAtPos(PPNODE Head, int no, int pos)
{
	int size=0,i=0;
	
	PNODE newn=NULL;
	PNODE temp=*Head;
	size=Count(*Head);
	
	if((pos<1)||(pos>size+1)) //Filter for invalid position
	{
		printf("Invalid Position\n");
		return;
	}
	
	if(pos==1)//first position
	{
		InsertFirst(Head,no);
	}
	else if(pos==size+1) //last position
	{
		InsertLast(Head,no);
	}
	else  				//inbetween position
	{
		newn=(PNODE)malloc(sizeof(NODE));
		
		newn->data=no;
		newn->next=NULL;
		
		for(i=1;i<(pos-1);i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}

}


void DeleteAtPos(PPNODE Head, int pos)
{
	int size=0,i=0;
	PNODE targeted=NULL;
	PNODE temp=*Head;
	size=Count(*Head);
	
	if((pos<1)||(pos>size)) //Filter for invalid position
	{
		printf("Invalid Position\n");
		return;
	}
	
	if(pos==1)//first position
	{
		DeleteFirst(Head);
	}
	else if(pos==size) //last position
	{
		DeleteLast(Head);
	}
	else  				//inbetween position
	{
		for(i=1;i<(pos-1);i++)
		{
			temp=temp->next;
		}
		targeted=temp->next;
		temp->next=targeted->next;
		free(targeted);
	}

}

int main()
{
	PNODE first=NULL;
	
	int iChoice=1, iValue=0,iRet=0,iPos=0;
	
	while(iChoice!=0)
	{
		printf("\n*******************Welcome*******************************************\n");
		printf("Enter The Desired Operation that you want to perform on linked list\n");
		printf("1:Insert the node at first Position\n");
		printf("2:Insert the node at Last Position\n");
		printf("3:Insert the node at desired Position\n");
		printf("4:Delete the node at first Position\n");
		printf("5:Delete the node at Last Position\n");
		printf("6:Delete the node at Desired Position\n");
		printf("7:Display the contents in Linked List\n");
		printf("8:Count the Number of nodes in Linked List\n");
		printf("0:Terminate The Application\n");
		scanf("%d",&iChoice);
		printf("\n**********************Thank You******************************************\n");
	
		switch(iChoice)
		{
			case 1:
				printf("Enter the data to insert\n");
				scanf("%d",&iValue);
				InsertFirst(&first,iValue);
				break;
				
			case 2:
				printf("Enter the data to insert\n");
				scanf("%d",&iValue);
				InsertLast(&first,iValue);
				break;
				
			case 3:
				printf("Enter the data to insert\n");
				scanf("%d",&iValue);
				printf("Enter the Position\n");
				scanf("%d",&iPos);
				InsertAtPos(&first,iValue, iPos);
				break;

			case 4:
				DeleteFirst(&first);
				break;

			case 5:
				DeleteLast(&first);
				break;
				
			case 6:
				printf("Enter the Position\n");
				scanf("%d",&iPos);
				DeleteAtPos(&first,iPos);
				break;
				
			case 7:
				printf("Elements of LinkedList are\n");
				Display(first);
				break;

			case 8:
				iRet=Count(first);
				printf("Number of Elements are:%d\n",iRet);
				break;
				
			case 0:
				break;	
				
			default:
				printf("Please Enter Proper Choice\n");
				break;
		}
	
	}
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
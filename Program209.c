/*
*********************PROBLEMS ON Data Structure*******************************
					         LINKED LIST
  STATEMENT: Doubly linear linked list (dynamic memory allocation) 
             menu driven application
  Input: 
  Output:

******************************************************************************
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

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    
    if(*Head != NULL)          //LinkList Contain Atleast One Node
    {
        *Head = (*Head)-> next;
        free(temp);
        if(*Head != NULL)
        {
            (*Head)->prev = NULL;
        }
    }
}

void DeleteFirstX(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if ((*Head)-> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)-> next;
        free((*Head)-> prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
   PNODE temp = *Head;    
   if(*Head == NULL)
    {
        return;
    }
    else if ((*Head)-> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        
        temp -> prev -> next = NULL;   //important
        free(temp);
    } 
}

void InsertAtPos(PPNODE Head, int no, int iPos)
{
    int size = Count(*Head);
    int i = 0;
    PNODE temp = *Head;
    PNODE newn = NULL;
    
    if((iPos < 1) || (iPos > size+1))
    {
        printf("Invalid Position\n");
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(Head, no);
    }
    else if(iPos == size+1)
    {
        InsertLast(Head, no);
    }
    else
    {
       newn = (PNODE) malloc (sizeof(NODE)); 
       
       newn->next = NULL;
       newn->prev = NULL;
       newn -> data = no;
       
       for(i=1; i < iPos-1; i++)
       {
           temp = temp -> next;
       }
       newn->next = temp->next;
       newn->next->prev =  newn;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int size = Count(*Head);
    int i = 0;
    PNODE temp = *Head;
    
    if((iPos < 1) || (iPos > size+1))
    {
        printf("Invalid Position\n");
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == size)
    {
        DeleteLast(Head);
    }
    else
    {
       for(i=1; i < iPos-1; i++)
       {
           temp = temp -> next;
       }
       temp -> next = temp -> next -> next;
       free(temp -> next -> prev);
       temp -> next -> prev = temp;
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
/* OUTPUT:

  |11| -> |21| -> |51| -> |11| -> NULL
  Number of Elements are: 4
*/
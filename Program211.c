
/********************* PROBLEMS ON Data Structure ******************************
					         LINKED LIST
  STATEMENT: Singly Circular linked list  in C
  Input: 
  Output:

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

    typedef struct node
    {
        int data;
        struct node *next;
        
    }NODE, *PNODE, **PPNODE;
    
    void Display(PNODE Head, PNODE Tail)
    {
        if((Head == NULL)&&(Tail == NULL))
        {
            return;
        }
        
        do
        {
            printf("|%d|->", Head->data);
            Head = Head->next;
        }while(Head != Tail->next);
        
        printf("\n");
    }
    
    int Count(PNODE Head, PNODE Tail)
    {
        int iCnt = 0;
        if((Head == NULL)&&(Tail == NULL))
        {
            return 0;
        }
        do
        {
            iCnt++;
            Head = Head->next;
        }while(Head != Tail->next);
        
        return iCnt;
    }
    
    void InsertFist(PPNODE Head, PPNODE Tail, int no)
    {
       PNODE newn = NULL;
       newn = (PNODE) malloc (sizeof(NODE));
       
       newn->data = no;
       newn->next = NULL;
       
       
       if((*Head == NULL)&&(*Tail == NULL))  //LL is Empty
       {
           *Head = newn;
           *Tail = newn;
       }
       else
       {
           newn -> next = *Head;   
           *Head = newn;
       }
       (*Tail) -> next = *Head;    // To Maintain Circular nature
    }
    void InsertLast(PPNODE Head, PPNODE Tail, int no)
    {
      PNODE newn = NULL;
       newn = (PNODE) malloc (sizeof(NODE));
       
       newn->data = no;
       newn->next = NULL;
       
       
       if((*Head == NULL)&&(*Tail == NULL))  //LL is Empty
       {
           *Head = newn;
           *Tail = newn;
       }
       else
       {
           (*Tail) -> next = newn;  
           (*Tail) = newn;
       }
       (*Tail) -> next = *Head;    // To Maintain Circular nature  
    }
    void InsertAtPos(PPNODE Head, PPNODE Tail, int no, int iPos)
    {
        
    }
    void DeleteFist(PPNODE Head, PPNODE Tail)
    {
       if((*Head == NULL)&&(*Tail == NULL))   // Empty node linked list
       {
           return;
       }
       else if(*Head == *Tail)                // single node linked list
       {
           free(*Head);
           *Head = NULL;
           *Tail = NULL;
       }
       else                                   // Multiple node linked list                             
       {
           *Head = (*Head)-> next;
           free((*Tail) -> next);
           (*Tail) -> next = *Head;
       }
    }
    void DeleteLast(PPNODE Head, PPNODE Tail)
    {
        PNODE temp = *Head;
        
        if((*Head == NULL)&&(*Tail == NULL))
       {
           return;
       }
       else if(*Head == *Tail)
       {
           free(*Head);
           *Head = NULL;
           *Tail = NULL;
       }
       else
       {
          while(temp -> next != *Tail)
          {
              temp = temp -> next;
          }
          free(*Tail);
          *Tail = temp;
          (*Tail) -> next = *Head;
       }
    }
    void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
    {
        
    }


     int main()
     {
         PNODE first = NULL;
         PNODE last = NULL;
         int iRet= 0;
         InsertFist(&first, &last, 51);
         InsertFist(&first, &last, 21);
         InsertFist(&first, &last, 11);
         
         InsertLast(&first, &last, 101);
         
         Display(first, last);
         iRet = Count(first, last);
         printf("Number of elements are :%d\n",iRet);
         
         DeleteFist(&first, &last);
         DeleteLast(&first, &last);
         
         Display(first, last);
         iRet = Count(first, last);
         printf("Number of elements are :%d\n",iRet);
         
         return 0;
     }
     
    /* OUTPUT:
    
        |11|->|21|->|51|->|101|->
        Number of elements are :4
        |21|->|51|->
        Number of elements are :2
    */
     
     
     
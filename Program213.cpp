 /********************* PROBLEMS ON Data Structure ******************************
					         LINKED LIST
  STATEMENT: Singly Circular linked list in C++
  Input: 
  Output:

*******************************************************************************/

 
 #include<iostream>
 using namespace std;
 
 typedef struct node
    {
        int data;
        struct node *next;
        
    }NODE, *PNODE;
    
    class SinglyCL
    {
        private:
         PNODE first;
         PNODE last;
         int size;
         
        public:
          SinglyCL()
          {
              first = NULL;
              last = NULL;
              size = 0;
          }
          
    void  Display()
    {
        PNODE temp = first;
        
        if(first == NULL && last == NULL)
        {
            return;
        }
       do
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp -> next;
        }while(temp != last-> next);
        
        cout<<"\n";
    }
    int Count()
    {
        return size;
    }
    void InsertFirst(int no)
    {
        PNODE newn = new NODE;
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        
        last -> next = first;
        size++;
    }
    void InsertLast(int no)
    {
       PNODE newn = new NODE;
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last -> next = newn;
            last = newn;
        }
        
        last -> next = first;
        size++;  
    }
    void InsertAtPos(int no, int iPos)
    {
       if((iPos < 1) || (iPos > (size+1)))    // Invalid Position
       {
           return;
       }
       if(iPos == 1)                         // first Position
       {
           InsertFirst(no);
       }
       else if(iPos == size+1)              //last Position
       {
           InsertLast(no);
       }
       else
       {
           PNODE newn = new NODE;
           
           newn-> data= no;
           newn->next = NULL;
           
           PNODE temp = first;
           
           for(int i=1; i< iPos-1; i++)
           {
               temp = temp-> next;
           }
           
           newn-> next = temp-> next;
           temp->next =newn;
           
           size++;
       }
    }
    void DeleteFirst(int no)
    {
         if((first == NULL) && (last == NULL))
         {
             return;
         }
         else if(first == last)
         {
            delete first;
            first = NULL;
            last = NULL;
         }
         else
         {
            first = first-> next;
            delete last -> next;
            last-> next = first;
         }
         size--;
    }
    void DeleteLast(int no)
    {
        PNODE temp = first;
       if((first == NULL) && (last == NULL))
         {
             return;
         }
         else if(first == last)
         {
            delete first;
            first = NULL;
            last = NULL;
         }
         else
         {
            while(temp->next != last)
            {
                temp = temp -> next;
            }
            
            delete last;
            last-> next = first;
         }
         size--; 
    }
    void DeleteAtPos(int iPos)
    {
      if((iPos < 1)||(iPos > size))  
      {
          return;
      }
      if(iPos == 1)
      {
          DeleteFirst();
      }
      else if(iPos == size)
      {
          DeleteLast();
      }
      else
      {
          PNODE temp = first;
          
          for(int i = 1; i < iPos-1; i++)
          {
              temp = temp -> next;
          }
          
          PNODE targated  = temp -> next;
          
          temp -> next = targated -> next;  //temp-> next = temp->next->next;
          delete targated;
          
          size--;
      }
    }
    
    };
    
    int main()
    {
        SinglyCL obj;
        int iRet = 0;
        
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.InsertLast(101);
        
        obj.InsertAtPos(55,4);
        
        obj.Display();
        iRet = obj.Count();
        cout<<"Number of elements are: "<<iRet<<"\n";
        
        obj.DeleteAtPos(4);
        
        obj.DeleteFirst();
        obj.DeleteLast();
        
        obj.Display();
        iRet = obj.Count();
        cout<<"Number of elements are: "<<iRet<<"\n";
        
        return 0;
    }
    
    /* OUTPUT:
    
        |11|->|21|->|51|->|101|->
        Number of elements are: 4
    */
    
    
    
    
    
    
    
    
    
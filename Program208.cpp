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

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE,**PPNODE;

class SinglyLL
{
	private:
		PNODE first;
		int size;
		
	public:
		SinglyLL()
		{
			first=NULL;
			size=0;
		}
		
		void InsertFirst(int no)
		{
			PNODE newn=new NODE;
			newn->data=no;
			newn->next=NULL;
			
			if(first==NULL)
			{
				first=newn;
			}
			else
			{
				newn->next=first;
				first=newn;
			}
			size++;
		}
		
		void InsertLast(int no)
		{
		
		}
		
		void InsertAtPos(int no, int ipos)
		{
		
		}
		
		void DeleteFirst(int no)
		{
		
		}
		
		void DeleteLast()
		{
		
		}
		
		void DeleteAtPos(int ipos)
		{
		
		}
		
		void Display()
		{
			PNODE temp=first;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
		
		int Count()
		{
			return size;
		}
};

int main()
{
	int iRet=0;
	SinglyLL obj;
	
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	
	obj.Display();
	
	iRet=obj.Count();
	cout<<"Number of elements are :"<<iRet<<"\n";
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
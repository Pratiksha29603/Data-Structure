/*
*********************PROBLEMS ON Data Structure*******************************
					         LinkedList
  STATEMENT: 
  Input: 1 2 3 4 5 
  Output: 15

******************************************************************************
*/
 #include<iostream>
 #include<stdio.h>
 
 using namespace std;
 
 typedef struct node
 {
	int data;
	struct node *next;
	
 }NODE,*PNODE,**PPNODE;
 
 void InsertFirst(PPNODE Head,int no)
 {
	PNODE newn=new NODE;
	newn->data=no;
	newn->next=NULL;
	
	if(*first==NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->next=*Head;
		*Head=newn;
	}
 }
 
 void Display(PNODE Head)
 {
	while(Head!=NULL)
	{
		cout<<"|"<<Head->data
	}
 }
 
 int main()
 {
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,101);
	InsertFirst(&first,11);
	InsertFirst(&first,01);
 }
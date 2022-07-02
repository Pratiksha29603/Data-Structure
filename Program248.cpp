/*
*********************PROBLEMS ON Tree*******************************
					       BST
  STATEMENT: 
  Input: 1 2 3 4 5 
  Output: 15

******************************************************************************
*/

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE Head, int no)
{
	PNODE newn=new NODE;
	
	newn->data=no;
	newn->lchild=NULL;
	newn->rchild=NULL; 
	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
	
		PNODE temp=*Head;
		
		while(1)  //unconditional loop for(;;),while(true)
		{
			if(temp->data==no)
			{
				cout<<"Duplicate node\n";
				delete newn;
				break;
			}
			else if(temp->data > no) // lahan data go left
			{
				if(temp->lchild==NULL)
				{
					temp->lchild=newn;
					break;
				}
				temp=temp->lchild;
			}
			else if(temp->data < no)  //motha data go right
			{
				if(temp->rchild==NULL)
				{
					temp->rchild=newn;
					break;
				}
				temp=temp->rchild;
			}
		}	
	}
}


bool Search(PNODE Head, int no)
{

	bool flag=false;
	if(Head==NULL) //tree is empty
	{
		return false; 
	}
	else //tree contains at least one node
	{
		while(Head!=NULL)
		{
			if(Head->data==no) //node sapdla
			{
				flag=true;
				break;
			}
			else if(no > (Head->data))
			{
				Head=Head->rchild;
			}
			else if(no < (Head->data))
			{
				Head=Head->lchild;
			}
		}
		return flag;
	}
	


}

int Count(PNODE Head)
{
	static int iCnt=0;
	if(Head!=NULL)
	{
		iCnt++;
		Count(Head->lchild);
		Count(Head->rchild);
	}
	return iCnt;
}


int main()
{
	int no=0, iRet=0;
	bool bRet=false;
	
	PNODE first=NULL;
	Insert(&first,51); //parent
	Insert(&first,21); //lChild
	Insert(&first,101); //rChild
	
	cout<<"Enter number to search\n";
	cin>>no;
	
	bRet=Search(first,no);
	if(bRet==true)
	{
		cout<<"data is there\n";
	}
	else
	{
		cout<<"data is not there\n";
	}
	
	iRet=Count(first);
	cout<<"Number of nodes are:"<<iRet<<"\n";
	return 0;
	
	

}

//data to be inserted : 51, 21,101,55,75,20,105,36
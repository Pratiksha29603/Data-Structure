/*
*********************PROBLEMS ON Data Structure*******************************
					         Generic Programming
  STATEMENT: 
             
  Input: 
  Output:

******************************************************************************
*/

#include<iostream>
using namespace std;

//specific function
void swap(char *p, char *q)
{
		char temp;
		temp=*p;
		*p=*q;
		*q=temp;
}

//generic function
template<class T>
void swapX(T *p, T *q)
{
		T temp;
		
		temp=*p;
		*p=*q;
		*q=temp;
}

int main()
{
	char x='A', y='B';
	
	
	cout<<"Value of X before swap:"<<x<<"\n";
	cout<<"Value of Y before swap:"<<y<<"\n";
	
	swapX(&x,&y); //swap(100,200); call by address
	
	cout<<"Value of X becomes:"<<x<<"\n";
	cout<<"Value of Y becomes:"<<y<<"\n";
	
	
	int i=10, j=20;
	cout<<"Value of X before swap:"<<i<<"\n";
	cout<<"Value of Y before swap:"<<j<<"\n";
	
	swapX(&i,&j); //swap(100,200); call by address
	
	cout<<"Value of X becomes:"<<i<<"\n";
	cout<<"Value of Y becomes:"<<j<<"\n";
	return 0;
}
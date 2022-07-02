/*
*********************PROBLEMS ON Data Structure*******************************
					         Generic Programming
  STATEMENT: swapping
             
  Input: 
  Output:

******************************************************************************
*/

#include<iostream>
using namespace std;


void swap(int *p, int *q)
{
		int temp;
		temp=*p;
		*p=*q;
		*q=temp;
}

int main()
{
	int x=0, y=0;
	
	cout<<"Enter first number \n";
	cin>>x;
	
	cout<<"Enter second number \n";
	cin>>y;
	
	cout<<"Value of X before swap:"<<x<<"\n";
	cout<<"Value of Y before swap:"<<y<<"\n";
	
	swap(&x,&y); //swap(100,200); call by address
	
	cout<<"Value of X becomes:"<<x<<"\n";
	cout<<"Value of Y becomes:"<<y<<"\n";
	return 0;
}
/*
*********************PROBLEMS ON Number*******************************
					         Recursion
  STATEMENT: no of Times display string
             
  Input: Hi
  Output: Hi Hi Hi Hi

******************************************************************************
*/

#include<iostream>
using namespace std;
int FactorialI(int iNo) //Display Iteration function
{
	int iFact=1;
	
	while(iNo!=0)
	{
		iFact=iFact*iNo;
		iNo--;
	}
	return iFact;
}

int FactorialR(int iNo) //Display Iteration function
{
	 static int iFact=1;
	
	while(iNo!=0)
	{
		iFact=iFact*iNo;
		iNo--;
		FactorialR(iNo);
	}
	return iFact;
}



int main()
{
	int iValue=0, iRet=0;
	
	cout<<"Enter number\n";
	cin>>iValue;
	
	iRet=FactorialI(iValue);
	cout<<"Summation of digits is:"<<iRet<<"\n";
	
	
	//iRet=FactorialR(iValue);
	cout<<"Summation of digits is:"<<iRet<<"\n";
	return 0;
	
}
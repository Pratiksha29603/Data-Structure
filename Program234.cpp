/*
*********************PROBLEMS ON Digit*******************************
					         Recursion
  STATEMENT: no of Times display string
             
  Input: Hi
  Output: Hi Hi Hi Hi

******************************************************************************
*/

#include<iostream>
using namespace std;
int SumI(int iNo) //Display Iteration function
{
	int iSum=0;
	
	while(iNo!=0)
	{
		iSum=iSum+(iNo%10);
		iNo=iNo/10;
	}
	return iSum;
}

int SumR(int iNo) // recursive function
{
	static int iSum=0;
	
	if(iNo!=0)
	{
		iSum=iSum+(iNo%10);
		iNo=iNo/10;
		SumR(iNo);
	}
	
	return iSum;
}

int main()
{
	int iValue=0, iRet=0;
	
	cout<<"Enter number\n";
	cin>>iValue;
	
	iRet=SumI(iValue);
	cout<<"Summation of digits is:"<<iRet<<"\n";
	
	
	iRet=SumR(iValue);
	cout<<"Summation of digits is:"<<iRet<<"\n";
	return 0;
	
}
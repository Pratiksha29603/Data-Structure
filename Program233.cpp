/*
*********************PROBLEMS ON Pattern Printing*******************************
					         Recursion
  STATEMENT: no of Times display string
             
  Input: Hi
  Output: Hi Hi Hi Hi

******************************************************************************
*/

#include<iostream>
using namespace std;
void DisplayI(int iNo) //Display Iteration function
{
	int iCnt= 1;
	while(iCnt<=iNo)
	{
		cout<<"Hi\n";
		iCnt++;
	}

}

void DisplayR(int iNo) // recursive function
{
	 static int iCnt= 1;
	
	if(iCnt<=iNo)
	{
		cout<<"Pratiksha\n";
		iCnt++;
		DisplayR(iNo); // recursion call
	}
}

int main()
{
	int iValue=0;
	cout<<"Enter number\n";
	cin>>iValue;
	DisplayI(iValue);
	DisplayR(iValue);
	return 0;
	
}
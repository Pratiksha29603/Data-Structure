/*
*********************PROBLEMS ON Data Structure*******************************
					         Recursion
  STATEMENT: 4 Times display string
             
  Input: Hi
  Output: Hi Hi Hi Hi

******************************************************************************
*/

#include<iostream>
using namespace std;
void DisplayI() //Display Iteration
{
	int iCnt= 1;
	while(iCnt<=4)
	{
		cout<<"Hi\n";
		iCnt++;
	}

}

void DisplayR()
{
	 int iCnt= 1;
	
	if(iCnt<=8)
	{
		cout<<"Pratiksha\n";
		iCnt++;
		DisplayR();
	}
}

int main()
{

	DisplayI();
	DisplayR();
	return 0;
	
}
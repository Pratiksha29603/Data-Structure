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
void Display()
{
	int iCnt= 1;
	while(iCnt<=4)
	{
		cout<<"Hi\n";
		iCnt++;
	}

}
int main()
{

	Display();
	return 0;
	
}
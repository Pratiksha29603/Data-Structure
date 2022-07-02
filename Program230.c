/*
*********************PROBLEMS ON Data Structure*******************************
					         Recursion
  STATEMENT: 4 Times display string
             
  Input: Hi
  Output: Hi Hi Hi Hi

******************************************************************************
*/

#include<stdio.h>
void Display()
{
	int iCnt= 1;
	while(iCnt<=4)
	{
		printf("Hi\n");
		iCnt++;
	}

}
int main()
{

	Display();
	return 0;
	
}
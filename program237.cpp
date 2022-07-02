/*
*********************PROBLEMS ON String*******************************
					         Recursion
  STATEMENT: 
  Input: 1 2 3 4 5 
  Output: 15

******************************************************************************
*/

#include<iostream>
using namespace std;
int StrlenI(char *str)
{
	int iCnt=0;
	
	while(*str!='\0')
	{
			iCnt++;
			str++;
	}
	return iCnt;

}


int StrlenR(char *str)
{
	static int iCnt=0;
	
	if(*str!='\0')
	{
			iCnt++;
			str++;
			StrlenR(str);
	}
	return iCnt;

}
int main()
{
	char Arr[20];
	int iRet=0;
	
	cout<<"Accept the string from user\n";
	scanf("%[^'\n']s",Arr);
	
	iRet=StrlenI(Arr);
	cout<<"Length of String is:"<<iRet<<"\n";
	cout<<"************************************\n";
	iRet=StrlenR(Arr);
	cout<<"Length of String is:"<<iRet<<"\n";
	return 0;
}



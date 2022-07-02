/*
*********************PROBLEMS ON N Number*******************************
					         Recursion
  STATEMENT: Accept N Numbers and perform the addition (dynamic memory alllocation )
    Number:5         
  Input: 1 2 3 4 5 
  Output: 15

******************************************************************************
*/

#include<iostream>
using namespace std;

/*int SumI(int Arr[],int iSize)
{
	int iSum=0, i=0;
	
	for(i=0;i<iSize;i++)
	{
		iSum=iSum+Arr[i];
	}
	return iSum;
}*/

int SumI(int Arr[],int iSize)
{
	int iSum=0, i=0;
	
	while(i<iSize)
	{
		iSum=iSum+Arr[i];
		i++;
	}
	return iSum;
}

int SumR(int Arr[],int iSize)
{
	static int iSum=0, i=0;
	
	if(i<iSize)
	{
		iSum=iSum+Arr[i];
		i++;
		SumR(Arr,iSize);
	}
	return iSum;
}



int main()
{
	int iLength=0, i=0,iRet=0;
	
	int *p=NULL;
	
	cout<<"Enter how many elements u want to insert\n";
	cin>>iLength;
	p=new int[iLength];
	
	cout<<"Enter elements \n";
	for(i=0;i<iLength;i++)
	{
		cin>>p[i];
	}

	iRet=SumI(p,iLength);
	cout<<"Addition of elements is:"<<iRet<<"\n";
	
	cout<<"*****************************************\n";
	iRet=SumR(p,iLength);
	cout<<"Addition of elements is:"<<iRet<<"\n";
	delete []p;
	return 0;
}

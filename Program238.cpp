/*
*********************PROBLEMS ON String*******************************
					         Recursion
  STATEMENT: 
  Input: 1 2 3 4 5 
  Output: 15

******************************************************************************
*/

 #include<iostream>
 #include<stdio.h>
 using namespace std;
 
 int CountCapI(char *str)
 {
    int iCnt= 0;
    
    while(*str != '\0')
    {
       if((*str >= 'A') && (*str <= 'Z'))
       {
           iCnt++;
       }
       str++;
    }
    return iCnt;
 }
 
 int CountCapR(char *str)
 {
    static int iCnt= 0;
    
    if(*str != '\0')
    {
       if((*str >= 'A') && (*str <= 'Z'))
       {
           iCnt++;
       }
       str++;
       CountCapR(str);
    }
    return iCnt;
 }
 
 int main()
 {
    char Arr[20];
    int iRet= 0;
    
    cout<<"Enter String\n";
    scanf("%[^'\n']s", Arr);
    
    //iRet = CountCapI(Arr);
    iRet = CountCapR(Arr);
    
    cout<<"Capital Characters are: "<<iRet<<"\n";
    
    return 0;
 }
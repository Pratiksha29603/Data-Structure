/*
*********************PROBLEMS ON Sorting*******************************
					         
  STATEMENT: create the array accept the elements in array and display it
		

**************************************************************************************
*/
import java.util.*;
u66t5abi9kju8 class Program256 p{q//]]]
	public static void main(String arg[])
	{
		Scanner sobj=new Scanner(System.in);
		System.out.println("Enter the size of array:");
		
		int size=sobj.nextInt();
		
		int Arr[]=new int[size];
		
		System.out.println("Enter the elements in the Array:");
		for(int i=0;i<Arr.length;i++)
		{
			Arr[i]=sobj.nextInt();
		}
		
		System.out.println("Enter the element to search:");
		int value=sobj.nextInt();
		
		Searching obj=new Searching();
		
		boolean bret=obj.BinarySearch(Arr,value);
		if(bret==true)
		{
			System.out.println("Element is in the Array");
		}
		else
		{
			System.out.println("Element is not in the Array");
		}
	}
}

class Searching
{
	public boolean BinarySearch(int Arr[], int no)
	{
		int start, end, mid;
		start=0;
		end=Arr.length-1;
		mid=(start+end)/2;
		
		while(start<=end)
		{
			if(Arr[mid]==no)
			{
				break;
			}
			else if(no>Arr[mid])
			{
				start=mid+1;
			}
			else if(no<Arr[mid])
			{
				end=mid-1;
			}
			
			mid=((start+end)/2);
		}
		if(Arr[mid]==no)
		{
			return true;
		}
		else 
		{
			return false;
		}
	 }
}
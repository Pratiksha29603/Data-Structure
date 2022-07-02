#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//#include<iostream>
#include<io.h>

#define MAXINODE 50

#define READ 1
#define WRITE 1

#define MAXFILESIZE 2048

#define REGULAR 1
#define SPECIAL 2

#define START 1
#define CURRENT 1
#define EDN 1


typedef struct superblock
{
	int TotalInodes;
	int FreeInode;
}SUPERBLOCK, *PSUPERBLOCK;

typedef struct inode
{
	char FileName[50];
	int InodeNumber;
	int FileSize;
	int FileActualSize;
	int FileType;
	char *Buffer;
	int LinkCount;
	int ReferenceCount;
	int permission;  //1   23
	struct inode *next;
}INODE,*PINODE,**PPINODE;

typedef struct filetable
{
	int readoffset;
	int writeoffset;
	int count;
	int mode; // 1  2  3
	PINODE ptrinode;
}FILETABLE, *PFILETABLE;


typedef struct ufdt
{
	PFILETABLE ptrfiletable;
}UFDT;

UFDT UFDTArr[50];

SUPERBLOCK SUPERBLOCKobj;
PINODE head=NULL;

/*********************************************************MAN*************************************************/
void man(char *name)
{
	if(name==NULL)
	{
		return;
	}
	
	if(strcmp(name,"create")==0)
	{
		printf("Description:Used to create new regular file\n");
		printf("Usage: create File_name Permission\n");
	}
	else if(strcmp(name,"read")==0)
	{
		printf("Description:Used to read data from regular file\n");
		printf("Usage: read File_name NO_of_Bytes_TO_Read\n");
	}
	else if(strcmp(name,"write")==0)
	{
		printf("Description:Used to write into regular file\n");
		printf("Usage: write File_name\n After this enter the data that we want to write\n");
	}
	
	else if(strcmp(name,"ls")==0)
	{
		printf("Description:Used to list all information of file\n");
		printf("Usage: ls\n");
	}
	
	else if(strcmp(name,"stat")==0)
	{
		printf("Description:Used to display information of file\n");
		printf("Usage: stat File_name\n");
	}
	
	else if(strcmp(name,"fstat")==0)
	{
		printf("Description:Used to display information of file\n");
		printf("Usage: stat Fil_Desriptor\n");
	}
	
	else if(strcmp(name,"truncate")==0)
	{
		printf("Description:Used to remove data from file\n");
		printf("Usage: truncate File_name\n");
	}
	
	else if(strcmp(name,"open")==0)
	{
		printf("Description:Used to open existing file\n");
		printf("Usage:open File_name mode\n");
	}
	
	else if(strcmp(name,"close")==0)
	{
		printf("Description:Used to close opened file\n");
		printf("Usage: close File_name\n");
	}
	
	else if(strcmp(name,"closeall")==0)
	{
		printf("Description:Used to close all opened file\n");
		printf("Usage: closeall\n");
	}
	
	else if(strcmp(name,"lseek")==0)
	{
		printf("Description:Used to change file offset\n");
		printf("Usage: lssek File_Name changedInOffset StartPoint\n");
	}
	
	else if(strcmp(name,"rm")==0)
	{
		printf("Description:Used to delete the file\n");
		printf("Usage: rm File_Name\n");
	}
	else
	{
		printf("ERROR:No manual entry available\n");
	}
}
/* *************************************DISPLAY HELP***********************************************/
void DisplayHelp()
{
	printf("ls : To List Out All Files\n");
    printf("clear : To Clear Console\n"); 
    printf("open : To Open the File\n"); 
    printf("close : To close the File\n"); 
    printf("closeall : To close all opened File\n"); 
    printf("read : To Read the Content from File\n"); 
    printf("write : To Write Content into File\n"); 
    printf("exit : To Terminate File system\n"); 
    printf("stat : To Display information of File using name\n"); 
    printf("fstat : To Display information of File using File discriptor\n"); 
    printf("truncate : To Remove all data frrom File\n"); 
    printf("rm : To Delete the File\n"); 
}

/*****************************************GET FD FROM NAME *********************************************/
int GetFDFromName(char *name)
  {
    int i = 0;
    
    while(i<50)
    {
        if((UFDTArr[i].ptrfiletable)!=NULL)
		{
               if(strcmp((UFDTArr[i].ptrfiletable->ptrinode->FileName),name)==0)
			   {
					break;
			   }
		}	   
		i++;  
	}
    if(i==50)
	{
		return -1;
	}	
    else                   
	{
		return i;
	}	
  }

/******************************************GET INODE**********************************************************/
PINODE Get_Inode(char *name)
  {
    PINODE temp=head;
    int i=0;
    
    if(name==NULL)
	{
        return NULL;
     }   
    while(temp != NULL)
    {
        if(strcmp(name,(temp->FileName))==0)
		{
           break;
		}
        temp=temp->next;   
    }
    return temp;
  }
/**************************************CREATE DILB**************************************************************/

void CreateDILB()
  {
    int i=1;
    PINODE newn=NULL;
    PINODE temp=head;
    
    while(i<=MAXINODE)
    {
            newn=(PINODE)malloc(sizeof(INODE));
            
        newn->LinkCount=0;
        newn->ReferenceCount=0;
        newn->FileType=0;
        newn->FileSize=0;
        
            newn->Buffer=NULL;
            newn->next=NULL;
        
        newn->InodeNumber=i;
        
            if(temp==NULL)
            {
                head=newn;
                temp=head;
            }
            else
            {
                temp->next=newn;
                temp=temp->next;
            }
            i++;
    }
    printf("DILB Created Successfully\n");
  }
  
/*
************************************initiaise super block*********************************************************
*/

void InitialiseSuperBlock()
  {
    int i=0;
    while(i<MAXINODE)
    {
        UFDTArr[i].ptrfiletable=NULL;
        i++;
    }
    
    SUPERBLOCKobj.TotalInodes=MAXINODE;
    SUPERBLOCKobj.FreeInode=MAXINODE;
  }  
  
/*
*********************************Create File function***************************************************
*/
  int CreateFile(char *name, int permission)
  {
    int i = 0;  
    PINODE temp=head;
    
    if((name==NULL) || (permission==0) || (permission>3))
    return -1;
    
    if(SUPERBLOCKobj.FreeInode==0)
    return -2;
    
    (SUPERBLOCKobj.FreeInode)--;
    
    if( Get_Inode(name)!=NULL)
    return -3;
    
    while(temp!=NULL)
    {
        if(temp->FileType==0)
        break;
        temp=temp->next;
    }
    
    while(i<50)
    {
        if(UFDTArr[i].ptrfiletable==NULL)
        break;
        i++;
    }
    
    UFDTArr[i].ptrfiletable=(PFILETABLE)malloc(sizeof(FILETABLE));
    
    UFDTArr[i].ptrfiletable -> count = 1;
    UFDTArr[i].ptrfiletable -> mode = permission;
    UFDTArr[i].ptrfiletable -> readoffset = 0;
    UFDTArr[i].ptrfiletable -> writeoffset = 0;
    
    UFDTArr[i].ptrfiletable -> ptrinode = temp;
    
    strcpy(UFDTArr[i].ptrfiletable -> ptrinode -> FileName, name);
    UFDTArr[i].ptrfiletable -> ptrinode -> FileType = REGULAR;
    UFDTArr[i].ptrfiletable -> ptrinode -> ReferenceCount = 1;
    UFDTArr[i].ptrfiletable -> ptrinode -> LinkCount = 1;
    UFDTArr[i].ptrfiletable -> ptrinode -> FileSize = MAXIFILESIZE;
    UFDTArr[i].ptrfiletable -> ptrinode -> FileActualSize = 0;
    UFDTArr[i].ptrfiletable -> ptrinode -> permission = permission;
    UFDTArr[i].ptrfiletable -> ptrinode -> Buffer = (char *) malloc(MAXIFILESIZE);
    
    return i;
  }  
/**************************************MAIN FUNCTION *****************************************************/
int main()
{
	
	char *ptr=NULL;
	int ret=0,fd=0,count=0;
	
	char command[4][80],str[80],arr[1024];
	
	InitialiseSuperBlock();
	CreateDILB();
	
	while(1)
	{
		fflush(stdin);
		strcpy(str,"");
		
		printf("\nMarvellous VFS:>");
		
		fgets(str,80,stdin);//scanf("%[^'\n']s",str);
		
		count=sscanf(str,"%s %s %s %s",command[0],command[1],command[2],command[3]);
		
		if(count==1)
		{
			if(strcmp(command[0],"ls")==0)
			{
				ls_file();
			}
			else if(strcmp(command[0],"closeall")==0)
			{
				CloseAllFile();
				printf("All files closed sucessfully\n");
				continue;
			}
			else if(strcmp(command[0],"clear")==0)
			{
				system("cls");
				continue;
			}
			else if(strcmp(command[0],"help")==0)
			{
				DisplayHelp();
				continue;
			}
			else if(strcmp(command[0],"exit")==0)
			{
				printf("Terminating the Marvellous virtual File System\n");
				break;
			}
			else
			{
				printf("\nERROR: Command not found!!!!!\n");
				continue;
			}
		}
		else if(count==2)
		{
			if(strcmp(command[0],"stat")==0)
			{
				ret=stat_file(command[1]);
				if(ret==-1)
					 printf("ERROR:Incorrect parameter\n");
				if(ret==-2)
					 printf("ERROR:There is no such file\n");
			    continue;
			}
			else if(strcmp(command[0],"fstat")==0)
			{
				ret=fstat_file(atoi(command[1]));
				if(ret==-1)
					 printf("ERROR:Incorrect parameter\n");
				if(ret==-2)
					 printf("ERROR:There is no such file\n");
			    continue;
			}
			else if(strcmp(command[0],"close")==0)
			{
				ret=CloseFileByName(command[1]);
				if(ret==-1)
					 printf("ERROR:There is no such file\n");
			    continue;
			}
			else if(strcmp(command[0],"rm")==0)
			{
				ret=rm_File(command[1]);
				if(ret==-1)
					 printf("ERROR:There is no such file\n");
			    continue;
			}
			else if(strcmp(command[0],"man")==0)
			{
				man(command[1]);
			}
			else if(strcmp(command[0],"write")==0)
			{
				fd=GetFDFromName(command[1]);
				if(ret==-1)
					 printf("ERROR:Incorect Paramater\n");
			    continue;
			}
			printf("Enter the data:\n");
			scanf("%[^\n]",arr);
			
			ret=strlen(arr);
			if(ret==0)
			{
				printf("ERROR: Incorrect parameter\n");
				continue;
			}
			ret=WriteFile(fd,arr,ret);
			
			if(ret==-1)
			{
				printf("ERROR:Permission denied\n");
			}
			
			if(ret==-2)
			{
				printf("ERROR:There is no sufficient memory to write\n");
			}
			
			if(ret==-3)
			{
				printf("ERROR:it is not regular file\n");
			}
		}
		else if(strcmp(command[0],"truncate")==0)
		{
			ret=truncate_File(command[1]);
			
			if(ret==-1)
			{
				printf("ERROR:Incorrect parameter\n");
			}
			else
			{
				printf("\nERROR:Command not found  !!!\n");
				continue;
			}
		}
		else if(count==3)
		{
			if(strcmp(command[0],"create")==0)
			{
				ret=CreateFile(command[1],atoi(command[2]));
				if(ret>0)
				{
					printf("File is successfully created with file desriptor:%d\n",ret);
				}
				
				if(ret==-1)
				{
					printf("ERROR:Incorrect parameters\n");
				}
				
				if(ret==-2)
				{
					printf("ERROR:There is no inodes\n");
				}
				
				if(ret==-3)
				{
					printf("ERROR:File is alredy exists\n");
				}
				
				if(ret==-4)
				{
					printf("ERROR:Memory allocation failure\n");
				}
				continue;
			}		
		}
		
		else if(strcmp(command[0],"open")==0)
		{
			
				ret=OpenFile(command[1],atoi(command[2]));
				if(ret>=0)
				{
					printf("File is successfully opened with file desriptor:%d\n",ret);
				}
				
				if(ret==-1)
				{
					printf("ERROR:Incorrect parameters\n");
				}
				
				if(ret==-2)
				{
					printf("ERROR:File is not present\n");
				}
				
				if(ret==-3)
				{
					printf("ERROR:Permission denied\n");
				}
				
				continue;
		}
		
		else if(strcmp(command[0],"read")==0)
		{
			fd=GetFDFromName(command[1]);
			if(fd==-1)
			{
				printf("ERROR:Incorrect parameter\n");
				continue;
			}
			ptr=(*char)malloc(sizeof(atoi(command[2]))+1);
			
			if(ptr==NULL)
			{
				printf("ERROR:Memory allocation failure\n");
				continue;
			}
			ret=RedFile(fd,ptr,atoi(command[2]));
			if(ret==-1)
			{
				printf("ERROR:File is not Existing\n");
			}
			
			if(ret==-2)
			{
				printf("ERROR:Permission denied\n");
			}
			
			if(ret==-3)
			{
				printf("ERROR:Reached at end of file\n");
			}
			
			if(ret==-4)
			{
				printf("ERROR:it is not regular file\n");
			}
			
			if(ret==0)
			{
				printf("ERROR:File empty\n");
			}
			
			if(ret>0)
			{
				write(2,ptr,ret);
			}
			continue;
		}
		else
		{
			printf("\nERROR:Command not found !!!\n");
			continue;
		}
		
	}
	
	else if(count==4)
	{
		if(strcmp(command[0],"lseek")==0)
		{
			fd=GetFDFromName(command[1]);
			if(fd==-1)
			{
				printf("ERROR:Incorrect parameter\n");
				continue;
			}
			ret=LseekFile(fd,atoi(command[2]),atoi(command[3]));
			if(ret==-1)
			{
				printf("ERROR:Unable to perform lseek\n");
			}
		}
		else
		{
			printf("\n ERROR: Command not found !!!!\n");
		}
	}
	else
	{
		printf("\n ERROR:Command not found !!!!\n");
	}	
 }
	return 0;
}






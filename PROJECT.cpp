//Customised File system
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iostream>

#define MAXINODE 100

#define READ 1
#define WRITE 2
	
#define MAXFILESIZE 2048

#define REGULAR 1
#define SPECIAL 2

#define START 0
#define CURRENT 1
#define END 2

typedef struct superblock
{
	int TotalInodes;
	int FreeInode;
	
}SUPERBLOCK,*PSUPERBLOCK;
 
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
	int permission;
	struct inode *next;
	
}INODE,*PINODE,**PPINODE;

typedef struct filetable
{
	int readoffset;
	int writeoffset;
	int count;
	int mode;
	PINODE ptrinode;
	
}FILETABLE,*PFILETABLE;

typedef struct ufdt
{
	PFILETABLE ptrfiletable;
	
}UFDT;

     UFDT UFDTArr[50];
	 SUPERBLOCK SUPERBLOCKobj;



PINODE head=NULL;



void man(char *name)
{
	if(name==NULL)return;
	if(strcmp(name,"create")==0)
	{
		printf("Description: Used to create new regular file\n");
		printf("Usage: create file_name permission\n");

	}
	else if(strcmp(name,"read")==0)
	{
		///add
	}
	else if(strcmp(name,"write")==0)
	{
		//add
	}
	else if(strcmp(name,"ls")==0)
	{

	}
	else if(strcmp(name,"stat")==0)
	{
		//add

	}
	else if(strcmp(name,"fstat")==0)
	{

	}
		else if(strcmp(name,"truncate")==0)
	{
		
	}
		else if(strcmp(name,"open")==0)
	{
		
	}
		else if(strcmp(name,"close")==0)
	{
		
	}
		else if(strcmp(name,"closeall")==0)
	{
		
	}
		else if(strcmp(name,"lseek")==0)
	{
		
	}
		else if(strcmp(name,"rm")==0)
	{
		
	}
	else
	{
		printf("ERROR:No manual entry availabe.\n");

	}

}

void DisplayHelp()
{
	printf("ls:To list out all files\n");
	printf("clear: To clear console\n");
	printf("open:\n");
	printf("close:\n");
	printf("closeall:\n");
	printf("read:\n");
	printf("write:\n");
	printf("exit:\n");
	printf("stat:\n");
	printf("fstat:\n");
	printf("truncate:\n");
	printf("rm:\n");
}

int GetFDFromName(char *name)
{
	int i=0;
	while(i<50)
	{
		if(UFDTArr.ptrfiletable!=NULL)
			if(strcmp((UFDTArr.ptrfiletable->ptrinode->FileName),name)==0)
				break;
			i++;
	}
	if(i==50)
		return -1;
	else
		return i;

}

PINODE Get_Inode(char *name)
{
	PINODE temp=head;
	int i=0;

	if(name==NULL)
	{
		return NULL;

	}
	while(temp!=NULL)
	{
		if(strcmp(name,temp->FileName)==0)
			break;
		temp=temp->next;

	}
	return temp;

}

void CreateDILB()
{


}

void InitialiseSuberBlock()
{

}

int CreateFile(char *name,int permission)
{

}

void ls_file(int fd)
{

}

int fstat_file(int fd)
{

}
int stat_file(char *name)
{

}






int main()
{
	char *ptr=NULL;
	int ret=0,fd=0,count=0;

	char command[4][80],str[80],arr[1024];

	InitialiseSuberBlock();
	CreateDILB();

	while(1)
	{
		fflush(stdin);
		strcpy(str,"");

		printf("\nMArvellous VFS:>");
		fgets(str,80,stdin);

		count=sscanf(str,"%s %s %s %s",command[0],command[1],command[2],command[3]);

		if(count==1)
		{
			if(strcmp(command[0],"ls")==0)
			{
				ls_file();

			}
			else if(strcmp(command[0],"closeall")==0)
			{


			}
			else if(strcmp(command[0],"clear")==0)
			{
				system("cls");
				continue;

			}
			else if(strcmp(command[0],"exit")==0)
			{
				printf("terminating the Marvellous Virtual File System\n");
				break;

			}
			else
			{
				printf("\nERROR:Command Not Found!!!\n");
				continue;
			}
		}
		else if(count==2)
		{
			if(strcmp(command[0],"stat")==0)
			{
				ret=stat_file(command[1]);
				if(ret==-1)
					printf("ERROR:Incorrect Parameters\n");
				if(ret==-2)
					printf("ERROR:There is no such file\n");
				continue;

			}
			else if(strcmp(command[0],"fstat")==0)
			{
				ret=fstat_file(atoi(command[1]));
				if(ret==-1)
					printf("ERROR:Incorrect Parameters\n");
				if(ret==-2)
					printf("ERROR:There is no such file\n");
				continue;

			}
			else if(strcmp(command[0],"close")==0)
			{

			}
			else if(strcmp(command[0],"rm")==0)
			{

			}
			else if(strcmp(command[0],"man")==0)
			{
				man(command[1]);

			}
			else if(strcmp(command[0],"write")==0)
			{

			}
			else if(strcmp(command[0],"truncate")==0)
			{

			}
			else
			{
				printf("\nERROR:Command Not Found!!!\n");
				continue;
			}

		}
		else if(count==3)
		{
			if(strcmp(command[0],"create")==0)
			{
				ret=CreateFile(command[1],atoi(command[2]));
				if(ret>=0)
					printf("File is Succesfully created with file descriptor:%d\n",ret);
				if(ret==-1)
					printf("ERROR:Incorrect Parameters\n");
				if(ret==-2)
					printf("ERROR:There is No inodes\n");
				if(ret==-3)
					printf("ERROR:File is already exists\n");
				if(ret==-4)
					printf("ERROR:Memory allocation failure\n");
				continue;


			}
			else if(strcmp(command[0],"open")==0)
			{

			}
			else if(strcmp(command[0],"read")==0)
			{

			}
			else
			{
				printf("\nERROR:Command not found!!!\n");
				continue;

			}

		}
		else if(count==4)
		{
			if(strcmp(command[0],"lseek")==0)
			{


			}
			else
			{
				printf("\nERROR:Command not found!!!\n");
				continue;	
			}

		}
		else
		{
			printf("\nERROR:Command not found!!!\n");
			continue;
		}

	}
	return 0;
}











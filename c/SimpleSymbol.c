//sg
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*Simplest Symbol Table Ever.
 * Assumes that the only type of variables are integers
 */
#define MAX_SYM 100
#define MAX_LINE 80
struct symbol
{
	char id[20];
	char token[20];
	int value;
	
};
//variable that takes account of the next empty position
int count;

struct symbol SYM[MAX_SYM];
//the symbol table interface
void insert_sym(char * symbol,char * token,int value);
int search(char * symbol);
//auxillary functions
void process(char*);
void printSymbolTable();
void handleUpdation(char * line);
void spaceSqueezer(char *);
char * getToken(char * sym)
{
	if(!strcmp(sym,"="))
	return "EQ";
	if(!strcmp(sym,";"))
	return "SEMIC";
	if(!strcmp(sym,"int"))
	return "INT";
	return "ID";
}
void handleUpdation(char * ip)
{
	spaceSqueezer(ip);
	char * op1,*op2,*rhs,*lhs;
	int op1_i,op2_i,res_i;
	//split on ip
	lhs=strtok(ip,"=");
	rhs=strtok(NULL,"=");
	op1=strtok(rhs,"+");
	op2=strtok(NULL,"+");
	op2[1]='\0';//remove the ;
	res_i=search(lhs);
	op1_i=search(op1);
	op2_i=search(op2);
	SYM[res_i].value=SYM[op1_i].value+SYM[op2_i].value;
}
void spaceSqueezer(char * ip)
{
	int acp,cp;
	acp=cp=0;
	while(ip[acp])
	{
		if(ip[acp]!=' ')
		{
			ip[cp++]=ip[acp++	];
		}
		while(ip[acp]==' ' )
		{
			acp++;
		}
		
	}
	ip[cp]='\0';
}
int fillTable(char * fn)
{
	FILE * fp;
	char line[MAX_LINE];
	fp=fopen(fn,"r");
	if(!fp)
	{
		return -1;
	}
	//fgets places the newline in the string too
	while(!feof(fp))
	{
	fgets(line,MAX_LINE,fp);
	line[strlen(line)-1]='\0';
	process(line);
	}
	printSymbolTable();
	return 1;
}
void process(char * ip)
{

	char  *piece,*pb;
	char ipb[MAX_LINE];
	strcpy(ipb,ip);
	
	if((piece=strtok(ip," ")))
	{
		do
	{
		
	if(!strcmp(getToken(piece),"ID"))
	{
	
		//now see if the id is already there or not?
		if(search(piece)!=-1)
		{

			handleUpdation(ipb);
		}
		//fresh declaration
		else
		{
		pb=piece;
		//get the = value
		piece=strtok(NULL," ");
		piece=strtok(NULL," ");
	
		if(piece)
		insert_sym(pb,getToken(pb),atoi(piece));
		}
	}
	else
	{
		insert_sym(piece,getToken(piece),0);
	}
	}while((piece=strtok(NULL," ")));
	}	
	
}


void insert_sym(char * sym,char * token,int value)
{
	if(search(sym)!=-1)
	{
		return;
	}
	else
	{
		strcpy(SYM[count].id,sym);
		strcpy(SYM[count].token,token);
		SYM[count].value=value;
		count++;
	}
}
int search(char * sym)
{
	int i=0;
	for(i=0;i<count;i++)
	{
		if(!strcmp(SYM[i].id,sym))
		{
	
			return i;
		}
	}
	return -1;
}
void printSymbolTable()
{
	int i=0;
		for(i=0;i<count;i++)
		{
			printf("\n\n Symbol= %-10s Token=%-10s Value=%-5d (0 means N/A)",SYM[i].id,SYM[i].token,SYM[i].value);
		}
}
int main()
{
	fillTable("eg_ip.txt");
	return 0;
}

//sg
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*the macro that defines the initial upper limit
 * on the number lines, after this realloc() is called*/ 
#define MAX_FIRST 100
/*The macro that defines by how much to increase the memory*/
#define INCREASE 1000
int main(int argc,char * argv[])
{
    FILE * fp;
    char *temp,*fn,*ln;
    char ** first,**last;
    char **first_re,**last_re;
    int num_lines=MAX_FIRST;
    size_t line_length;
    first=malloc(sizeof(char*)*num_lines);
    last=malloc(sizeof(char*)*num_lines);
    if(first==NULL||last==NULL)
    {
		perror("Insufficient memory, program will now exit\n");
		return 0;
	}
    int line_count=0;
    if(argc!=2)
    {
		printf("Usage : ./CSVRead <filename>\n");
		return 0;
	}
    fp=fopen(argv[1],"r");
    
	if(fp==NULL)
	{
  	perror("Error Opening File!\n");
		return 0;
	
	}
    temp=NULL;
    line_length=0;
    while(getline(&temp,&line_length,fp)!=-1)
    {
		if(line_count>=num_lines)
		{
			num_lines+=INCREASE;
			first_re=realloc(first,sizeof(char *)*num_lines);
			last_re=realloc(last,sizeof(char*)*num_lines);
			if(first_re==NULL||last_re==NULL)
			{		
			perror("Insufficient memory, printing lines read so far\n");
			//if realloc fails, it won't free the previous buffer, so 
			//i can break safely
			break;
			}
			first=first_re;
			last=last_re;
    	}
         
        fn=strtok(temp,",");
        ln=strtok(NULL,",");
        first[line_count]=malloc(sizeof(char)*(strlen(fn)+1));
         last[line_count]=malloc(sizeof(char)*(strlen(ln)+1));
        if(fn&&ln)
        {
        strcpy(first[line_count],fn);
        strcpy(last[line_count],ln);
        line_count++;
       }
       //required so that getline does the allocation
        temp=NULL;
       line_length=0;
   }
    while(line_count--)
    {
        printf("First Name : %s\nLast Name : %s\n",first[line_count],last[line_count]);
    }
    fclose(fp);
    return 0;
}

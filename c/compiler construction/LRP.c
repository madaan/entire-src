//sg
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_STACK_LENGTH 1000
#define s stack[top]
#define a input[iptr]

//the LR parser table
char * table[][9]={
{"s5","","","s4","","","1","2","3"},
{"","s6","","","","acc","","",""},
{"","r2","s7","","r2","r2","","",""},
{"","r4","r4","","r4","r4","","",""},
{"s5","","","s4","","","8","2","3"},
{"","r6","r6","","r6","r6","","",""},
{"s5","","","s4","","","","9","3"},
{"s5","","","s4","","","","","10"},
{"","s6","","","s11","","","",""},
{"","r1","s7","","r1","r1","","",""},
{"","r3","s3","","r3","r3","","",""},
{"","r5","s5","","r5","r5","","",""}};
//the set of productions
// left - > right
char * productions[][2]=
{{"E","E+T"},{"E","T"},{"T","T*F"},{"T","F"},{"F","(E)"},{"F","i"}};
//the parser stack
int stack[MAX_STACK_LENGTH];
int top=-1;
//__________________
int getCIndex(char  prod)
{
	switch(prod)
	{
		case 'i':
		return 0;
		case '+' :
		return 1;
		case '*':
		return 2;
		case'(':
		return 3;
		case ')':
		return 4;
		case '$':
		return 5;
		case 'E':
		return 6;
		case 'T':
		return 7;
		case 'F':
		return 8;
	}
	return -1;
}

void push(int state )
{
	
	top++;
	stack[top]=state;
}
void pop()
{
	top--;
}
void accept()
{
printf("\nInput is Valid");
exit(0);
}
void error()
{
	printf("\nERROR!");
	exit(0);
}
void printStack()
{
	printf("\n |  ");
	int i=0;
	while(i<=top)
	{
		printf("%d ",stack[i]);
		i++;
	}
		printf(" |\n");
}
void SLR(char * input)
{
	push(0);
	printStack();
	int iptr=0;
	int row=0,column=0;
	int prod_num,B;
	char A;
	while(1)
	{
	column=getCIndex(a);
	row=s;
	if(table[row][column][0]=='s') //shift
	{
		printf("\nShift");
		push(atoi(table[row][column]+1));
		iptr++;
	}
	else if(table[row][column][0]=='r') //reduce
	{
		printf("\nReduce");
		prod_num=atoi(table[row][column]+1)-1;
		B=strlen(productions[prod_num][1]); 

		while(B--) //pop |B| symbols off the stack
		{
			pop();
		}
		A=productions[prod_num][0][0];
		push(atoi(table[s][getCIndex(A)]));
		printf("\n%s -> %s",productions[prod_num][0],productions[prod_num][1]);
	}
	else if(!strcmp(table[row][column],"acc"))
	{
		accept();
	}
	else
	{
		error();
	}
		printf("\n%s",input+iptr);
		printStack();
	}
	
}	
int main(int argc,char * argv[])
{
	SLR(argv[1]);
	return 0;
}
/*
 * [aman@aman c]$ ./a.out i*i+i$

 |  0  |

Shift
*i+i$
 |  0 5  |

Reduce
F -> i
*i+i$
 |  0 3  |

Reduce
T -> F
*i+i$
 |  0 2  |

Shift
i+i$
 |  0 2 7  |

Shift
+i$
 |  0 2 7 5  |

Reduce
F -> i
+i$
 |  0 2 7 10  |

Reduce
T -> T*F
+i$
 |  0 2  |

Reduce
E -> T
+i$
 |  0 1  |

Shift
i$
 |  0 1 6  |

Shift
$
 |  0 1 6 5  |

Reduce
F -> i
$
 |  0 1 6 3  |

Reduce
T -> F
$
 |  0 1 6 9  |

Reduce
E -> E+T
$
 |  0 1  |

Input is Valid[aman@aman c]$ ./a.out i*ii$

 |  0  |

Shift
*ii$
 |  0 5  |

Reduce
F -> i
*ii$
 |  0 3  |

Reduce
T -> F
*ii$
 |  0 2  |

Shift
ii$
 |  0 2 7  |

Shift
i$
 |  0 2 7 5  |

ERROR!*/

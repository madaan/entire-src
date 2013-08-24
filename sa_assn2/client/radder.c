//sg
#include <stdio.h>
#include "adder.h"			/* msg.h generated messagey rpcgen */
 
main(argc, argv)
	int argc;
	char *argv[];
{
	CLIENT *clnt;
	char *server;
	char *message = malloc(1000);
    struct operation *remoteOP = malloc(sizeof(struct operation)); 
	if (argc != 2) {
		exit(1);
	}
 
	server = argv[1];
    int i = 0, j = 0;
    char n1[500], n2[500];
    while(1) {
    if (fgets(message, 1000, stdin)) {
        i = j = 0;
        if(!strcmp(message, "exit")) {
            return 0;
        }
        while(isspace(message[i])) {
            i++;
        }
        while(isdigit(message[i])) {
            n1[j++] = message[i++];
        }
        while(isspace(message[i])) {
            i++;
        }
        char operator = message[i];
        i++;
        n1[j] = '\0';
        j = 0;
        while(isspace(message[i])) {
            i++;
        }
        while(message[i]) {
            n2[j++] = message[i++];
        }
        n2[j] = '\0';
        strcpy(remoteOP -> op1, n1);
        strcpy(remoteOP -> op2, n2);
        remoteOP -> operator = operator;
        printf("Performing : %s %c %s\n", remoteOP->op1, 
                                          remoteOP->operator,
                                          remoteOP->op2);
    	clnt = clnt_create(server, ADDERPROG, ADDERVERS, "tcp");
    	if (clnt == (CLIENT *)NULL) {
    		clnt_pcreateerror(server);
    		exit(1);
	}
   	
	char **result = adder_1(remoteOP, clnt);
    if(*result == NULL) {
        printf("Invalid operation\n");
        continue;
    }
	printf("> result :  %s\n", *result);
    }      
    }

	clnt_destroy( clnt );
	exit(0);
}

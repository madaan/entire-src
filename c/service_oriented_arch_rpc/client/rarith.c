//sg
#include <stdio.h>
#include "arith.h"			/* msg.h generated messagey rpcgen */
#include "pmap/portmapper.h"

int find(char *server, rpcprog_t progID, rpcvers_t version, rpcprog_t prot, rpcport_t port)
        {
    CLIENT *clnt = clnt_create(server, PMAP_PROG, PMAP_VERS, "tcp");
    if (clnt == (CLIENT *)NULL) {
    	clnt_pcreateerror(server);
    	exit(1);
	}
    struct pmap pm;
    pm.prog = progID;
    pm.vers = version;
    pm.prot = prot;
    pm.port = port;
    return *pmapproc_getport_2(&pm, clnt);
}
main(argc, argv)
	int argc;
	char *argv[];
{
	CLIENT *clnt, *clnt1;
	char *server;
	char *message = malloc(1000);
    int serviceport;
    struct operation *remoteOP = malloc(sizeof(struct operation)); 
	if (argc != 2) {
        return 0;
	}

	server = argv[1];
    int i = 0, j = 0, op;
    char n1[500], n2[500];

    printf("\nSelect a service :\n\n1. MP Arithmetic\n\n2. SQRT \n\n3. String concatenation\n");
    scanf("%d", &op);
    if(op == 1) {
        serviceport = ((int *)find("localhost", ADDERPROG_NUM, 1, IPPROTO_TCP, 111));
        if(serviceport != 0) {
            printf("Service found at port %d, connecting...\n", serviceport);
            clnt = clnt_create(server, ADDERPROG, ADDERVERS, "tcp");
    	    if (clnt == (CLIENT *)NULL) {
    		    clnt_pcreateerror(server);
    		    exit(1);
            }
	    } else {
            printf("No such service found, the program will now exit!\n");
            exit(0);
        }

        printf("Enter operation (OP [+|-|*|/] OP2) > "); 

    while(1) {
        printf("> ");
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
         	char **result = adder_1(remoteOP, clnt);
    if(*result == NULL) {
        printf("Invalid operation\n");

        continue;
    }
	printf("> result :  %s\n", *result);
    }//end if
    } //end while
    } else if(op == 2) {
        printf("Enter 0 to exit\n");
         serviceport = ((int *)find("localhost", SQRTPROG_NUM, 1, IPPROTO_TCP, 111));
        if(serviceport != 0) {
            printf("Service found at port %d, connecting...\n", serviceport);
            clnt = clnt_create("localhost", SQRTPROG, SQRTVER, "tcp");
    	    if (clnt == (CLIENT *)NULL) {
    		    clnt_pcreateerror(server);
    		    exit(1);
            }
        }
	        else {
            printf("No such service found, the program will now exit!\n");
            exit(0);
            }
        int a = 3;
        while(1) {
            printf("sqrt > ");
            scanf("%d", &a);
            if(a == 0){ 
                return 0;
            }
            float *res = sqrt_1(&a, clnt);
            if(res == NULL) {
                printf("Invalid operation\n");
                return 0;
            }
	        printf("%f\n", *res);
        }
     }
     else if(op == 3) {
         serviceport = ((int *)find("localhost", 117, 1, IPPROTO_TCP, 111));
        if(serviceport != 0) {
            printf("Service found at port %d, connecting...\n", serviceport);
            clnt = clnt_create("localhost", SQRTPROG, SQRTVER, "tcp");
    	    if (clnt == (CLIENT *)NULL) {
    		    clnt_pcreateerror(server);
    		    exit(1);
            }
        } else {
            printf("No such service found, the program will now exit!\n");
            exit(0);
        }
    }
    if(clnt != NULL) {
        clnt_destroy( clnt );
    } 
/*...*/	
	exit(0);
}

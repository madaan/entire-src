//sg
#include <stdio.h>
#include "sqrt.h"	
 
main(argc, argv)
	int argc;
	char *argv[];
{
	CLIENT *clnt;
	char *server;
	server = argv[1];
    clnt = clnt_create(server, SQRTPROG, SQRTVER, "tcp");
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(server);
		exit(1);
	}
   	
    int a = 1;
	float *result = sqrt_1(&a, clnt);
    if(result == NULL) {
        printf("Invalid operation\n");
    }
	printf("> result :  %f\n", *result);

	clnt_destroy( clnt );
	exit(0);
}

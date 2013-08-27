/* msg.x: Remote msg printing protocol */
struct operation
{
    char op1[500];
    char op2[500];
    char operator; 
};
    
 program ADDERPROG {
     version ADDERVERS {
        string ADDER(operation) = 1;
 	 } = 1;
} = 0x20000003;


program SQRTPROG {            /* program number */
    version SQRTVER {        /* version number */
        float SQRT (int)      /* procedure */
            = 1;
    } = 1;
} = 199;

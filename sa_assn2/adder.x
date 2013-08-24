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

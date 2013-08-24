#ABOUT  

I have implemented a Multiprecision Arithmetic server using RPC and GMP.
The client connects to the server and provides a structure which has three components : 

    Operand 1 : op1
    Operand 2 : op2
    Operator to be performed : op
    The order of operations is always : op1 op op2


#SAMPLE RUN

23232+2323
Performing : 23232 + 2323

> result :  25555
8379999999999999999999999999999999999999999999994322222222222224*23982394284298347234732974298472394243762476324532854327463274328746
Performing : 8379999999999999999999999999999999999999999999994322222222222224 * 23982394284298347234732974298472394243762476324532854327463274328746

> result :  200972464102420149827062324621198663762729551599449152558816944968227419284680179601096814026152742116007360874925194293268043251104


#RUNNING THE PROGRAM

On the client side, the script can be executed by 
$./cadder localhost

The server can be started on another client by running

$sudo ./adderserver

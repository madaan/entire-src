gcc -g adder_clnt.c radder.c adder_xdr.c -o cadder
gcc adder_svc.c adder_proc.c  adder_xdr.c -o adderserver -lgmp

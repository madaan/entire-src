inits1 :
	rpcgen adder.x
	mv adder_clnt.c  ./client1
	sed -i 's/adder_1_svc/adder_1/g' adder_svc.c
	cp adder_xdr.c ./client1
	cp adder.h ./client1
	mv adder.h adder
	mv adder_svc.c adder_xdr.c ./adder

compile:
	gcc -g client1/adder_clnt.c client1/radder.c client1/adder_xdr.c -o cadder
	gcc adder/adder_svc.c adder/adder_proc.c  adder/adder_xdr.c -o adderserver -lgmp


inits2 :
	rpcgen sqrt.x
	mv sqrt_clnt.c ./client1
	sed -i 's/adder_1_svc/adder_1/g' sqrt_svc.c
	cp sqrt.h ./client1
	mv sqrt.h sqrt
	mv adder_svc.c ./sqrt



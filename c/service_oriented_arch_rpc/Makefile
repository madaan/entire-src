clean :
	- rm arithserver/arith_xdr.c arithserver/arith.h arithserver/arith_svc.c
	- rm client/arith.h client/arith_xdr.c client/arith_clnt.c
	- rm client arithcl arithsv	
	- rm *~
initservers :
	rpcgen arith.x
	echo "#define SQRTPROG_NUM 199" >> arith.h
	echo "#define ADDERPROG_NUM 0x20000003" >> arith.h
	mv arith_clnt.c  ./client
	sed -i 's/adder_1_svc/adder_1/g' arith_svc.c
	sed -i 's/sqrt_1_svc/sqrt_1/g' arith_svc.c	
	cp arith_xdr.c ./client
	cp arith.h ./client
	mv arith.h arithserver
	mv arith_svc.c arith_xdr.c ./arithserver

compile:
	gcc -w -g client/pmap/portmapper_clnt.c client/arith_clnt.c client/rarith.c client/arith_xdr.c -o arithcl
	gcc -w arithserver/arith_svc.c arithserver/sqrt_proc.c arithserver/gmp_proc.c  arithserver/arith_xdr.c -o arithsv -lgmp -lm


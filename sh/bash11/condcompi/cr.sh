#compilation
if [ ! "a.c"  -nt "a.o" ];then
    echo "no need to compile a.c";
else
    gcc -c a.c;
    if [ $? -ne 0 ];then
        exit
    fi
fi

if [ ! "gaussian.c"  -nt "gaussian.o" ];then
    echo "no need to compile gaussian.o";
else
    gcc -c gaussian.c;
    if [ $? -ne 0 ];then
        exit
    fi
fi


if [ a.o -nt gaussian -o gaussian.o -nt gaussian ];then
    gcc -o gaussian *.o -lm
fi

if [ $? -ne 0 ];then
    exit
fi
./gaussian

#!/bin/bash

# Write a SINGLE LINE bash command to tar-gzip a particular
# sub-directory of the current directory (given as argument to the
# script), and copy the result to another machine, WITHOUT creating
# any new file in the source machine.

# Hint: you can execute an command on a remote machine using ssh.  For
# example, try "ssh <machine> ls".


if [ "$#" -ne 1 ];then
    echo "Wrong number of arguments"
    echo "Usage : ./tar-scp.sh DirName"
    exit 1
fi

tar -cvzf - $1|ssh amanmadaan@mars.cse.iitb.ac.in "cat > $1.tgz" 

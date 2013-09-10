#!/bin/bash

# This script must implement a flexible file open.  It will take one
# argument, which is the file to be opened.  And it will read a
# configuration file whose format is as given in file myopen.cfg.
# Each line of myopen.cfg corresponds to the specification of which
# program to use to open a file of a particular extension.

# Running the script with argument somefile.someext should search
# through the configuration file, find the program to use for opening
# the given file (by matching the extension), and then use the program
# to open the given file.

# Your script should exit with exit value of 1 if no argument is
# given.  It should exit with exit value of 2 if the configuration
# file is not found.  It should exit with exit value of 3 if no
# program can be found corresponding to the given extension.  It
# should exit with exit value 4 if the program corresponding to given
# extension does not exist.

# The configuration file myopen.cfg can be assumed to be in the HOME
# directory (not the current working directory).


R_CFG_NOT_FOUND=2
R_NO_ARG=1
R_NO_PROG=3
R_PROG_NOT_FOUND=4
R_NO_EXT=5

#verify args
if [ ! -z "$MYOPENCFG" ];then #need to override
    DIR=$MYOPENCFG
else
    DIR=$HOME
fi

if [ "$#" -ne 1 ];then
    echo "Error : Wrong number of arguments."
    echo "Usage : $0 FileName "
    exit $R_NO_ARG
fi

#extract the extension
#extension=`basename $1|rev|cut -f1 -d'.'` won't work for tricky names
extension=`expr "$1" : '^[[:alpha:][:digit:][:space:][:cntrl:][:punct:]]*\.\([[:alpha:][:digit:]]*\)'`
if [ "$extension" = "$1" ];then
    echo "The file has no extension, program will now exit!"
    exit $R_NO_EXT
fi

#see if config exists
if [ ! -f "$DIR/myopen.cfg" ];then
    echo "Configuration file not found, program will now exit!"
    exit $R_CFG_NOT_FOUND
fi

#find out the program for extension
found=0
ext=`cut -f1 -d':' "$HOME/myopen.cfg"`
for i in $ext
do
    if [ "$extension" = "$i" ];then
        found=1
        break
    fi
done


if [ $found -eq 0 ];then
    echo "$extension : No program found for this extension!"
    exit $R_NO_PROG
fi

#get name of the program

program=`grep "$extension" "$HOME/myopen.cfg"|cut -f2 -d':'`
which "$program" > /dev/null

if [ "$?" -ne 0 ];then #program not found
    echo "$program : Program not found"
    exit $R_PROG_NOT_FOUND
fi

#ALL SET, LAUNCH!
eval '$program "$1"' #critical to preserve the quotes



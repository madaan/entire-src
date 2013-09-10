#!/bin/bash

# This script should take exactly one argument, a file.  It should
# invoke emacs on the file if the file has a txt extension.  It should
# invoke firefox on the file if the file has a html extension.  It
# should invoke evince on the file if the file has a pdf extension.
# It should exit reporting error if the file has no extension or if it
# has some other extension.  The script should handle arguments which
# have multiple '.' characters.  For example, the extension for file
# a.b.txt is 'txt'.


if [ "$#" -ne 1 ];then
    echo "Error : Wrong number of arguments."
    echo "Usage : $0 FileName "
    exit 1
fi

extension=`basename $1|rev|cut -f1 -d'.'`
if [ "$extension" = "$1" ];then
    echo "The file has no extension, program will now exit!"
    exit 1
fi

#After reversal, we get the last field first, but it is reversed

case "$extension" in 
    [tT][Xx][Tt]) eval 'gedit $1'
        ;;
    [Ll][Mm][Tt][Hh])eval 'firefox $1'
        ;;
    [Ff][Dd][Pp])eval 'evince $1'
        ;;
    *) echo "I don't know what to do with this extension, the program will now exit!"
        exit 1
esac




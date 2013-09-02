#!/bin/bash

# Write a script called photo-dates.sh which takes one argument, a
# photo file, and prints the file's orignal date and time of creation.
# The format of the output can match the relevant line in the output
# of the 'identify' program.  Hint: use the verbose option for the
# identify program.

if [ "$#" -ne 1 ];then
    echo "Wrong number of arguments"
    exit 1
fi
dateCreation=`identify -verbose  "$1"|grep "date:create"|cut -d':' -f3-|cut -d'T' -f1|sed 's/^ //g'`
timeCreation=`identify -verbose "$1"|grep "date:create"|cut -d':' -f3-|cut -d'T' -f2|cut -f1 -d'+'`

echo "The image was created on $dateCreation at $timeCreation"


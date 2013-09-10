#!/bin/bash

# This script, for each of its arguments (assumed to be photo files),
# will print the file name followed by the original date and time of
# creation, in the following example format:

# photo1.jpg 2012:10:02 13:47:18
# photo2.jpg 2012:10:02 13:47:24
# photo3.jpg 2012:10:20 17:28:05
# photo4.jpg 2012:10:25 19:18:13

# Hint: You will have to use the "identify" program with the "verbose"
# option, and look for the DateTimeOriginal exif image property.


###
#PLEASE NOTE On my system ,identify -verbose displayes no DateTimeOriginal exif property, using date:create
###
if [ "$#" -eq 0 ];then
    echo "Wrong number of arguments"
    exit 1
fi
for i in "$@";do
    dateCreation=`identify -verbose  "$i"|grep "date:create"|cut -d':' -f3-|cut -d'T' -f1|sed 's/^ //g'`
    timeCreation=`identify -verbose "$i"|grep "date:create"|cut -d':' -f3-|cut -d'T' -f2|cut -f1 -d'+'`
    echo "$i $dateCreation $timeCreation"
done


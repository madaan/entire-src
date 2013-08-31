#!/bin/bash
#sg
# This program should compile the latex file given as argument.  The
# tex file can be in any directory; its full path name or relative
# path name may be given as argument.  And if the latex compilation
# succeeds, it should tar-gzip the entire directory in which the latex
# file resides, from the parent directory, to a tgz file.  The name of
# the tgz file should be <dirname>.tgz where <dirname> is the name of
# the directory in which the latex file resides.  It should then move
# the tgz file to /tmp.

if [ "$#" -ne 1 ];then
   echo "Wrong number of arguments!";
   exit 1
fi

dirFile=`dirname $1` #get the directory name in which the file resides

echo "Directory name is : $dirFile"
cd $dirFile #move to that directory
echo "Currently in" `pwd`

texFile=`basename $1` #get the filename

latex $texFile > /dev/null #try to compile the latex

if [ "$?" -ne 0 ];then #see if it worked
    echo "Error creating the latex file, the program will now exit!";
    exit
fi

cd .. #shift to the parent directory
echo "Currently in" `pwd`
echo "Creating the tar..."
tar -cvzf $dirFile.tgz `dirname $dirFile` > /dev/null #create the tar

mv $dirFile.tgz /tmp






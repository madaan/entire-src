#/bin/bash

# This program should compile the latex file given as argument, a tex
# file assumed to be in the current/working directory.  And if the
# latex compilation succeeds, it should tar-gzip the entire current
# directory (from the current directory) to a tgz file called
# paper.tgz.  It should then move the paper.tgz file to /tmp.
echo "$#"
if [ "$#" -ne 1 ]
then
    echo "Wrong number of arguments!"
    exit
fi

latex $1
if [ "$?" -ne 0 ]
then
    echo "Latex failed!"
    echo "The program will now exit!"
    exit

else
    echo "Created dvi successfully!"
fi

tar --ignore-failed-read -cvzf  paper.tgz .
mv paper.tgz /tmp

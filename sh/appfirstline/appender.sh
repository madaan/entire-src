#sg
if [ $# -lt 2 ]
then
echo "Usage : ./appender.sh [name of the file to append to] [string to append 1]... [string to append n]";
exit 1;
fi
#create a temporary file
touch tmp;
#first dump the new strings to the file
count=$#;
for i in "$@"
do
if [ $count -ne $# ] #don't dump first arg, which is the filename
then
echo $i>>tmp;
fi
count=`expr $count - 1`;
done
#now write the old strings
filename=$1	
#tmpifs=$IFS;
#IFS='\\n'
 
while read oldstr
do
echo  $oldstr>>tmp
done<$1
#IFS=$tmpifs;
#rename tmp as your file, thus deleting the old file
mv tmp $1

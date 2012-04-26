#sg
for (( i=0;i<80;i++ ))
do
for (( j=0;j<80;j++))
do
x=`expr $i + $j`
x=`expr $x % 2`
if [ $x -eq 0 ];then
echo -e -n '\033[44m '
else
echo -e -n '\033[41m '
fi
done
echo
done

echo -e  '\033[0m'

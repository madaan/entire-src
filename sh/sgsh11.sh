#sg
for ((i=0;i<100;i++))
do
for ((j=0;j<100;j++))

do
x=`expr $i + $j`;
y=`expr $x % 2`
if [ $y -eq 0 ];then
echo -e -n '\033[47m '
else
echo -e -n '\033[40m '
fi

done
echo
done
echo -e '\033[0m'



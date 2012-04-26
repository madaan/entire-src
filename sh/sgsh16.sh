#sg
read n
for ((i=$n;i>=2;i--))
do
for ((j=2;j<=sqrt(i);j++))
do
pflag=1;

if [ `expr $i %  $j` -eq 0 ]
then
pflag=0;
break;
fi
done
if [ $pflag -eq 1 ];then
echo $i;
exit;
fi
done
 

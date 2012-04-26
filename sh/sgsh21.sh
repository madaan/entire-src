#sg
read n
temp=0
i=0
while [ $n -gt 0 ]
do
temp=`expr $temp \* 10`
modv=`expr $n % 10`
n=`expr $n / 10`
temp=`expr $temp + $modv`
done
echo $temp

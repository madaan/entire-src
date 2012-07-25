i=0
op=0
while [ $i -lt 100000 ] 
do
op=`expr $i \* 100`
echo "a "$op;
i=`expr $i + 1`
done

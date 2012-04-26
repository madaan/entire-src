#sg
echo "100"
var=100
for ((i=1; i<=100; i++))
do
echo "100"
var=100
for(( j=1; j<=100; j++))
do
echo $var
var=`expr $var + 100`
done
done


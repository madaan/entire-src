#
read n
case $n in
??????????)echo "LENGTH 10";;
esac
x=`expr $n : ".*"`
if [ $x -eq 10 ];then
echo "LENGTH 10"
fi


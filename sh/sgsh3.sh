#sg
read fn
if [ -f $fn ];then
mt=`ls -lt $fn|tr -s ' ' '|'|cut -d'|' -f8`
echo $mt
else
echo "FILE NOT FOUND"
fi

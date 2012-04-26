#sg
read fn
if [ -f $fn ];then
ls -l $fn|awk '{print $6,$7,$8}'
else
echo "FNE"
fi


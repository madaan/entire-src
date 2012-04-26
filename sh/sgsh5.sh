#sg
echo $PATH|tr ':' '\n'>tmp
for i in `cat tmp`;do
if [ -x $i ];then
echo -e $i "IS ACCESSIBLE\n"
fi
done
rm tmp

#sg
if [ $# -ne 2 ]
then
echo "WRONG NUMBER OF INPUTS "
exit 1 
fi

cd $1

for fn in `ls ../$2`
do
if [ -f $fn ];then
rm $fn;
fi
done


#sg
OFS=$IFS
IFS=:
set -- $PATH
for i in  "$@"
do
if [ -x $i ] 
then
echo "$i-YES"
else
echo "$i-NO"
fi
done
IFS=OFS

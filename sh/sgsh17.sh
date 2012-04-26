#
echo $x $y
cmp $1 $2&&echo "FILES SAME"
cmp $1 $2||echo "NOT SAME"

#sg
for ((i=5;i>=0;i--))
do
#print spaces
for ((j=i;j>=0;j--))
do
echo -n " " #same line,don't print newline
done
#now print '#'
for ((k=5-i;k>=0;k--))
do
echo -n " #"
done
echo 
done


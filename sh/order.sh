echo "Enter the input file name"
read ip

index=0

while read line ; do
        NAME[$index]="$line"
            index=$(($index+1))
            done < $ip

echo "Enter the file having order"
read od

while read line ; do
        echo "${NAME[$line]}";
            done < $od


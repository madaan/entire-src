#sg
#Printing figlet banner
space=" ";
op=$1;
i=0;
limit=$2;
while [ "$i" -lt "$limit" ]
do
op="$space""$1";
figlet -f slant "$op"
space="$space""     ";
sleep $3
i=`expr $i + 1`
done
 


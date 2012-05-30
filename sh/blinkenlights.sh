#sg
i=1;
if [ $# -lt 1 ]
then
echo -e "\nUsage : ./blinkenlights.sh [Delay in seconds]"
exit
fi
while [ $i -eq 1 ]
do
#turn on
setleds +num
sleep $1
setleds +caps
sleep $1
setleds +scroll
#turn off
setleds -num
sleep $1
setleds -caps
sleep $1
setleds -scroll
done

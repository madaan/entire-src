#sg
if [ $# -eq 0 ]
then
echo " Usage : $ ./SoundGen <YourMessage>  " 
exit -1
fi
which text2wave 2>/dev/null
if [ "$?" -eq 1 ]
then 
echo "'text2wave' not found,please try again after "
exit -1
fi
which play 2>/dev/null 
if [ "$?" -eq 1 ]
then 
echo "'play' required for running this script"
exit -1
fi

`echo "$@"|text2wave 1>a1.wav 2>/dev/null`
play a1.wav &>/dev/null
rm -f a1.wav
exit 0

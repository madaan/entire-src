
ld=~/irclogs/freenode
mailbak=~/mailbak
mkdir $mailbak 2> /dev/null
declare -a names=('#amarok.log' '#kde-in.log' '#kde-soc.log' '#bvplug.log'
'away.log');
declare -a paths=($ld/'#amarok.log' $ld/'#kde-in.log' $ld/'#kde-soc.log'
$ld/'#bvplug.log' $ld/'#away.log');
count=${#names[@]}
#while true
 #   do
        for (( i=0; i<${count}; i++ ))
            do
                filename=${names[i]}
                filePath=${paths[i]}
                echo $fileName;
                echo $filePath;
                echo $i;
                echo $count;
            done
 #    done



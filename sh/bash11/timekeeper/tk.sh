#sg
#As a shortcut, for var; do ...; done means for var in "$@"; do ...; done
function sleepandplay() {
    sleep $1
    mpg123 -n 30 $2 2&>1 /dev/null
}


index=0
ti=0
fi=0
for i;do
    if [ $(( $index % 2 )) -eq 0 ];then #add to timings
        timings[$ti]=$1
        let "ti = ti + 1"
    else
        files[$fin]=$1
        let "fin = fin + 1"
    fi
    let "index = index + 1"
    shift
done

for i in $(seq 0 $((${#timings[@]} - 1)));do
   echo "${timings[$i]}" "${files[$i]}"
   sleepandplay "${timings[$i]}" "${files[$i]}"
done

        

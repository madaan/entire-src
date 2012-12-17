c=("${BASH_ARGV[@]:3:"$#"}")
echo ${#c[@]}
for i in "${c[@]}"
do
echo $i
done

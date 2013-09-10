a[1]=1212
a[2]=2323
a[3]=1212
echo "${a[3]}"
declare -a arr1=(1 1 2 3 5 8)



for i in "${arr1[@]}";do
    echo $i
done

echo "with \$@"
for i in "$@";do
    echo $i
done

echo "with \$*"

for i in "$*";do
    echo $i
done

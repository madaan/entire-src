#sg
for i in ` ls *.$1`;do
    name=`expr "$i" : '^\([[:alpha:][:digit:]]\)*\..*';`
    echo "renaming $i to $name.$2"
done


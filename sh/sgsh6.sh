#sg
grep "$1" /etc/passwd>/dev/null||{echo "NOT FOUND";exit;} 
find -type f -user $1 -ls 1>&2 /dev/null|awk '{count++}
END{
printf("%d",count);
}'


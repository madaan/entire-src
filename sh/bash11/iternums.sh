#sg

for i in $(seq 91 110);do
     l=${#i}
    case $l in

        2) i=00$i
            ;;
        3) i=0$i
            ;;
        ?);;
    esac
    echo 2011-08-15-$i.jpg

done


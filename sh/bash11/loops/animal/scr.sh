#sg

while read line;do
    animalName=`echo $line|cut -f1 -d':'`
    soundName=`echo $line|cut -f2 -d':'`
    firstChar=`expr "$soundName" : '^\([a-z]\)'`
    echo "Old McDonald had a farm ei-ei-o"
    echo "On that farm he had a $animalName ei-ei-o"
    case $firstChar in
        [aeiou])
	    echo "With an $soundName-$soundName here, $soundName-$soundName there"
        echo "Here an $soundName there an $soundName, everywhere $soundName-$soundName"
        ;;
        ?)

	    echo "With a $soundName-$soundName here, $soundName-$soundName there"
        echo "Here a $soundName there a $soundName, everywhere $soundName-$soundName"

        ;;
    esac
        echo 
done <& 0
 echo "Old McDonald had a farm ei-ei-o"

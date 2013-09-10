#sg

for i in "$@";do
    case $i in
        "-dir")
           ls -l ~|grep "^d"
           ;;
       "-links")
           ls -l ~|grep "^l"
           ;;

       "-exec")
           find /home/aman -executable
           ;;
       ?)
           echo "Invalid option"
           ;;
   esac
done


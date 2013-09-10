#sg
#check if there is a need to create the file

if [ "test.tex" -nt "test.dvi" ];then
    echo "tex file updated, creating dvi"
    latex test.tex 2&>1 /dev/null
else
    echo "tex file is not updated, no need to create the dvi"
    exit
fi

if [ $? -ne 0 ];then
echo "Error creating dvi"
exit 1
fi


evince test.dvi

rm *.aux *.log

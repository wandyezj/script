make
if [ $? -eq 0 ];then
    cd bin
    echo
    ./script
    echo
    cd ..
fi

# make and run
# may need to run dos2unix if get errors
# sudo apt install dos2unix
clear
make
if [ $? -eq 0 ];
then
    cd bin
    echo
    ./script ./test/basic.test.txt
    echo
    cd ..
fi

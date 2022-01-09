# run flex
# http://alumni.cs.ucr.edu/~lgao/teaching/flex.html
#../flex/src/flex --help

rm -rf ./bin

mkdir bin

# direct to flex file
# can build github repository or
# sudo apt-get install flex
flex -o ./bin/scanner.c ./in.lex

clang -c ./bin/scanner.c -o ./bin/scanner.o
clang -o ./bin/scanner ./bin/scanner.o
#-o ./scanner/scanner


./bin/scanner ./lex.test.txt
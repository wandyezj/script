# variables
CC = clang

src = ./src
test = ./test

bin = ./bin
bin_test = $(bin)/test


test_files = $(bin_test)/basic.test.txt

# files
script = $(bin)/script

# rules
all:  $(script) $(test_files)

run:
	cd ./bin && ./script


$(script): bin $(bin)/script.o
	$(CC) -o $(script) $(bin)/script.o

$(bin)/script.o: $(src)/script.c
	$(CC) -c $(src)/script.c -o $(bin)/script.o

./bin:
	mkdir bin

$(bin_test)/basic.test.txt: $(test)/basic.test.txt bin/test
	cp $(test)/basic.test.txt $(bin)/test

bin/test:
	mkdir -p bin/test

clean:
	rm -rf bin
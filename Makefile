# variables
CC = clang

src = ./src
bin = ./bin

# files
script = $(bin)/script

# rules
all:  $(script) $(bin)/test.txt

run:
	cd ./bin && ./script


$(script): bin $(bin)/script.o
	$(CC) -o $(script) $(bin)/script.o

$(bin)/script.o: $(src)/script.c
	$(CC) -c $(src)/script.c -o $(bin)/script.o

./bin:
	mkdir bin

$(bin)/test.txt: $(src)/test.txt
	cp $(src)/test.txt $(bin)/test.txt

clean:
	
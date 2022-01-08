# makefile to construct script executable and tests

# variables
CC = clang

# sources
src = ./src
test = ./test

# outputs
# everything goes in bin to make it easy to .gitignore and clean
bin = ./bin
obj = $(bin)/obj
bin_test = $(bin)/test

#
# files
#
script = $(bin)/script

test_files = \
	$(bin_test)/basic.test.txt

script_objects = \
	$(obj)/script.o \
	$(obj)/constants.o \
	$(obj)/characters.o \
	$(obj)/tokenize.o

#
# rules
#

all: dirs $(script) $(test_files)

# makefile macros
# $@ : $<
# $@ item on left side of :
# $< first item on the right side of :

# main file
$(script): $(script_objects)
	$(CC) -o $@ $(script_objects)

# individual object files
# specific header dependencies
$(obj)/script.o: $(src)/script.c $(src)/constants.h $(src)/characters.h $(src)/tokenize.h
	$(CC) -c $< -o $@

$(obj)/constants.o: $(src)/constants.c $(src)/constants.h
	$(CC) -c $< -o $@

$(obj)/characters.o: $(src)/characters.c $(src)/characters.h
	$(CC) -c $< -o $@

$(obj)/tokenize.o: $(src)/tokenize.c $(src)/constants.h $(src)/tokenize.h 
	$(CC) -c $< -o $@

# headers
# simply look at source
$(src)%.h: $(src)%.h

# test files
$(bin_test)/%.test.txt: $(test)/%.test.txt $(bin_test)
	cp $< $@

# directories
dirs: $(bin) $(obj) $(bin_test)

$(bin):
	mkdir $@

$(obj):
	mkdir -p $@

$(bin_test):
	mkdir -p $@

clean:
	rm -rf $(obj)
	rm -rf $(bin)


# makefile to construct script executable and tests

# variables
CC = clang++ -std=c++20

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
	$(obj)/main.o \
	$(obj)/characters.o \
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
# specific header dependencies ( avoids need to recompile everything if a single header changes)
$(obj)/main.o: $(src)/main.cpp
	$(CC) -c $< -o $@

# $(obj)/constants.o: $(src)/constants.c $(src)/constants.h
# 	$(CC) -c $< -o $@

$(obj)/characters.o: $(src)/characters.cpp $(src)/characters.h
	$(CC) -c $< -o $@

# $(obj)/tokenize.o: $(src)/tokenize.c $(src)/tokenize.h $(src)/constants.h $(src)/characters.h
# 	$(CC) -c $< -o $@

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


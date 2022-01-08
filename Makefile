# variables
CC = clang



src = ./src
test = ./test

bin = ./bin
obj = $(bin)/obj
bin_test = $(bin)/test


test_files = $(bin_test)/basic.test.txt

# files
script = $(bin)/script

script_objects = $(bin)/script.o  $(bin)/constants.o $(bin)/characters.o $(bin)/tokenize.o

# rules
all: clean dirs $(script) $(test_files)

run:
	cd ./bin && ./script

# main file
$(script): bin $(script_objects)
	$(CC) -o $(script) $(script_objects)

# individual object files
# $(ODIR)/%.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $<

# $< first item in the dependency list (right side of :s)
# $@ name of item on left side of :

$(bin)/script.o: $(src)/script.c $(bin)/constants.h $(bin)/characters.h $(bin)/tokenize.h
	$(CC) -c $< -o $@

$(bin)/constants.o: $(src)/constants.c $(bin)/constants.h
	$(CC) -c $< -o $@

$(bin)/characters.o: $(src)/characters.c $(bin)/characters.h
	$(CC) -c $< -o $@

$(bin)/tokenize.o: $(src)/tokenize.c $(bin)/constants.h $(bin)/tokenize.h 
	$(CC) -c $< -o $@


# headers
$(bin)/constants.h:
$(bin)/tokenize.h:
$(bin)/characters.h:


# test files
$(bin_test)/basic.test.txt: $(test)/basic.test.txt bin/test
	cp $(test)/basic.test.txt $(bin)/test

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


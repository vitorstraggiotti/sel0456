
CC = gcc

CFLAGS = -c -g -Wall -pedantic

PROGNAME1 = sort
PROGNAME2 = sort-o

all: 
	@ echo " Make options:"
	@ echo "  make $(PROGNAME1)"
	@ echo "  make $(PROGNAME2)"
	@ echo "  make clear"
	@ echo ""
	@ mkdir build

############################################
$(PROGNAME1): ./build/sort.o
	$(CC) -o $@ $^

./build/sort.o: sort.c
	$(CC) $(CFLAGS) -o $@ $^

############################################
$(PROGNAME2): ./build/sort-o.o
	$(CC) -o $@ $^

./build/sort-o.o: sort-o.c
	$(CC) $(CFLAGS) -o $@ $^

############################################
.PHONY: clean
clean:
	rm -r ./build $(PROGNAME1) $(PROGNAME2)

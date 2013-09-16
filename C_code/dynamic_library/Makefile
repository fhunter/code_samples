CFLAGS=-Ilibrary
LDFLAGS=-Llibrary -ll1

all: main

main: main.o library/libl1.so

library/libl1.so: library
	make -C library

clean:
	make -C library clean
	rm -f *.o main *.*~

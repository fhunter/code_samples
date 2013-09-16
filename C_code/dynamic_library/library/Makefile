CFLAGS=-fPIC

all: libl1.so

libl1.so: file1.o file2.o
	$(CC) -shared -Wl,-soname,libl1.so -o libl1.so $^

clean:
	rm -f *.o *.so *.*~

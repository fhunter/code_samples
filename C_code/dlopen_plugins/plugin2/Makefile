CFLAGS=-fPIC

all: plugin.so

plugin.so: plugin.o
	$(CC) -shared -o $@ $^

clean:
	rm -f *.so *.o *.*~

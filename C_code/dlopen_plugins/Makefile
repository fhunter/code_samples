#Подключить библиотеку для работы с dlopen
LDFLAGS=-ldl

all: main plugins

#Это заставляет собрать плагины и копирует их в эту папку
plugins: plugin1/plugin.so plugin2/plugin.so
	cp plugin1/plugin.so ./plugin1.so
	cp plugin2/plugin.so ./plugin2.so

plugin1/plugin.so: plugin1
	make -C plugin1 all

plugin2/plugin.so: plugin2
	make -C plugin2 all

clean:
	make -C plugin1 clean
	make -C plugin2 clean
	rm -f *.o main *.*~ *.so

test: main plugins
	#This is a dirty hack, need improvement
	LD_LIBRARY_PATH=./ ./main

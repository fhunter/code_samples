# Флаг PIC - position independent code. нужен для сборки библиотеки
CFLAGS=-fPIC

all: libl1.so

libl1.so: file1.o file2.o
	#$(CC) - переменная, определяющая имя компилятора
	# -shared - флаг заставляющий собрать библиотеку
	# $^ - передаёт все файлы, от которых зависит данная цель - в данном случае - file1.o file2.o
	$(CC) -shared -Wl,-soname,libl1.so -o libl1.so $^

clean:
	rm -f *.o *.so *.*~

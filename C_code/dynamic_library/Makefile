# CFLAGS - это аргументы для этапа компиляции. Здесь - указано, что искать файлы include нужно в ./library
CFLAGS=-Ilibrary
# LDFLAGS - это аргументы для этапа линковки. Здесь указано, что библиотеки надо искать в ./library и подцепить библиотеку l1
# что разворачивается в имя libl1.so или libl1.so.<версия>
LDFLAGS=-Llibrary -ll1

all: main

main: main.o library/libl1.so

library/libl1.so: library
	#Сборка всего и вся в каталоге library
	make -C library

clean:
	#Вызов правила clean для каталога library
	make -C library clean
	rm -f *.o main *.*~

test: main
	#Префикс - заставляет игнорировать код возврата команды
	-./main
	#LD_LIBRARY_PATH определяет где искать библиотеки при запуске программы. (Ещё это определяется конфигом /etc/ld.so.conf )
	#Возможно можно сделать загрузку библиотек из более удобного места, но я с ходу не знаю как
	LD_LIBRARY_PATH=./library ./main

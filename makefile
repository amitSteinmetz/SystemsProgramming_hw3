all: txtfind isort

isort: isort.c 
	gcc -Wall -g -o isort isort.c

txtfind: txtfind.c
	gcc -Wall -g -o txtfind txtfind.c

clean: 
	rm -f *.o txtfind isort
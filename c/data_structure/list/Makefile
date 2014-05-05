
all: test radix_sort

test:
	gcc -g list.c testlist.c list.h fatal.h -o testlist.o
	./testlist.o

radix_sort:
	gcc -g list.c radix_sort.c list.h fatal.h -o radix_sort.o -lm
	./radix_sort.o

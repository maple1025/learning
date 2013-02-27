sort: sort.o stringarray.a
	cc -o sort sort.o stringarray.a

sort.o: sort.c stringarray.h
	cc -c sort.c

stringarray.a: stringarray.c
	cc = c stringarray.c
	ar ur stringarray.a stringarray.o

clean:
	rm sort sort.o stringarray.a stringarray.o
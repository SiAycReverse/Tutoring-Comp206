CC=gcc

all: ass3

ass3: main.o m3.o m1.o m2.o
	gcc -o ass3 main.o

main.o: main.c m1.h m3.h
	gcc -c main.c

m3.o: m3.c m3.h m1.h
	gcc -c m3.c

m1.o: m1.c m1.h m3.h m2.h
	gcc -c m1.c

m2.o: m2.c m2.h m3.h
	gcc -c m2.c

clean:
	rm -f ass3 *.o *.gch

run: ass3
	./ass3

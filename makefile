CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: all clean

crawler : main.o liblista.o utils.o
	$(CC) main.o liblista.o utils.o -o crawler

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

liblista.o : liblista.h liblista.c 
	$(CC) $(CFLAGS) -c liblista.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all
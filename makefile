CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: all clean

lattes : main.o  liblist.o utils.o 
	$(CC) main.o  liblist.o utils.o -o lattes

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

liblist.o : liblist.h liblist.c 
	$(CC) $(CFLAGS) -c liblist.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all

purge:
	rm *.o lattes
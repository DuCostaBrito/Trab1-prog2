CC = gcc
CFLAGS = -std=c99 -Wall -D_DEFAULT_SOURCE -g

.PHONY: all clean

lattes : main.o  liblist.o utils.o 
	$(CC) $(CFLAGS) main.o  liblist.o utils.o -o lattes

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
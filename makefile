CC = gcc
CFLAGS = -std=c99 -Wall -D_DEFAULT_SOURCE -g

.PHONY: all clean

lattes : main.o events.o utils.o 
	$(CC) $(CFLAGS) main.o events.o utils.o -o lattes

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

events.o : events.h events.c 
	$(CC) $(CFLAGS) -c events.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all

purge:
	rm *.o lattes
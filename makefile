CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: all clean

crawler : main.o encoding.o utils.o
	$(CC) main.o encoding.o utils.o -o crawler

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

encoding.o : encoding.h encoding.c 
	$(CC) $(CFLAGS) -c encoding.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all
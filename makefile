CC = gcc
CFLAGS = -std=c99 -Wall -D_DEFAULT_SOURCE -g

.PHONY: all clean

lattes : main.o  libpool.o liblist.o years.o utils.o 
	$(CC) $(CFLAGS) main.o  libpool.o liblist.o years.o utils.o -o lattes

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

libpool.o : libpool.h libpool.c 
	$(CC) $(CFLAGS) -c libpool.c 

liblist.o : liblist.h liblist.c 
	$(CC) $(CFLAGS) -c liblist.c 

years.o : years.h years.c 
	$(CC) $(CFLAGS) -c years.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all

purge:
	rm *.o lattes
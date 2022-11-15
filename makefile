CC = gcc
CFLAGS = -std=c99 -Wall -D_DEFAULT_SOURCE -g

.PHONY: all clean

lattes : main.o  libpool.o liblist.o libbst.o utils.o 
	$(CC) $(CFLAGS) main.o  libpool.o liblist.o libbst.o utils.o -o lattes

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

libpool.o : libpool.h libpool.c 
	$(CC) $(CFLAGS) -c libpool.c 

liblist.o : liblist.h liblist.c 
	$(CC) $(CFLAGS) -c liblist.c 

libbst.o : libbst.h libbst.c 
	$(CC) $(CFLAGS) -c libbst.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all

purge:
	rm *.o lattes
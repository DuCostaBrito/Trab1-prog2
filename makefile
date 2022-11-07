CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: all clean

crawler : main.o libbst.o libstack.o utils.o 
	$(CC) main.o libbst.o libstack.o utils.o -o crawler

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

libbst.o : libbst.h libbst.c 
	$(CC) $(CFLAGS) -c libbst.c 

libstack.o : libstack.h libstack.c 
	$(CC) $(CFLAGS) -c libstack.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all
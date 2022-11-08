CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: all clean

lattes : main.o libbst.o liblist.o libstack.o utils.o 
	$(CC) main.o libbst.o liblist.o libstack.o utils.o -o lattes

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c 

libbst.o : libbst.h libbst.c 
	$(CC) $(CFLAGS) -c libbst.c 

liblist.o : liblist.h liblist.c 
	$(CC) $(CFLAGS) -c liblist.c 

libstack.o : libstack.h libstack.c 
	$(CC) $(CFLAGS) -c libstack.c 

utils.o : utils.h utils.c 
	$(CC) $(CFLAGS) -c utils.c 

clean :
	rm *.o *~ all

purge:
	rm *.o lattes
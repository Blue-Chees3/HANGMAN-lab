CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o string.o

all: string_driver

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

main.o: main.c my_string.h string.h
	$(CC) $(CFLAGS) -c main.c 


my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c
 

clean:
	rm -f  string_driver *.o


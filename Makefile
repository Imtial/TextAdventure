# the compiler: gcc for C program, define as g++ for C++
CC = gcc
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -c -g -Wall
# the build target executable:
items.o: items.c
	$(CC) $(CFLAGS) items.c

rooms.o: rooms.c
	$(CC) $(CFLAGS) rooms.c

adventure.o: adventure.c
	$(CC) $(CFLAGS) adventure.c

adventure: items.o rooms.o adventure.o
	$(CC) items.o rooms.o adventure.o -o adventure

clean:
	rm *.o adventure
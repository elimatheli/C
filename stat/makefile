CC = gcc
CFLAGS = -W -Wall -ansi -pedantic -O0 -g -fsanitize=address

all: stat

stat: stat.o
	$(CC) $(CFLAGS) -o stat stat.o


clean:
	rm -f *.o stat *~


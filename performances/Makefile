CC = gcc
CFLAGS = -W -Wall

all: cat mcat test_perf

cat: cat.o
	$(CC) $(CFLAGS) -o cat cat.o

mcat: mcat-lib.o
	$(CC) $(CFLAGS) -o mcat_lib mcat-lib.o

test_perf: cat mcat
	./script.sh


clean:
	rm -f *.o mcat_lib cat *.png *.dat *.gnu *~


CC = gcc
CFLAGS = -W -Wall -ansi -pedantic -O0 -g -fsanitize=address

all: lstar

lstar: lstar.o
	$(CC) $(CFLAGS) -o lstar lstar.o

test: lstar
	$(info ************ Création des fichiers test ************)
	touch test
	touch vide
	$(info ************ Remplissage de 20 octets dans test ************)
	echo ceci est un test ou >> test
	$(info ************  Création de l archive test.tar ************)
	tar -H ustar -c vide test > test.tar
	$(info ************  Execution de lstar sur test ************)
	tar -H ustar -c vide test | ./lstar
	$(info ************  Suppresion des fichiers après la commande ************)
	rm -f test vide test.tar

clean:
	rm -f *.o lstar *~


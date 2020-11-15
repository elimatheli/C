EXEC=test_tri test_nomine test_quicksort_generique
all: $(EXEC)


test_tri: test_tri.o init_rand.o quicksort_int.o
	gcc -Wall -Werror -ansi -pedantic -o test_tri test_tri.o quicksort_int.o init_rand.o
test_nomine: test_nomine.o func_nomine.o
	gcc -Wall -Werror -ansi -pedantic -o test_nomine test_nomine.o func_nomine.o
test_quicksort_generique: test_quicksort_generique.o func_nomine.o quicksort_generique.o
	gcc -Wall -Werror -ansi -pedantic -o test_quicksort_generique test_quicksort_generique.o func_nomine.o quicksort_generique.o


init_rand.o: init_rand.c
	gcc -Wall -Werror -ansi -pedantic -c init_rand.c
quicksort_int.o: quicksort_int.c 
	gcc -Wall -Werror -ansi -pedantic -c quicksort_int.c
test_tri.o: test_tri.c macros.h fonctions_ext.h Nomine_s.h
	gcc -Wall -Werror -ansi -pedantic -c test_tri.c
func_nomine.o: func_nomine.c Nomine_s.h
	gcc -Wall -Werror -ansi -pedantic -c func_nomine.c
test_nomine.o: test_nomine.c macros.h Nomine_s.h fonctions_ext.h
	gcc -Wall -Werror -ansi -pedantic -c test_nomine.c
test_quicksort_generique.o: test_quicksort_generique.c macros.h Nomine_s.h fonctions_ext.h
	gcc -Wall -Werror -ansi -pedantic -c test_quicksort_generique.c



clean:
	rm -rf *.o
	rm -rf $(EXEC)

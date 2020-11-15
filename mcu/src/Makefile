all: mcu_test mcu_wc mcu_ww mcu_wl mcu_rev mcu_uniq mcu_xxd

mcu_test: mcu_putint.o mcu_fatal.o mcu_readl.o mcu_test.o
	gcc -Wall -Werror -ansi -pedantic -o mcu_test mcu_putint.o mcu_fatal.o mcu_readl.o mcu_test.o
mcu_wc: mcu_wc.o mcu_putint.o
	gcc -Wall -Werror -ansi -pedantic -o mcu_wc mcu_wc.o mcu_putint.o
mcu_ww: mcu_ww.o mcu_putint.o
	gcc -Wall -Werror -ansi -pedantic -o mcu_ww mcu_ww.o mcu_putint.o
mcu_wl: mcu_wl.o mcu_putint.o mcu_readl.o mcu_fatal.o
	gcc -Wall -Werror -ansi -pedantic -o mcu_wl mcu_wl.o mcu_putint.o mcu_readl.o mcu_fatal.o
mcu_rev: mcu_rev.o mcu_putint.o mcu_readl.o mcu_fatal.o
	gcc -Wall -Werror -ansi -pedantic -o mcu_rev mcu_rev.o mcu_putint.o mcu_readl.o mcu_fatal.o
mcu_uniq: mcu_uniq.o mcu_putint.o mcu_readl.o mcu_fatal.o
	gcc -Wall -Werror -ansi -pedantic -o mcu_uniq mcu_uniq.o mcu_putint.o mcu_readl.o mcu_fatal.o
mcu_xxd: mcu_xxd.o mcu_putint.o
	gcc -Wall -Werror -ansi -pedantic -o mcu_xxd mcu_xxd.o mcu_putint.o

putint.o: putint.c
	gcc -Wall -Werror -ansi -pedantic -c mcu_putint.c
mcu_fatal.o: mcu_fatal.c mcu_fatal.h mcu_macros.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_fatal.c
mcu_readl.o: mcu_readl.c mcu_fatal.h mcu_macros.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_readl.c
mcu_test.o: mcu_test.c mcu_macros.h mcu_fatal.h mcu_readl.h mcu_putint.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_test.c
mcu_wc.o: mcu_wc.c mcu_putint.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_wc.c
mcu_ww.o: mcu_ww.c mcu_putint.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_ww.c
mcu_wl.o: mcu_wl.c mcu_putint.h mcu_readl.h mcu_macros.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_wl.c
mcu_rev.o: mcu_rev.c mcu_putint.h mcu_readl.h mcu_macros.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_rev.c
mcu_uniq.o: mcu_uniq.c mcu_putint.h mcu_readl.h mcu_macros.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_uniq.c
mcu_xxd.o: mcu_xxd.c mcu_putint.h
	gcc -Wall -Werror -ansi -pedantic -c mcu_xxd.c

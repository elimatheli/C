CC      = gcc

CFLAGS  = -Wall -Wextra
CFLAGS += -g

LDFLAGS = -g -pthread -lpthread

TOUS := aleazard compteur-gc rdv compteur-gc-thread

tout: ${TOUS}

gnuplot: tout
	./script.sh

aleazard: aleazard.c
	${CC} ${CFLAGS} $< -o $@ ${LDFLAGS}

compteur-gc: compteur-gc.c
	${CC} ${CFLAGS} $< -o $@ ${LDFLAGS}

rdv: rdv.c
	${CC} ${CFLAGS} $< -o $@ ${LDFLAGS}

compteur-gc-thread: compteur-gc-thread.c
	${CC} ${CFLAGS} $< -o $@ ${LDFLAGS}

clean:
	rm -f core *.o res.dat run.gnu test res.png

realclean: clean
	rm -f ${TOUS}

.PHONY: all clean realclean

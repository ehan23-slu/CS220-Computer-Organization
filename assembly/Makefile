CFLAGS = -Wall

ifdef DEBUG
CFLAGS += -g
endif

ss: ss.o sum_squares.o
	gcc ${CFLAGS} -o ss ss.o sum_squares.o

ss.o: ss.c
	gcc ${CFLAGS} -c ss.c

sum_squares.o: sum_squares.s
	gcc ${CFLAGS} -c sum_squares.s

clean:
	rm -rf *.o ss
CC=gcc
CFLAGS=${DEBUGINFO} -I"../../Include/Base" ${MODE} -std=c99  -Wno-main -Wall

all: gp_example
clean:;	rm -f *.o *.exe

gp_example: gp_error.o gp_types.o gp_error_codes.o gp_example.o
	gcc ${CFLAGS} -o "${OUTPUT}\$@" $^

gp_error.o: gp_error_codes.c
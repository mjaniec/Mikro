CC=gcc
CFLAGS=-I"../include" -D${MODE} -std=c99

all:	clean debug
clean:;	rm -f *.o *.exe

debug:;	make _all MODE=DEBUG
release:;make _all

_all:	gp_example
gp_example:gp_error.o gp_types.o gp_error_codes.o
gp_error.o:gp_error_codes.o


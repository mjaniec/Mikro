CC=gcc
CFLAGS=${DEBUGINFO} -I"${INCLUDE}/Base" -I"${INCLUDE}/Math" -D${MODE} -std=c99  -Wno-main -Wall

all: clean libGPMath.a
clean:;	rm -f *.o *.exe *.a

libGPMath.a: gp_Math.o
	ar -r ${OUTPUT}\$@ $^
	
%.o:%.c
	gcc -c ${CFLAGS} -o $@ $<

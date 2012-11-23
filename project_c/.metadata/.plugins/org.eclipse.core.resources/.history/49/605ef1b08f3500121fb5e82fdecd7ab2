<<<<<<< HEAD

CC="E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/gcc.exe"
TOOLCHAIN="--sysroot=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi\bin"
CFLAGS= ${TOOLCHAIN} -fPIC ${DEBUGINFO} -I"../../Include/Base" -D${MODE} -std=c99  -Wno-main -Wall

all: gp_example libGPBase.so
clean:;	rm -f *.o *.exe

libGPBase.so: gp_error.o gp_types.o gp_error_codes.o
	${CC} ${CFLAGS} -shared -Wl,-soname,${@} -o ${OUTPUT}/${@}.1.0.1 $^

gp_example: gp_error.o gp_types.o gp_error_codes.o gp_example.o
	${CC} ${CFLAGS} -o "${OUTPUT}/$@" $^
	
=======
CC=gcc
CFLAGS=${DEBUGINFO} -I"../../Include/Base" ${MODE} -std=c99  -Wno-main -Wall

all: gp_example
clean:;	rm -f *.o *.exe

gp_example: gp_error.o gp_types.o gp_error_codes.o gp_example.o
	gcc ${CFLAGS} -o "${OUTPUT}\$@" $^

>>>>>>> b74117b7844fb7cf113fd3a8e1fe727947193f51
gp_error.o: gp_error_codes.c
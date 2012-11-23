CC=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/gcc.exe
AR=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/ar.exe
LD=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/ld.exe

CFLAGS=${DEBUGINFO} -I"../../Include/Base" -D${MODE} -std=c99  -Wno-main -Wall

all: gp_example libGPBase.a
clean:;	rm -f *.o *.exe

libGPBase.a: gp_error.o gp_types.o gp_error_codes.o
	${AR} -r ${OUTPUT}\$@ $^

gp_example: gp_error.o gp_types.o gp_error_codes.o gp_example.o
	${CC} ${CFLAGS} -o "${OUTPUT}\$@" $^
	
gp_error.o: gp_error_codes.c
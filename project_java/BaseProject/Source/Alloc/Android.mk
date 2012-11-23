CC=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/gcc.exe
AR=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/ar.exe
LD=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/ld.exe

CFLAGS=${DEBUGINFO} -I"${INCLUDE}/Base" -I"${INCLUDE}/Math" -I"${INCLUDE}/Alloc" -D${MODE} -std=c99  -Wno-main -Wall

all: clean libGPAlloc.a 
clean:;	rm -f *.o *.exe *.a

libGPAlloc.a: gp_Alloc.o
	${AR} -r ${OUTPUT}\$@ $^
	
%.o:%.c
	${CC} -c ${CFLAGS} -o $@ $<
	
GPAlloc : 
	${CC} ${CFLAGS} -L"${OUTPUT}" -lGPAlloc -lGPBase -lGPMath -o test
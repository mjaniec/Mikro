CC="E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/gcc.exe"
TOOLCHAIN="--sysroot=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin"
CFLAGS=${TOOLCHAIN}  ${DEBUGINFO} -I"${INCLUDE}/Base" -I"${INCLUDE}/Math" -I"${INCLUDE}/Alloc" -D${MODE} -std=c99  -Wno-main -Wall 

all: clean libGPAlloc.so 
clean:;	rm -f *.o *.exe *.a

libGPAlloc.so: gp_Alloc.o
	${CC} ${CFLAGS} -L${OUTPUT} -shared -Wl,-soname,${@} -o ${OUTPUT}/${@}.1.0.1 $^ ${OUTPUT}/libGPBase.so.1.0.1
	
%.o:%.c
	${CC} -c ${CFLAGS} -o $@ $<
	
GPAlloc : 
	${CC} ${CFLAGS} -L"${OUTPUT}" -lGPAlloc -lGPBase -lGPMath -o test
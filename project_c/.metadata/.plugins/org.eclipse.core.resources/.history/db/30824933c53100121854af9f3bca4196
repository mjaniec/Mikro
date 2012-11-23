CC="E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin/gcc.exe"
TOOLCHAIN="--sysroot=E:/Android/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/arm-linux-androideabi/bin"
CFLAGS=${TOOLCHAIN} ${DEBUGINFO} -I"${INCLUDE}/Base" -I"${INCLUDE}/Math" -D${MODE} -std=c99  -Wno-main -Wall

all: clean libGPMath.so
clean:;	rm -f *.o *.exe *.a

libGPMath.so: gp_Math.o
	echo ${OUTPUT}
	${CC} ${CFLAGS} -shared -Wl,-soname,${@} -o ${OUTPUT}/${@}.1.0.1 $^
	
%.o:%.c
	${CC} -c ${CFLAGS} -o $@ $<

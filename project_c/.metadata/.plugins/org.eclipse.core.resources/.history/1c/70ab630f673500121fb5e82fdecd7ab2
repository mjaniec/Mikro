CC=gcc
HEADERS=-I"${INCLUDE}/Base" -I"${INCLUDE}/Math" -I"${INCLUDE}/Alloc" -I"${INCLUDE}/Instance" -I"${INCLUDE}/InstanceLearner" -I"${INCLUDE}/InputGesture" -I"${INCLUDE}/OutputGesture" -I"${INCLUDE}/GestureStore" 
CFLAGS=${DEBUGINFO} ${HEADERS} ${MODE} -std=c99  -Wno-main -Wall

all: gp_Main.o

gp_Main.o: jni/gp_Main.c
	mkdir -p ${OUTPUT}
	${CC} -c ${CFLAGS} -o "${OUTPUT}\$@" $^
	ar -r "${OUTPUT}\libgpMain.a" "${OUTPUT}\$@" 
	make all -C "${INCLUDE}\Base\Generator"
	
	
gp_Main.s: jni/gp_Main.c
	${CC} -E ${CFLAGS} -o "${OUTPUT}\$@" $^
	
clean:
	make clean -C "${INCLUDE}\Base\Generator"
	rm -rf ${OUTPUT}
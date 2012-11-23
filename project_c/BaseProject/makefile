<<<<<<< HEAD
SUBDIRS ?= Include Source
OUTPUT="C:/Users/Janiec/Documents/GitHub/Mikro/project_c/BaseProject/Output"
=======
CC=gcc
HEADERS=-I"${INCLUDE}/Base" -I"${INCLUDE}/Math" -I"${INCLUDE}/Alloc" -I"${INCLUDE}/Instance" -I"${INCLUDE}/InstanceLearner" -I"${INCLUDE}/InputGesture" -I"${INCLUDE}/OutputGesture" -I"${INCLUDE}/GestureStore" 
CFLAGS=${DEBUGINFO} ${HEADERS} ${MODE} -std=c99  -Wno-main -Wall
>>>>>>> b74117b7844fb7cf113fd3a8e1fe727947193f51

all: gp_Main.o

gp_Main.o: jni/gp_Main.c
	mkdir -p ${OUTPUT}
	${CC} -c ${CFLAGS} -o "${OUTPUT}\$@" $^
	ar -r "${OUTPUT}\libgpMain.a" "${OUTPUT}\$@" 
	make all -C "${INCLUDE}\Base\Generator"
	make all -C "Source\Base"
	
	
gp_Main.s: jni/gp_Main.c
	${CC} -E ${CFLAGS} -o "${OUTPUT}\$@" $^
	
clean:
	make clean -C "${INCLUDE}\Base\Generator"
	make clean -C "Source\Base"
	rm -rf ${OUTPUT}

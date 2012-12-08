
INCLUDES = -I"../../BaseProject" -I"../../BaseProject/Include/Alloc" -I"../../BaseProject/Include/Base" -I"../../BaseProject/Include/Gestures"
INCLUDES +=-I"../../BaseProject/Include"  -I"../Include/" -I"../../Base/Project/Include/Math" -I"../../BaseProject/InOut"

LIBS += -L"../lib" -l cunit

RM := rm -rf

all: clean Tests.exe


# Tool invocations
Tests.exe:
	gcc -std=c99  -Wall $(INCLUDES) ../Source/AllTests.c  $(LIBS) -o Tests.exe -g3  
	-@echo ' '

# Other Targets
clean:
	-$(RM)  Tests.exe
	-@echo ' '

.PHONY: all clean


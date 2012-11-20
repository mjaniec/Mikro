SUBDIRS ?= Include Source
OUTPUT="C:/Users/Janiec/Documents/GitHub/Mikro/project_c/BaseProject/Output"

all: ${subdirs}
	mkdir -p ${OUTPUT}
	for dir in $(SUBDIRS); do \
		$(MAKE) $@ -C $$dir; \
	done
   
clean: ${subdirs}
	for dir in $(SUBDIRS); do \
		$(MAKE) $@ -C $$dir; \
	done
	rm -rf Output
                       
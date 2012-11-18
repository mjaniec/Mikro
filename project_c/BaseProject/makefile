SUBDIRS ?= Include Source

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
                       
SUBDIRS = Base Math Alloc

all: ${subdirs}
	for dir in $(SUBDIRS); do \
		$(MAKE) $@ -C $$dir; \
	done
   
clean: ${subdirs}
	for dir in $(SUBDIRS); do \
		$(MAKE) $@ -C $$dir; \
	done
                       
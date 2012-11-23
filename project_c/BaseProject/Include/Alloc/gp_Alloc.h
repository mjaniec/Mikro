#ifndef GP_ALLOC_H
#define GP_ALLOC_H

#include "../Base/gp_types.h"

#ifndef gpAlloc_MAX_MEM
#define gpAlloc_MAX_MEM 1000
#endif

gpVoid* gpAlloc_alloc(gpInt size);
gpVoid gpAlloc_free(gpVoid* ptr);

#endif

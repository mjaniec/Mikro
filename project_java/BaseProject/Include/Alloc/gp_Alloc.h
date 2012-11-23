#include "../Base/gp_types.h"

#ifndef GP_ALLOC_H
#define GP_ALLOC_H

#ifndef gp_MAX_MEM
#define gp_MAX_MEM 1000
#endif

gpVoid* gpAlloc_alloc(gpInt size);
gpVoid gpAlloc_free(gpVoid* ptr);

#endif

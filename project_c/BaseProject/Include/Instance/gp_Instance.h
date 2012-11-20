#ifndef GPINSTANCE_H_
#define GPINSTANCE_H_

#include "../Base/gp_types.h"
#include "../InputGesture/gp_InputGesture.h"

typedef struct gpInstance {
	// the feature vector
	gpFloat* vector;

	gpWord size;

	// the label can be null
	gpString label;

	// the id of the instance
	gpWord id;
} gpInstance;

gpInstance* gpInstance_createInstance(gpInt, gpInt, gpInputGesture*, gpString);

#endif

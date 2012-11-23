#ifndef gp_Instance_c
#define gp_Instance_c

#include "..\..\Include\Instance\gp_Instance.h"
#include "..\..\Include\GestureStore\gp_GestureStore.h"
#include "..\..\Include\Alloc\gp_Alloc.h"

gpInt _gpInstance_SEQUENCE_SAMPLE_SIZE = 16;
gpInt _gpInstance_PATCH_SAMPLE_SIZE = 16;
/*
gpFloat[] ORIENTATIONS = {
		0, gpDiv(gpMath_PI, 4), gpDiv(gpMath_PI, 2), gpDiv(gpMul(gpMath_PI, 3, 4)),
		gpMath_PI, -0, gpDiv(gpNeg(gpMath_PI), 4), gpDiv(gpNeg(gpMath_PI), 2),
		gpDiv(gpMul(gpNeg(gpMath_PI), 3), 4), gpNeg(gpMath_PI)
};
*/


gpInstance* New(gpWord id, gpFloat* sample, gpWord size, gpString label)
{
	gpInstance* instance = gpAlloc_alloc(sizeof(gpInstance));
	instance->id = id;
	instance->vector = sample;
	instance->size = size;
	instance->label = label;
	return instance;
}

void _gpInstance_normalize(gpInstance* this) {
	gpFloat* sample = this->vector;
	gpFloat sum = 0;

	for (gpInt i = 0; i < this->size; i++) {
		sum = gpAdd(sum, gpMul(sample[i], sample[i]));
	}

	//gpFloat magnitude = gpMath_sqrt(sum);
	//for (gpInt i = 0; i < this->size; i++) {
//		sample[i] = gpDiv(sample[i], magnitude);
//	}
}

gpInstance* gpInstance_createInstance(gpInt sequenceType, gpInt orientationType, gpInputGesture* gesture, gpString label)
{
        gpFloat* pts;
        gpUByte size;
        gpInstance* instance;
        if (sequenceType == gpGestureStore_SEQUENCE_SENSITIVE) {
  //          pts = temporalSampler(orientationType, gesture, &size);
            instance = New(gesture->id, pts, size, label);
            _gpInstance_normalize(instance);
        } else {
    //        pts = spatialSampler(gesture, &size);
            instance = New(gesture->id, pts, size, label);
        }
        return instance;
    }


/*
private static float[] spatialSampler(Gesture gesture) {
    return GestureUtils.spatialSampling(gesture, PATCH_SAMPLE_SIZE, false);
}
*/
/*
gpFloat* temporalSampler(gpInt orientationType, gpGesture* gesture) {
    gpFloat* pts = GestureUtils.temporalSampling(gesture.getStrokes().get(0),
            SEQUENCE_SAMPLE_SIZE);
    float[] center = GestureUtils.computeCentroid(pts);
    float orientation = (float)Math.atan2(pts[1] - center[1], pts[0] - center[0]);

    float adjustment = -orientation;
    if (orientationType != GestureStore.ORIENTATION_INVARIANT) {
        int count = ORIENTATIONS.length;
        for (int i = 0; i < count; i++) {
            float delta = ORIENTATIONS[i] - orientation;
            if (Math.abs(delta) < Math.abs(adjustment)) {
                adjustment = delta;
            }
        }
    }

    GestureUtils.translate(pts, -center[0], -center[1]);
    GestureUtils.rotate(pts, adjustment);

    return pts;
}

*/
#endif

#ifndef GP_GESTURESTORE_H_
#define GP_GESTURESTORE_H_

#include "../Base/gp_types.h"

gpInt gpGestureStore_SEQUENCE_INVARIANT = 1;
// when SEQUENCE_SENSITIVE is used, only single stroke gestures are currently allowed
gpInt gpGestureStore_SEQUENCE_SENSITIVE = 2;

// ORIENTATION_SENSITIVE and ORIENTATION_INVARIANT are only for SEQUENCE_SENSITIVE gestures
gpInt gpGestureStore_ORIENTATION_INVARIANT = 1;
// at most 2 directions can be recognized
gpInt gpGestureStore_ORIENTATION_SENSITIVE = 2;

#endif

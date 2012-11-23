#include "gp_Main.c"
#include "gpGestures_GP_Delegator.c"
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     gpGestures_GP_Delegator
 * Method:    recognize
 * Signature: (II[[FI)Z
 */
JNIEXPORT jboolean JNICALL Java_gpGestures_GP_1Delegator_recognize
  (JNIEnv *, jobject, jint, jint, jobjectArray, jint){

}

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isTap
 * Signature: ()LgpGestures/GP_Tap;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isTap
  (JNIEnv *, jobject);

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isPress
 * Signature: ()LgpGestures/GP_Press;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isPress
  (JNIEnv *, jobject);

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isFlick
 * Signature: ()LgpGestures/GP_Flick;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isFlick
  (JNIEnv *, jobject);

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isMove
 * Signature: ()LgpGestures/GP_Move;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isMove
  (JNIEnv *, jobject);

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isRotate
 * Signature: ()LgpGestures/GP_Rotate;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isRotate
  (JNIEnv *, jobject);

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isScroll
 * Signature: ()LgpGestures/GP_Scroll;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isScroll
  (JNIEnv *, jobject);

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isTwoFingerScroll
 * Signature: ()LgpGestures/GP_TwoFingerScroll;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isTwoFingerScroll
  (JNIEnv *, jobject);

/*
 * Class:     gpGestures_GP_Delegator
 * Method:    isZoom
 * Signature: ()LgpGestures/GP_Zoom;
 */
JNIEXPORT jobject JNICALL Java_gpGestures_GP_1Delegator_isZoom
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
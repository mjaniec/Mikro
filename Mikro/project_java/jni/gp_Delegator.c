/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <android/log.h>
#define __ANDROID
#include "../../project_c/BaseProject/Source/gp_Main.c"
/* Header for class gp_Delegator */

#ifndef _Included_gp_Delegator
#define _Included_gp_Delegator
#ifdef __cplusplus
extern "C" {
#endif

#define jnull 0;
 
static gpFloat jf2gpf(jfloat x){
	long y=x;
	return y*GP_FLOAT_BASE;
}

static jfloat gpf2jf(gpFloat x){
	jfloat y=x;
	return y/GP_FLOAT_BASE;
}
 

/*
 * Class:     gp_Delegator
 * Method:    recognize
 * Signature: (II[FI)Z
 */

JNIEXPORT jint JNICALL Java_gp_Delegator_recognize(JNIEnv *env, jobject self, jint jaction, jint jsize, jfloatArray jtab, jint jtime){
	jfloat* ctab=(*env)->GetFloatArrayElements(env,jtab,0);
	if(!ctab) return false;
	
	gpMotionEvent motionEvent;
	
	motionEvent.actionType=jaction;
	motionEvent.size=jsize;
	motionEvent.time=jtime;
	motionEvent.coordinates=gpAlloc_alloc(jsize*sizeof(gpFloat)*2)$r0;
	
	
	for(int i=0; i<2*jsize; ++i){
		motionEvent.coordinates[i]=jf2gpf(ctab[i]);
	}
		
	(*env)->ReleaseFloatArrayElements(env,jtab,ctab,0);

	gpRecognize(&motionEvent);
	return true;
}


/*
 * Class:     gp_Delegator
 * Method:    isTap
 * Signature: ()Lgp/Tap;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isTap(JNIEnv *env, jobject self){
	if(!gp_isTap)return jnull;
	gp_isTap=false;

	jclass clazz=(*env)->FindClass(env,"gp/Tap");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FF)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor,gpf2jf(gp_TapData.x),gpf2jf(gp_TapData.y));
}


/*
 * Class:     gp_Delegator
 * Method:    isPress
 * Signature: ()Lgp/Press;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isPress(JNIEnv *env, jobject self){
	if(!gp_isPress)return jnull;
	gp_isPress=false;

	jclass clazz=(*env)->FindClass(env,"gp/Press");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FF)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor,gpf2jf(gp_PressData.x),gpf2jf(gp_PressData.y));
}

/*
 * Class:     gp_Delegator
 * Method:    isFlick
 * Signature: ()Lgp/Flick;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isFlick(JNIEnv *env, jobject self){
	if(!gp_isFlick)return jnull;
	gp_isFlick=false;

	jclass clazz=(*env)->FindClass(env,"gp/Flick");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FFZ)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor,gpf2jf(gp_FlickData.x),gpf2jf(gp_FlickData.y),gp_FlickData.direction);
}

/*
 * Class:     gp_Delegator
 * Method:    isMove
 * Signature: ()Lgp/Move;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isMove(JNIEnv *env, jobject self){
	if(!gp_isMove)return jnull;
	gp_isMove=false;

	jclass clazz=(*env)->FindClass(env,"gp/Move");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FFFFFF)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor,
			gpf2jf(gp_MoveData.x),gpf2jf(gp_MoveData.y),
			gpf2jf(gp_MoveData.prev_x),gpf2jf(gp_MoveData.prev_y),
			gpf2jf(gp_MoveData.first_x),gpf2jf(gp_MoveData.first_y));
}

/*
 * Class:     gp_Delegator
 * Method:    isRotate
 * Signature: ()Lgp/Rotate;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isRotation(JNIEnv *env, jobject self){
	if(!gp_isRotation)return jnull;
	gp_isRotation=false;

	jclass clazz=(*env)->FindClass(env,"gp/Rotation");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FZ)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor,gpf2jf(gp_RotationData.angle),gp_RotationData.direction);
}

/*
 * Class:     gp_Delegator
 * Method:    isScroll
 * Signature: ()Lgp/Scroll;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isScroll(JNIEnv *env, jobject self){
	if(!gp_isScroll)return jnull;
	gp_isScroll=false;

	jclass clazz=(*env)->FindClass(env,"gp/Scroll");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FFZ)V");
	return (*env)->NewObject(env,clazz,constructor,gpf2jf(gp_ScrollData.x),gpf2jf(gp_ScrollData.y),gp_ScrollData.direction);
}

/*
 * Class:     gp_Delegator
 * Method:    isTwoFingerScroll
 * Signature: ()Lgp/TwoFingerScroll;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isTwoFingerScroll(JNIEnv *env, jobject self){
	if(!gp_isTwoFingerScroll)return jnull;
	gp_isTwoFingerScroll=false;

	jclass clazz=(*env)->FindClass(env,"gp/TwoFingerScroll");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FFZ)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor,gpf2jf(gp_TwoFingerScrollData.x),gpf2jf(gp_TwoFingerScrollData.y),gp_TwoFingerScrollData.direction);
}

/*
 * Class:     gp_Delegator
 * Method:    isZoom
 * Signature: ()Lgp/Zoom;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isZoom(JNIEnv *env, jobject self){
	if(!gp_isZoom)return jnull;
	gp_isZoom=false;

	jclass clazz=(*env)->FindClass(env,"gp/Zoom");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FZ)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor, gpf2jf(gp_ZoomData.magnification), gp_ZoomData.direction);
}

/*
 * Class:     gp_Delegator
 * Method:    isTwoFingerScroll
 * Signature: ()Lgp/TwoFingerTap;
 */
JNIEXPORT jobject JNICALL Java_gp_Delegator_isTwoFingerTap(JNIEnv *env, jobject self){
	if(!gp_isTwoFingerTap)return jnull;
	gp_isTwoFingerTap=false;

	jclass clazz=(*env)->FindClass(env,"gp/TwoFingerTap");
	if(!clazz)return jnull;
	jmethodID constructor=(*env)->GetMethodID(env,clazz,"<init>","(FF)V");
	if(!constructor)return jnull;
	return (*env)->NewObject(env,clazz,constructor,gpf2jf(gp_TwoFingerTapData.x),gpf2jf(gp_TwoFingerTapData.y));
}


JNIEXPORT jint JNICALL Java_gp_Delegator_test(JNIEnv *env, jobject self){
}

/**
$ javap -s gp/*
Compiled from "Delegator.java"
public class gp.Delegator {
  public gp.Delegator();
    Signature: ()V

  public static gp.Delegator getInstance();
    Signature: ()Lgp/Delegator;

  public native int test();
    Signature: ()I

  public native boolean recognize(int, int, float[], int);
    Signature: (II[FI)Z

  public native gp.Tap isTap();
    Signature: ()Lgp/Tap;

  public native gp.Press isPress();
    Signature: ()Lgp/Press;

  public native gp.Flick isFlick();
    Signature: ()Lgp/Flick;

  public native gp.Move isMove();
    Signature: ()Lgp/Move;

  public native gp.Rotate isRotate();
    Signature: ()Lgp/Rotate;

  public native gp.Scroll isScroll();
    Signature: ()Lgp/Scroll;

  public native gp.TwoFingerScroll isTwoFingerScroll();
    Signature: ()Lgp/TwoFingerScroll;

  public native gp.Zoom isZoom();
    Signature: ()Lgp/Zoom;
}
Compiled from "Flick.java"
public class gp.Flick {
  public final float x;
    Signature: F
  public final float y;
    Signature: F
  public final boolean direction;
    Signature: Z
  gp.Flick(float, float, boolean);
    Signature: (FFZ)V
}
Compiled from "Move.java"
public class gp.Move {
  public final float x;
    Signature: F
  public final float y;
    Signature: F
  public final byte direction;
    Signature: B
  public gp.Move(float, float, byte);
    Signature: (FFB)V
}
Compiled from "Press.java"
public class gp.Press {
  public final float x;
    Signature: F
  public final float y;
    Signature: F
  public gp.Press(float, float);
    Signature: (FF)V
}
Compiled from "Rotate.java"
public class gp.Rotate {
  public final float angle;
    Signature: F
  public final boolean direction;
    Signature: Z
  public gp.Rotate(float, boolean);
    Signature: (FZ)V
}
Compiled from "Scroll.java"
public class gp.Scroll {
  public final float x;
    Signature: F
  public final float y;
    Signature: F
  public final boolean direction;
    Signature: Z
  gp.Scroll(float, float, boolean);
    Signature: (FFZ)V
}
Compiled from "Tap.java"
public class gp.Tap {
  public final float x;
    Signature: F
  public final float y;
    Signature: F
  public gp.Tap(float, float);
    Signature: (FF)V
}
Compiled from "TwoFingerScroll.java"
public class gp.TwoFingerScroll {
  public final float x;
    Signature: F
  public final float y;
    Signature: F
  public final boolean direction;
    Signature: Z
  gp.TwoFingerScroll(float, float, boolean);
    Signature: (FFZ)V
}
Compiled from "Zoom.java"
public class gp.Zoom {
  public final float maginfication;
    Signature: F
  public final boolean direction;
    Signature: Z
  public gp.Zoom(float, boolean);
    Signature: (FZ)V
}

*/

#ifdef __cplusplus
}
#endif
#endif

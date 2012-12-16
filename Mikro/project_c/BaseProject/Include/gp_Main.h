#ifndef GP_MAIN_H_
#define GP_MAIN_H_

#define DEBUG

#include "Base/gp.h"
#include "Alloc/gp_Alloc.h"
#include "Math/gp_Math.h"
#include "InOut/gp_MotionEvent.h"
#include "InOut/gp_OutputGesture.h"
#include "Gestures/gp_gestures_parameters.h"

gpBool gp_isTap				=false;
gpBool gp_isPress			=false;
gpBool gp_isFlick			=false;
gpBool gp_isMove			=false;
gpBool gp_isRotation		=false;
gpBool gp_isScroll			=false;
gpBool gp_isZoom			=false;
gpBool gp_isTwoFingerScroll	=false;
gpBool gp_isTwoFingerTap	=false;

gpOutputGesture_tap 				gp_TapData;
gpOutputGesture_press 				gp_PressData;
gpOutputGesture_flick				gp_FlickData;
gpOutputGesture_move				gp_MoveData;
gpOutputGesture_rotation			gp_RotationData;
gpOutputGesture_scroll				gp_ScrollData;
gpOutputGesture_zoom 				gp_ZoomData;
gpOutputGesture_two_finger_scroll 	gp_TwoFingerScrollData;
gpOutputGesture_two_finger_tap		gp_TwoFingerTapData;

typedef struct{
	gpVector* finger1;
	gpVector* finger2;
	gpByte fingers;
	gpInt firstTime;
}gpRecognizeContext;

gpVoid gpRecognize(gpMotionEvent*event);

gpBool gpTryTap				(gpMotionEvent*event,gpRecognizeContext*context);
gpBool gpTryPress			(gpMotionEvent*event,gpRecognizeContext*context);
gpBool gpTryFlick			(gpMotionEvent*event,gpRecognizeContext*context);
//Notice no gpTryMove
gpBool gpTryRotation		(gpMotionEvent*event,gpRecognizeContext*context);
gpBool gpTryScroll			(gpMotionEvent*event,gpRecognizeContext*context);
gpBool gpTryZoom			(gpMotionEvent*event,gpRecognizeContext*context);
gpBool gpTryTwoFingerScroll	(gpMotionEvent*event,gpRecognizeContext*context);
gpBool gpTryTwoFingerTap	(gpMotionEvent*event,gpRecognizeContext*context);


#endif

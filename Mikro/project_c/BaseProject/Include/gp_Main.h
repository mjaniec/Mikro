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
	gpVector* gesture;
	gpPoint* first;
	gpInt firstTime;
}gpRecognizeContext;


gpVoid gpRecognize(gpMotionEvent*event);

gpVoid gpTryTap				(gpMotionEvent*event,gpRecognizeContext*context);
gpVoid gpTryPress			(gpMotionEvent*event,gpRecognizeContext*context);
gpVoid gpTryFlick			(gpMotionEvent*event,gpRecognizeContext*context);
//Notice no gpTryMove
gpVoid gpTryRotation		(gpMotionEvent*event,gpRecognizeContext*context);
gpVoid gpTryScroll			(gpMotionEvent*event,gpRecognizeContext*context);
gpVoid gpTryZoom			(gpMotionEvent*event,gpRecognizeContext*context);
gpVoid gpTryTwoFingerScroll	(gpMotionEvent*event,gpRecognizeContext*context);
gpVoid gpTryTowFIngerTap	(gpMotionEvent*event,gpRecognizeContext*context);



#endif

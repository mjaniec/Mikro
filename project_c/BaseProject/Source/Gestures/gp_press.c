#ifndef GP_PRESS_C
#define GP_PRESS_C

gpVoid gpTryPress(gpMotionEvent*event,gpRecognizeContext*context){
  $fun;
  if(event->time-context->firstTime<=GP_TAP_MAX_TIME)return;
  gpInt size=gpVector_getSize(context->finger1)$r;
  gpPoint*current;
  gpPoint end;
  end.x=gpMotionEvent_getX(event,0)$r;
  end.y=gpMotionEvent_getY(event,0)$r;
  gpFloat maxDistSquare=gpMath_Square(GP_TAP_PRESS_MOVE)$r;
  for(gpInt i=0; i<size; ++i){
	 current=(gpPoint*)gpVector_at(context->finger1,i)$r;
	 if(gpPoint_distance2(context->first1,current)>maxDistSquare)return;
  }
  if(gpPoint_distance2(context->first1,&end)>maxDistSquare)return;

  //PRESS!

  gp_isPress=true;
  gp_PressData.x=context->first1->x;
  gp_PressData.y=context->first1->y;
}


#endif

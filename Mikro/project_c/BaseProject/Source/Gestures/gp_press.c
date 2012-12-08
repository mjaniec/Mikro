#ifndef GP_PRESS_C
#define GP_PRESS_C

gpBool gpTryPress(gpMotionEvent*event,gpRecognizeContext*context){
  $fun;
  printf("%s begin",__FILE__+100);
  if(event->time-context->firstTime<=GP_TAP_MAX_TIME)return false;
  gpInt size=gpVector_getSize(context->finger1)$r0;
  gpPoint first=*((gpPoint*)gpVector_at(context->finger1,0))$r0;
  gpPoint last= *((gpPoint*)gpVector_at(context->finger1,size-1))$r0;
  gpPoint*current;
  gpFloat maxDistSquare=gpMath_Square(GP_TAP_PRESS_MOVE)$r0;
  for(gpInt i=0; i<size; ++i){
	 current=(gpPoint*)gpVector_at(context->finger1,i)$r0;
	 if(gpPoint_distance2(&first,current)>maxDistSquare)return false;
  }

  //PRESS!

  gp_isPress=true;
  gp_PressData.x=first.x;
  gp_PressData.y=first.y;
  return true;
}


#endif

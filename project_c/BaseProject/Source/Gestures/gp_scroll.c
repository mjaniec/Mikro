#ifndef GP_SCROLL_C
#define GP_SCROLL_C

gpVoid gpTryScroll(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpPoint last;
	last.x=gpMotionEvent_getX(event,0)$r;
	last.y=gpMotionEvent_getY(event,0)$r;
	gpFloat dx=last.x-context->first->x;
	gpFloat dy=last.y-context->first->y;


	if(gpMath_Abs(dy)<GP_SCROLL_MIN_LEN)return;
	if(gpMath_Abs(gpMul(gpMkFloat("4"),dx))>gpMath_Abs(dy))return;
	gpBool dir=dy>gpMkFloat(0);

	gpInt size=gpVector_getSize(context->gesture)$r;
    gpPoint*current;
    gpPoint*prevoius=context->first;
    for(gpInt i=1; i<=size; ++i){
    	if(i<size){ current=(gpPoint*)gpVector_at(context->gesture,i)$r;}
    	else current=&last;
  	   dx=current->x-prevoius->x;
  	   dy=current->y-prevoius->y;
	   if(gpMath_Abs(dx)>gpMath_Abs(dy))return;
	   if((dir&&dy<gpMkFloat(0)) || (!dir&&dy>gpMkFloat(0)))return;
	   prevoius=current;
    }
    //SCROLL
    gp_isScroll=true;
    gp_ScrollData.direction=dir;
    gp_ScrollData.x=last.x;
    gp_ScrollData.y=last.y;
}

#endif

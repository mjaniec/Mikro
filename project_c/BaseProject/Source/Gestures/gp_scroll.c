#ifndef GP_SCROLL_C
#define GP_SCROLL_C

gpVoid gpTryScroll(gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	gpPoint last;
	last.x=gpMotionEvent_getX(event,0)$r;
	last.y=gpMotionEvent_getY(event,0)$r;
	gpFloat dx=last.x-context->first1->x;
	gpFloat dy=last.y-context->first1->y;


	if(gpMath_Abs(dy)<GP_SCROLL_MIN_LEN)return;
	if(gpMath_Abs(gpMul(gpMkFloat("3"),dx))>gpMath_Abs(dy))return;
	gpBool dir=dy>gpMath_0;

	gpInt size=gpVector_getSize(context->finger1)$r;
	gpInt bounds=3;
	if(size<2*bounds+2)return;
	size-=bounds;
    gpPoint*current;
    gpPoint*prevoius=gpVector_at(context->finger1,bounds-1);

    for(gpInt i=bounds; i<=size; ++i){
    	if(i<size){ current=(gpPoint*)gpVector_at(context->finger1,i)$r;}
    	else current=&last;
  	   dx=current->x-prevoius->x;
  	   dy=current->y-prevoius->y;
	   if(gpMath_Abs(dx)>gpMath_Abs(dy))return;
	   if((dir&&dy<gpMath_0) || (!dir&&dy>gpMath_0))return;
	   prevoius=current;
    }

    //SCROLL
    gp_isScroll=true;
    gp_ScrollData.direction=dir;
    gp_ScrollData.x=last.x;
    gp_ScrollData.y=last.y;
}

#endif

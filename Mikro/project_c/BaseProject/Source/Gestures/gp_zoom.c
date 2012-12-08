#ifndef GP_ZOOM_C
#define GP_ZOOM_C



gpBool gpTryZoom (gpMotionEvent*event,gpRecognizeContext*context){
	$fun;
	printf("%s begin",__FILE__+100);
	printVector(context->finger1,"one")$r0;
	printVector(context->finger2,"two")$r0;
	/*gpRecognizeContext*context2=context;
	context2->finger1=context2->finger2;*/
	return false;
}

#endif//GP_ZOOM_C


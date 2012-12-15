#ifndef gp_error_c
#define gp_error_c

#include "..\..\Include\Base\gp_error.h"

#ifdef DEBUG
#include "..\..\Include\Base\gp_error_codes.h"
#endif
#define _gpError_SIZE 4096



gpVoid __print_called_from(gpString filename,gpInt line){
	gpString last;
	for(gpChar*x=filename; *x; ++x)if(*x=='\\'||*x=='/')last=x;
	printf("File: \"%s\" Line: %d: ",last, (int) line);
}
gpVoid __print_error(){
	if(gp_errno==GP_EOK)return;
	if(gp_errno<0)return;
	printf("ERROR: %s",GP_ERRSTR[gp_errno]);
}

gpVoid __print_assertion(){
	if(gp_errno==GP_EOK)return;
	if(gp_errno<0)return;
	printf("ASSERTION FAILED: %s. ",GP_ERRSTR[gp_errno]);
}

#endif


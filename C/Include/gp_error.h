#ifndef __GP_ERROR
#define __GP_ERROR

#ifdef DEBUG
	#include <stdio.h>
	#include <stdlib.h>
	#include "gp_types.h"
	#include "gp_error_codes.h"	
		
	extern gpInt gp_errno;
	extern gpString GP_ERRSTR[];
	
	gpVoid __print_called_from(gpString filename,gpInt line);
	gpVoid __print_error();
	gpVoid __print_assertion();
	
	#define $fun \
		do{	gp_errno=0; }while(0)
	#define $assert(cond,error)\
		do{if(!(cond)){\
			gp_errno=error;\
			__print_assertion(gp_errno);\
			__print_called_from(__FILE__,__LINE__);\
			gp_errno=-gp_errno; \
			return;\
		}}while(0)
	
	#define $r \
		;do{ \
			if(gp_errno != GP_EOK){\
				if(gp_errno<0){\
					printf("Called from: \n"); \
					__print_called_from(__FILE__,__LINE__);\
					return;\
				}else{\
					__print_error(gp_errno);\
					__print_called_from(__FILE__,__LINE__);\
					gp_errno=-gp_errno;\
					return;\
				}\
			 }\
		}while(0)
	#define $c\
		;do{ \
			if(gp_errno != GP_EOK){\
				if(gp_errno<0){\
					printf("Called from: \n"); \
					__print_called_from(__FILE__,__LINE__);\
				}else{\
					__print_error(gp_errno);\
					__print_called_from(__FILE__,__LINE__);\
					gp_errno=-gp_errno;\
				}\
			 }\
		}while(0)
	#define $e \
		;do{ \
			if(gp_errno != GP_EOK){\
				if(gp_errno<0){\
					printf("Called from: \n"); \
					__print_called_from(__FILE__,__LINE__);\
				}else{\
					__print_called_from(__FILE__,__LINE__);\
					__print_error(gp_errno);\
					gp_errno=-gp_errno;\
				}\
				exit(gp_errno);\
			 }\
		}while(0)

		
#endif

#ifndef DEBUG
	#define $fun
	#define $assert(cond,error)
	#define $r
	#define $c
	#define $e
#endif
#endif

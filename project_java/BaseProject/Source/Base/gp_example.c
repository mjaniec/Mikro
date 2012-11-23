#include <gp.h>
#include <stdio.h>

gpVoid gpLibFun2(){
	$fun;
	//fake assertion
	$assert(false,GP_MYERROR);
	puts("Only release goes here");
}


gpInt gpLibFun1(){
	$fun;
	//calls another library function
	//print position and [R]ise up
	gpLibFun2()$r;
}
 
gpInt main(){
	//print stack trace and [C]ontinue
	printf("print stack trace and continue\n");
	gpLibFun1()$c;
	//print statc trace and [E]xit
	printf("\n\nprint stack trace and exit\n");
	gpLibFun1()$e;
	//this code wont be executed
	gpLibFun1()$e;
	return 0;
}

#include "gp.h"
#include <stdio.h>


int main(){
	puts("error handling");
	puts("geting error description");
	printf("Code: %d Des: %s", GP_EOK, GP_ERRSTR[GP_EOK]);
	return 0;
}
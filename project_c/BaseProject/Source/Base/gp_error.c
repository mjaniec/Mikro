#ifndef gp_error_c
#define gp_error_c

#include "..\..\Include\Base\gp_error.h"
#include "..\..\Include\Base\gp_bool.h"

#ifdef DEBUG
#include <string.h>
#include <stdio.h>
<<<<<<< HEAD
#include <gp_bool.h>
#include <gp_error_codes.h>
#define size 4096            // a la constant :)
=======
#include "..\..\Include\Base\gp_error_codes.h"

#define _gpError_SIZE 4096            // a la constant :)


>>>>>>> b74117b7844fb7cf113fd3a8e1fe727947193f51
static void ___nth(FILE* fd, gpInt line){
   gpInt stat, cline=1, i, j;
   gpBool nend=true, all=false;
   gpChar buff[_gpError_SIZE+1];                   //+ one for eventually null.
   
   while(nend){
      stat=fread(buff,1,_gpError_SIZE,fd);
      if(stat==-1)return;
      if(stat<_gpError_SIZE)nend=false,all=true;
      for(i=0; cline<line && i<stat; ++i)
         if(buff[i]=='\n')
            ++cline;
      if(cline==line)nend=false;      
   }
   
   if(cline==line){
      for(j=i+1; j<stat && buff[j]!='\n';++j);
      if(j<stat)buff[j]='\0';   //stopped because of end line.
      else{            
         if(!all){               //not all line in buff.
            buff[stat]='\0';
            strcpy(buff,buff+i);
            i=0;
            fread(buff+i,1,_gpError_SIZE-i,fd);
            for(j=i+1; j<stat && buff[j]!='\n';++j);
            if(j<stat)buff[j]='\0';     
            else return;        //probably line is longer than 4096 or an error occurred.
         }
         else buff[stat]='\0';
      }
   }
   fprintf(stderr,"%s\n",buff+i);
}

gpVoid __print_called_from(gpString filename,gpInt line){
	printf("File:\"%s\"\tLine: %d:\t", filename, line);
	FILE*f=fopen(filename,"r");
	if(!f){puts("");return;}
	
	___nth(f,line);
}
gpVoid __print_error(){
	if(gp_errno==GP_EOK)return;
	if(gp_errno<0)return;
	printf("ERROR: %s\n",GP_ERRSTR[gp_errno]);
}

gpVoid __print_assertion(){
	if(gp_errno==GP_EOK)return;
	if(gp_errno<0)return;
	printf("ASSERTION FAILED: %s\n",GP_ERRSTR[gp_errno]);
}

#endif

#endif

#include <gp_error.h>


#ifdef DEBUG
#include <string.h>
#include <stdio.h>
#include <gp_error_codes.h>
#define size 4096            // a la constant :)
static void ___nth(FILE* fd, gpInt line){
   gpInt stat, cline=1, i, j;
   gpBool nend=true, all=false;
   gpChar buff[size+1];                   //+ one for eventually null.
   
   while(nend){
      stat=fread(buff,1,size,fd);
      if(stat==-1)return;
      if(stat<size)nend=false,all=true;
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
            fread(buff+i,1,size-i,fd);
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


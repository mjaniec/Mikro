#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4096

char* fword(char* src){
	static char bufor[SIZE];
	strcpy(bufor,src);
	//puts(bufor);
	for(int i=0; i<SIZE && bufor[i]; ++i)
		if(bufor[i]==' '){
			bufor[i]='\0';
			//puts("ok");
			return bufor;
		}
	return bufor;
}

char*rest(char*src){
	char *b;
	for(int i=0; src[i]; ++i)
		if(src[i]==' '){
			b=src+i+1;
			for(int i=0; b[i]; ++i)
				if(b[i]=='\n')
					b[i]='\0';
			return b;
		}
	return src;
}

int main(){
	FILE*input=fopen("../gp_error_codes","r");
	FILE*header=fopen("../gp_error_codes.h","w");
	FILE*code=fopen("../../Source/Base/gp_error_codes.c","w");
	char bufor[SIZE];
	char*r;
	fputs("//Do not edit this filie. \n//This is autogenerated file, edit gp_error_codes istead\n",header);
	fputs("//Do not edit this filie. \n//This is autogenerated file, edit gp_error_codes istead",code);
	fputs("\n#include <gp_types.h> \n\ngpInt gp_errno;\ngpString GP_ERRSTR[]={\n",code);
	for(int i=0; (r=fgets(bufor,SIZE,input)); ++i){
		//printf("%s\n",bufor);
		fprintf(header,"#define %s %d\n",fword(bufor),i);
		fprintf(code,"\"%s\",\n",rest(bufor));
	}
	fputs("\n};",code);
	fclose(code);
	fclose(header);
	fclose(input);
	printf("done");
}
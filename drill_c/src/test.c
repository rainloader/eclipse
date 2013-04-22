#include <stdio.h>

#include <string.h>

#include <stdlib.h>




char* rtrim(char *str)

{

	 char * result;

	 int len = strlen(str);

	 int i = len;

	 int end=0;

	 result = (char *)calloc(len,sizeof(char));

	 strcpy(result, str);




	 while(i>0)

	 {

		 if( result[--i] == ' ' || result[i] == '\n' || result[i] == '\t' )	 continue;

		 end = ++i;

		 break;

	 }

	 result[end] = '\0';

	 return result;

}




int main (void){

	 char temp[] = "test    \n    test2    \t		 \n";

	 char* result;

	 printf("[%s]\n", temp);

	 result = rtrim(temp);

	 printf("[%s]\n", result);

	 return 0;

}

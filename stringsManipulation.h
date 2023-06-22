#include <stdio.h>
#include <string.h>

void removeBreakRow(char string[]){
	int len;
	len = strlen(string);
	
	if(string[len-1] == '\n'){
		string[len-1] = 0;
	}
}

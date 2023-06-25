#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeBreakRow(char string[]){
	int len;
	len = strlen(string);
	
	if(string[len-1] == '\n'){
		string[len-1] = 0;
	}
}

int newID(){
	char ch;
	int i, j, newID;
	char lastID[4];
	FILE *file;
	
	file = fopen("savedata.txt", "r");
	
	while (!feof(file)){
		fscanf(file, "%c", &ch);
		if(ch == '\n'){
			for (i = 0; i < 4; i++){
				lastID[i] = getc(file);
				if (!(lastID[i] >= '0' && lastID[i] <= '9')){
					break;
				}
			}
		}
	}
	
	newID = atoi(lastID) + 1;
	
	return newID;
}

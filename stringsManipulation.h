#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeBreakRow(char string[]){
	// INICIALIZA��O DAS VARIAVEIS
	int len;
	len = strlen(string);
	
	// REMOVENDO O CARACTERE DE QUEBRA DE LINHA PARA REGISTROS FGETS
	if(string[len-1] == '\n'){
		string[len-1] = 0;
	}
}

int newID(FILE *file){
	
	// INICIALIZA��O DAS VARIAVEIS
	char ch;
	int i, j, newID;
	char lastID[4];
//	FILE *file;
//	
//	file = fopen("savedata.txt", "r");
	
	//LOOP DE VERIFICA��O DO ULTIMO ID NO ARQUIVO
	while (!feof(file)){
		fscanf(file, "%c", &ch);
		if(ch == '\n'){ // LEITURA DO CARACTERE POSTERIOR AO CARACTERE DE QUEBRA DE LINHA
			for (i = 0; i < 4; i++){
				lastID[i] = getc(file); // SALVANDO O VALOR NO VETOR
				if (!(lastID[i] >= '0' && lastID[i] <= '9')){
					break;
				}
			}
		}
	}
	
	//CONVERS�O DE VETOR PARA INTEIRO
	newID = atoi(lastID) + 1;
	
	return newID;
}

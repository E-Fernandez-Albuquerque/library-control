#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void removeBreakRow(char string[]){
	// INICIALIZAÇÃO DAS VARIAVEIS
	int len;
	len = strlen(string);
	
	// REMOVENDO O CARACTERE DE QUEBRA DE LINHA PARA REGISTROS FGETS
	if(string[len-1] == '\n'){
		string[len-1] = 0;
	}
}

int newID(FILE *file){
	
	// INICIALIZAÇÃO DAS VARIAVEIS
	char ch;
	int i, j, newID;
	char lastID[4];
//	FILE *file;
//	
//	file = fopen("savedata.txt", "r");
	
	//LOOP DE VERIFICAÇÃO DO ULTIMO ID NO ARQUIVO
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
	
	//CONVERSÃO DE VETOR PARA INTEIRO
	newID = atoi(lastID) + 1;
	
	return newID;
}


book getBook(FILE *file, char id[]){
	int i;
	char searchID[4];
	char ch;
	int mod;
	book bk;
	
	do{
		fscanf(file, "%c", &ch);
		if(ch == '\n'){
			for(i=0; i<4; i++){
				ch = getc(file);
				if (ch > '9' || ch < '0'){
					break;
				}
				searchID[i] = ch;		
			}
		}
	} while (strcmp(searchID,id) != 0 && !feof(file));
	
	if (feof(file)){
		printf("Livro nao encontrado.");
	}
	else {
		printf("Livro encontrado: \nID:");
		for (i=0; i<4; i++){
			printf("%c", searchID[i]);
		}
		
		ch = getc(file);
		i=0;
		while (ch != ','){
			ch = getc(file);
			if (ch != ','){
				bk.title[i] = ch;
				i++;
			}
		}
		
		ch = getc(file);
		i=0;
		while(ch != ','){
			ch = getc(file);
			if (ch != ','){
				bk.author[i] = ch;
				i++;
			}
		}
		
		ch = getc(file);
		i=0;
		while(ch != ','){
			ch = getc(file);
			if (ch != ','){
				bk.publisher[i] = ch;
				i++;
			}
		}
		
		ch = getc(file);
		i=0;
		while(ch != ','){
			ch = getc(file);
			if (ch != ','){
				bk.year[i] = ch;
				i++;
			}
		}
		
		ch = getc(file);
		i=0;
		while(ch != ','){
			ch = getc(file);
			if (ch != ','){
				bk.pages[i] = ch;				
				i++;
			}
		}
		
		ch = getc(file);
		i=0;
		while(ch != ','){
			ch = getc(file);
			if (ch != ','){
				bk.language[i] = ch;
				i++;
			}
		}
		
		ch = getc(file);
		i=0;
		while(ch != ';'){
			ch = getc(file);
			if (ch != ';'){
				bk.isbn[i] = ch;
				i++;
			}
		}
	}
	return bk;
}


#include <stdio.h>
#include "stringsManipulation.h"
#include <unistd.h>
#include <conio.h>

int confirmation;

enum categories {
	fiction = 1, nonfiction, adventure, classic, crime, fantasy, horror, historicalfiction, humour, mystery, poetry, romance, thriller, war, autobiography, selfhelp, biography 
};

void bookCreate(FILE *file, char title[], char author[], char year[], char pages[], char language[], char publisher[], char isbn[]) {	

	// ABRINDO ARQUIVO DE LEITURA
	FILE *file_r = fopen("savedata.txt", "r");
	
	// SALVANDO...
	printf("Salvando informações.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	
	// REMOVENDO QUEBRA DE LINHA DO FGETS
	removeBreakRow(title);
	removeBreakRow(author);
	removeBreakRow(publisher);
	
	// ESCREVENDO EM ARQUIVO
	fprintf(file, "\n%d, %s, %s, %s, %s, %s, %s, %s", newID(file_r), title, author, publisher, year, pages, language, isbn);
	
	//FECHAMENTO DO ARQUIVO DE LEITURA
	fclose(file_r);
	
	// SUCESSO E LIMPEZA DE TELA
	printf("\nSucesso.\n\n");
	sleep(1);
	system("cls");
}





void showAll(FILE *file) {
	
	// INICIALIZAÇÃO DA VARIAVEL
	char ch;
	
	//VERIFICACAO DA EXISTENCIA DO ARQUIVO
	if (file == NULL){
		printf("Arquivo inexistente.");
		sleep(1);
	};
	
	//LOOP DE ESCRITA DOS REGISTROS EM TELA
	while (!feof(file)){
		fscanf(file, "%c", &ch);
		printf("%c", ch);
	}
	
	//PAUSE NO SISTEMA E LIMPEZA DE TELA PARA RETORNAR AO MENU
	printf("\n\n");
	system("pause");
	system("cls");
}

void bookView() {
	//TODO
}

void bookDelete() {
	//TODO
}

void bookUpdate() {
	//TODO
}

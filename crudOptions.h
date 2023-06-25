#include <stdio.h>
#include "stringsManipulation.h"
#include <unistd.h>
#include <conio.h>

int confirmation;

enum categories {
	fiction = 1, nonfiction, adventure, classic, crime, fantasy, horror, historicalfiction, humour, mystery, poetry, romance, thriller, war, autobiography, selfhelp, biography 
};

void bookCreate() {
	
	FILE *file;
	
	file = fopen("savedata.txt", "a");
	if (file == NULL){
		file = fopen("savedata.txt", "w");
	};
	
	int ID;
	char isbn[22];
	char title[150];
	char author[80];
	char year[5];
	char pages[5];
	char language[20];
	char publisher[40];
	
	do {
		printf("\nInsira os dados do livro que deseja registrar: ");
		
		printf("\nTitulo: ");
//		scanf("%s", &book.title);			
		getchar();
		fgets(title, 120, stdin);
		removeBreakRow(title);
		
		printf("Autor(a): ");
//		scanf("%s", book.author);
		fgets(author, 60, stdin);
		removeBreakRow(author);
		
		printf("Editora: ");
		fgets(publisher, 40, stdin);
		removeBreakRow(publisher);
		
		printf("Ano de publicacao: ");
		scanf("%s", year);
		
		printf("Paginas: ");
		scanf("%s", pages);
		
		printf("Lingua: ");
		scanf("%s", language);
		
		printf("ISBN: ");
		scanf("%s", isbn);	
		
		system("cls");
		
		printf("As informações estao corretas?");

		printf("\nTitulo: %s\n", title);
		printf("Autor: %s\n", author);
		printf("Editora: %s\n", publisher);
		printf("Ano de publicacao: %s\n", year);
		printf("Numero de paginas: %s\n", pages);
		printf("Lingua: %s\n", language);
		printf("ISBN: %s\n", isbn);

		printf("\n0 - Descartar / 1 - Registrar ");
		scanf("%d", &confirmation);
		
	} while (confirmation != 1);
	printf("Salvando informações.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	fprintf(file, "\n%d, %s, %s, %s, %s, %s, %s, %s", newID(), title, author, publisher, year, pages, language, isbn);
	printf("\nSucesso.\n\n");
	sleep(1);
	fclose(file);
	system("cls");
}





void showAll() {
	FILE *file;
	char ch;
	
	file = fopen("savedata.txt", "r");
	
	if (file == NULL){
		printf("Arquivo inexistente.");
		sleep(1);
	};
	
	while (!feof(file)){
		fscanf(file, "%c", &ch);
		printf("%c", ch);
	}
	printf("\n");
	system("pause");
	system("cls");
}

void bookView() {
}

void bookDelete() {
}

void bookUpdate() {
	
	newID();
}

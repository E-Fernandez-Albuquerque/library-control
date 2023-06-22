#include <stdio.h>
#include "stringsManipulation.h"
#include <unistd.h>
#include <conio.h>

int confirmation;

enum categories {
	fiction = 1, nonfiction, adventure, classic, crime, fantasy, horror, historicalfiction, humour, mystery, poetry, romance, thriller, war, autobiography, selfhelp, biography 
};

void bookCreate(char title[120], char author[60], char isbn[14], char year[5], char pages[5], char language[6], FILE *file) {
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
		
		printf("Ano de publicacao: ");
		scanf("%s", year);
		
		printf("Paginas: ");
		scanf("%s", pages);
		
		printf("Lingua: ");
		scanf("%s", language);
		
		printf("ISBN: ");
		scanf("%s", isbn);	
		
		system("cls");
		
		printf("\nAs informações estao corretas?");
		printf("\nInserir o livro nos registros?\n");

		printf("Titulo: %s\n", title);
		printf("Autor: %s\n", author);
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
	fprintf(file, "%s,%s,%s,%s,%s,%s\n", title, author, year, pages, language, isbn);
	printf("\nSucesso.");
}

int library() {
	return 0;
}

int bookView() {
	return 0;
}

int bookDelete() {
	return 0;
}

int bookUpdate() {
	return 0;
}

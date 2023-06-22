#include <stdio.h>
#include "menu.h"
#include "crudOptions.h"
#include <unistd.h>

int main() {
	
	FILE *file;
	
	file = fopen("savedata.txt", "a");
	if (file == NULL){
		file = fopen("savedata.txt", "w");
	};
	int opcao = menu();

	struct books {
		char isbn[14];
		char title[120];
		char author[60];
		char year[5];
		char pages[5];
		char language[6];
	};
	
	struct books book;
	
	switch(opcao){
		case 1:
			printf("--- Cadastrar novo livro ---");
			sleep(1);	
			bookCreate(book.title, book.author, book.isbn, book.year, book.pages, book.language, file);
			break;
		case 2:
			printf("--- Ver biblioteca ---");
			bookView();
			break;
		case 3:
			printf("--- Atualizar registro de livro ---");
			bookUpdate();
			break;
		case 4:
			printf("--- Deletar livro ---");
			bookDelete();
			break;
		case 5:
			printf("--- Finalizando o programa ---");
			fclose(file);
			
			
	}
}


#include <stdio.h>
#include "menu.h"
#include "crudOptions.h"
#include <unistd.h>
#include <windows.h>

int main() {
	//DECLARACAO DE VARIAVEIS
	int opcao;
	FILE *file;
	
	file = fopen("savedata.txt", "a");
	if (file == NULL){
		file = fopen("savedata.txt", "w");
	};

	fclose(file);
	
	char ch;
	
	file = fopen("savedata.txt", "r");

	//DECLARACAO DE STRUCTS
	struct books {
		int ID;
		char isbn[22];
		char title[150];
		char author[80];
		char year[5];
		char pages[5];
		char language[20];
		char publisher[40];
	};
	
	struct books book;
	
	//MAIN LOOP
	do{
		opcao = menu();
		switch(opcao){
			case 1:
				printf("\n--- Cadastrar novo livro ---\n");	
				bookCreate();
				break;
			case 2:
				printf("\n--- Ver biblioteca ---\n");
				showAll();
				break;
			case 3:
				printf("\n--- Atualizar registro de livro ---\n");
				bookUpdate();
				break;
			case 4:
				printf("\n--- Deletar livro ---\n");
				bookDelete();
				break;
			case 5:
				printf("\n--- Finalizando o programa ---");
				return 0;
				break;
		}
	} while (opcao != 5);
}


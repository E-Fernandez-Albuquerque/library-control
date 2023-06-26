#include <stdio.h>
#include "menu.h"
#include "crudOptions.h"
#include <unistd.h>
#include <windows.h>

int main() {
	//DECLARACAO DE VARIAVEIS
	int option, confirmation;
	FILE *file;
	
	file = fopen("savedata.txt", "a");
	if (file == NULL){
		file = fopen("savedata.txt", "w");
	};

	fclose(file);
	
	char ch;

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
	
	typedef struct books book;
	
	//MAIN LOOP
	do{
		option = menu();
		switch(option){
			case 1: // INSERIR REGISTRO
				
				// ABRIR ARQUIVO
				file = fopen("savedata.txt", "a");
				
				// INICIALIZAR A STRUCT
				book b;
				
				// LOOP DE VERIFICA플O
				do{
					printf("----------------------------- Cadastrar novo livro -----------------------------\n");
					
					// INSERINDO INFORMA합ES
					printf("\nTitulo: ");
					getchar();
					fgets(b.title, 120, stdin);
				
					printf("Autor(a): ");
					fgets(b.author, 60, stdin);
				
					printf("Editora: ");
					fgets(b.publisher, 40, stdin);
				
					printf("Ano de publicacao: ");
					scanf("%s", b.year);
		
					printf("Paginas: ");
					scanf("%s", b.pages);
		
					printf("Lingua: ");
					scanf("%s", b.language);
		
					printf("ISBN: ");
					scanf("%s", b.isbn);	
					
					// CONFIRMA플O
					printf("\nConfirmar os dados e inserir nos registros?");
					printf("\n0 - Cancelar / 1 - Confirmar: ");
					scanf("%d", &confirmation);
				} while (confirmation != 1);
				
				// INVOCA플O DA FUN플O RESPONS햂EL POR REGISTRAR NO ARQUIVO
				bookCreate(file, b.title, b.author, b.year, b.pages, b.language, b.publisher, b.isbn);
				
				// FECHAMENTO DO ARQUIVO
				fclose(file);
				break;
								
			case 2: // VISUALIZAR REGISTROS
				printf("\n--- Ver biblioteca ---\n");
				
				// ABERTURA DO ARQUIVO
				file = fopen("savedata.txt", "r");
				
				//LIMPAR CONSOLE
				system("cls");
				
				printf("----------------------------- Registros na biblioteca -----------------------------\n");
				
				// INVOCA플O DA FUN플O QUE REALIZA A LEITURA DOS REGISTROS
				showAll(file);
				break;
			case 3: //TODO
				printf("\n--- Atualizar registro de livro ---\n");
				bookUpdate();
				break;
			case 4: //TODO
				printf("\n--- Deletar livro ---\n");
				bookDelete();
				break;
			case 5: //TODO
				printf("\n--- Finalizando o programa ---");
				return 0;
				break;
		}
	} while (option != 5);
}


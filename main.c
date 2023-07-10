#include <stdio.h>
#include "menu.h"
#include "crudOptions.h"
#include <unistd.h>
#include <windows.h>
#include "structs.h"

int main() {
	//DECLARACAO DE VARIAVEIS
	int option, confirmation;
	FILE *file;
	
	//CRIA플O INICIAL DO ARQUIVO QUE ARMAZENA OS DADOS, SE N홒 HOUVER
	file = fopen("savedata.txt", "a");
	if (file == NULL){
		file = fopen("savedata.txt", "w");
	};
	fclose(file);
	
	char ch;

//	//DECLARACAO DE STRUCTS
//	struct books {
//		int ID;
//		char isbn[22];
//		char title[150];
//		char author[80];
//		char year[5];
//		char pages[5];
//		char language[20];
//		char publisher[40];
//	};
	
//	typedef struct books book;
	
	//MAIN LOOP
	do{
		option = menu();
		switch(option){
			
			// OK!!!
			
			case 1: {	// INSERIR REGISTRO
				
			
				system("cls");
				
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
			}
			
			// OK!!!
							
			case 2: {	// VISUALIZAR TODOS OS REGISTROS
			
				system("cls");
				printf("\n--- Ver biblioteca ---\n");
				
				// ABERTURA DO ARQUIVO
				file = fopen("savedata.txt", "r");
				
				//LIMPAR CONSOLE
				system("cls");
				
				printf("----------------------------- Registros na biblioteca -----------------------------\n");
				
				// INVOCA플O DA FUN플O QUE REALIZA A LEITURA DOS REGISTROS
				showAll(file);
				break;
			}
			
			// OK!!!
			
			case 3: {	//PESQUISAR REGISTRO POR ID
				system("cls");
				printf("----------------------------- Pesquisa por ID -----------------------------\n");
				
				//INICIALIZA플O DE VARI햂EIS
				char id[5];
				file = fopen("savedata.txt", "r");
				
				//RECEBIMENTO DE ID A PESQUISAR
				printf("Insira o ID do livro que quer pesquisar: ");
				scanf("%s", id);
				
				//INVOCA플O DA FUN플O DE PESQUISA E EXIBI플O
				bookView(file, id);
				printf("\n");
				
				//PAUSA NO SISTEMA PARA VISUALIZA플O DO RETORNO
				system("pause");
				
				//LIMPAR TERMINAL
				system("cls");
				break;
			}
			
			// FALTANDO PARTE DE ATUALIZA플O
			
			case 4: {	//ATUALIZAR DADOS DE REGISTRO
				system("cls");
				printf("----------------------------- Atualizacao de registros -----------------------------\n");
				
				//INICIALIZA플O DE VARIAVEIS
				file = fopen("savedata.txt", "r");
				char id[5];
				
				//RECEBIMENTO DE ID
				printf("Qual o ID do livro que deseja modificar? ");
				scanf("%s", id);
				
				//INVOCACAO DE FUNCAO DE PESQUISA E ATUALIZA플O
				bookUpdate(file, id);
				
				break;
			}
				
			case 5:{ //TODO - DELETAR REGISTROS
				char id[4];
			
				printf("----------------------------- Deletar registro -----------------------------\n");
				printf("Insira o ID do livro que deseja deletar: ");
				scanf("%s", id);
				bookDelete();
				break;
			}
			// OK!!!
			
			case 6: //ENCERRAR O PROGRAMA
				printf("\n--- Finalizando o programa ---");
				return 0;
				break;
		}
	} while (option != 6);
}


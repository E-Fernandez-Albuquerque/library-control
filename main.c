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
	
	//CRIAÇÃO INICIAL DO ARQUIVO QUE ARMAZENA OS DADOS, SE NÃO HOUVER
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
		system("cls");
		option = menu();
		switch(option){
			
			// OK!!!
			
			case 1: {	// INSERIR REGISTRO
				
			
				system("cls");
				
				// ABRIR ARQUIVO
				file = fopen("savedata.txt", "a");
				
				// INICIALIZAR A STRUCT
				book b;
				
				// LOOP DE VERIFICAÇÃO
				do{
					printf("----------------------------- Cadastrar novo livro -----------------------------\n");
					// INSERINDO INFORMAÇÕES
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
					
					// CONFIRMAÇÃO
					printf("\nConfirmar os dados e inserir nos registros?");
					printf("\n0 - Cancelar / 1 - Confirmar: ");
					scanf("%d", &confirmation);
				} while (confirmation != 1);
				
				// INVOCAÇÃO DA FUNÇÃO RESPONSÁVEL POR REGISTRAR NO ARQUIVO
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
				
				// INVOCAÇÃO DA FUNÇÃO QUE REALIZA A LEITURA DOS REGISTROS
				showAll(file);
					
				//PAUSE NO SISTEMA E LIMPEZA DE TELA PARA RETORNAR AO MENU
				printf("\n\n");
				system("pause");
				fclose(file);
				system("cls");
				break;
			}
			
			// OK!!!
			
			case 3: {	//PESQUISAR REGISTRO POR ID
				system("cls");
				printf("----------------------------- Pesquisa por ID -----------------------------\n");
				
				//INICIALIZAÇÃO DE VARIÁVEIS
				char id[5];
				file = fopen("savedata.txt", "r");
				
				//RECEBIMENTO DE ID A PESQUISAR
				printf("Insira o ID do livro que quer pesquisar: ");
				scanf("%s", id);
				
				//INVOCAÇÃO DA FUNÇÃO DE PESQUISA E EXIBIÇÃO
				bookView(file, id);
				printf("\n");
				
				//PAUSA NO SISTEMA PARA VISUALIZAÇÃO DO RETORNO
				system("pause");
				
				fclose(file);
				
				//LIMPAR TERMINAL
				system("cls");
				break;
			}
			
			case 4: {	//ATUALIZAR DADOS DE REGISTRO
				char id[5], searchID[5], ch;
				int update_option;
				book bk;
				FILE *file;
				FILE *temp;
				system("cls");
				
				temp = fopen("temp.txt", "a");
				if (temp == NULL){
					temp = fopen("temp.txt", "w");
				};
				fclose(temp);
				
				
				printf("----------------------------- Atualizacao de registros -----------------------------\n");
			
				file = fopen("savedata.txt", "r");
				showAll(file);
				fclose(file);
				
				file = fopen("savedata.txt", "r");
				temp = fopen("temp.txt", "w");
				
				printf("\n\nID do livro que deseja atualizar: ");
				scanf("%s", id);
				printf("\n");
			
				while (fscanf(file, "\n%[^,]", searchID) == 1) {
        			if (strcmp(searchID, id) == 0) {
            			fscanf(file, ", %[^,]", bk.title);
            			fscanf(file, ", %[^,]", bk.author);
            			fscanf(file, ", %[^,]", bk.publisher);
            			fscanf(file, ", %[^,]", bk.year);
            			fscanf(file, ", %[^,]", bk.pages);
            			fscanf(file, ", %[^,]", bk.language);
            			fscanf(file, ", %[^;\n]", bk.isbn);
            			fscanf(file, "%c", &ch);
            			
            			
            			printf("1- Titulo: %s\n2 - Autor: %s\n3 - Editora: %s\n4 - Ano de publicacao: %s\n5 - Numero de paginas: %s\n6 - Lingua: %s\n7 - ISBN: %s\n8 - Cancelar\n", bk.title, bk.author, bk.publisher, bk.year, bk.pages, bk.language, bk.isbn);
            			printf("\nQual informacao deseja modificar? ");
            			
            			scanf("%d", &update_option);
            			switch(update_option){
            				case 1: {
								printf("\nTitulo: ");
								getchar();
								fgets(bk.title, 120, stdin);
								removeBreakRow(bk.title);
								break;
							}
							
							case 2: {
								printf("\nAutor: ");
								getchar();
								fgets(bk.author, 80, stdin);
								removeBreakRow(bk.author);								
								break;
							}
							
							case 3: {
								printf("\nEditora: ");
								getchar();
								fgets(bk.publisher, 40, stdin);
								removeBreakRow(bk.publisher);								
								break;
							}
							
							case 4: {
								printf("Ano de publicacao: ");
								scanf("%s", bk.year);
								break;
							} 
							
							case 5: {
								printf("Numero de paginas: ");
								scanf("%s", bk.pages);
								break;
							}
							
							case 6: {
								printf("Lingua: ");
								scanf("%s", bk.language);
								break;
							}
							
							case 7: {
								printf("ISBN: ");
								scanf("%s", bk.isbn);
								break;
							}
							
							case 8: {
								break;
							}
							
							default: {
								break;
							}
						}
            			
            			fprintf(temp, "\n%s, %s, %s, %s, %s, %s, %s, %s;", searchID, bk.title, bk.author, bk.publisher, bk.year, bk.pages, bk.language, bk.isbn);

        			} else {
            			fscanf(file, ", %[^,]", bk.title);
            			fscanf(file, ", %[^,]", bk.author);
            			fscanf(file, ", %[^,]", bk.publisher);
            			fscanf(file, ", %[^,]", bk.year);
            			fscanf(file, ", %[^,]", bk.pages);
            			fscanf(file, ", %[^,]", bk.language);
            			fscanf(file, ", %[^;\n]", bk.isbn);
            			fscanf(file, "%c", &ch);
            			fprintf(temp, "\n%s, %s, %s, %s, %s, %s, %s, %s;", searchID, bk.title, bk.author, bk.publisher, bk.year, bk.pages, bk.language, bk.isbn);
        			}
    			}
    			
    			fclose(file);
    			fclose(temp);
				remove("savedata.txt");
				rename("temp.txt", "savedata.txt");
				
				break;
			}
				
			case 5:{ //DELETAR REGISTROS
			//ERRO: REMOVE E RENAME DO ARQUIVO .TXT
			
				char id[5], searchID[5], ch;
				book bk_del;
				book bk;
				FILE *file;
				FILE *temp;
				system("cls");
				
				temp = fopen("temp.txt", "a");
				if (temp == NULL){
					temp = fopen("temp.txt", "w");
				};
				fclose(temp);
				
				
				printf("----------------------------- Exclusao de registros -----------------------------\n");
			
				file = fopen("savedata.txt", "r");
				
			
				showAll(file);
				fclose(file);
				
				file = fopen("savedata.txt", "r");
				temp = fopen("temp.txt", "w");
				
				printf("\n\nID do livro que deseja remover: ");
				scanf("%s", id);
			
				while (fscanf(file, "\n%[^,]", searchID) == 1) {
        			if (strcmp(searchID, id) == 0) {
            		fscanf(file, ", %[^,]", bk_del.title);
            			fscanf(file, ", %[^,]", bk_del.author);
            			fscanf(file, ", %[^,]", bk_del.publisher);
            			fscanf(file, ", %[^,]", bk_del.year);
            			fscanf(file, ", %[^,]", bk_del.pages);
            			fscanf(file, ", %[^,]", bk_del.language);
            			fscanf(file, ", %[^;\n]", bk_del.isbn);
            			fscanf(file, "%c", &ch);
        			} else {
            			fscanf(file, ", %[^,]", bk.title);
            			fscanf(file, ", %[^,]", bk.author);
            			fscanf(file, ", %[^,]", bk.publisher);
            			fscanf(file, ", %[^,]", bk.year);
            			fscanf(file, ", %[^,]", bk.pages);
            			fscanf(file, ", %[^,]", bk.language);
            			fscanf(file, ", %[^;\n]", bk.isbn);
            			fscanf(file, "%c", &ch);
            			fprintf(temp, "\n%s, %s, %s, %s, %s, %s, %s, %s;", searchID, bk.title, bk.author, bk.publisher, bk.year, bk.pages, bk.language, bk.isbn);
        			}
    			}
    			fclose(file);
    			fclose(temp);
				remove("savedata.txt");
				rename("temp.txt", "savedata.txt");
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


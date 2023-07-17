#include <stdio.h>
#include "stringsManipulation.h"
#include <unistd.h>
#include <conio.h>

int confirmation;

//enum categories {
//	fiction = 1, nonfiction, adventure, classic, crime, fantasy, horror, historicalfiction, humour, mystery, poetry, romance, thriller, war, autobiography, selfhelp, biography 
//};

void bookCreate(FILE *file, char title[], char author[], char year[], char pages[], char language[], char publisher[], char isbn[]) {	

	// ABRINDO ARQUIVO DE LEITURA
	FILE *file_r = fopen("savedata.txt", "r");
	
	// SALVANDO...
	printf("Salvando informacoes.");
	sleep(1);
	printf(".");
	sleep(1);

	
	// REMOVENDO QUEBRA DE LINHA DO FGETS
	removeBreakRow(title);
	removeBreakRow(author);
	removeBreakRow(publisher);
	
	// ESCREVENDO EM ARQUIVO
	fprintf(file, "\n%d, %s, %s, %s, %s, %s, %s, %s;", newID(file_r), title, author, publisher, year, pages, language, isbn);
	
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
}

void bookDataPrint(book b){
	int i = 0;
	printf("\nTitulo: ");
	for (i=0; i<strlen(b.title); i++){
		printf("%c", b.title[i]);
	}
	
	printf("\nAutor: ");
	for (i=0; i<strlen(b.author); i++){
		printf("%c", b.author[i]);
	}

	printf("\nEditora: ");
	for (i=0; i<strlen(b.publisher); i++){
		printf("%c", b.publisher[i]);
	}

	printf("\nAno de publicacao: ");
	for (i=0; i<strlen(b.year); i++){
		printf("%c", b.year[i]);
	}

	printf("\nNumero de paginas: ");
	for (i=0; i<strlen(b.pages); i++){
		printf("%c", b.pages[i]);
	}
	
	printf("\nLingua: ");
	for (i=0; i<strlen(b.language); i++){
		printf("%c", b.language[i]);
	}
	
	printf("\nISBN: ");
	for (i=0; i<strlen(b.isbn); i++){
		printf("%c", b.isbn[i]);
	}
	printf("\n");
}

void bookView(FILE *file, char id[]) {
	book b;
	b = getBook(file, id);
	
	bookDataPrint(b);
}



void bookDelete(FILE *file, char id[]) {
	
}



int bookUpdate(FILE *file, char id[]) {
	int i, mod, updateOption;
	book b;
	b = getBook(file, id);
	FILE *temp;
	
	bookDataPrint(b);
	
	printf("\nQual dos valores deseja modificar? ");
	printf("\n1 - Titulo ");
	printf("\n2 - Autor ");	
	printf("\n3 - Editora ");
	printf("\n4 - Ano ");
	printf("\n5 - Paginas ");
	printf("\n6 - Lingua ");
	printf("\n7 - ISBN ");
	printf("\n8 - Cancelar\n");
	
	printf(">>> ");
	scanf("%d", &updateOption);
	switch(updateOption){
		case 1: {//TITULO
			char newTitle[150];
			printf("Insira o titulo: ");
			getchar();
			fgets(newTitle, 150, stdin);
			removeBreakRow(newTitle);
			strcpy(b.title, newTitle);
			break;
		}
		
		case 2: {//AUTOR
			char newAuthor[80];
			printf("Insira o autor: ");
			fgets(newAuthor, 80, stdin);
			strcpy(b.author, newAuthor);
			break;
		}
		
		case 3: {//EDITORA
			char newPublisher[40];
			printf("Insira a editora: ");
			fgets(newPublisher, 40, stdin);
			strcpy(b.publisher, newPublisher);
			break;
		}
		
		case 4: {//ANO
			char newYear[5];
			printf("Insira o ano de lancamento: ");
			scanf("%s", newYear);
			strcpy(b.year, newYear);
			break;
		}
		
		case 5: {//PAGINAS
			char newPages[5];
			printf("Insira o numero de paginas: ");
			scanf("%s", newPages);
			strcpy(b.pages, newPages);
			break;
		}
		
		case 6: {//LINGUA
			char newLanguage[20];
			printf("Insira a lingua: ");
			scanf("%s", newLanguage);
			strcpy(b.language, newLanguage);
			break;
		}
		
		case 7: {//ISBN
			char newISBN[22];
			printf("Insira o ISBN: ");
			scanf("%s", newISBN);
			strcpy(b.isbn, newISBN);
			break;
		}
		
		case 8: {//SAIR
			break;
		}
		
		default:{
			break;
		}
	}
	
//	temp = fopen("save")
	
}




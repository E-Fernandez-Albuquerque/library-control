#ifndef STRUCTS_H
#define STRUCTS_H

//DECLARACAO DE STRUCTS
typedef struct books {
	int ID;
	char isbn[22];
	char title[150];
	char author[80];
	char year[5];
	char pages[5];
	char language[20];
	char publisher[40];
} book;

#endif

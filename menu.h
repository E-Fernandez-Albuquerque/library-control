int menu() {
	int choice = 0;
	do {
		printf("Selecione uma opcao: \n");
		printf("1 - Cadastrar\n2 - Listar\n3 - Atualizar\n4 - Excluir\n5 - Sair\n>>> ");
		scanf("%d", &choice);
	} while (choice <= 0 || choice > 5);
	return choice;
}

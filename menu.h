int menu() {
	int choice = 0;
	do {
		printf("Selecione uma opcao: \n");
		printf("1 - Cadastrar\n2 - Listar\n3 - Pesquisar por ID\n4 - Atualizar\n5 - Excluir\n6 - Sair\n>>> ");
		scanf("%d", &choice);
	} while (choice <= 0 || choice > 6);
	return choice;
}

#include <stdio.h> //bibioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro(){
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int continuar, laco=1;
	
	system("cls");
		
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das strings
	
	
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo com o nome da variável "arquivo", que nesse caso é o CPF
	fprintf(file,cpf);//salva o valor da variável CPF no arquivo criado
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome),
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n\nDeseja incluir novo registro?\n\n");
	printf("\t1 - SIM, quero fazer outro registro!\n");
	printf("\t2 - NÃO, quero voltar ao menu inicial!\n");
	scanf("%d", &continuar);
	
	for(laco=1;laco=1;){
		switch (continuar){
			case 1:
			registro();		
			break;
			
			case 2:
			menu();	
			break;
						
			default: 
			system("cls");
			printf("Essa opção não está disponível!!!\n");
			printf("\n\nDeseja incluir novo registro?\n\n");
			printf("\t1 - SIM, quero fazer outro registro!\n");
			printf("\t2 - NÃO, quero voltar ao menu inicial!\n");
			scanf("%d", &continuar);
			break;
		}
	}	
		
	
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo para leitura
	
	if(file == NULL){
		printf("Arquivo não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //coloca tudo o que está em file em conteúdo
	    printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar(){
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);	
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL){
		printf("Usuário não se encontra no sistema \n\n");
		system("pause");
	}
	else{
		remove(cpf);
		printf("Usuário excluído com sucesso!!!\n\n");
		system("pause");
	}	
	
	
	
	
	
	
	
	
	
}


int menu(){
	
	int opcao=0; //definindo as váriáveis
	int laco=1;
	
	
	for(laco=1;laco=1;)
		{
			
			system("cls");
			
			
		
			printf("###CARTÓRIO DA EBAC###\n\n"); //início menu
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); //fim do menu
			printf("\t4 - Sair do sistema\n\n");
			printf("Opcão: ");
			
			scanf("%d", &opcao); //armazenando a escolha do usuário
			
			system("cls");
			
			switch (opcao){
				case 1:
				registro();
				
				break;
				
				case 2:
				consulta();
				
				break;
				
				case 3:
				deletar();
				
				break;
				
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");				
				exit(0);
				
				break;
				
				
				default: 
				printf("Essa opção não está disponível\n");
				system("pause");
				break;
			}
			
		}
	
}

int main()
{
	
	
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
	char senhadigitada[10]="a";
	char senha[10]="admin";
	int laco=1;
	int result=0;
	
	
	
	
		
	for(laco=1;laco=1;){
		
		
		
		printf("###Cartório da EBAC ###\n\n");
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);	
	
		if(strcmp(senhadigitada,senha)==0){				
			menu();				
		}
		else{
			system("cls");
			printf("\n\nSenha incorreta!\n\n");			
		}
			
	}
	
	
	
	
	
}


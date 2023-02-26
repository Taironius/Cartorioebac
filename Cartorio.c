#include <stdio.h> //bibioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

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
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores das strings
	
	
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo com o nome da vari�vel "arquivo", que nesse caso � o CPF
	fprintf(file,cpf);//salva o valor da vari�vel CPF no arquivo criado
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
	printf("\t2 - N�O, quero voltar ao menu inicial!\n");
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
			printf("Essa op��o n�o est� dispon�vel!!!\n");
			printf("\n\nDeseja incluir novo registro?\n\n");
			printf("\t1 - SIM, quero fazer outro registro!\n");
			printf("\t2 - N�O, quero voltar ao menu inicial!\n");
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
		printf("Arquivo n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //coloca tudo o que est� em file em conte�do
	    printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar(){
	char cpf[40];
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);	
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL){
		printf("Usu�rio n�o se encontra no sistema \n\n");
		system("pause");
	}
	else{
		remove(cpf);
		printf("Usu�rio exclu�do com sucesso!!!\n\n");
		system("pause");
	}	
	
	
	
	
	
	
	
	
	
}


int menu(){
	
	int opcao=0; //definindo as v�ri�veis
	int laco=1;
	
	
	for(laco=1;laco=1;)
		{
			
			system("cls");
			
			
		
			printf("###CART�RIO DA EBAC###\n\n"); //in�cio menu
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); //fim do menu
			printf("\t4 - Sair do sistema\n\n");
			printf("Opc�o: ");
			
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
			
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
				printf("Essa op��o n�o est� dispon�vel\n");
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
		
		
		
		printf("###Cart�rio da EBAC ###\n\n");
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


#include <stdio.h> //Comunica��o com o usu�rio
#include <stdlib.h> //Aloca��o de espa�o de mem�ria
#include <locale.h> //Aloca��o de texto por regi�o
#include <string.h> //Respons�vel por cuidar das strings

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo regi�o para uso dos caracteres
	
	//In�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //Chamando a fun��o FILE se referindo ao arquivo criado
	file = fopen(cpf,"r"); //Abrindo o arquivo para "r" = ler a vari�vel CPF
	
	if(file == NULL) //Se o valor do arquivo for nulo, n�o existir no banco de dados, apresentar a mensagem abaixo ao usu�rio
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado\n\n"); //Mensagem que apresentar� as informa��es do usu�rio
	}
	
	if(file != NULL) //Se o valor for diferente de nulo, exibir a seguinte mensagem
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n\n"); //Mensagem que apresentar� as informa��es do usu�rio	
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Loop, enquanto o arquivo n�o for nulo, pegar as informa��es contidas na vari�vel e exibir ao usu�rio
	{
		printf("%s", conteudo);
	}	
	
	printf("==================================================\n\n");	
	
	fclose(file); //Fecha o arquivo
	system("pause"); //Pausa o programa
}

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	//Fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a armazenamento de informa��es digitadas pelo usu�rio em strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo / "w" significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" significa que estamos alterando o arquivo
	fprintf(file,"\nNOME: "); //Adicionando t�tulo para o valor que ser� inserido pelo usu�rio
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,nome); //Alterando o arquivo, direcionando a vari�vel correta, com a informa��o coletada do usu�rio
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,"\nSOBRENOME: "); //Adicionando t�tulo para o valor que ser� inserido pelo usu�rio
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo	
	fprintf(file,sobrenome); //Alterando o arquivo, direcionando a vari�vel correta, com a informa��o coletada do usu�rio
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,"\nCARGO: "); //Adicionando t�tulo para o valor que ser� inserido pelo usu�rio 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cargo); 
	
	file = fopen(arquivo, "a"); //Abre o arquivo		
	fprintf(file,cargo); //Alterando o arquivo, direcionando a vari�vel correta, com a informa��o coletada do usu�rio
	fprintf(file,"\n\n\n");	//Adicionando quebra de linhas para melhor organiza��o
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausando o programa ap�s o fim da fun��o		
}

int excluir()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo regi�o para uso dos caracteres
	
	//In�cio da cria��o de vari�veis/strings
	char cpf[40];
	//Fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF do usu�rio a ser exclu�do: "); //Colentando informa��es do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //Chamando a fun��o FILE se referindo ao arquivo criado
	file = fopen(cpf, "r"); //Abrindo o arquivo para "r" = ler a vari�vel CPF
	fclose(file); //Fecha o arquivo
	
	if(file == NULL) //Se a informa��o inserida n�o for encontrada no banco de dados "NULL", mostrar a mensagem abaixo ao usu�rio
	{
		printf("\nO usu�rio n�o se encontra no sistema, tente outro.\n\n");
		printf("==================================================\n\n");
		system("pause"); //Pausa o programa	
	}
	else //Ou, se a informa��o for encontrada, deletar o arquivo especificado pelo usu�rio e mostrar a mensagem abaixo
	{
		remove(cpf); //Remove a informa��o da vari�vel indicada pelo usu�rio
		printf("\nUsu�rio deletado com sucesso!\n\n");
		printf("==================================================\n\n");
		system("pause"); //Pausa o programa	
	}
}

int main() //Fun��o principal e primeira a ser exibida do programa "MENU"
{
	setlocale(LC_ALL, "Portuguese"); //Definindo regi�o para uso dos caracteres
	
	//Definindo vari�veis e seus valores
	int opcao=0;
	int laco=1;
	int compara=2;
	char senhadigitada[10]="a";
	
	while(1) //Loop criado para voltar a valida��o de senha
	{
		printf("================ CART�RIO DA EBAC ================\n\n");		
		printf("\t\tLogin: ADMINISTRADOR\n");
		printf("\t\tSenha: ");
		scanf("%s",senhadigitada); //Armazena o valor na string "senhadigitada"
		system("cls");
	
		compara = strcmp(senhadigitada, "admin"); //Compara a vari�vel "senhadigitada" com a informa��o dada pelo usu�rio
		
		if (compara == 0) //Quebra de loop se a senha for a indicada
		{
			for(laco=1;laco=1;) //Operador de repeti��o para sempre voltar a este menu, a este "la�o"
			{
				system("cls");
				setlocale(LC_ALL, "Portuguese"); //Definindo regi�o para uso dos caracteres
	
				printf("================ CART�RIO DA EBAC ================\n\n"); //In�cio do MENU
				printf("\t  Escolha a op��o desejada abaixo:\n\n");
				printf("\t\t1 - Consultar Nomes\n");
				printf("\t\t2 - Registrar Nomes\n");
				printf("\t\t3 - Excluir Nomes\n\n");
				printf("\t\t4 - Sair do Sistema\n\n");		
				printf("==================================================\n\n");
				printf("Op��o:"); //Fim do MENU
			
				scanf("%d", &opcao); //Armazenando a escolha do usu�rio / "%d" atribui��o para armazenar vari�vel do tipo inteiro / &define em qual vari�vel ele ir� armazenar a escolha
	
				system("cls"); //Respons�vel por limpar a tela
			
				switch(opcao) //In�cio da sele��o do menu
				{
					case 1:
					consulta(); //Chamada de fun��es
					break;	
			
					case 2:
					registro();
					break;
			
					case 3:				
					excluir(); 
					break;	
			
					case 4:
					printf("\nObrigado por utilizar o sistema!\n\n");
					return 0;
					break;
			
					default:
					printf("Essa op��o n�o est� dispon�vel\n");
					system("pause");
					break;							
				} //Fim da sele��o		
			}
		}
	
		else //Em caso de erro da senha ser� exibida a mensagem abaixo, e retorna o loop de login
		{
			printf("\nSenha incorreta! Tente novamente\n\n");
			system("pause");
			system("cls");
		}	
	}
}

#include <stdio.h> //Comunicação com o usuário
#include <stdlib.h> //Alocação de espaço de memória
#include <locale.h> //Alocação de texto por região
#include <string.h> //Responsável por cuidar das strings

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo região para uso dos caracteres
	
	//Início da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file; //Chamando a função FILE se referindo ao arquivo criado
	file = fopen(cpf,"r"); //Abrindo o arquivo para "r" = ler a variável CPF
	
	if(file == NULL) //Se o valor do arquivo for nulo, não existir no banco de dados, apresentar a mensagem abaixo ao usuário
	{
		printf("\nNão foi possível abrir o arquivo, não localizado\n\n"); //Mensagem que apresentará as informações do usuário
	}
	
	if(file != NULL) //Se o valor for diferente de nulo, exibir a seguinte mensagem
	{
		printf("\nEssas são as informações do usuário:\n\n"); //Mensagem que apresentará as informações do usuário	
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Loop, enquanto o arquivo não for nulo, pegar as informações contidas na variável e exibir ao usuário
	{
		printf("%s", conteudo);
	}	
	
	printf("==================================================\n\n");	
	
	fclose(file); //Fecha o arquivo
	system("pause"); //Pausa o programa
}

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	//Fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a armazenamento de informações digitadas pelo usuário em strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo / "w" significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //Salvo o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" significa que estamos alterando o arquivo
	fprintf(file,"\nNOME: "); //Adicionando título para o valor que será inserido pelo usuário
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,nome); //Alterando o arquivo, direcionando a variável correta, com a informação coletada do usuário
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,"\nSOBRENOME: "); //Adicionando título para o valor que será inserido pelo usuário
	fclose(file); //Fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo	
	fprintf(file,sobrenome); //Alterando o arquivo, direcionando a variável correta, com a informação coletada do usuário
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,"\nCARGO: "); //Adicionando título para o valor que será inserido pelo usuário 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cargo); 
	
	file = fopen(arquivo, "a"); //Abre o arquivo		
	fprintf(file,cargo); //Alterando o arquivo, direcionando a variável correta, com a informação coletada do usuário
	fprintf(file,"\n\n\n");	//Adicionando quebra de linhas para melhor organização
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausando o programa após o fim da função		
}

int excluir()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo região para uso dos caracteres
	
	//Início da criação de variáveis/strings
	char cpf[40];
	//Fim da criação de variáveis/strings
	
	printf("Digite o CPF do usuário a ser excluído: "); //Colentando informações do usuário
	scanf("%s",cpf);
	
	FILE *file; //Chamando a função FILE se referindo ao arquivo criado
	file = fopen(cpf, "r"); //Abrindo o arquivo para "r" = ler a variável CPF
	fclose(file); //Fecha o arquivo
	
	if(file == NULL) //Se a informação inserida não for encontrada no banco de dados "NULL", mostrar a mensagem abaixo ao usuário
	{
		printf("\nO usuário não se encontra no sistema, tente outro.\n\n");
		printf("==================================================\n\n");
		system("pause"); //Pausa o programa	
	}
	else //Ou, se a informação for encontrada, deletar o arquivo especificado pelo usuário e mostrar a mensagem abaixo
	{
		remove(cpf); //Remove a informação da variável indicada pelo usuário
		printf("\nUsuário deletado com sucesso!\n\n");
		printf("==================================================\n\n");
		system("pause"); //Pausa o programa	
	}
}

int main() //Função principal e primeira a ser exibida do programa "MENU"
{
	setlocale(LC_ALL, "Portuguese"); //Definindo região para uso dos caracteres
	
	//Definindo variáveis e seus valores
	int opcao=0;
	int laco=1;
	int compara=2;
	char senhadigitada[10]="a";
	
	while(1) //Loop criado para voltar a validação de senha
	{
		printf("================ CARTÓRIO DA EBAC ================\n\n");		
		printf("\t\tLogin: ADMINISTRADOR\n");
		printf("\t\tSenha: ");
		scanf("%s",senhadigitada); //Armazena o valor na string "senhadigitada"
		system("cls");
	
		compara = strcmp(senhadigitada, "admin"); //Compara a variável "senhadigitada" com a informação dada pelo usuário
		
		if (compara == 0) //Quebra de loop se a senha for a indicada
		{
			for(laco=1;laco=1;) //Operador de repetição para sempre voltar a este menu, a este "laço"
			{
				system("cls");
				setlocale(LC_ALL, "Portuguese"); //Definindo região para uso dos caracteres
	
				printf("================ CARTÓRIO DA EBAC ================\n\n"); //Início do MENU
				printf("\t  Escolha a opção desejada abaixo:\n\n");
				printf("\t\t1 - Consultar Nomes\n");
				printf("\t\t2 - Registrar Nomes\n");
				printf("\t\t3 - Excluir Nomes\n\n");
				printf("\t\t4 - Sair do Sistema\n\n");		
				printf("==================================================\n\n");
				printf("Opção:"); //Fim do MENU
			
				scanf("%d", &opcao); //Armazenando a escolha do usuário / "%d" atribuição para armazenar variável do tipo inteiro / &define em qual variável ele irá armazenar a escolha
	
				system("cls"); //Responsável por limpar a tela
			
				switch(opcao) //Início da seleção do menu
				{
					case 1:
					consulta(); //Chamada de funções
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
					printf("Essa opção não está disponível\n");
					system("pause");
					break;							
				} //Fim da seleção		
			}
		}
	
		else //Em caso de erro da senha será exibida a mensagem abaixo, e retorna o loop de login
		{
			printf("\nSenha incorreta! Tente novamente\n\n");
			system("pause");
			system("cls");
		}	
	}
}

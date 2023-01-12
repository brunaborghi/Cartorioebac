#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40]; //[]quantidade de caracteres
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informaçõa do usuário
	scanf("%s", cpf); //Armazenando a escolha do usuário dentro de uma string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo (write)
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");// Abrir o arquivo para atualizar
	fprintf(file,","); //Incluindo a vírgula no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar o nome
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar o sobrenome
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abrindo arquivo para atualizar o cargo
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //Voltar ao menu
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200]; //criando variável tipo string para consultar
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo para ler o cpf (read)
	
	if(file == NULL ) //Validação para caso o arquivo não seja encontrado
	{
		printf("\nNão foi possível abrir o arquivo, CPF não localizado!\n\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Validação caso o CPF seja encontrado (fgets = ler uma string em um arquivo)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo para ler o cpf (read)

	if(file == NULL ) //Validação para caso o arquivo não seja encontrado
	{
		printf("\n O usuário não se encontra no sistema!.\n\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //Definindo as variáveis
	int laco=1; //Definindo as variáveis
	
	for(laco=1;laco=1;) //Operação de repetição
	{
	
		system("cls"); //Limpar tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\n*** Cartório da EBAC ***\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: ");//Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário na variável
	
		system("cls"); //Limpar a tela
	
		switch(opcao) //Inicio da seleção 
		{
		case 1: 
		registro(); //chamada de funções
		break; //Encerrando a opção
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
			
		default:
		printf("Essa opção não está disponível!!\n\n");
		system("pause");
		break;
		} //Fim da seleção

	}
}


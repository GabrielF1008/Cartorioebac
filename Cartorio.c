#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memório
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	// Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, "w"(write) para inicialização
	fprintf(file, cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualização
	fprintf(file,","); // Adiciona uma vírgula para a separação dos resultados
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", nome); // atribuindo a informação do usuário à variável "nome"
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, nome); // atualiza o arquivo, adicionando a variável nome após a vírgula
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  // abre o arquivo para atualização
	fprintf(file,","); // adiciona outra vírgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", sobrenome); // atribuindo a informação coletada à variável "sobrenome"
	
	file = fopen(arquivo, "a"); // abrindo o arquivo para atualização
	fprintf(file, sobrenome); // atualiza o arquivo, adicionando a variável sobrenome após a vírgula
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); // atualiza o arquivo, adicionando uma vírgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", cargo); // atribuindo a informação coletada à variável "cargo"
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file, cargo); // atualiza o arquivo, adicionando a variável cargo após a vírgula
	fclose(file); // fecha o arquivo
	
	system("pause"); // pausa o loop 
}

int consulta() // Função responsável por consultar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// Início da declaração das variáveis
	char cpf[40];
	char conteudo[200];
	// Fim da declaração das variáveis
	
	printf("Digite o CPF a ser consultado: "); // Coletando informações do usuário
	scanf("%s", cpf); // atribuindo a informação coletada à variável cpf
	
	FILE *file; // chamando a função pré definida da biblioteca para lidar com arquivos
	file = fopen(cpf, "r"); // "r" de read, abre o arquivo e lê
	
	if(file == NULL) // Tratativa para lidar com possíveis erros de não encontrar o cpf cadastrado (usuário pode digitar um CPF inválido, que nãao está no sistema)
	{
		printf("Não foi possível consultar o usuário, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // loop para ler todas as informações do conteúdo, 200 é quando para, lê os 200 caracteres da string
	{
		printf("\nEssas são as informações do usuário: "); // Mensagem prévia para avisar pro usuário, as informações coletadas
		printf("%s", conteudo); // Mostrando ao usuário o conteúdo que o loop lêu
		printf("\n\n"); // 2 "tags" para pular linha (similaridade ao <br> do HTML)
	}
	
	fclose(file);
	system("pause"); // pausando o loop
}

int deletar() //Função responsável por deletar os usuários
{
	char cpf[40]; // declarando a variável que será a PK(Primary key); chave única para identificação do usuário
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coletando informações do usuário
	scanf("%s", cpf); // Atribuindo a informação coletada à variável cpf
	
	remove(cpf); // função da biblioteca que remove alguma variável
	
	FILE *file; // chamando a função para lidar co arquivos
	file = fopen(cpf, "r"); // abrindo o arquivo e lendo-o
	
	if(file == NULL){ // Tratativa de erro caso não haja cliente com a primary key que o usuário forneceu
		printf("O usuário não se encontra no sistema!\n");
		system("pause"); // pausando o loop
	}
	
}

int main() // Função principal
	{
	int opcao=0; //Definindo as variáveis
	int laco=1;

	for(laco=1;laco=1;) //Criando um laço para que o usuário tenha a opção de voltar ao menu e escolher outras opções
	{
		
		system("cls"); //Limpa a tela de comandos
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");// Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Limpa a tela de comandos
		
		switch(opcao){ // switch case para captar a informação do usuário
			case 1:
			registro(); // chamando a função de registro, caso o usuário tenha selecionado a opção 1
			break;
			
			case 2:
			consulta();// chamando a função de consulta, caso o usuário tenha selecionado a opção 2
			break;
			
			case 3:
			deletar();// chamando a função de deketar, caso o usuário tenha selecionado a opção 3
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível");// Tratativa de erro, mensagem caso o usuário não selecione nenhuma das opções disponíveis(1,2,3)
			system("pause"); // pausando o loop
		}

	}
}


























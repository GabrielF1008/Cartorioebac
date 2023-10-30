#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�rio
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	// Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, "w"(write) para inicializa��o
	fprintf(file, cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" para atualiza��o
	fprintf(file,","); // Adiciona uma v�rgula para a separa��o dos resultados
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", nome); // atribuindo a informa��o do usu�rio � vari�vel "nome"
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, nome); // atualiza o arquivo, adicionando a vari�vel nome ap�s a v�rgula
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  // abre o arquivo para atualiza��o
	fprintf(file,","); // adiciona outra v�rgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", sobrenome); // atribuindo a informa��o coletada � vari�vel "sobrenome"
	
	file = fopen(arquivo, "a"); // abrindo o arquivo para atualiza��o
	fprintf(file, sobrenome); // atualiza o arquivo, adicionando a vari�vel sobrenome ap�s a v�rgula
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); // atualiza o arquivo, adicionando uma v�rgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", cargo); // atribuindo a informa��o coletada � vari�vel "cargo"
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file, cargo); // atualiza o arquivo, adicionando a vari�vel cargo ap�s a v�rgula
	fclose(file); // fecha o arquivo
	
	system("pause"); // pausa o loop 
}

int consulta() // Fun��o respons�vel por consultar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// In�cio da declara��o das vari�veis
	char cpf[40];
	char conteudo[200];
	// Fim da declara��o das vari�veis
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��es do usu�rio
	scanf("%s", cpf); // atribuindo a informa��o coletada � vari�vel cpf
	
	FILE *file; // chamando a fun��o pr� definida da biblioteca para lidar com arquivos
	file = fopen(cpf, "r"); // "r" de read, abre o arquivo e l�
	
	if(file == NULL) // Tratativa para lidar com poss�veis erros de n�o encontrar o cpf cadastrado (usu�rio pode digitar um CPF inv�lido, que n�ao est� no sistema)
	{
		printf("N�o foi poss�vel consultar o usu�rio, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // loop para ler todas as informa��es do conte�do, 200 � quando para, l� os 200 caracteres da string
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Mensagem pr�via para avisar pro usu�rio, as informa��es coletadas
		printf("%s", conteudo); // Mostrando ao usu�rio o conte�do que o loop l�u
		printf("\n\n"); // 2 "tags" para pular linha (similaridade ao <br> do HTML)
	}
	
	fclose(file);
	system("pause"); // pausando o loop
}

int deletar() //Fun��o respons�vel por deletar os usu�rios
{
	char cpf[40]; // declarando a vari�vel que ser� a PK(Primary key); chave �nica para identifica��o do usu�rio
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando informa��es do usu�rio
	scanf("%s", cpf); // Atribuindo a informa��o coletada � vari�vel cpf
	
	remove(cpf); // fun��o da biblioteca que remove alguma vari�vel
	
	FILE *file; // chamando a fun��o para lidar co arquivos
	file = fopen(cpf, "r"); // abrindo o arquivo e lendo-o
	
	if(file == NULL){ // Tratativa de erro caso n�o haja cliente com a primary key que o usu�rio forneceu
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause"); // pausando o loop
	}
	
}

int main() // Fun��o principal
	{
	int opcao=0; //Definindo as vari�veis
	int laco=1;

	for(laco=1;laco=1;) //Criando um la�o para que o usu�rio tenha a op��o de voltar ao menu e escolher outras op��es
	{
		
		system("cls"); //Limpa a tela de comandos
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");// In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Limpa a tela de comandos
		
		switch(opcao){ // switch case para captar a informa��o do usu�rio
			case 1:
			registro(); // chamando a fun��o de registro, caso o usu�rio tenha selecionado a op��o 1
			break;
			
			case 2:
			consulta();// chamando a fun��o de consulta, caso o usu�rio tenha selecionado a op��o 2
			break;
			
			case 3:
			deletar();// chamando a fun��o de deketar, caso o usu�rio tenha selecionado a op��o 3
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel");// Tratativa de erro, mensagem caso o usu�rio n�o selecione nenhuma das op��es dispon�veis(1,2,3)
			system("pause"); // pausando o loop
		}

	}
}


























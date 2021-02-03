// adicionando bibliotecas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "funcoes.h"

//variaveis globais

int c; 							
int contadorAviao = 0;
int contadorPassageiro = 0;
char concatenado[COMP];
char resp;
int *assentosAviao;
InfoVoo vet[VOO];

//criando os ponteiros para usar com os arquivos

FILE *aviao;
FILE *aviaoDados;

//__________________________________________________________________________________________________________________

//  A - Exibir os voos cadastrados e suas informacoes 

void exibirDados(){																									
	
	char resp;
	int contador;
	// criando arquivos
	aviao = fopen("cadastroVoo.txt", "r");
	
	// imprimiri dados do arquivo
	do{
		c = fgetc(aviao);
		if(c != EOF){
			printf("%c", c);
		}
	}while (c != EOF);
	//voltando ao menu principal
	do{
			printf("\n-----------------------------------------------------\n");
			printf("\nPrecione (s - sim) para voltar ao menu: \n");
			resp = getch();
				if(resp != 's'){
				printf("\nInsira um caractere valido.\n");
				delay();
			}
			system("cls");
		
		}while(resp != 's');
		
}
//__________________________________________________________________________________________________________________

//  B - Cadastro de Voos

void cadastrarVoo(){                                                                                            	
	
	//parametro cadastrar voo, pede os dados de cada VOO e joga na struct "InfoVoo".
		
	char c;
	char concateno[COMP];
	// criando txt
	aviao = fopen("cadastroVoo.txt", "a");
	
	// laco para o cadastro
	do{
		
	system("cls");
	// recebendo informacao do usuario
	
	fprintf(aviao, "\n");
	printf("\nInsira o numero do Voo: ");	
	fgets(vet[contadorAviao].numVoo, COMP, stdin);
	fflush(stdin);
	strtok(vet[contadorAviao].numVoo, "\n");
	
	printf("\nInsira o preco da passagem: ");
	scanf("%f", &vet[contadorAviao].precoPas);
	fflush(stdin);
	
	printf("\nInsira o Aeroporto de origem: ");
	fgets(vet[contadorAviao].aeroOri, COMP, stdin);
	fflush(stdin);
	strtok(vet[contadorAviao].aeroOri, "\n");
	
	printf("\nInsira o Aeroporto de destino: ");
	fgets(vet[contadorAviao].aeroDestin, COMP, stdin);	
	fflush(stdin);	
	strtok(vet[contadorAviao].aeroDestin, "\n");
	
	printf("\nInsira a hora de partida (AA:MM): ");
	fgets(vet[contadorAviao].horaPart, COMP, stdin);
	fflush(stdin);	
	strtok(vet[contadorAviao].horaPart, "\n");
	
	printf("\nInsira a hora de chegada (AA:MM): ");
	fgets(vet[contadorAviao].horaCheg, COMP, stdin);
	fflush(stdin);	
	strtok(vet[contadorAviao].horaCheg, "\n");
	
	// definindo limites e limitando
	do{
		printf("\nInsira um numero de lugares\n(numero max: 50): ");
		scanf("%d", &vet[contadorAviao].lugares);
			
		}while(vet[contadorAviao].lugares > 50);
		fflush(stdin);

	alterar();
		
	system("cls");
	
	}while(resp == 's');
	
	//alocando memoria para salvar assentos
	if(resp  == 'n' ){
		int aux3 = vet[contadorAviao].lugares;
	
		vet[contadorAviao].assentos = malloc(aux3 * sizeof(char*)); 
		int x;
		for (x = 0; x < aux3; x++) {
    		vet[contadorAviao].assentos[x] = malloc((COMP+1) * sizeof(char));
    		*vet[contadorAviao].assentos[x] = NULL; 
		}
	}
	
	salvarVooUnico(resp, concateno);
	
}  

//__________________________________________________________________________________________________________________
// funcao para salvar os voos unicos

void salvarVooUnico(char resp, char concateno[COMP]) { 

	if (resp == 'n'){
		
		strcpy(concateno, vet[contadorAviao].numVoo);
		strcat(concateno, ".txt");
		
		aviaoDados = fopen(concateno, "w");
		fprintf(aviaoDados, "\n%s", vet[contadorAviao].numVoo);
		
		fprintf(aviaoDados, "\n-----------------------------------------------------\n");
		fprintf(aviaoDados, "Numero do aviao: %s\n", vet[contadorAviao].numVoo );
		fprintf(aviaoDados, "Preco da passagem: %.2f", vet[contadorAviao].precoPas);
		fprintf(aviaoDados, "\nAeroporto de origem: %s\n", vet[contadorAviao].aeroOri );
		fprintf(aviaoDados, "Aeroporto de destino: %s\n", vet[contadorAviao].aeroDestin);
		fprintf(aviaoDados, "Hora de saida: %s\n", vet[contadorAviao].horaPart);
		fprintf(aviaoDados, "Hora de chegada: %s\n", vet[contadorAviao].horaCheg);
		fprintf(aviaoDados, "Numero de lugares: %d\n", vet[contadorAviao].lugares);
		fclose(aviaoDados);
		
		aviaoDados = fopen(concateno, "r");
		
		char ch;
		
		while((ch = fgetc(aviaoDados)) != EOF)
		fprintf(aviao, "%c", ch);
		
		fclose(aviao);	
		
		contadorAviao++;	
	}
}



//__________________________________________________________________________________________________________________
// Estrutura para decidir se havera alteracoes

void alterar(){
	
	do{
		printf("\n-----------------------------------------------------\n");
		printf("\nVoce deseja alterar algum dado?(s - sim / n - nao): \n");
		resp = getch();
	     if(resp != 's' && resp != 'n'){
		 printf("\nInsira um caractere valido.\n");
		 }
	}while(resp != 's' && resp != 'n');
}

//__________________________________________________________________________________________________________________

//  C - Consultar Voos especificos 
	
void exibirDadosVoo(){																							
	char nome[COMP];
    char resp;
    
    //recebendo dados
    printf("-------------Exibicao de dados-------------");
    printf("\nInsira o nome/numero do voo desejado: ");
    scanf("%s", &nome);
    
    // verificando se o dado recebido e existente
    strcat(nome, ".txt");
    if(aviaoDados = fopen(nome, "r")) {
        char ch;
        while((ch = fgetc(aviaoDados)) != EOF)
              printf("%c", ch);
    } else {
    	printf("\n-----------------------------------------\n");
        printf("\n O voo solicitado nao esta cadastrado");
        printf("\n-----------------------------------------\n");
    }   
    
    // voltando para o menu
    do{
			printf("\n-----------------------------------------------------\n");
			printf("\nPrecione (s - sim) para voltar ao menu: \n");
			resp = getch();
				if(resp != 's'){
				printf("\nInsira um caractere valido.\n");
			delay();
			}
			system("cls");
		}while(resp != 's');
}


//__________________________________________________________________________________________________________________

//  D - cadastro de passageiros 

void cadastroDePassageiros(){																						
	
	InfoPass cadastro[PAS];
	
	char nome[COMP];	//char resp;
	int aux = 0;
	int ok = 0;
	
	
	// laco para o cadastro
	
	// verificando se esta ok
	
    do {
    	
	printf("\n--------------CADASTRO DE PASSAGEIROS--------------\n");
    printf("\nInsira o nome/numero do voo desejado: ");
	scanf("%s", &nome);
	    
    strcat(nome, ".txt");
    
	if(aviaoDados = fopen(nome, "r")){
		
	fprintf(aviaoDados, "\n");
	fprintf(aviaoDados, "\nCadastro de passageiro \n");
	fflush(stdin);
	
	printf("\nInsira o nome do passageiro: ");
	fgets(cadastro[contadorPassageiro].nome , COMP, stdin);
	fflush(stdin);
	
	printf("\nInsira o CPF do passageiro: ");
	scanf("%s", &cadastro[contadorPassageiro].CPF);
	fflush(stdin);
	
	printf("\nInsira a data de nascimento: ");
	fgets(cadastro[contadorPassageiro].dataNascimento , COMP, stdin);
	fflush(stdin);
	
	printf("\nInsira o numero de telefone: ");
	fgets(cadastro[contadorPassageiro].numTel , COMP, stdin);
	fflush(stdin);
	
	printf("\nInsira um e-mail valido: ");
	fgets(cadastro[contadorPassageiro].eMail , COMP, stdin);
	fflush(stdin);
		
	// verificar que o assento está ok.
	
	ok = 0;
	
	do {
		
		printf("\ninsira o numero do assento desejado: ");
		scanf("%d", &cadastro[contadorPassageiro].numAssen);
		fflush(stdin);
		
		int assento = cadastro[contadorPassageiro].numAssen - 1;
		// checar o avião para ter o indice de VET.
		// assim você pega os assentos.
		
		
		// achar o avião correto.
		size_t tamanhoVet = sizeof(vet)/sizeof(vet[0]);
		int i;
		int index = 0;
		for(i = 0; i < tamanhoVet; i++) {
			if(vet[i].numVoo == nome) {
				index = i;
				break;
			}
		}
		// parte em andamento, o intuito era verificar se o assento esta vazio
		if(vet[index].assentos[assento] == NULL || vet[index].assentos[assento] == "")
			ok = 1;
		} while(ok != 0);
		
		alterar();
		
	// andamento
	if(resp == 'n' && aux == 0){
		salvarPassageiro(cadastro);
	}
	
	system("cls");
	printf("\nCadastro realizado com sucesso!");
	delay();
	menu();
	    	ok = 1;
	    }else{
	    	system("cls");
	    	printf("\n--------------CADASTRO DE PASSAGEIROS--------------\n");
	    	printf("\n---------------------------------------------------\n");
	        printf("O voo solicitado nao esta cadastrado!");
	        printf("\n---------------------------------------------------\n");
	        delay();
	        delay();
	        system("cls");
	    }	
	    
	    
	}while(!ok);
	// recebendo dados
	
}

// função para salvar o passageiro no txt do voo.

void salvarPassageiro(InfoPass* cadastro) {
		fprintf(aviaoDados, "\n-----------------------------------------------------\n");
		fprintf(aviaoDados, "\nNome: %s", cadastro[contadorPassageiro].nome);
		fprintf(aviaoDados, "\nCPF: %s", cadastro[contadorPassageiro].CPF);
		fprintf(aviaoDados, "\nData de nascimento: %s", cadastro[contadorPassageiro].dataNascimento);
		fprintf(aviaoDados, "\nNumero de telefone: %s", cadastro[contadorPassageiro].numTel);
		fprintf(aviaoDados, "\nE-Mail: %s", cadastro[contadorPassageiro].eMail);
		fprintf(aviaoDados, "\nPoltrona reservada: %d", cadastro[contadorPassageiro].numAssen);
		fclose(aviaoDados);
		contadorPassageiro++;	
}
	
//__________________________________________________________________________________________________________________
// delay para mensagens curtas

void delay(){
	int contador;
	for(contador = 0; contador < 600000000; contador++){		
	}
	
}
	
//__________________________________________________________________________________________________________________	
// menu para exibicao

void menu(){
	printf("\n");
	printf("     _____________________________________________\n");
	printf("   ||Escolha uma das opcoes abaixo para continuar:||\n");
	printf("   ||(A) - Listar Voos                            ||\n");
	printf("   ||(B) - Cadastrar Voo                          ||\n");
	printf("   ||(C) - Consultar Voo                          ||\n");
	printf("   ||(D) - Efetuar Reserva                        ||\n");
	printf("   ||(F) - Sair                                   ||\n");
	printf("   ||_____________________________________________||\n");

 }

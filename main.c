#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "funcoes.h"


int main(){
	int contador = 0;
	char opcaoMenu, nomVoo;
	menu(); // chamando o menu
do{	
	printf("\n      Digite a opcao desejada: ");
	opcaoMenu = getch();
	fflush(stdin);
	
	do{
		if(opcaoMenu != 'a' && opcaoMenu != 'b' && opcaoMenu != 'c' && opcaoMenu != 'd' && opcaoMenu != 'f' ){
			printf("\nDigite um comando valido.\n ");
			opcaoMenu = getch();
			fflush(stdin);
			}
	switch (opcaoMenu){
		case 'A':
		case 'a':
			exibirDados(); 				// exibindo dados
			menu();
			break;
		case 'B':	
		case 'b':
			system("cls");		
			cadastrarVoo(); 			// cadastrando
			system("cls");
			printf("\n Cadastro realizado com sucesso!");
			delay();
			system ("cls");
			menu(); 					// menu
			break;
		case 'C':	
		case 'c':
			system("cls");
			exibirDadosVoo(); 			// exibindo dados de voos especificos
			system("cls");
			menu();		 				// menu
			break;
		case 'D':	
		case 'd': 						// efetuar reserva
			system("cls");
			cadastroDePassageiros();    // verificando o voo, cadastrando o passageiro e salvando arquivos no txt especifico 
			system("cls");
			menu();
			break;
		case 'F':	
		case 'f':
			printf("Finalizando."); 	// finalizando
			delay();
			printf("."); 	// finalizando
			delay();
			printf("."); 	// finalizando
			delay();
			return 0; 
		}
		
	}while (opcaoMenu != 'a' && opcaoMenu != 'b' && opcaoMenu != 'c' && opcaoMenu != 'd' && opcaoMenu != 'f' ); 		// verificando opcoes
	
}while(opcaoMenu != 'f'); 				// laco finalizando
}


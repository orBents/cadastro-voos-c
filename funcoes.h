#define COMP 30					//tamanho char string
#define CAD 30 					//cadastro
#define VOO 10					//numero de voos possiveis.
#define PAS 50					//numero de passageiros possiveis por voo.
#define TRUE 1                  // define auxiliar
#define FALSE 0                 // define auxiliar


typedef struct {
	
	//instrução de dados dos passageiros.
	
	char CPF[COMP];					//CPF.
	char nome[COMP]; 			//Nome. 
	char dataNascimento[COMP]; 		//Data de Nascimento.
	char numTel[COMP]; 			//Telefone.
	char eMail[COMP];			//E-mail.
	int numAssen;				//Número do Assento.
	
}InfoPass;


typedef struct {

    //instrução de dados de cada VOO.

    char numVoo[COMP];            //Número do voo (exs.: TAM8179, TAP2553).
    float precoPas;                //Preço da Passagem.
    char aeroOri[COMP];            //Aeroporto de Origem. 
    char aeroDestin[COMP];            //Aeroporto de Destino. 
    char horaPart[COMP];            //Horário Partida.
    char horaCheg[COMP];            //Horário Chegada. 
    int lugares;                //Quantidade de lugares (assentos).
    char **assentos;


}InfoVoo;
// prototipos utilizados
void cadastrarVoo();
void exibirDados();
void cadastroDePassageiros();
void exibirDadosVoo();
void alterar();
void delay();
void menu();

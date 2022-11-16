#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//---------------Externos---------------
struct Colaborador exColaborador[];
void Excessoes(char* msg);
void Mensagem(char* msg, short cor, short pritOpcao);
struct OptCabecalo;
void GerCabecalhos(struct OptCabecalo* opt);
void Clientes(int id);
//-----------------------------------------------

extern void Usuario(int id);

void UInicio();

void Usuario(int id){
	
	struct OptCabecalo opt;
	strcpy(opt.Titulo, "Bem vindo");
	strcpy(opt.Complemento, exColaborador[id - 1].nome);
	GerCabecalhos(&opt);
	
	UInicio(id);
	
}

void UInicio(int id){
	short opcao = 0;
	
	Mensagem("Selecione uma opcao \n\n 1 - Clientes \n 2 - Relatorios \n 3 - Sair", 0, 0);
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1: 
			Clientes(id);
			break;
		
		case 2: 
			//ir para a tela de edição	
			break;
			
		case 3: 
			system("cls"); 
			exit(0);
			break;
		
		default:
			Excessoes("Erro!");
			break;
	}
}




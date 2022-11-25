#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//---------------Externos---------------
struct ColaboradorLogado exColaboradorLogado;
void Excessoes(char* msg);
void Mensagem(char* msg, short cor, short pritOpcao);
struct OptCabecalo;
void GerCabecalhos(struct OptCabecalo* opt);
void Clientes();
//-----------------------------------------------

extern void Usuario();

void UInicio();

void Usuario(){
	
	struct OptCabecalo opt;
	strcpy(opt.Titulo, "Bem vindo");
	strcpy(opt.Complemento, exColaboradorLogado.InfoColabLogado.nome);
	GerCabecalhos(&opt);
	
	UInicio();
	
}

void UInicio(){
	char opcao;
	
	Mensagem("Selecione uma opcao \n\n 1 - Clientes \n 2 - Relatorios \n 3 - Sair", 0, 0);
	opcao = getch();
	
	switch(opcao){
		case '1': 
			Clientes();
			break;
		
		case '2': 
			Excessoes("Tela ainda noo existe!");
			break;
			
		case '3': 
			system("cls"); 
			exit(0);
			break;
		
		default:
			Excessoes("Opcao invalida!");
			break;
	}
}




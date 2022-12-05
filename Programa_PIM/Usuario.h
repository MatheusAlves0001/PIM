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
void GeraRelatorioClientesCadastrados();
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
	
	Mensagem("Selecione uma opcao: ", 0, 0);
	Mensagem("\n\n 1 - Clientes \n 2 - Relatorios \n\n ", 2, 0);
	Mensagem(" 3 - Sair", 1, 0);
	opcao = getch();
	
	switch(opcao){
		case '1': 
			Clientes();
			break;
		
		case '2': 
			GeraRelatorioClientesCadastrados();
			Usuario();
			break;
			
		case '3': 
			system("cls"); 
			exit(0);
			break;
		
		default:
			Excessoes("Opcao invalida!");
			Usuario();
			break;
	}
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Cadastro.h"

//---------------Externos---------------
struct Pessoa;
struct Pessoa pessoas[];
//-----------------------------------------------

extern void Usuario(int id);
void GerCabecalho(int id);
void UInicio();

void Usuario(int id){
	
	GerCabecalho(id);
	UInicio();
	
}

void UInicio(){
	short opcao = 0;
	
	Mensagem("Digite \n\n 1 - Novo documento \n 2 - Editar documento \n 3 - Sair", 0, 0);
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1: 
			//ir para a tela de cadastro	
			break;
		
		case 2: 
			//ir para a tela de edição	
			break;
			
		case 3: 
			system("cls"); 
			exit(0);
			break;
		
		default:
			Mensagem("Erro!", 0, 2);
			break;
	}
}

void GerCabecalho(int id){
	char msg[100];
	sprintf(msg, "\t\t\t\t\t\tSeja bem vindo %s!!\n\n", pessoas[id - 1].nome);
	Mensagem(msg, 4, 1);
}



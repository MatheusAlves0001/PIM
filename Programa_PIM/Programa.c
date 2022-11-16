#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdbool.h>

#include "Exceptions.h"
#include "Mensagens.h"
#include "Repositorio.h"
#include "Util.h"
#include "Cadastro.h"
#include "Login.h"
#include "Usuario.h"
#include "CadCliente.h"

//---------------Externos---------------
struct Colaborador exColaborador[];
void VerificaAcesso(char* email, char* password);
void CriarPessoa(char* nome, char* email, char* password);
void Mensagem(char* msg, short cor, short pritOpcao);
char* MascararSenha();
//-----------------------------------------------


void Inicio();
void Entrar();
void Cadastro();

int main(){
	setlocale(LC_ALL,"Portuguese");
	Inicio();
	return 0;
}


void Inicio(){
	
	do{
		short opcao = 0;
		Mensagem("\t\t\t\t\t\tSeja bem vindo ao Max Cad\n\n\n\n", 4, 1);
		Mensagem("Selecione uma opcao: \n 1 - Entrar \n 2 - Cadastro \n 3 - Sair \n", 0, 0);
		scanf("%hd", &opcao);
		
		switch(opcao)		
		{
			case 1: Entrar(); break;
			case 2: Cadastro(); break;
			case 3: system("cls"); exit(0); break;
			default: printf("Opção inválida!"); break;
		}
	}while(1);
}


void Entrar(){
	char email[100], password[100];
	
	Mensagem("\t\t\t\t\t\t\tENTRAR\n\n\n\n", 4, 1);
	Mensagem("Email: \n", 0, 0);
	scanf("%s", &email);
	Mensagem("Password: \n", 0, 0);
	
	strcpy(password, MascararSenha());
	
	VerificaAcesso(email, password);
}

void Cadastro(){
	char email[100], password[100], nome[100];
	
	Mensagem("\t\t\t\t\t\t\tCADASTRO\n\n\n\n", 4, 1);
	
	Mensagem("Digite seu nome: \n", 0, 0);
	scanf(" %[^\n]", &nome);
	fflush(stdin);

	Mensagem("Digite seu email: \n", 0, 0);
	scanf("%s", &email);
	fflush(stdin);
	
	Mensagem("Digite seu password: \n", 0, 0);
	scanf("%s", &password);
	fflush(stdin);
	CriarPessoa(nome, email, password);
}
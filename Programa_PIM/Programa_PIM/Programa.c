#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Cadastro.h"
#include "Login.h"

//---------------Métodos externos---------------
struct Pessoa;
struct Pessoa pessoas[];

void VerificaAcesso(char email[], char password[]);
void CriarPessoa(char email[], char password[]);

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
		printf("Selecione uma opção: \n 1 - Entrar \n 2 - Cadastro \n 3 - Sair \n");
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
	
	printf("Email: \n");
	scanf("%s", &email);
	printf("Password: \n");
	scanf("%s", &password);
	
	VerificaAcesso(email, password);
}

void Cadastro(){
	char email[100], password[100];
	
	printf("Digite seu email: \n");
	scanf("%s", &email);
	printf("Digite seu password: \n");
	scanf("%s", &password);
	CriarPessoa(email, password);
}
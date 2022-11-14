#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#define CAD_MAX 1

#ifndef EXTERNS
#define EXTERNS 1

//---------------Externos---------------
void Excessoes(char* msg);
void Mensagem(char msg[], short cor, short pritOpcao);
//-----------------------------------------------

extern struct Pessoa {
	
	int id;
	char nome[100];
	char email[100];
	char password[100];
	
} Pessoa;

extern struct Pessoa pessoas[CAD_MAX];

int GerId();
extern void CriarPessoa(char nome[], char email[], char password[]);

void CriarPessoa(char nome[], char email[], char password[]){
	int novoId = GerId();
	
	if(novoId != -1){
		
		pessoas[novoId - 1].id = novoId;
		strcpy(pessoas[novoId - 1].nome, nome);
		strcpy(pessoas[novoId - 1].email, email);
		strcpy(pessoas[novoId - 1].password, password);
		
		char msg[100];
		sprintf(msg, "Nome: %s, email: %s, password: %s, ID: %d", pessoas[novoId - 1].nome , pessoas[novoId - 1].email, pessoas[novoId - 1].password, novoId);
		Mensagem(msg, 3, 2);
		
	}
	else{
		Excessoes("Numero de cadastros foi excedido!");
	}
}

int GerId(){
	short qtd = 0;
	
	for(int i = 0; i < CAD_MAX; i++){
		if(pessoas[i].id != 0){
			qtd++;
		}
	}
	
	if(qtd >= CAD_MAX)
		return -1;
	
	return (qtd + 1);
}

#endif

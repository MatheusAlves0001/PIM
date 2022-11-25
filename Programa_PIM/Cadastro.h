#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>


//---------------Externos---------------
struct Colaborador exColaborador[];
void Excessoes(char* ex);
void Mensagem(char* msg, short cor, short pritOpcao);
//-----------------------------------------------

int GerId();
extern void CriarPessoa(char* nome, char* email, char* password);

void CriarPessoa(char* nome, char* email, char* password){
	int novoId = GerId();
	
	if(novoId != -1){
		
		exColaborador[novoId - 1].id = novoId;
		strcpy(exColaborador[novoId - 1].nome, nome);
		strcpy(exColaborador[novoId - 1].email, email);
		strcpy(exColaborador[novoId - 1].password, password);
		
		char msg[100];
		sprintf(msg, "Nome: %s, email: %s, password: %s, ID: %d", exColaborador[novoId - 1].nome , exColaborador[novoId - 1].email, exColaborador[novoId - 1].password, novoId);
		Mensagem(msg, 3, 2);
		
	}
	else{
		Excessoes("Numero de cadastros foi excedido!");
	}
}

int GerId(){
	short qtd = 0;
	
	for(int i = 0; i < CAD_MAX; i++){
		if(exColaborador[i].id != 0){
			qtd++;
		}
	}
	
	if(qtd >= CAD_MAX)
		return -1;
	
	return (qtd + 1);
}


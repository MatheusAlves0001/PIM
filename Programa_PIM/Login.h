#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//---------------Métodos externos---------------
struct Colaborador exColaborador[];
void Excessoes(char* msg);
void Usuario(int id);
//-----------------------------------------------

extern void VerificaAcesso(char *email, char *password);

void VerificaAcesso(char *email, char *password){
	
	for(int i = 0; i < CAD_MAX; i++){
		
		if(strcmp(exColaborador[i].email, email) == 0 && strcmp(exColaborador[i].password, password) == 0){
			Usuario(exColaborador[i].id);
		}
		else
		{
			Excessoes("Login ou senha nao encontrados!");
		}
	}
}
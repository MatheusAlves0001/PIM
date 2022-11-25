#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//---------------Métodos externos---------------
struct Colaborador exColaborador[];
struct ColaboradorLogado exColaboradorLogado;
void Excessoes(char* msg);
void Usuario();
//-----------------------------------------------

extern void VerificaAcesso(char *email, char *password);

void VerificaAcesso(char *email, char *password){
	short usuarioExiste = 0;
	for(int i = 0; i < CAD_MAX; i++){
		
		if(strcmp(exColaborador[i].email, email) == 0 && strcmp(exColaborador[i].password, password) == 0){
			
			exColaboradorLogado.InfoColabLogado.id = exColaborador[i].id;
			strcpy(exColaboradorLogado.InfoColabLogado.nome, exColaborador[i].nome);
			strcpy(exColaboradorLogado.InfoColabLogado.email, exColaborador[i].email);
			strcpy(exColaboradorLogado.InfoColabLogado.password, exColaborador[i].password);
			
			Usuario();
			usuarioExiste = 1;
		}
	}
	
	if(usuarioExiste == 0)
		Excessoes("Login ou senha nao encontrados!");
}
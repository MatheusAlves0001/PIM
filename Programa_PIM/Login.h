#include "Cadastro.h"
#include "Usuario.h"

struct Pessoa pessoas[];

extern void VerificaAcesso(char email[], char password[]);

void VerificaAcesso(char email[], char password[]){
	
	for(int i = 0; i < CAD_MAX; i++){
		
		if(strcmp(pessoas[i].email, email) == 0 && strcmp(pessoas[i].password, password) == 0){
			//Aqui será chamada a tela do usuário.
		}
	}
}
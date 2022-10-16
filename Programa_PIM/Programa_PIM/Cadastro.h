#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define RED \033[1;31m
#define YELLOW \033[1;33m
#define GREEN \033[0;32m
#define RESET_COLOR \033[0m

#define CAD_MAX 5

#ifndef EXTERNS
#define EXTERNS 1

extern struct Pessoa {
	
	int id;
	char email[100];
	char password[100];
	
} Pessoa;

extern struct Pessoa pessoas[CAD_MAX];

int GerId();
extern void CriarPessoa(char email[], char password[]);



void CriarPessoa(char email[], char password[]){
	int novoId = GerId();
	
	if(novoId <= CAD_MAX){
		
		pessoas[novoId].id = novoId;
		strcpy(pessoas[novoId].email, email);
		strcpy(pessoas[novoId].password, password);
		
		system("cls");
		
		printf("\033[0;32m");
		printf("email: %s, password: %s, ID: %d \n", pessoas[novoId].email, pessoas[novoId].password, novoId);
		printf("\033[0m");
		getch();
		
		system("cls");
	}
	else{
		system("cls");
		
		printf("\033[1;31m");
		printf("O número de registros foi excedido!\n");
		printf("Pressione uma tecla para continuar.");
		printf("\033[0m");
		getch();
		
		system("cls");
		
	}
}

int GerId(){
	short qtd = 0;
	
	for(int i = 0; i < CAD_MAX; i++){
		if(pessoas[i].id != 0){
			qtd++;                      
		}
	}
	return (qtd + 1);
}

#endif

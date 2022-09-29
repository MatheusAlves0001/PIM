#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <C:\Users\Usuario\Desktop\Projetos\C\Programa_PIM\pessoa.h>

void CriarPessoa(char email[], char password[]);
void Inicio();
void Adicionar();

int main(){
	setlocale(LC_ALL,"Portuguese");
	Inicio();
	return 0;
}


void Inicio(){
	//Este será o controlador de todos os processos do programa.
}

void Adicionar(){
	char email[100], password[100];
	
	printf("Digite seu email: \n");
	scanf("%s", &email);
	printf("Digite seu password: \n");
	scanf("%s", &password);
	CriarPessoa(email, password);
}
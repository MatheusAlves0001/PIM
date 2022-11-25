#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//---------------Externos---------------
struct Tabela;
struct OptCabecalo;
//-----------------------------------------------

extern void Mensagem(char* msg, short cor, short pritOpcao);
extern void GerTabelas(struct Tabela *);

char* DefineCor(short cor);

void Mensagem(char msg[], short cor, short pritOpcao){
		
		switch(pritOpcao){
			case 0:
				{
					printf(DefineCor(cor));
					printf("%s\n", msg);
				}break;
					
				case 1:{
					system("cls");
					printf(DefineCor(cor));
					printf("%s\n", msg);
				}break;
					
				case 2: {
					
					system("cls");
					printf(DefineCor(cor));
					printf("\n\n\n\n\n\n\n\n\n\n");
					printf("\t\t\t\t\t%s\n", msg);
					printf("\t\t\t\t\tPressione uma tecla para continuar!");
					printf("\033[0m");
					getch();
					system("cls");
				}break;
				
				default:{
					printf("%s", msg);
				}
		}
}


char* DefineCor(short cor){
	char *escolha = (char*)malloc(sizeof *escolha * 10),
		 branco[] = "\033[0m",
	 	 vermelho[] = "\033[1;31m",
		 amarelho[] = "\033[1;33m",
		 verde[] = "\033[0;32m",
		 azul[] = "\033[1;34m";
	 
	 
	switch(cor){
		case 0:  strcpy(escolha,branco); break; //Branco
		case 1:  strcpy(escolha,vermelho); break;//Vermelho
		case 2:  strcpy(escolha,amarelho); break;//Amarelo
		case 3:  strcpy(escolha,verde); break;//Verde
		case 4:  strcpy(escolha,verde); break;//Azul
		default:  strcpy(escolha,branco); //Branco (padrão)
	}
	
	return escolha;
}

void GerTabelas(struct Tabela* tab){
	int contador = 0;
	do{
		
		if(strlen(tab->Cabecalho[contador].Valor) != 0){
			
			printf("%s\t\t\t", tab->Cabecalho[contador].Valor);
			contador++;			
		}
		else
			contador = 0;
			
	}while(contador > 0);
	
	printf("\n");
	
	short idLinhaAtual = 0;
	do{
		
		if(strlen(tab->Linhas[contador].Valor) != 0){
			
			if(tab->Linhas[contador].LinhaId == idLinhaAtual){
				
				printf("%s\t\t\t", tab->Linhas[contador].Valor);
				contador++;	
				
			}
			else{
				
				printf("\n");
				printf("%s\t\t\t", tab->Linhas[contador].Valor);
				
			}
					
			idLinhaAtual = tab->Linhas[contador].LinhaId;
		}
		else
			contador = 0;
			
	}while(contador > 0);
	
	getch();
}
		


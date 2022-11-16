#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

extern void Mensagem(char* msg, short cor, short pritOpcao);
char* DefineCor(short cor);


void Mensagem(char msg[], short cor, short pritOpcao){
		
		switch(pritOpcao){
			case 0:
				{
					printf(DefineCor(cor));
					printf("%s\n", msg);
				}
					break;
				case 1:{
					system("cls");
					printf(DefineCor(cor));
					printf("%s\n", msg);
				}
					break;
				case 2: {
					
					system("cls");
					printf(DefineCor(cor));
					printf("\n\n\n\n\n\n\n\n\n\n");
					printf("\t\t\t\t\t%s\n", msg);
					printf("\t\t\t\t\tPressione uma tecla para continuar!");
					printf("\033[0m");
					getch();
					system("cls");
				}
					break;
			
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
		


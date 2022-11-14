#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdbool.h>

extern void Mensagem(char msg[], short cor, short pritOpcao);

char* DefineCor(short cor);

void Mensagem(char msg[], short cor, short pritOpcao){
		
		switch(pritOpcao){
			case 0:
				{
					printf(DefineCor(cor));
					printf("%s", msg);
				}
					break;
				case 1:{
					system("cls");
					printf(DefineCor(cor));
					printf("%s", msg);
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
	
	switch(cor){
		case 0: return "\033[0m"; break; //Branco
		case 1: return "\033[1;31m"; break; //Vermelho
		case 2: return "\033[1;33m"; break; //Amarelo
		case 3: return "\033[0;32m"; break; //Verde
		case 4: return "\033[1;34m"; break; //Azul
		default: return "\033[0m"; //Branco (padrão)
	}
}


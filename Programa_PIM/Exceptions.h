#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void Excessoes(char* msg);
void Excessoes(char* msg){
	
		system("cls");
		printf("\033[1;31m");
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t%s\n", msg);
		printf("\t\t\t\t\tPressione uma tecla para continuar.");
		printf("\033[0m");
		getch();
		system("cls");
		
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

extern char* MascararSenha();
char* MascararSenha(){
	
	int tamanho = 0;
	char password[100], 
		*retorno = (char*)malloc(sizeof *retorno * 100);
	
	do{
		password[tamanho] = getch();
		
		if(password[tamanho] == 0x08 && tamanho > 0){
			
			printf("\b \b");
			password[tamanho] = 0x00;
			tamanho--;
		}
		else if(password[tamanho] == 13){
			
			password[tamanho] = 0x00;
			break;
		}
		else if(password[tamanho] != 0x08){
			
			putchar('*');
			tamanho++;
			
		}
	}while(tamanho < 100);
	
	strcpy(retorno, password);
	
	return retorno;
}
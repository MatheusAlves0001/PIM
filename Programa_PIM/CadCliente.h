#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

//---------------Externos---------------
struct Colaborador exColaborador[];
struct Formulario exFormulario;
struct Titulo exTitulo;
struct Pergunta exPergunta;
struct OptCabecalo;
void Usuario(int id);
void GerCabecalhos(struct OptCabecalo* opt);
//--------------------------------------

extern void Clientes(int id);
void Cadastrar();
void EditarCadastro();

void Clientes(int id){
	
	
	
	short escolha = 0;
	do{
		struct OptCabecalo opt;
		strcpy(opt.Titulo, "Clientes");
		GerCabecalhos(&opt);
		
		char msg[] = "Selecione uma opcao \n\n 1 - Novo cadastro \n 2 - Editar cadastro \n 3 - Voltar";
		Mensagem(msg, 0, 0);
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:Cadastrar(); break;
			case 2: EditarCadastro(); break;
			case 3: Usuario(id); break;
			default: Usuario(id);				
		}
		
	}while(escolha != 0);
	
}

void Cadastrar(){
	
	strcpy(exFormulario.Titulos[0].titulo, "Informacoes sobre o cliente");
	strcpy(exFormulario.Titulos[0].Questao[0].pergunta, "Nome");
	strcpy(exFormulario.Titulos[0].Questao[1].pergunta, "idade");
	strcpy(exFormulario.Titulos[0].Questao[2].pergunta, "Sexo");
	 
	strcpy(exFormulario.Titulos[1].titulo, "Informacoes sobre o endereco do cliente");
	strcpy(exFormulario.Titulos[1].Questao[0].pergunta, "Endereco");
	strcpy(exFormulario.Titulos[1].Questao[1].pergunta, "Estado");
	strcpy(exFormulario.Titulos[1].Questao[2].pergunta, "Cidade");
	
	strcpy(exFormulario.Titulos[2].titulo, "Informacoes sobre a ocupacao do cliente");
	strcpy(exFormulario.Titulos[2].Questao[0].pergunta, "Empresa onde trabalha");
	strcpy(exFormulario.Titulos[2].Questao[1].pergunta, "Cargo");
	
	short contador = 0, qtdTitulos = 0;
	do{
		
		if(strlen(exFormulario.Titulos[contador].titulo) != 0){
			contador++;
			qtdTitulos++;
			continue;
		}

		contador = 0;
		
	}while(contador > 0);
	
	for(short titulo = 0; titulo < qtdTitulos; titulo++){
		
		short qtdQuestoes = 0;
			  
		Mensagem(exFormulario.Titulos[titulo].titulo, 0, 0);
		
			do{
				
				if(strlen(exFormulario.Titulos[titulo].Questao[contador].pergunta) != 0){
					contador++;
					qtdQuestoes++;
					continue;
				}
				
				contador = 0;
			}while(contador > 0);
		
		
		for(short questao = 0; questao < qtdQuestoes; questao++){
			
			Mensagem(exFormulario.Titulos[titulo].Questao[questao].pergunta, 0, 0);
			scanf(" %[^\n]", exFormulario.Titulos[titulo].Questao[questao].resposta);
			fflush(stdin);
		}
	}
	
	char msg[100];
		sprintf(msg, "Cliente %s cadastrado com sucesso!", exFormulario.Titulos[0].Questao[0].resposta);
		Mensagem(msg, 3, 2);
}


void EditarCadastro(){
	
}










#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

//---------------Externos---------------
struct ColaboradorLogado exColaboradorLogado;
struct Formulario exFormulario;
struct Titulo exTitulo;
struct Pergunta exPergunta;
struct OptCabecalo;
void Usuario();
void GerCabecalhos(struct OptCabecalo* opt);
struct Cliente clientes[CAD_MAX_CLI];
void Excessoes(char* ex);
struct Tabela;
void GerTabelas(struct Tabela *);
//--------------------------------------

extern void Clientes();

void Cadastrar();
void ExibirClientesCadastrados();
int GerCliId();
void GerCliente();

void Clientes(){
	
	char escolha;
	do{
		struct OptCabecalo opt;
		strcpy(opt.Titulo, "Clientes");
		GerCabecalhos(&opt);
		
		Mensagem("Selecione uma opcao \n\n 1 - Novo cadastro \n 2 - Clientes cadastrados \n 3 - Voltar", 0, 0);
		escolha = getch();
		
		switch(escolha){
			case '1':Cadastrar(); break;
			case '2': ExibirClientesCadastrados(); break;
			case '3': Usuario(); break;
			default: Excessoes("Opcao invalida!"); 				
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
	strcpy(exFormulario.Titulos[1].Questao[3].pergunta, "CEP");
	
	strcpy(exFormulario.Titulos[2].titulo, "Informacoes sobre a ocupacao do cliente");
	strcpy(exFormulario.Titulos[2].Questao[0].pergunta, "Empresa onde trabalha");
	strcpy(exFormulario.Titulos[2].Questao[1].pergunta, "Cargo");
	strcpy(exFormulario.Titulos[2].Questao[2].pergunta, "Salario");
	
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
	
	GerCliente();
}

void GerCliente(){
	
	int idCli = GerCliId();
	
	if(idCli != -1){
	
		clientes[idCli - 1].Id = idCli;
		clientes[idCli - 1].IdcolabResp = exColaboradorLogado.InfoColabLogado.id;
		
		strcpy(clientes[idCli - 1].Nome, exFormulario.Titulos[0].Questao[0].resposta);
		clientes[idCli - 1].idade = atoll(exFormulario.Titulos[0].Questao[1].resposta);
		strcpy(clientes[idCli - 1].Sexo, exFormulario.Titulos[0].Questao[2].resposta);
		
		strcpy(clientes[idCli - 1].Endereco.Endereco, exFormulario.Titulos[1].Questao[0].resposta);
		strcpy(clientes[idCli - 1].Endereco.Estado, exFormulario.Titulos[1].Questao[1].resposta);
		strcpy(clientes[idCli - 1].Endereco.Cidade, exFormulario.Titulos[1].Questao[2].resposta);
		strcpy(clientes[idCli - 1].Endereco.CEP, exFormulario.Titulos[1].Questao[3].resposta);
		
		strcpy(clientes[idCli - 1].Profissao.EmpresaOndeTrabalha, exFormulario.Titulos[2].Questao[0].resposta);
		strcpy(clientes[idCli - 1].Profissao.Cargo, exFormulario.Titulos[2].Questao[1].resposta);
		clientes[idCli - 1].Profissao.Salario = atof(exFormulario.Titulos[2].Questao[2].resposta);
		
		char msg[100];
		sprintf(msg, "Cliente %s cadastrado com sucesso!", clientes[idCli - 1].Nome);
		Mensagem(msg, 3, 2);
		
	}
	else{
		Excessoes("Numero de clientes cadastrados foi excedido!");
	}
}

void ExibirClientesCadastrados(){
	
	int contCli = 0;
	system("cls");
	do{
		printf("\n\n");
		if(clientes[contCli].Id != 0){
			printf("Nome: %s \n", clientes[contCli].Nome);
			printf("Sexo: %s \n", clientes[contCli].Sexo);
			printf("Idade: %d \n", clientes[contCli].idade);
			printf("Cargo: %s \n", clientes[contCli].Profissao.Cargo);
			printf("__________________________________________");
			contCli++;
		}
		else{
			contCli = 0;
		}
		
		
	}while(contCli > 0);
	
	Mensagem("[ESC] para voltar",0 ,0);
	
	char teclaPressionada;
	teclaPressionada = getch();
	
	if(teclaPressionada != 27)
		ExibirClientesCadastrados();
}

int GerCliId(){
	short qtd = 0;
	
	for(int i = 0; i < CAD_MAX_CLI; i++){
		if(clientes[i].Id != 0){
			qtd++;
		}
	}
	
	if(qtd >= CAD_MAX_CLI)
		return -1;
	
	return (qtd + 1);
}








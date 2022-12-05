#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//---------------Externos---------------
struct Cliente clientes[CAD_MAX_CLI];
struct ColaboradorLogado exColaboradorLogado;
//-----------------------------------------------

extern void GeraRelatorioClientesCadastrados();

int contRelatorio = 0;
bool VerificadorExistemClientesCadastrados();

void GeraRelatorioClientesCadastrados(){
	
	bool verificaCli = VerificadorExistemClientesCadastrados();
	
	if(verificaCli){
		
	FILE *arq;
	
	contRelatorio++;
	
	char nomeRelatorio[60];
	sprintf(nomeRelatorio, "./Relatorios/Relatorio_%d.txt", contRelatorio);
	
	arq = fopen(nomeRelatorio, "a");
	time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char data[64];
   	size_t ret = strftime(data, sizeof(data), "%c", tm);
    assert(ret);
	
	fprintf(arq, "Relatório gerado no dia e hora %s por %s\n\n\n\n\n", data, exColaboradorLogado.InfoColabLogado.nome);
	
	for(int i = 0; i < CAD_MAX_CLI; i++){
		if(clientes[i].Id != 0){
			fprintf(arq, "Nome: %s\n", clientes[i].Nome );
			fprintf(arq, "Sexo: %s\n", clientes[i].Sexo );
			fprintf(arq, "Idade: %b\n", clientes[i].idade );
			fprintf(arq, "Cargo: %s\n", clientes[i].Profissao.Cargo );
			fprintf(arq, "%s\n", "----------------------------------");
		}
	}
	
	fclose(arq);
	Mensagem("Relatorio criado com sucesso!", 3, 2);
		
	}
	else{
		Excessoes("Nao existem clientes para exibir");
	}
}

bool VerificadorExistemClientesCadastrados(){
	short qtd = 0;
	
	for(int i = 0; i < CAD_MAX_CLI; i++){
		if(clientes[i].Id != 0){
			qtd++;
		}
	}
	
	if(qtd <= 0)
		return 0;
		
	return 1;
}


#include <stdbool.h>

#define CAD_MAX 1
#define CAD_MAX_CLI 1

//------------Colaborador------------
typedef struct Colaborador {
	
	int id;
	char nome[100];
	char email[100];
	char password[100];
	
} Colaborador;


//------------Cliente------------
typedef struct ClienteEndereco{
	
	char CEP[100],
		 Endereco[100],
		 Estado[100],
		 Cidade[100];
		 
} ClienteEndereco;

  typedef struct ClienteProfissao{
	
	char EmpresaOndeTrabalha[100],
		 Cargo[100];
	
	float Salario;
		 
} ClienteProfissao;

 typedef struct Cliente{
	
	char Nome[100];
	short idade;
	bool Sexo;
	
	ClienteEndereco Endereco;
	ClienteProfissao Profissao;
	
} Cliente;


//------------Formulario------------
 typedef struct Pergunta{
	char pergunta[50],
	 	 resposta[50];
}Pergunta;

 typedef struct Titulo{
	
		char titulo[50];
		struct Pergunta Questao[50];
		
}Titulo;	

typedef struct Formulario{
		struct Titulo Titulos[50];
} Formulario;

//------------Cabecalho------------
extern struct OptCabecalo{
	char Titulo[50],
		 Complemento[50];
}OptCabecalo;


//------------Ex. Colaborador------------
extern struct Colaborador exColaborador[CAD_MAX];

//------------Ex. Cliente------------
extern struct Cliente clientes[CAD_MAX_CLI];
extern struct ClienteEndereco exClienteEndereco;
extern struct ClienteProfissao exClienteProfissao;

//------------Ex. Formulario------------
extern struct Formulario exFormulario;
extern struct Titulo exTitulo;
extern struct Pergunta exPergunta;


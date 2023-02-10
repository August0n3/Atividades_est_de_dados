#include<stdio.h>
#include<stdlib.h>

//
typedef struct funcionario{
	char nome[50];
	float salario;
	int identificador;
	char cargo[50];
}Funcionario;

//protitipando funções
void preencher(Funcionario *preenche, int qtd);
float altera (Funcionario * altera, int indice);
void maior_menor(Funcionario * mem, int qtd);

int main (){
    //definindo variaveis e colando a quantidade de funcionarios
	int quantidade, index;
	printf("Informe a quantidade de funcionarios: ");
	scanf ("%i", &quantidade);
    
    //alocando dinamicamente a empresa
	Funcionario * empresa = (Funcionario*) malloc (quantidade*sizeof(Funcionario) );
	if(empresa == NULL){
		exit (1);
	}
	
    //chamando as funções
	preencher(empresa, quantidade);
	altera(empresa, 0);
	maior_menor(empresa, quantidade);
	

	free(empresa);
	return 0;
}

//função de cadastro de funcionarios
void preencher(Funcionario *preenche, int qtd){
    int i;
	for(i = 0; i < qtd; i++){
	printf("Informe o nome do funcionario: ");
	scanf(" %[^\n]s", preenche[i].nome);
	printf("Informe o salario: ");
	scanf("%f", &preenche[i].salario);
	printf("Informe o identificador do funcionario: ");
	scanf("%d", &preenche[i].identificador);
	printf("Informe o cargo: ");
	scanf(" %[^\n]s", preenche[i].cargo);
	
	printf("Nome do funcionario e %s, seu salario e de %.1f, o identificador e %d, com cargo de %s \n", preenche[i].nome, preenche[i].salario, preenche[i].identificador, preenche[i].cargo); 
    //acho q precisava de uma função só pra o print, depois eu faço
}
}

//alterando um salario baseado em um indice passado na função (depois da pra mudar isso, ta só metendo mais 1k no primeiro funcionario)
float altera (Funcionario * altera, int indice){
	altera[indice].salario += 1000;
}

//função que imprime o maior e o menor salario dentre os funcionarios cadastrados
void maior_menor(Funcionario * mem, int qtd){
 float	menor = 0, maior = 0;
 int i, indice_maior = 0, indice_menor = 0;
	for( i = 0; i < qtd; i++){
		if(i == 0){
			menor = mem[i].salario; //definindo o primeiro salario como menor salario
		}
		if(mem[i].salario > maior){
			maior = mem[i].salario;
			indice_maior = i;
		} 
		if(mem[i].salario < menor){
			menor = mem[i].salario;
			indice_menor = i;
		} 
	}
	printf("O funcionario com maior salario e %s, com salario de %.1f \n", mem[indice_maior].nome, mem[indice_maior].salario);
	printf("O funcionario com menor salario e %s, com salario de %.1f", mem[indice_menor].nome, mem[indice_menor].salario);
}


//Feito por minha pessoa e https://github.com/EsromMS 
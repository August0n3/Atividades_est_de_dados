#include <stdio.h>
#include <stdlib.h>

//definindo o time de pessoa
typedef struct pessoa{
char nome[50];
int documento;
int idade;
}Pessoa;
 
//prototipando funções
void cadastra(Pessoa *vetor_de_pessoas,int qnt_pessoas);
void maior_menor(Pessoa* mem, int qtd);
void imprime (Pessoa *pessoa, int index);

int main (){
    int qnt_pessoas, index = 0;
    printf ("Informe a quantidade de alunos: ");
    //solicitando a quantidade de pessoas
    scanf("%d", &qnt_pessoas);

    //alocando dinamicamente o vetor de pessoas
    Pessoa * vetor_de_pessoas = (Pessoa*) malloc(qnt_pessoas*sizeof(Pessoa));
    
    if (vetor_de_pessoas==NULL){
        printf("ERRO!!!");
    }
    
    //chamada de funções
    cadastra(vetor_de_pessoas,qnt_pessoas);

    imprime(vetor_de_pessoas, 0);

    maior_menor(vetor_de_pessoas,qnt_pessoas);

    //liberando o espaço na memoria
    free(vetor_de_pessoas);

    return 0;   
}

//cadastro de pessoas
void cadastra(Pessoa *vetor_de_pessoas,int qnt_pessoas){
    int index;
    for(index=0; index < qnt_pessoas; index++){   
        printf("Digite o nome da pessoa: ");
        scanf(" %[^\n]s", vetor_de_pessoas[index].nome);
        printf("Digite o documento: ");
        scanf(" %d", &vetor_de_pessoas[index].documento);
        printf("Digite a idade: ");
        scanf("%d", &vetor_de_pessoas[index].idade);
    }
}

//calculando a maior e menor idade
void maior_menor(Pessoa* mem, int qtd){  
 int menor = 0, maior = 0;
 int i, indice_maior = 0, indice_menor = 0;
	
    for( i = 0; i < qtd; i++){
		if(i == 0){ 
			menor = mem[i].idade; //definindo a menor idade como a idade inicial
		}

		if(mem[i].idade > maior){
			maior = mem[i].idade;
			indice_maior = i;
		} 
		if(mem[i].idade < menor){
			menor = mem[i].idade;
			indice_menor = i;
		} 
	}
	printf("A Pessoa com maior idade e %s, com idade de %d\n", mem[indice_maior].nome, mem[indice_maior].idade);
	printf("A Pessoa com menor idade e %s, com idade de %d\n", mem[indice_menor].nome, mem[indice_menor].idade);
}

//imprimindo uma pessoa de determinado indice (depois mudar isso aq)
void imprime (Pessoa *pessoa, int index){
    printf("Nome: %s\nDocumento: %d\nIdade: %d\n",pessoa[index].nome,pessoa[index].documento,pessoa[index].idade);
}
// feito por minha pessoa e https://github.com/jp5773
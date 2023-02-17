#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo o tipo de tipo
typedef union tipo{
char alimento[20];
char bebida[15];
char eletronico[25];
}Tipo;

//criando estrutura pra o produto
typedef struct produto{
char nome[50];
float preco;
Tipo tipo; //tipo do produto
}Produto;

int main(void){
Produto produto;//criando a variavel produto
char tipo[25];//variavel auxiliar

//bloco de coleta de dados
printf("Digite o nome do produto: ");
scanf(" %[^\n]s", &produto.nome);
printf("Digite o preço do produto: ");
scanf("%f", &produto.preco);
printf("Digite o tipo do produto\nalimento\nbebida\neletronico\n");
scanf(" %[^\n]s", &produto.tipo.alimento);

//printando o produto cadastrado
printf("Nome: %s\nPreco: %.2fR$\nTipo: %s ", produto.nome, produto.preco, produto.tipo.alimento);


return 0;
}
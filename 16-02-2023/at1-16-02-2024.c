#include <stdio.h>
#include <stdlib.h>

typedef enum sexo{
masculino,
feminino
}Sexo;

typedef struct pessoa{
char nome[50];
int idade;
Sexo sexo;
}Pessoa;

int main(void){
Pessoa pessoa;
int sexo;
int i;

printf("Digite seu nome: ");
scanf(" %[^\n]", &pessoa.nome);
printf("Digite sua idade: ");
scanf(" %d", &pessoa.idade);
for(i =0; i<1;i++){
printf("Digite seu sexo masculino/feminino ");

scanf(" %d", (int*)&sexo);

switch(sexo){
case feminino:
pessoa.sexo = sexo;
break;
case masculino:
pessoa.sexo = sexo;
break;
default:
printf("Opcao invalida\n");
i--;
break;
}
}

/*printf("Digite seu sexo masculino/feminino ");

scanf(" %d", (int*)&pessoa.sexo);*/

printf("Nome: %s\nIdade: %d\nSexo: ", pessoa.nome, pessoa.idade);

pessoa.sexo == masculino?printf("Masculino"):printf("Feminino");

return 0;
}

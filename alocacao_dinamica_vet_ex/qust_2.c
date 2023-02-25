#include <stdio.h>
#include <stdlib.h>

int main(){
//variaveis de aux
int i;
int j;
int qst = 0;
float qtd_questoes;//definidno como float pra n dar erro na divisão
float nota = 0;
int cont = 0;
//coletando a qtd_quest
printf("Digite a quantidade de questões da prova: ");
scanf("%f", &qtd_questoes);


//alocação dinamica
float *provas = (float*) malloc(10*sizeof(float));
int *gabarito = (int*) malloc(qtd_questoes*sizeof(int));
//int *respostas = (int*) malloc(qtd_questoes*sizeof(int));

if(provas == NULL){
        printf("Erro na alocação\n");
        exit(1);
    } 

if(gabarito == NULL){
        printf("Erro na alocação\n");
        exit(1);
    } 
 

//coletando o gabarito
printf("Digite o gabarito entre 1 e 5 as respostas da prova\n");
for(i = 0; i<qtd_questoes; i++){
    printf("Resposta da %d questão: ", i+1);
    scanf("%d", &gabarito[i]);
}

//coletando as respostas das provas dos alunos e calculando suas pontuações
for ( i = 0; i < 10; i++){
    for (j = 0; j < qtd_questoes; j++){
        printf("Digite a %d questao do %d aluno: ",j+1,i+1);
        scanf("%d", &qst);
        if(qst == gabarito[j]){
            nota += 10/qtd_questoes;
        }
    }
    provas[i] = nota;
    nota = 0;
}
//imprimindo a nota dos alunos e calculando o percentual
for ( i = 0; i < 10; i++){
    printf("Aluno - %d nota - %.2f\n",i+1,provas[i]);
    if (provas[i]>=6){
        cont++;
    }
    }
printf("Percentual de aprovados foi de %d%%!", cont*10); //exibindo percentual


free(provas);//liberando memoria
free(gabarito);//liberando memoria
return 0;
}
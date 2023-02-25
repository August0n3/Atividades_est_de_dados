#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//tem alguns erros que não consegui arrumar :(, mas no geral funciona :D

#define MAX_TURMAS 8 //definindo o maximo de turmas
#define MAX_ALUNOS 10 //o maximo de alunos por turma

typedef struct aluno{ //criando a struct de alunos
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;

typedef struct turmas{ //criando a struct de turmas
    char id;
    int vagas;
    Aluno *alunos[MAX_ALUNOS];
}Turma;

Turma *turmas[MAX_TURMAS];//definindo vetor de turmas
//prototipando as funções
Turma* criar_turma(char id);
Turma* procura_turma(Turma** turmas, int n, char id);
void matricula_aluno(Turma* turma, int mat, char* nome);
void lanca_notas(Turma* turma);
void imprime_alunos(Turma* turma);
void imprime_turmas(Turma** turmas, int n);

int main(void){
    int cont = 0; //contador de turmar criadas
    int opcao = 0; //opção do usuario
    char nome[81]; // variavel para receber os nomes dos alunos
    int mat; //variavel pra receber a matricula dos alunos
    char id;// variavel pra receber o id das turmas
    Turma *turma = (Turma*) malloc(sizeof(Turma)); //variavel pra receber a turma retornada pela pesquisa
    
    while (opcao != 6){//menu interativo
        printf("MENU:\n1 – Criar turma\n2 – Listar turmas\n3 – Matricular aluno\n4 – Lancar notas\n5 – Listar alunos\n6 – Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {   
        case 1: //criar turmas
            if (cont<MAX_TURMAS){
                printf("Criando turma...\n");
                printf("Digite o id da turma: ");
                scanf(" %[^\n]", &id);
                turmas[cont] = criar_turma(id);
                printf("Turma criada com sucesso!\n");
                cont++;
                break;
            }else{
                printf("Numero maximo de turmas atingido\n");
                break;
            }
            
            
        case 2: //mostrar turmas
            printf("Mostrando turmas...\n");
            imprime_turmas(turmas,cont);
            break;
        case 3://matricular alunos
            printf("digite o ID da turma: ");
            scanf(" %[^\n]", &id);
            printf("Matriculando Aluno...\n");
            printf("Digite o nome do Aluno: ");
            scanf(" %[^\n]s", &nome);
            printf("Digite a matricula do Aluno: ");
            scanf("%d",&mat);
            turma = procura_turma(turmas,cont,id);
            matricula_aluno(turma,mat,&nome);
            break;
        case 4://lancando notas
            printf("digite o ID da turma: ");
            scanf(" %[^\n]", &id);
            turma = procura_turma(turmas,cont,id);
            lanca_notas(turma);
            break;
        case 5://exibir alunos
            printf("digite o ID da turma: ");
            scanf(" %[^\n]", &id);
            turma = procura_turma(turmas,cont,id);
            imprime_alunos(turma);
            break;
        case 6:
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    }
    

    //liberação de memoria
    free(turma);
    for (int i = 0; i < cont; i++){
        for (int j = 0; i < MAX_ALUNOS-turmas[i]->vagas; i++){
            free(turmas[i]->alunos[j]);
        }
    }
    for (int i = 0; i < cont; i++){
        free(turmas[i]);
    }
    
    return 0;
}

Turma* criar_turma (char id){//criando turma
    Turma *sala = (Turma*) malloc(sizeof(Turma));//definindo espaço de memoria
    sala->id = id;
    sala->vagas=MAX_ALUNOS;
    for ( int j = 0; j < MAX_ALUNOS; j++){
        sala->alunos[j] = NULL;//zerando a lista de alunos
    }
    return (sala);
}

Turma* procura_turma(Turma** turmas, int n, char id){ //busca de turma por id
    int i = 0;
    while ((turmas[i]->id!= id)&& (i < n) ){//enquanto não se econtrar continua procurando
        i++;
    }
    if (i<n){
        return(turmas[i]);
    }else{
        printf("Turma não encontrada");
        return NULL;//se não achar retorna null *tem erro*
    }
}

void imprime_turmas(Turma** turma, int n){
    int i;
    for ( i = 0; i < n; i++){//percorre todas as turmas e mostra tudo sobre ela
        printf("turma - %d\n ID - %c  Vagas disponiveis - %d\n",i+1, turma[i]->id,turma[i]->vagas);
        }
        
}
    
void matricula_aluno(Turma* turma, int mat, char* nome){//matricula alunos
    
    for ( int i = 0; i < MAX_ALUNOS; i++){//percorrendo as vagas
        if (turma->alunos[i]==NULL){
            turma->alunos[i] = (Aluno*)malloc(sizeof(Aluno));//alocando espaço para os alunos
            strcpy(turma->alunos[i]->nome,nome); //usando funcao pra definir o nome
            turma->alunos[i]->mat = mat;    
        }else{
            printf("Não há vagas");
    }
        
    }
    if (turma->vagas != 0){
        turma->vagas = turma->vagas-1;//se for cadastrado acaba uma vaga
    }      
}

void imprime_alunos(Turma* turma){
    for (int i = 0; i < (MAX_ALUNOS - turma->vagas); i++){//percorre uma turma imprimindo todos os alunos
        printf("Aluno - %d\n Nome - %s\n Matricula - %d\n Média - %.2f\n", i+1, turma->alunos[i]->nome, turma->alunos[i]->mat, turma->alunos[i]->media);        
    }
    
}

void lanca_notas(Turma* turma){
    for (int i = 0; i < (MAX_ALUNOS-turma->vagas); i++){//funcao q lanca notas de alunos de uma turma e calcula a media
        printf("Matricula: %d  Aluno: %s \n", turma->alunos[i]->mat, turma->alunos[i]->nome);
        printf("Digite a nota 1: ");
        scanf("%f", &turma->alunos[i]->notas[0]);
        printf("Digite a nota 2: ");
        scanf("%f", &turma->alunos[i]->notas[1]);
        printf("Digite a nota 3: ");
        scanf("%f", &turma->alunos[i]->notas[2]);//colentando as 3 notas
        turma->alunos[i]->media= (turma->alunos[i]->notas[0]+turma->alunos[i]->notas[1]+turma->alunos[i]->notas[2])/3;//calculando a media
    }
        
}   
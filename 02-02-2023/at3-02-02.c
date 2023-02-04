#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int qtd_frutas, linha;
    
    printf("Digite a quantidade de frutas: \n");
    scanf("%d", &qtd_frutas); 

    
    char ** frutas = (char**) malloc(qtd_frutas*sizeof(char*));
    
    if(frutas==NULL){ 
        printf("Erro");
        exit(1);
    } 
    
    for(linha=0; linha<qtd_frutas; linha++){
        frutas[linha] = (char*) malloc(50*sizeof(char));
    }   
    
    float * prec_frutas = (float*) malloc(qtd_frutas*sizeof(float));

    if(prec_frutas==NULL){
        printf("Error");
        exit(1);
    }
    
    for(linha=0; linha<qtd_frutas; linha++){
        printf("Digite a fruta: ");
        scanf(" %[^\n]s", frutas[linha]);
        printf("digite o preco da fruta: ");
        scanf("%f", &prec_frutas[linha]);
        realloc(frutas[linha], strlen(frutas[linha]));
    } 
    
    printf("Lista de frutas \n");
    printf("---------------------\n"); 
    for(linha=0; linha<qtd_frutas; linha++){
        printf("%s, preco: R$%.2f \n", frutas[linha], prec_frutas[linha]);
    }

    for(linha=0; linha< qtd_frutas ; linha++){
        free(frutas[linha]);
    }

    free(frutas);
    free(prec_frutas);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tamanho = 10;
    int i;
    int * V = (int* ) malloc(tamanho * sizeof(int));
    
    if(V == NULL){
        printf("Erro na alocação\n");
        exit(1);
    }


    for( i = 0; i<10 ;i++){
        V[i] = i;
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%i\n", V[i]);
    }
    
    free(V);

    return(0);

}
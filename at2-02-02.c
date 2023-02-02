#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tamanho = 3;
    int j, i, c=0;
    
    int ** Matriz = (int**) malloc(tamanho*sizeof(int*));
    
    for ( i = 0 ; i < tamanho; i++){
        
        Matriz[i] = (int*) malloc(tamanho*sizeof(int));

    }
    
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            Matriz[i][j] = i*3 + j;
        }
    }
    
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            printf("%d",Matriz[i][j]);  
            if(c==2){
                printf(" \n");
                c=-1;
            }
            c++;
        }
   }
        for(i=0;i<tamanho;i++){
            free(Matriz[i]);
        }
    
        free(Matriz);

}
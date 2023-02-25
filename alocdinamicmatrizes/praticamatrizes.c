#include <stdio.h>
#include <stdlib.h>
//não terminei ainda :(
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    if ((m>=1 && m<=1000)&&(n>=1 && n<=1000) ){

    char ** mapa = (char**) malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    mapa[i] = (char*) malloc(m*sizeof(char));

    for ( int i = 0; i < n; i++){
        for (int j = 0; i < m; i++){
            scanf(" %[^\n]", &mapa[i][j]);
        }
    }

    }



    else{
        printf("tamanho invalido!");
    }
}
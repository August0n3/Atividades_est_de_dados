#include <stdio.h>

void inv (int v[], int n);

int main(){
	int n; 
	
	printf("Declare o tamanho do vetor: \n");
	scanf("%i", &n);
	
	int v[n];
	
	for(int i = 0; i<n; i++){
		printf("Digite o %i elemento: \n",i + 1);
		scanf("%i", &v[i]);
	}
	
	inv(v,n);
	
	return 0;
}

void inv (int v[], int n){
	int aux[n];
	int c = n;
	for(int i = 0; i <n; i++){
		
		aux [i] = v[c-1];
		
		c--;
	}
	printf("Vetor: ");
	for (int i = 0; i<n; i++){
		printf("%i ", aux[i]);
	}
	
}

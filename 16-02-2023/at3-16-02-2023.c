#include <stdio.h>
#include <stdlib.h>
//enum dos meses do ano de 0 a 11
typedef enum  mes{
janeiro,
fevereiro,
marco,
abril,
maio,
junho,
julho,
agosto,
setembro,
outubro,
novembro,
dezembro
}Mes;
//estrutura de datas
typedef struct data{
int dia;
Mes mes;
int ano;
}Data;


int main(){
Data data;
//colentando a data
printf("Digite o dia: ");
scanf(" %d", &data.dia);
printf("Digite o mes: ");
scanf(" %d", (int*)&data.mes);
printf("Digite o ano: ");
scanf(" %d", &data.ano);
//exibindo a data
data.mes <= outubro?printf("%d/0%d/%d", data.dia,data.mes,data.ano):printf("&d/%d/%d", data.dia,data.mes,data.ano);


return (0);
}
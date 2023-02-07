#include <stdio.h>
#include <stdlib.h>

int main(void){
    //variaveis de auxilio
    int i,opiniao, num_mulheres=0,num_homens=0;
    float percentual1=0,percetual2=0;
    char sexo;
    //numero N de entrevistados
    int num_entrevistados = 5; //exemplo

    //declarando vetores dinamicamente    
    int * sex = (int*) malloc(num_entrevistados*sizeof(int)); //0 = Masculino /1 = Feminino
    int * opiniao_entrevistados = (int*) malloc(num_entrevistados*sizeof(int)); //0 = gostou / 1 = nao gostou

    //checando integridade dos vetores
    if(sex == NULL){
        printf("Erro na alocação\n");
        exit(1);
    } 
    
    if(opiniao_entrevistados == NULL){
        printf("Erro na alocação\n");
        exit(1);
    }

        
    for(i = 0; i<num_entrevistados; i++){
        //Solicitando o sexo dos entrevistados
        printf("Oi, entrevistado numero %i, poderia indicar seu sexo\n",i+1);
        printf("M = Masculino\nF = Feminino\n");
        scanf(" %[^\n]", &sexo);
        sexo = toupper(sexo);

        //checando se foi definida uma opcao valida
        if( (sexo!='M') && (sexo != 'F')){
            printf("Opcao invalida!\n");
            i--;
        }else{
             //caso fosse uma opção valida vamos perguntar a sua opiniao
            printf("Qual sua opiniao sobre o nosso produto\n Digite 0 se gostou \n Digite 1 se nao gostou\n");
            scanf("%d", &opiniao);
            
            if((opiniao!= 0) && (opiniao!=1)){
                printf("Opcao invalida!\n");
                i--;
            }else{
                //definindo nos arrays a opiniao e os sexos
 
                switch (sexo){
                case  'F':
                    sex[i]= 1;
                    break;
                case  'M':
                    sex[i]= 0;
                    break;
                default:
                    break;
                }

                opiniao_entrevistados[i] = opiniao;
                sexo = 0;
                opiniao =0;
            }
        }
    }
    
    for ( i = 0; i < num_entrevistados; i++){
        //Exibindo os resultados
        switch (sex[i]){
        case 0:
            printf("Masculino - ");
            break;

        case 1:
            printf("Feminino - ");
            break;
        default:
            break;
        }

        switch (opiniao_entrevistados[i]){
        case 0:
            printf("Gostou\n");
            break;

        case 1:
            printf("Nao gostou\n");
            break;
        default:
            break;
        }

    }

    
    for ( i = 0; i < num_entrevistados; i++){
        //calcular percentuais
        if (sex==0){
            num_mulheres++;
        }
        
        if (sex==1){
            num_mulheres++;
        }
        
        if ((opiniao_entrevistados[i]==0)&&(sex==1)){
            percentual1++;
        }
        if ((opiniao_entrevistados[i]==1)&&(sex==0)){
            percetual2++;
        }
    }
    


    percentual1 = (percentual1*num_mulheres)/100;
    percetual2 =  (percetual2*num_homens)/100;


    printf("%i %i", percentual1, percetual2);


    
    free(sex);
    free(opiniao_entrevistados);

    return 0;
}

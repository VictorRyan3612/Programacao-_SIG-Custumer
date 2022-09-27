#include <stdio.h>
#include "biblio.h"

void enter(void){
    char opcao;
    printf("Aperte enter para continuar\n");
    scanf("%c", &opcao);
    getchar();
}

char confirmacao(){
    char resp;
    printf("\n");
    printf("Confirme se está correto (s para sim)...\n");
    scanf("%c", &resp);
    getchar();
    printf("\n");
    return resp;
}

char opcoes_pergunta(void){
    char opcoes;
    scanf("%[1-3]", &opcoes);
    printf("\n\n");
    getchar();
    return opcoes;
}


void vizualizar_lista(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(a[i] == ';'){
            printf("\n");
        } else{
            printf("%c",a[i]);
        }
        i++;
    }
}


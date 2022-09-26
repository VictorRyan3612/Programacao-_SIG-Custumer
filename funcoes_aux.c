#include <stdio.h>
#include "biblio.h"

char confirmacao(char resp){

    printf("\n");
    printf("Confirme se está correto (s para sim)...\n");
    scanf("%c", &resp);
    getchar();
    printf("\n");
    return resp;
}


char opcoes_pergunta(void){
    char opcoes;
    scanf("%c", &opcoes);
    printf("\n\n");
    getchar();
    return opcoes;
}

void opcoes_interesse(void){
    printf("Qual deseja Cadastrar?\n"
    "Jogo:\t 1\n"
    "Livro:\t 2\n"
    "Filme:\t 3\n"
    );
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
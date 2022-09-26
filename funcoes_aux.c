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
    scanf("%[1-3]", &opcoes);
    printf("\n\n");
    getchar();
    return opcoes;
}

void opcoes_redeSocial(void){
    printf("\n");
    printf("Digite qual deseja:\n"
        "Steam:\t\t 1\n"
        "Twitter:\t 2\n"
        "Youtube:\t 3\n"
    );
}

void opcoes_interesse(void){
    printf("\n");
    printf("Digite qual deseja:\n"
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

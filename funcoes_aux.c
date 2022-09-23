#include <stdio.h>
#include "biblio.h"

char confirmacao(char resp){

    printf("\n");
    printf("Confirme se está correto...\n");
    printf("(s para sim)\n");
    scanf("%c", &resp);
    getchar();
    printf("\n");
    return resp;
}
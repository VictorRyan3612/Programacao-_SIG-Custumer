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

// usado em usuario.c
// Adaptado de Daynne github: https://github.com/DayXL ↓
char validar_nome(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else{
            return 'n';
        }
    }
    return 's';
}

// usado em usuario.c
char validar_email(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= '@' ) && (a[i] <= 'z')) || (a[i] == '.')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return 'n';
        }
    }
    return 's';
}

// usado em usuario.c
char validar_telefone(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if((a[i] >= '0' ) && (a[i] <= '9')){
            i += 1;
        } 
        else if ((a[i] == '(' ) || (a[i] <= ')') || (a[i] == ' ')){
            i += 1;
        }
        else{
            return 'n';
        }
    }
    return 's';
}

// usado em redeSocial.c
char validar_twitterSteam(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= '@' ) && (a[i] <= 'z')) || (a[i] == '.')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return 'n';
        }
    }
    return 's';
}

// usado em redeSocial.c
char validar_youtube(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return 'n';
        }
    }
    return 's';
}

// usado em interesse.c
char validar_nomeMidia(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ') || (a[i] == ';')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else if ((a[i] == '&') || (a[i] == '\'') || (a[i] == ':') || (a[i] == '.')){
            i += 1;
        }
        else{
            return 'n';
        }
    }
    return 's';
}
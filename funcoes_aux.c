#include <stdio.h>
#include "biblio.h"
#define True 1
#define False 0


void enter(void){
    char opcao;
    printf("Aperte enter para continuar\n");
    scanf("%c", &opcao);
    getchar();
}

int confirmacao(void){
    char resp;
    printf("\n");
    printf("Confirme se está correto (s para sim)...\n");
    scanf("%c", &resp);
    getchar();
    printf("\n");
    
    if (resp == 's'){
        return True;
    }
    else{
        return False;
    }
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
int validar_nome(char a[]){
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
            return False;
        }
    }
    return True;
}

// usado em usuario.c
int validar_email(char a[]){
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
            return False;
        }
    }
    return True;
}

// usado em usuario.c
int validar_telefone(char a[]){
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
            return False;
        }
    }
    return True;
}

// usado em redeSocial.c
int validar_twitterSteam(char a[]){
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
            return False;
        }
    }
    return True;
}

// usado em redeSocial.c
int validar_youtube(char a[]){
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
            return False;
        }
    }
    return True;
}

// usado em interesse.c
int validar_nomeMidia(char a[]){
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
            return False;
        }
    }
    return True;
}
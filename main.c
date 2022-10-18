#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "modulo_midia.h"
#include "modulo_usuario.h"
#include "modulo_redeSocial.h"
#include "funcoes_aux.h"


// Para explicações sobre o código, por favor verificar o arquivo
// detalhes.md


// Assinatura das funções:
int menu_principal(void);
int menu_sobre(void);
int modulo_usuario(char a[], int cpf, char b[], char c[]);
int modulo_redeSocial(char a[], char b[], char c[]);
int modulo_interesse(char a[], char b[], char c[]);


// variaveis globais
// usuario.c
char nome[50];
char email[50];
int cpf = '\0';
char telefone[20];
// midia.c
char jogo[50];
char livro[50];
char filme[50];
// redeSocial
char steam[50];
char twitter[30];
char youtube[50];



int main(void){
    setlocale (LC_ALL, "portuguese");

    char opcao = '\0';
    do {
        system("cls||clear");
        menu_principal();
        printf("\n\n");
        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao == '1'){
            modulo_usuario(nome, cpf, email, telefone);
        }
        else if (opcao == '2'){
            modulo_redeSocial(steam,twitter,youtube);
        }
        else if (opcao == '3'){
            modulo_midia(jogo,livro,filme);
        }
        else if (opcao == '4'){
            menu_sobre();
        }
        else if (opcao == '0'){
            printf("Fechando...\n");
        }
        printf("Aperte enter para continuar\n");
        getchar();
        }

        while (opcao != '0');
        return 0;
    }



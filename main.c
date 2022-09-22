#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "biblio.h"

// Para explicações sobre o código, por favor verificar o arquivo
// detalhes.md


// Assinatura das funções:
int menu_principal(void);
int modulo_usuario(char a[], char b[], char c[]);
int modulo_redeSocial(void);
int menu_usuario(void);
int menu_sobre(void);


// variaveis globais

// usuario.c
char nome[50];
char email[50];
char telefone[20];
//interesse.c
char jogo[50];
char livro[50];
char filme[50];

int main(void){
    setlocale (LC_ALL, "portuguese");

    char opcao = '\0';
    do {
        system("cls||clear");
        menu_principal();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao == '1'){
            modulo_usuario(nome, email, telefone);
        }
        else if (opcao == '2'){
            modulo_redeSocial();
        }
        else if (opcao == '3'){
            modulo_interesse(jogo,livro,filme);
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



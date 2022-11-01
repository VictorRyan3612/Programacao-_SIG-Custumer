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
int modulo_usuario(void);
int modulo_redeSocial(char a[], char b[], char c[]);
int modulo_midia(void);


// variaveis globais
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
            modulo_usuario();
        }
        else if (opcao == '2'){
            modulo_redeSocial(steam,twitter,youtube);
        }
        else if (opcao == '3'){
            modulo_midia();
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



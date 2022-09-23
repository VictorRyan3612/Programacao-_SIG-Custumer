#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

// Assinatura das funções:
int menu_usuario(void);
int usuario_cadastro(char a[], char b[], char c[]);
int usuario_vizualizar(char a[], char b[], char c[]);
int usuario_pesquisar(char a[], char b[], char c[]);
int usuario_editar(char a[], char b[], char c[]);
int usuario_excluir(char a[], char b[], char c[]);


//variaveis globais de usuario



int modulo_usuario(char a[], char b[], char c[]){
    
    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do{
        menu_usuario();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                usuario_cadastro(a, b, c);
            }
            else if (opcao == '2'){
                usuario_vizualizar(a,b, c);
            }
            else if (opcao == '3'){
                usuario_pesquisar(a,b,c);
            }
            else if (opcao == '4'){
                usuario_editar(a, b, c);
            }
            else if (opcao == '5'){
                usuario_excluir(a, b, c);
            }
            
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            printf("Aperte enter para continuar\n");
            getchar();
        }
            
        
        if (opcao == '0'){
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');
    return 0;
}



int usuario_cadastro(char a[], char b[], char c[]){
    char resp;
    printf("\n");

    //nome
    do {
        printf("Informe seu nome:\n");
        scanf("%[A-Z a-z]", a);
        getchar();

        resp = confirmacao(resp);
        } while (resp != 's');


    //email
    do {
        printf("Informe seu email:\n");
        scanf("%[A-Za-z0-9.@-]", b);
        getchar();
        
        resp = confirmacao(resp);
        } while (resp != 's');


    //telefone
    do {
        printf("Informe seu telefone:\n");
        scanf("%[0-9 +()-]", c);
        getchar();

        resp = confirmacao(resp);
        } while (resp != 's');

    return 0;
}

int usuario_vizualizar(char a[], char b[], char c[]){

    printf("Seu nome é esse:\n");
    printf("%s", a);
    printf("\n\n\n");


    printf("Seu email é esse:\n");
    printf("%s", b);
    printf("\n\n\n");


    printf("Seu telefone é esse:\n");
    printf("%s", c);
    printf("\n\n\n");

    return 0;
}

int usuario_pesquisar(char a[], char b[], char c[]){
    printf("Busca não disponível\n");

    return 0;
}

int usuario_editar(char a[], char b[], char c[]){
    char editar;
    printf("\nDigite o que deseja editar:\n\n");
    printf("\n"
        "Nome:\t\t 1\n"
        "Email:\t\t 2\n"
        "Telefone:\t 3\n");
    
    scanf("%[1-3]", &editar);   
    getchar();
    printf("\n");
    

    // Editar nome
    if (editar == '1'){
        char resp;

        printf("Seu atual nome é esse:\n");
        printf("%s", a);
        printf("\n\n");
        do{
            printf("Informe seu novo nome:\n");
            scanf("%[A-Z a-z]", a);
            getchar();

            resp = confirmacao(resp);
            } while (resp != 's');
    }
    // Editar email
    else if (editar == '2'){
        char resp;

        printf("Seu atual email é esse:\n");
        printf("%s", b);
        printf("\n\n");
        do{
            printf("Informe seu novo email:\n");
            scanf("%[A-Za-z0-9.,@-]", b);
            getchar();

            resp = confirmacao(resp);
            } while (resp != 's');
    }

        
    // Editar telefone
    else if (editar == '3'){
        char resp;

        printf("Seu atual telefone é esse:\n");
        printf("%s", c);
        printf("\n\n");
        do{
            printf("Informe seu novo telefone:\n");
            scanf("%[0-9 +()-]", c);
            getchar();

            resp = confirmacao(resp);
        } while (resp != 's');
    }
    return 0;
}

int usuario_excluir(char a[], char b[], char c[]){
    char opcao;

    printf("Qual deseja Excluir?\n"
    "Nome:\t\t 1\n"
    "Email:\t\t 2\n"
    "telefone:\t 3\n"
    );


    scanf("%c", &opcao);
    printf("\n\n");
    getchar();


    if (opcao == '1'){
        printf("Exluindo seu nome\n");
        strcpy(a, "");
        printf("%s",a);
        printf("Exluído com sucesso\n");

        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }

    else if (opcao == '2'){
        printf("Exluindo seu email cadastrado\n");
        strcpy(b, "");
        printf("%s",b);
        printf("Exluído com sucesso\n");

        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }
    
    else if (opcao == '3'){
        printf("Exluindo seu telefone cadastrado\n");
        strcpy(c, "");
        printf("%s",c);
        printf("Exluído com sucesso\n");
        
        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }

    return 0;
}

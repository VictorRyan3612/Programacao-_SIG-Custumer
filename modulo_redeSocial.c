#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"


/////  Assinatura das funções:

char opcoes_pergunta(void);
int menu_redeSocial(void);
void menu_redeSocial_cadastro(void);
void menu_redeSocial_editar(void);
void menu_redeSocial_excluir(void);

int redeSocial_cadastro(char a[], char b[], char c[]);
int redeSocial_vizualizar(char a[], char b[], char c[]);
int redeSocial_pesquisar(char a[], char b[], char c[]);
int redeSocial_editar(char a[], char b[], char c[]);
int redeSocial_excluir(char a[], char b[], char c[]);




int modulo_redeSocial(char a[], char b[], char c[]){

    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do {
        menu_redeSocial();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                redeSocial_cadastro(a,b,c);
            }
            else if (opcao == '2'){
                redeSocial_vizualizar(a,b,c);
            }
            else if (opcao == '3'){
                redeSocial_pesquisar(a,b,c);
            }
            else if (opcao == '4'){
                redeSocial_editar(a,b,c);
            }
            else if (opcao == '5'){
                redeSocial_excluir(a,b,c);
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


int redeSocial_cadastro(char a[], char b[], char c[]){
    char opcao;
    char resp;

    menu_redeSocial_cadastro();
    opcao = opcoes_pergunta();


    //steam
    if (opcao == '1'){
        do {
            printf("Informe seu perfil da steam:\n");
            scanf("%[A-Za-z0-9]", a);
            getchar();
        
            resp = confirmacao(resp);
        } while (resp != 's');
    }
    

    //twitter
    if (opcao == '2'){
        do {
            printf("Informe seu twitter:\n");
            scanf("%[A-Za-z0-9@_.]", b);
            getchar();

            resp = confirmacao(resp);;
        } while (resp != 's');
    }

    //youtube
    if (opcao == '3'){
        do {
            printf("Informe seu canal do youtube:\n");
            scanf("%[A-Za-z 0-9]", c);
            getchar();

            resp = confirmacao(resp);
        } while (resp != 's');
    }
    return 0;
}

int redeSocial_vizualizar(char a[], char b[], char c[]){

    printf("Seu perfil do steam é essa:\n");
    vizualizar_lista(a);
    printf("\n\n\n");


    printf("Seu twitter é esse:\n");
    vizualizar_lista(b);
    printf("\n\n\n");


    printf("Seu canal do youtube é esse:\n");
    vizualizar_lista(c);
    printf("\n\n\n");

    return 0;
}

int redeSocial_pesquisar(char a[], char b[], char c[]){
    printf("Busca não disponível\n");

    return 0;
}

int redeSocial_editar(char a[], char b[], char c[]){
    char opcao;

    menu_redeSocial_editar();
    opcao = opcoes_pergunta();

    
    // Editar steam
    if (opcao == '1'){
        char resp;

        printf("Seu atual perfil da steam é esse:\n");
        printf("%s", a);
        printf("\n\n");
        do{
            printf("Informe seu novo perfil steam:\n");
            scanf("%[A-Z a-z]", a);
            getchar();

            resp = confirmacao(resp);
        } while (resp != 's');
}
    // Editar twitter
    else if (opcao == '2'){
        char resp;


        printf("Sua atual conta do twitter é essa:\n");
        printf("%s", b);
        printf("\n\n");
        do{
            printf("Informe seu novo twitter:\n");
            scanf("%[A-Za-z0-9.,@-]", b);
            getchar();

            resp = confirmacao(resp);
            } while (resp != 's');
    }

        
    // Editar youtube
    else if (opcao == '3'){
        char resp;


        printf("Seu atual canal do youtube é esse:\n");
        printf("%s", c);
        printf("\n\n");
        do{
            printf("Informe seu novo canal do youtube:\n");
            scanf("%[0-9 +()-]", c);
            getchar();

            resp = confirmacao(resp);
        } while (resp != 's');
    }


    return 0;
}

int redeSocial_excluir(char a[], char b[], char c[]){
    char opcao;

    menu_redeSocial_excluir();
    opcao = opcoes_pergunta();


    if (opcao == '1'){
        printf("Exluindo seu perfil steam cadastrado\n");
        strcpy(a, "");
        printf("%s",a);
        printf("Exluído com sucesso\n");

        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }

    else if (opcao == '2'){
        printf("Exluindo seu perfil do twitter cadastrado\n");
        strcpy(b, "");
        printf("%s",b);
        printf("Exluído com sucesso\n");

        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }
    
    else if (opcao == '3'){
        printf("Exluindo seu canal youtube cadastrado\n");
        strcpy(c, "");
        printf("%s",c);
        printf("Exluído com sucesso\n");
        
        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }

    return 0;
}

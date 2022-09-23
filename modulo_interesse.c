#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

// Assinatura das funções:
int menu_interesse();
int interesse_cadastro(char a[], char b[], char c[]);
int interesse_vizualizar(char a[], char b[], char c[]);
int interesse_pesquisar(char a[], char b[], char c[]);
int interesse_editar(char a[], char b[], char c[]);
int interesse_excluir(char a[], char b[], char c[]);


//variaveis globais de redeSocial



int modulo_interesse(char a[], char b[], char c[]){

    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do{
        menu_interesse();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                interesse_cadastro(a,b,c);
            }
            else if (opcao == '2'){
                interesse_vizualizar(a,b,c);
            }
            else if (opcao == '3'){
                interesse_pesquisar(a,b,c);
            }
            else if (opcao == '4'){
                interesse_editar(a,b,c);
            }
            else if (opcao == '5'){
                interesse_excluir(a,b,c);
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



int interesse_cadastro(char a[], char b[], char c[]){
    char opcao;
    char resp;
    printf("No momento, apenas 1 interesse está disponível\n\n");

    printf("Qual deseja Cadastrar?\n"
    "Jogo:\t 1\n"
    "Livro:\t 2\n"
    "Filme:\t 3\n"
    );

    scanf("%c", &opcao);
    printf("\n\n");
    getchar();

    printf("\n");

    //Jogo
    if (opcao == '1'){
        do {
            printf("Informe qual jogo está interessado:\n");
            scanf("%[A-Za-z0-9 ']", a);
            getchar();

            resp = confirmacao(resp);
        } while (resp != 's');
    }


    //Livro
    if (opcao == '2'){
        do {
            printf("Informe qual livro está interessado:\n");
            scanf("%[A-Za-z0-9 .,'""()]", b);
            getchar();


            resp = confirmacao(resp);
        } while (resp != 's');
    }
    //Filme
    if (opcao == '3'){
        do{
            printf("Informe qual filme está interessado:\n");
            scanf("%[A-Za-z0-9]", c);
            getchar();

            resp = confirmacao(resp);
        } while (resp != 's');
    } 
    return 0;
}

int interesse_vizualizar(char a[], char b[], char c[]){

    printf("Esse é o jogo que está interessado:\n");
    printf("%s", a);
    printf("\n\n\n");


    printf("Esse é o livro que está interessado:\n");
    printf("%s", b);
    printf("\n\n\n");


    printf("Esse é o filme que está interessado:\n");
    printf("%s", c);
    printf("\n\n\n");

    return 0;
}

int interesse_pesquisar(char a[], char b[], char c[]){
    printf("Busca não disponível\n");

    return 0;
}

int interesse_editar(char a[], char b[], char c[]){
    char editar;

    printf("\nDigite o que deseja editar:\n\n");
    printf("\n"
        "Jogo:\t 1\n"
        "Livro:\t 2\n"
        "filme:\t 3\n");
    
    scanf("%[1-3]", &editar);
    getchar();
    printf("\n");

    
    // Editar Jogo
    if (editar == '1'){
        char resp;

        printf("Seu atual interesse em jogo é:\n");
        printf("%s", a);
        printf("\n\n");
        do{
            printf("Informe qual jogo está interessado:\n");
            scanf("%[A-Z a-z0-9 ,.'""()]", a);
            getchar();

            resp = confirmacao(resp);
            } while (resp != 's');
    }
    
    // Editar livro
    else if (editar == '2'){
        char resp;

        printf("Seu atual interesse em livro é:\n");
        printf("%s", b);
        printf("\n\n");
        do{
            printf("Informe qual livro está interessado:\n");
            scanf("%[A-Za-z0-9 ,.'""()]", b);
            getchar();

            resp = confirmacao(resp);
            } while (resp != 's');
    }

        
    // Editar filme
    else if (editar == '3'){
        char resp;


        printf("Seu atual interesse em filme é:\n");
        printf("%s", c);
        printf("\n\n");
        do{
            printf("Informe qual filme está interessado:\n");
            scanf("%[A-Za-z0-9 ,.()'""]", c);
            getchar();

            resp = confirmacao(resp);
        } while (resp != 's');
    }


    return 0;
}

int interesse_excluir(char a[], char b[], char c[]){
    char opcao;

    printf("Qual deseja Excluir?\n"
    "Jogo:\t 1\n"
    "Livro:\t 2\n"
    "Filme:\t 3\n"
    );


    scanf("%c", &opcao);
    printf("\n\n");
    getchar();


    if (opcao == '1'){
        printf("Exluindo seu interesse em jogo\n");
        strcpy(a, "");
        printf("%s",a);
        printf("Exluído com sucesso\n");

        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }

    else if (opcao == '2'){
        printf("Exluindo seu livro interessado\n");
        strcpy(b, "");
        printf("%s",b);
        printf("Exluído com sucesso\n");

        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }

    else if (opcao == '3'){
        printf("Exluindo seu filme interessado\n");
        strcpy(c, "");
        printf("%s",c);
        printf("Exluído com sucesso\n");
        
        printf("Aperte enter para continuar\n");
        scanf("%c", &opcao);
        getchar();
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_midia.h"
#include "funcoes_aux.h"

#define True 1
#define False 0

typedef struct midia Midia;

///// Assinatura das funções:

char opcoes_pergunta(void);
int menu_midia(void);
void menu_midia_cadastro(void);
void menu_midia_editar(void);
void menu_midia_excluir(void);

void midia_cadastro(void);
void midia_vizualizar(void);
void midia_pesquisar(void);
void midia_editar(void);
void midia_excluir(void);





void modulo_midia(){

    
    char opcao = '\0';


    do{
        menu_midia();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                midia_cadastro();
            }
            else if (opcao == '2'){
                midia_vizualizar();
            }
            else if (opcao == '3'){
                midia_pesquisar();
            }
            else if (opcao == '4'){
                midia_editar();
            }
            else if (opcao == '5'){
                midia_excluir();
            }
            
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        
        if (opcao == '0'){
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');

}


void midia_cadastro(){

    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));

    char opcao;
    int resp;
    
    menu_midia_cadastro();
    opcao = opcoes_pergunta();


    //Jogo
    if (opcao == '1'){
        do {
            printf(""
                "=======================================\n"
                "====  Qual jogo está interessado?  ====\n"
                "=======================================\n"
                );
            printf("(use ; para mais de um)\n");
            printf("\n");
            scanf("%20[^\n]", fulano -> jogo);
            getchar();

            resp = validar_nomeMidia(fulano -> jogo);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }


    //Livro
    else if (opcao == '2'){
        do {
            printf(""
                "=======================================\n"
                "====  Qual livro está interessado? ====\n"
                "=======================================\n"
                );
            printf("use ; para mais de um\n");
            printf("\n");
            scanf("%20[^\n]", fulano -> livro);
            getchar();

            resp = validar_nomeMidia(fulano -> livro);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }

    //Filme
    else if (opcao == '3'){
        do{
            printf(""
                "=======================================\n"
                "====  Qual Filme está interessado? ====\n"
                "=======================================\n"
                );
            printf("use ; para mais de um\n");
            printf("\n");
            scanf("%20[^\n]", fulano -> filme);
            getchar();

            resp = validar_nomeMidia(fulano -> filme);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
}



void midia_vizualizar(){
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));
    printf("\n");
    char dovizualizar[50];

    printf("Esse são os jogos que está interessado:\n");
    strcpy(dovizualizar , fulano -> jogo);
    vizualizar_lista(dovizualizar);
    printf("\n\n\n");


    printf("Esse são os livros que está interessado:\n");
    strcpy(dovizualizar , fulano -> livro);
    vizualizar_lista(dovizualizar);
    printf("\n\n\n");


    printf("Esse são os filmes que está interessado:\n");
    strcpy(dovizualizar , fulano -> filme);
    vizualizar_lista(dovizualizar);
    printf("\n\n\n");


}

void midia_pesquisar(){
    printf("Busca não disponível\n");


}

void midia_editar(){
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));

    char opcao;
    int resp;

    menu_midia_editar();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    midia_vizualizar();

    opcao = opcoes_pergunta();

    
    // Editar Jogo
    if (opcao == '1'){
        printf("Seu atual interesse em jogo é:\n");
        printf("%s", fulano -> jogo);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", fulano -> jogo);
            getchar();

            resp = validar_nomeMidia(fulano -> jogo);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
    
    // Editar livro
    else if (opcao == '2'){
        printf("Seu atual interesse em livro é:\n");
        printf("%s", fulano -> livro);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", fulano -> livro);
            getchar();

            resp = validar_nomeMidia(fulano -> livro);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }

        
    // Editar filme
    else if (opcao == '3'){


        printf("Seu atual interesse em filme é:\n");
        printf("%s", fulano -> filme);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", fulano -> filme);
            getchar();

            resp = validar_nomeMidia(fulano -> filme);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
    else{
        printf("Opção não dessenvolvida ou inválida\n");
    }


}

void midia_excluir(){
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));

    char opcao;
    int resp;

    menu_midia_excluir();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    midia_vizualizar();

    printf("Digite qual deseja:\n");
    opcao = opcoes_pergunta();

    resp = confirmacao();
    if (resp == True){
        if (opcao == '1'){
            printf("Exluindo seu interesse em jogo\n");
            strcpy(fulano -> jogo, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '2'){
            printf("Exluindo seu livro interessado\n");
            strcpy(fulano -> livro, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '3'){
            printf("Exluindo seu filme interessado\n");
            strcpy(fulano -> filme, "");
            printf("Exluído com sucesso\n");
            
        }
    }
}
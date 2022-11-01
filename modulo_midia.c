#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_midia.h"
#include "funcoes_aux.h"

#define True 1
#define False 0


///// Assinatura das funções:

char opcoes_pergunta(void);
int menu_midia(void);
void menu_midia_cadastro(void);
void menu_midia_editar(void);
void menu_midia_excluir(void);

int midia_cadastro(Midia*);
int midia_vizualizar(const Midia*);
int midia_pesquisar(const Midia*);
int midia_editar(Midia* fulano);
int midia_excluir(Midia* fulano);


typedef struct midia Midia;

struct midia {
    char jogo[81];
    char livro[51];
    char filme[41];
};

int modulo_midia(){

    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';
    Midia fulano;
    do{
        menu_midia();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                midia_cadastro(&fulano);
            }
            else if (opcao == '2'){
                midia_vizualizar(&fulano);
            }
            else if (opcao == '3'){
                midia_pesquisar(&fulano);
            }
            else if (opcao == '4'){
                midia_editar(&fulano);
            }
            else if (opcao == '5'){
                midia_excluir(&fulano);
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


int midia_cadastro(Midia* fulano){
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
    if (opcao == '2'){
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
    if (opcao == '3'){
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
    return 0;
}



int midia_vizualizar(const Midia* fulano){
    printf("\n");

    printf("Esse são os jogos que está interessado:\n");
    vizualizar_lista(fulano -> jogo);
    printf("\n\n\n");

    printf("Esse são os livros que está interessado:\n");
    vizualizar_lista(fulano -> livro);
    printf("\n\n\n");


    printf("Esse são os filmes que está interessado:\n");
    vizualizar_lista(fulano -> filme);
    printf("\n\n\n");

    return 0;
}

int midia_pesquisar(const Midia* fulano){
    printf("Busca não disponível\n");

    return 0;
}

int midia_editar(Midia* fulano){
    char opcao;
    int resp;

    menu_midia_editar();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    midia_vizualizar(fulano);

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


    return 0;
}

int midia_excluir(Midia* fulano){
    char opcao;
    int resp;

    menu_midia_excluir();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    midia_vizualizar(fulano);

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
    return 0;
}
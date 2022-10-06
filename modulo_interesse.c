#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"


///// Assinatura das funções:

char opcoes_pergunta(void);
int menu_interesse(void);
void menu_interesse_cadastro(void);
void menu_interesse_editar(void);
void menu_interesse_excluir(void);

int interesse_cadastro(char a[], char b[], char c[]);
int interesse_vizualizar(char a[], char b[], char c[]);
int interesse_pesquisar(char a[], char b[], char c[]);
int interesse_editar(char a[], char b[], char c[]);
int interesse_excluir(char a[], char b[], char c[]);




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
    
    menu_interesse_cadastro();
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
            scanf("%20[^\n]", a);
            getchar();

            resp = validar_nomeMidia(a);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != 's');
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
            scanf("%20[^\n]", b);
            getchar();

            resp = validar_nomeMidia(b);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != 's');
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
            scanf("%20[^\n]", c);
            getchar();

            resp = validar_nomeMidia(c);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != 's');
    } 
    return 0;
}



int interesse_vizualizar(char a[], char b[], char c[]){
    printf("\n");

    printf("Esse são os jogos que está interessado:\n");
    vizualizar_lista(a);
    printf("\n\n\n");

    printf("Esse são os livros que está interessado:\n");
    vizualizar_lista(b);
    printf("\n\n\n");


    printf("Esse são os filmes que está interessado:\n");
    vizualizar_lista(c);
    printf("\n\n\n");

    return 0;
}

int interesse_pesquisar(char a[], char b[], char c[]){
    printf("Busca não disponível\n");

    return 0;
}

int interesse_editar(char a[], char b[], char c[]){
    char opcao;
    char resp;

    menu_interesse_editar();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    interesse_vizualizar(a,b,c);

    opcao = opcoes_pergunta();

    
    // Editar Jogo
    if (opcao == '1'){
        printf("Seu atual interesse em jogo é:\n");
        printf("%s", a);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", a);
            getchar();

            resp = validar_nomeMidia(a);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
            } while (resp != 's');
    }
    
    // Editar livro
    else if (opcao == '2'){
        printf("Seu atual interesse em livro é:\n");
        printf("%s", b);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", b);
            getchar();

            resp = validar_nomeMidia(b);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
            } while (resp != 's');
    }

        
    // Editar filme
    else if (opcao == '3'){


        printf("Seu atual interesse em filme é:\n");
        printf("%s", c);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", c);
            getchar();

            resp = validar_nomeMidia(c);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != 's');
    }


    return 0;
}

int interesse_excluir(char a[], char b[], char c[]){
    char opcao;
    char resp;

    menu_interesse_excluir();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    interesse_vizualizar(a,b,c);

    printf("Digite qual deseja:\n");
    opcao = opcoes_pergunta();

    resp = confirmacao();
    if (resp == 's'){
        if (opcao == '1'){
            printf("Exluindo seu interesse em jogo\n");
            strcpy(a, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '2'){
            printf("Exluindo seu livro interessado\n");
            strcpy(b, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '3'){
            printf("Exluindo seu filme interessado\n");
            strcpy(c, "");
            printf("Exluído com sucesso\n");
            
        }
    }
    return 0;
}
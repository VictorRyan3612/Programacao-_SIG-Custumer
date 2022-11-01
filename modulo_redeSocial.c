#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_redeSocial.h"
#include "funcoes_aux.h"

#define True 1
#define False 0

/////  Assinatura das funções:

char opcoes_pergunta(void);
int menu_redeSocial(void);
void menu_redeSocial_cadastro(void);
void menu_redeSocial_editar(void);
void menu_redeSocial_excluir(void);

int redeSocial_cadastro(RedeSocial* fulano);
int redeSocial_vizualizar(const RedeSocial* fulano);
int redeSocial_pesquisar(const RedeSocial* fulano);
int redeSocial_editar(RedeSocial* fulano);
int redeSocial_excluir(RedeSocial* fulano);

typedef struct redeSocial RedeSocial;

struct redeSocial {
    char steam[81];
    char twitter[51];
    char youtube[41];
};


int modulo_redeSocial(){

    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';
    RedeSocial fulano;

    do {
        menu_redeSocial();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                redeSocial_cadastro(&fulano);
            }
            else if (opcao == '2'){
                redeSocial_vizualizar(&fulano);
            }
            else if (opcao == '3'){
                redeSocial_pesquisar(&fulano);
            }
            else if (opcao == '4'){
                redeSocial_editar(&fulano);
            }
            else if (opcao == '5'){
                redeSocial_excluir(&fulano);
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


int redeSocial_cadastro(RedeSocial* fulano){
    char opcao;
    int resp;

    menu_redeSocial_cadastro();
    opcao = opcoes_pergunta();


    //steam
    if (opcao == '1'){
        do {
            printf(""
                "=======================================\n"
                "====  Informe seu perfil da steam: ====\n"
                "=======================================\n"
                );
            printf("\n");
            scanf("%s", fulano -> steam);
            getchar();
            resp = validar_twitterSteam(fulano -> steam);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
    

    //twitter
    if (opcao == '2'){
        do {
            printf(""
                "=======================================\n"
                "====     Informe seu Twitter:      ====\n"
                "=======================================\n"
                );
            printf("\n");
            scanf("%s", fulano -> twitter);
            getchar();

            resp = validar_twitterSteam(fulano -> twitter);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }

    //youtube
    if (opcao == '3'){
        do {
            printf(""
                "=======================================\n"
                "====     Informe seu Youtube:      ====\n"
                "=======================================\n"
                );
            printf("\n");
            scanf("%s", fulano -> youtube);
            getchar();

            resp = validar_youtube(fulano -> youtube);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
    return 0;
}

int redeSocial_vizualizar(const RedeSocial* fulano){
    printf("\n");

    printf("Seu perfil do steam é essa:\n");
    printf("%s", fulano -> steam);
    printf("\n\n\n");


    printf("Seu twitter é esse:\n");
    printf("%s", fulano -> twitter);
    printf("\n\n\n");


    printf("Seu canal do youtube é esse:\n");
    printf("%s", fulano -> youtube);
    printf("\n\n\n");

    return 0;
}

int redeSocial_pesquisar(const RedeSocial* fulano){
    printf("Busca não disponível\n");

    return 0;
}

int redeSocial_editar(RedeSocial* fulano){
    char opcao;
    int resp;

    menu_redeSocial_editar();
    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    redeSocial_vizualizar(fulano);
    opcao = opcoes_pergunta();

    
    // Editar steam
    if (opcao == '1'){
        printf("Seu atual perfil da steam é esse:\n");
        printf("%s", fulano -> steam);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%s", fulano -> steam);
            getchar();
            resp = validar_twitterSteam(fulano -> steam);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
}
    // Editar twitter
    else if (opcao == '2'){
        printf("Sua atual conta do twitter é essa:\n");
        printf("%s", fulano -> twitter);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%s", fulano -> twitter);
            getchar();

            resp = validar_twitterSteam(fulano -> twitter);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }

        
    // Editar youtube
    else if (opcao == '3'){
        printf("Seu atual canal do youtube é esse:\n");
        printf("%s", fulano -> youtube);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%s", fulano -> youtube);
            getchar();

            resp = validar_youtube(fulano -> youtube);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }


    return 0;
}

int redeSocial_excluir(RedeSocial* fulano){
    char opcao;
    int resp;

    menu_redeSocial_excluir();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");

    redeSocial_vizualizar(fulano);

    printf("Digite qual deseja:\n");
    opcao = opcoes_pergunta();

    resp = confirmacao();
    if (resp == True){
        if (opcao == '1'){
            
            printf("Exluindo seu perfil steam cadastrado\n");
            strcpy(fulano -> steam, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '2'){
            printf("Exluindo seu perfil do twitter cadastrado\n");
            strcpy(fulano -> twitter, "");
            printf("Exluído com sucesso\n");

        }
        
        else if (opcao == '3'){
            printf("Exluindo seu canal youtube cadastrado\n");
            strcpy(fulano -> youtube, "");
            printf("Exluído com sucesso\n");
            
        }
    }
    return 0;
}

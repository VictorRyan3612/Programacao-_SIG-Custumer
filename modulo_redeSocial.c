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
            printf(""
                "=======================================\n"
                "====  Informe seu perfil da steam: ====\n"
                "=======================================\n"
                );
            printf("\n");
            scanf("%[A-Za-z0-9]", a);
            getchar();
        
            resp = confirmacao();
        } while (resp != 's');
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
            scanf("%[A-Za-z0-9@_.]", b);
            getchar();

            resp = confirmacao();
        } while (resp != 's');
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
            scanf("%[A-Za-z 0-9]", c);
            getchar();

            resp = confirmacao();
        } while (resp != 's');
    }
    return 0;
}

int redeSocial_vizualizar(char a[], char b[], char c[]){
    printf("\n");

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
    char resp;

    menu_redeSocial_editar();
    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    redeSocial_vizualizar(a,b,c);
    opcao = opcoes_pergunta();

    
    // Editar steam
    if (opcao == '1'){
        printf("Seu atual perfil da steam é esse:\n");
        printf("%s", a);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%[A-Z a-z]", a);
            getchar();

            resp = confirmacao();
        } while (resp != 's');
}
    // Editar twitter
    else if (opcao == '2'){
        printf("Sua atual conta do twitter é essa:\n");
        printf("%s", b);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%[A-Za-z0-9.,@-]", b);
            getchar();

            resp = confirmacao();
            } while (resp != 's');
    }

        
    // Editar youtube
    else if (opcao == '3'){
        printf("Seu atual canal do youtube é esse:\n");
        printf("%s", c);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%[0-9 +()-]", c);
            getchar();

            resp = confirmacao();
        } while (resp != 's');
    }


    return 0;
}

int redeSocial_excluir(char a[], char b[], char c[]){
    char opcao;
    char resp;

    menu_redeSocial_excluir();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");

    redeSocial_vizualizar(a,b,c);

    opcao = opcoes_pergunta();

    resp = confirmacao();
    if (resp == 's'){
        if (opcao == '1'){
            
            printf("Exluindo seu perfil steam cadastrado\n");
            strcpy(a, "");
            printf("%s",a);
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '2'){
            printf("Exluindo seu perfil do twitter cadastrado\n");
            strcpy(b, "");
            printf("%s",b);
            printf("Exluído com sucesso\n");

        }
        
        else if (opcao == '3'){
            printf("Exluindo seu canal youtube cadastrado\n");
            strcpy(c, "");
            printf("%s",c);
            printf("Exluído com sucesso\n");
            
        }
    }
    return 0;
}

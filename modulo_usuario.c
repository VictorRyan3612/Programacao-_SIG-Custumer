#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"


// Assinatura das funções:
int menu_usuario(void);
void menu_usuario_editar(void);
void menu_usuario_excluir(void);
char confirmacao(void);

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

    system("cls||clear");
    printf("\n");

    //nome
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu nome:       ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%20[^\n]", a);
        getchar();

        resp = validar_nome(a);
        if (resp != 's'){
            printf("Caractere inválido detectado, Digite novamente:\n");
        }
        } while (resp != 's');


    //email
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu email:      ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%s", b);
        getchar();
        
        resp = validar_email(b);
        if (resp != 's'){
            printf("Caractere inválido detectado, Digite novamente:\n");
        }
        } while (resp != 's');


    //telefone
    do {
        printf(""
            "=======================================\n"
            "====     Informe seu telefone:     ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%s", c);
        getchar();

        resp = validar_telefone(c);
        if (resp != 's'){
            printf("Caractere inválido detectado, Digite novamente:\n");
        }
        } while (resp != 's');

    return 0;
}

int usuario_vizualizar(char a[], char b[], char c[]){
    printf("\n");

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
    char opcao;
    char resp;
    
    menu_usuario_editar();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    usuario_vizualizar(a,b,c);

    opcao = opcoes_pergunta();

    // Editar nome
    if (opcao == '1'){
        printf("Seu atual nome é esse:\n");
        printf("%s", a);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", a);
            getchar();

            resp = validar_nome(a);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
            } while (resp != 's');
    }
    // Editar email
    else if (opcao == '2'){
        printf("Seu atual email é esse:\n");
        printf("%s", b);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%s", b);
            getchar();
            
            resp = validar_email(b);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
            } while (resp != 's');
    }

        
    // Editar telefone
    else if (opcao == '3'){
        printf("Seu atual telefone é esse:\n");
        printf("%s", c);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====      Informe o atualizado:    ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%s", c);
            getchar();

            resp = validar_telefone(c);
            if (resp != 's'){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != 's');
    }
    return 0;
}

int usuario_excluir(char a[], char b[], char c[]){
    char opcao;
    char resp;

    menu_usuario_excluir();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    usuario_vizualizar(a,b,c);

    printf("Digite qual deseja:\n");
    opcao = opcoes_pergunta();

    resp = confirmacao();
    if (resp == 's'){
        if (opcao == '1'){
            printf("Exluindo seu nome\n");
            strcpy(a, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '2'){
            printf("Exluindo seu email cadastrado\n");
            strcpy(b, "");
            printf("Exluído com sucesso\n");

        }
        
        else if (opcao == '3'){
            printf("Exluindo seu telefone cadastrado\n");
            strcpy(c, "");
            printf("Exluído com sucesso\n");
            
        }
    }
    return 0;
}

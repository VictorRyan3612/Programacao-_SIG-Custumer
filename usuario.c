#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Assinatura das funções:
int menu_usuario();
int usuario_cadastro();
int usuario_vizualizar();
int usuario_pesquisar();
int usuario_editar();
int usuario_excluir();


//variaveis globais de usuario
char nome[50];
char email[50];
char telefone[20];


int modulo_usuario(){
    
    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do{
        menu_usuario();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                usuario_cadastro();
            }
            else if (opcao == '2'){
                usuario_vizualizar();
            }
            else if (opcao == '3'){
                usuario_pesquisar();
            }
            else if (opcao == '4'){
                usuario_editar();
            }
            else if (opcao == '5'){
                usuario_excluir();
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



int usuario_cadastro(){
    char resp;

    //nome
    printf("Informe seu nome:\n");
    scanf("%[A-Z a-z]", nome);
    getchar();

    do {
        printf("Seu nome é esse?\n");
        printf("%s", nome);
        printf("\n\n");
        
        printf("(s para sim)\n");
        scanf("%c", &resp);
        getchar();
        } while (resp != 's');


    //email
    printf("Informe seu email:\n");
    scanf("%[A-Za-z0-9.@-]", email);
    getchar();
    do {
        printf("Seu email é esse?\n");
        printf("%s", email);
        printf("\n\n");

        printf("(s para sim)\n");
        scanf("%c", &resp);
        getchar();
        } while (resp != 's');

    //telefone
    printf("Informe seu telefone:\n");
    scanf("%[0-9 +()-]", telefone);
    getchar();

    do {
        printf("Seu telefone é esse?\n");
        printf("%s", telefone);
        printf("\n\n");

        printf("(s para sim)\n");
        scanf("%c", &resp);
        getchar();
        } while (resp != 's');

    return 0;
}
int usuario_vizualizar(){

    printf("Seu nome é esse:\n");
    printf("%s", nome);
    printf("\n\n\n");


    printf("Seu email é esse:\n");
    printf("%s", email);
    printf("\n\n\n");


    printf("Seu telefone é esse:\n");
    printf("%s", telefone);
    printf("\n\n\n");

    return 0;
}
int usuario_pesquisar(){
    printf("Busca não disponível\n");

    return 0;
}

int usuario_editar(){

    char editar;
    printf("Digite o que deseja editar:\n\n");
    printf("\n"
        "Nome:\t\t 1\n"
        "Email:\t\t 2\n"
        "Telefone:\t 3\n");
    
    scanf("%[1-3]", &editar);   
    getchar();

    

    // Editar nome
    if (editar == '1'){
        char resp;


            printf("Seu atual nome é esse:\n");
            printf("%s", nome);
            printf("\n\n");
        do{
            printf("Informe seu novo nome:\n");
            scanf("%[A-Z a-z]", nome);
            printf("\n\n");
            getchar();


            printf("Esse é seu nome?\n");
            printf("%s", nome);
            printf("\n\n");

            printf("(s para sim)\n");
            scanf("%c", &resp);
            getchar();
            } while (resp != 's');
    }
    // Editar email
    else if (editar == '2'){
        char resp;


        printf("Seu atual email é esse:\n");
        printf("%s", email);
        printf("\n\n");
        do{
            printf("Informe seu novo email:\n");
            scanf("%[A-Za-z0-9.,@-]", email);
            printf("\n\n");
            getchar();

            printf("Seu email novo é esse?\n");
            printf("%s", email);
            printf("\n\n");

            printf("(s para sim)\n");
            scanf("%c", &resp);
            getchar();
            } while (resp != 's');
    }

        
    // Editar telefone
    else if (editar == '3'){
        char resp;

        printf("Seu atual telefone é esse:\n");
        printf("%s", telefone);
        printf("\n\n");
        do{
            printf("Informe seu novo telefone:\n");
            scanf("%[0-9 +()-]", telefone);
            printf("\n\n");
            getchar();

            printf("Seu novo telefone é esse?\n");
            printf("%s", telefone);
            printf("\n\n");

            printf("(s para sim)\n");
            scanf("%c", &resp);
            getchar();
        } while (resp != 's');
    }


    return 0;
}
int usuario_excluir(){
    printf("Exclusão não disponível\n");
    
    return 0;
}
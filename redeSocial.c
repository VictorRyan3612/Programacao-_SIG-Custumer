#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


// Assinatura das funções:
int menu_redeSocial();
int redeSocial_cadastro();
int redeSocial_vizualizar();
int redeSocial_pesquisar();
int redeSocial_editar();
int redeSocial_excluir();


//variaveis globais de redeSocial
char steam[50];
char twitter[30];
char youtube[50];


int modulo_redeSocial(){     

    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do {
        menu_redeSocial();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                redeSocial_cadastro();
            }
            else if (opcao == '2'){
                redeSocial_vizualizar();
            }
            else if (opcao == '3'){
                redeSocial_pesquisar();
            }
            else if (opcao == '4'){
                redeSocial_editar();
            }
            else if (opcao == '5'){
                redeSocial_excluir();
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

int redeSocial_cadastro(){
    char opcao;

    printf("Qual deseja Cadastrar?\n"
    "Steam:\t\t 1\n"
    "Twitter:\t 2\n"
    "Youtube:\t 3\n"
    );

    scanf("%c", &opcao);
    getchar();


    //steam
    if (opcao == '1'){
        printf("Informe seu perfil da steam:\n");
        scanf("%[A-Za-z0-9]", steam);
        getchar();

        printf("Sua steam é esse?\n");
        printf("%s", steam);
        printf("\n\n\n");

    }
    

    //twitter
    if (opcao == '2'){
        printf("Informe seu twitter:\n");
        scanf("%[A-Za-z0-9@_.]", twitter);
        getchar();

        printf("Seu twitter é esse?\n");
        printf("%s", twitter);
        printf("\n\n\n");
    }

    //youtube
    if (opcao == '2'){
    printf("Informe seu canal do youtube:\n");
    scanf("%[A-Za-z 0-9]", youtube);
    getchar();

    printf("Seu youtube é esse?\n");
    printf("%s", youtube);
    printf("\n\n\n");
    }
    return 0;
}

int redeSocial_vizualizar(){

    printf("Seu perfil do steam é essa:\n");
    printf("%s", steam);
    printf("\n\n\n");


    printf("Seu twitter é esse:\n");
    printf("%s", twitter);
    printf("\n\n\n");


    printf("Seu canal do youtube é esse:\n");
    printf("%s", youtube);
    printf("\n\n\n");

    return 0;
}
int redeSocial_pesquisar(){
    printf("Busca não disponível\n");

    return 0;
}

int redeSocial_editar(){
    char editar;
    printf("Digite o que deseja editar:\n\n");
    printf("\n"
        "Steam:\t\t 1\n"
        "Twitter:\t\t 2\n"
        "Youtube:\t 3\n");
    
    scanf("%[1-3]", &editar);   
    getchar();

    
    // Editar steam
    if (editar == '1'){
        char resp;
        do {

            printf("Seu atual perfil da steam é esse:\n");
            printf("%s", steam);
            printf("\n\n\n");
            
            printf("Informe seu novo perfil steam:\n");
            scanf("%[A-Z a-z]", steam);
            getchar();


            printf("Seu perfil da steam é esse? (s para sim)\n");
            printf("%s", steam);
            printf("\n\n");

            scanf("%c", &resp);
            getchar();
            } while (resp != 's');
    }
    // Editar twitter
    else if (editar == '2'){
        char resp;
        do {

            printf("Sua atual conta do twitter é essa:\n");
            printf("%s", twitter);
            printf("\n\n");

            printf("Informe seu novo twitter:\n");
            scanf("%[A-Za-z0-9.,@-]", twitter);
            getchar();

            printf("Seu twitter novo é esse? (s para sim)\n");
            printf("%s", twitter);
            printf("\n\n\n");

            scanf("%c", &resp);
            getchar();
            } while (resp != 's');
    }

        
    // Editar youtube
    else if (editar == '3'){
        char resp;
        do {

            printf("Seu atual canal do youtube é esse:\n");
            printf("%s", youtube);
            printf("\n\n");

            printf("Informe seu novo canal do youtube:\n");
            scanf("%[0-9 +()-]", youtube);
            getchar();

            printf("Seu novo youtube é esse? (s para sim)\n");
            printf("%s", youtube);
            printf("\n\n");
            scanf("%c", &resp);
            getchar();
        } while (resp != 's');
    }


    return 0;
}


int redeSocial_excluir(){
    printf("Exclusão não disponível\n");

    return 0;
}
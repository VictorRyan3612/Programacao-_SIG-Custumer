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
char facebook[50];
char twitter[50];
char youtube[20];


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
    "Facebook:\t 1\n"
    "Twitter:\t 2\n"
    "Youtube:\t 3\n"
    );

    scanf("%c", &opcao);
    getchar();


    //facebook
    if (opcao == '1'){
        printf("informe seu facebook:\n");
        scanf("%[A-Za-z0-9.@]", facebook);
        getchar();

        printf("Seu facebook é esse?\n");
        printf("%s", facebook);
        printf("\n\n\n");

    }
    

    //twitter
    if (opcao == '2'){
        printf("informe seu twitter:\n");
        scanf("%[A-Za-z0-9@_]", twitter);
        getchar();

        printf("Seu twitter é esse?\n");
        printf("%s", twitter);
        printf("\n\n\n");
    }

    //youtube
    printf("informe seu youtube:\n");
    scanf("%[A-Za-z 0-9]", youtube);
    getchar();

    printf("Seu youtube é esse?\n");
    printf("%s", youtube);
    printf("\n\n\n");

    return 0;
}

int redeSocial_vizualizar(){
    printf("vizualização não disponível\n");

    return 0;
}
int redeSocial_pesquisar(){
    printf("Busca não disponível\n");

    return 0;
}

int redeSocial_editar(){
    printf("Edição não disponível\n");

    return 0;
}
int redeSocial_excluir(){
    printf("Exclusão não disponível\n");

    return 0;
}
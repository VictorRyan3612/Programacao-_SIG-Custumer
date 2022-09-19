#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


// Assinatura das funções:
int menu_usuario();
int usuario_cadastro();
int usuario_vizualizar();
int usuario_pesquisar();
int usuario_editar();
int usuario_excluir();




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
    char nome[50];
    char email[50];
    char telefone[20];

    //nome
    printf("Infome seu nome:\n");
    scanf("%s", nome);
    getchar();

    printf("Seu nome é esse?\n");
    printf("%s", nome);
    printf("\n\n\n");


    //email
    printf("Infome seu email:\n");
    scanf("%s", email);
    getchar();

    printf("Seu email é esse?\n");
    printf("%s", email);
    printf("\n\n\n");


    //telefone
    printf("Infome seu telefone:\n");
    scanf("%s", telefone);
    getchar();

    printf("Seu teçefone é esse?\n");
    printf("%s", telefone);
    printf("\n\n\n");

    return 0;
}
int usuario_vizualizar(){
    printf("vizualização não disponível\n");

    return 0;
}
int usuario_pesquisar(){
    printf("Busca não disponível\n");

    return 0;
}

int usuario_editar(){
    printf("Edição não disponível\n");

    return 0;
}
int usuario_excluir(){
    printf("Exclusão não disponível\n");

    return 0;
}
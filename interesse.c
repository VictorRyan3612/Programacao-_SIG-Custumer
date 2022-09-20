#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


// Assinatura das funções:
int menu_interesse();
int interesse_cadastro();
int interesse_vizualizar();
int interesse_pesquisar();
int interesse_editar();
int interesse_excluir();


//variaveis globais de redeSocial
char jogo[50];
char livro[50];
char filme[50];


int modulo_interesse(){

    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do{
        menu_interesse();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                interesse_cadastro();
            }
            else if (opcao == '2'){
                interesse_vizualizar();
            }
            else if (opcao == '3'){
                interesse_pesquisar();
            }
            else if (opcao == '4'){
                interesse_editar();
            }
            else if (opcao == '5'){
                interesse_excluir();
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



int interesse_cadastro(){
    char opcao;
    char resp;
    printf("No momento, apenas 1 interesse está disponível\n\n");

    printf("Qual deseja Cadastrar?\n"
    "Jogo:\t 1\n"
    "Livro:\t 2\n"
    "Filme:\t 3\n"
    );

    scanf("%c", &opcao);
    printf("\n\n");
    getchar();

    //Jogo
    if (opcao == '1'){
        printf("Informe qual jogo está interessado:\n");
        scanf("%[A-Za-z0-9 ']", jogo);
        printf("\n");
        getchar();

        do {
            printf("Está interessado nesse jogo?\n");
            printf("%s", jogo);
            printf("\n\n");

            printf("(s para sim)\n");
            scanf("%c", &resp);
            getchar();
        } while (resp != 's');
    }


    //Livro
    if (opcao == '2'){
        printf("Informe qual livro está interessado:\n");
        scanf("%[A-Za-z0-9 .,'""()]", livro);
        getchar();
        do {
            printf("Está interessado nesse livro?\n");
            printf("%s", livro);
            printf("\n\n\n");

            printf("(s para sim)\n");
            scanf("%c", &resp);
            getchar();
        } while (resp != 's');
    }
    //Filme
    if (opcao == '3'){
        printf("Informe qual filme está interessado:\n");
        scanf("%[A-Za-z0-9]", filme);
        getchar();
        do {
            printf("Está interessado nesse filme?\n");
            printf("%s", filme);
            printf("\n\n\n");
            printf("(s para sim)\n");
            scanf("%c", &resp);
            getchar();
        } while (resp != 's');
    } 
    return 0;
}
int interesse_vizualizar(){

    printf("Esse é o jogo que está interessado:\n");
    printf("%s", jogo);
    printf("\n\n\n");


    printf("Esse é o livro que está interessado:\n");
    printf("%s", livro);
    printf("\n\n\n");


    printf("Esse é o filme que está interessado:\n");
    printf("%s", filme);
    printf("\n\n\n");

    return 0;
}
int interesse_pesquisar(){
    printf("Busca não disponível\n");

    return 0;
}

int interesse_editar(){
    char editar;
    printf("Digite o que deseja editar:\n\n");
    printf("\n"
        "Jogo:\t 1\n"
        "Livro:\t 2\n"
        "filme:\t 3\n");
    
    scanf("%[1-3]", &editar);   
    getchar();

    
    // Editar Jogo
    if (editar == '1'){
        char resp;
        do {

            printf("Seu atual interesse em jogo é:\n");
            printf("%s", jogo);
            printf("\n\n\n");
            
            printf("Informe qual jogo está interessado:\n");
            scanf("%[A-Z a-z0-9 ,.'""()]", jogo);
            getchar();


            printf("Esse é seu novo interesse? (s para sim)\n");
            printf("%s", jogo);
            printf("\n\n");

            scanf("%c", &resp);
            getchar();
            } while (resp != 's');
    }
    // Editar livro
    else if (editar == '2'){
        char resp;
        do {

            printf("Seu atual interesse em livro é:\n");
            printf("%s", livro);
            printf("\n\n");

            printf("Informe qual livro está interessado:\n");
            scanf("%[A-Za-z0-9 ,.'""()]", livro);
            getchar();

            printf("Esse é seu novo interesse? (s para sim)\n");
            printf("%s", livro);
            printf("\n\n\n");

            scanf("%c", &resp);
            getchar();
            } while (resp != 's');
    }

        
    // Editar filme
    else if (editar == '3'){
        char resp;
        do {

            printf("Seu atual interesse em filme é:\n");
            printf("%s", filme);
            printf("\n\n");

            printf("Informe qual filme está interessado:\n");
            scanf("%[A-Za-z0-9 ,.()'""]", filme);
            getchar();

            printf("Esse é seu novo interesse? (s para sim)\n");
            printf("%s", filme);
            printf("\n\n");
            scanf("%c", &resp);
            getchar();
        } while (resp != 's');
    }


    return 0;
}
int interesse_excluir(){
    printf("Exclusão não disponível\n");

    return 0;
}
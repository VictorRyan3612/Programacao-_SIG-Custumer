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
    printf("Cadastro não disponível\n");

    return 0;
}
int interesse_vizualizar(){
    printf("vizualização não disponível\n");

    return 0;
}
int interesse_pesquisar(){
    printf("Busca não disponível\n");

    return 0;
}

int interesse_editar(){
    printf("Edição não disponível\n");

    return 0;
}
int interesse_excluir(){
    printf("Exclusão não disponível\n");

    return 0;
}
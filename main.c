#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Para explicações sobre o código, por favor verificar o arquivo
// detalhes.md


// Assinatura das funções:
int menu_principal();
int menu_usuario();
int menu_sobre();
int usuario_cadastro();
int usuario_vizualizar();
int usuario_pesquisar();
int usuario_editar();
int usuario_excluir();


int main() {
    setlocale (LC_ALL, "portuguese");

    char opcao = '\0';
    do {
        system("cls||clear");
        menu_principal();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao == '1'){
            menu_usuario();
        }
        else if (opcao == '4'){
            menu_sobre();
        }
        else if (opcao == '0'){
            printf("Fechando...\n");
        }
        printf("Aperte enter para continuar\n");
        getchar();
        }

        while (opcao != '0');
        return 0;
    }




int menu_usuario(){
    
    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do{
        system("cls||clear");
        printf("\n"
        "\t==============================\n"
        "\t\tMenu Controle de Usuário\n"
        "\t==============================\n"
        "\t1 - Cadastrar usuário\n"
        "\t2 - Exibir lista de usuários\n"
        "\t3 - Procurar usuário\n"
        "\t4 - Editar usuário\n"
        "\t5 - Excluir usuário\n"
        "\t0 - Sair\n"
        );

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
    printf("Cadastro não disponível\n");

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
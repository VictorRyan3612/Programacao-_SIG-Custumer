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



int menu_principal(){
    setlocale (LC_ALL, "portuguese");
    printf("\n"
    "\t\t==============================\n"
    "\t\tPrograma Controle de Clientes\n"
    "\t\t==============================\n"
    "\t\t1 - Módulo usuário\n"
    "\t\t2 - Módulo em desenvolvimento\n"
    "\t\t3 - Módulo em desenvolvimento\n"
    "\t\t4 - Sobre e equipe\n"
    "\t\t0 - Encerrar\n"
    "\n"
    );
    
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




int menu_sobre(){
    setlocale (LC_ALL, "portuguese");
    printf("\n"
    "\t\tSobre o projeto:\n"
    "\tSIG-Custumer: Um sistema de controle de cliente\n"
    "As empresas da atualidade utilizam complexos sistemas gerenciais para, "
    "entre várias outras funções, gerenciar e manter seus clientes, "
    "além de ajudar a conseguir novos clientes. "
    "O presente projeto tem como objetivo propor um software que implementa "
    "funcionalidades básicas relacionadas ao controle de clientes de uma empresa, "
    "facilitando a gestão\n"
    "\n\n"

    "\t\tDiscente/Autor do Projeto:\n"
    "Victor Ryan Galvão Silva\n"
    "matrícula:20220035163\n"
    "email:\n"
    "vitorsilva3612@gmail.com\n"
    "ryan.silva.706@ufrn.edu.br\n"
    "\n"
    );
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
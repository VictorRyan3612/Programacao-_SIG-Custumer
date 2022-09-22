#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


int menu_sobre(void){
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



int menu_principal(void){
    setlocale (LC_ALL, "portuguese");
    printf("\n"
    "\t\t==============================\n"
    "\t\tPrograma Controle de Clientes\n"
    "\t\t==============================\n"
    "\t\t1 - Módulo Usuário\n"
    "\t\t2 - Módulo Redes Sociais\n"
    "\t\t3 - Módulo Interesses\n"
    "\t\t4 - Sobre e equipe\n"
    "\t\t0 - Encerrar\n"
    "\n"
    );
    
    return 0;
}

int menu_usuario(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");

        printf("\n"
        "\t==============================\n"
        "\tMenu Controle de Usuário\n"
        "\t==============================\n"
        "\t1 - Cadastrar usuário\n"
        "\t2 - Exibir lista de usuários\n"
        "\t3 - Procurar usuário\n"
        "\t4 - Editar usuário\n"
        "\t5 - Excluir usuário\n"
        "\t0 - Sair\n"
        );
        return 0;
}

int menu_redeSocial(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");

        printf("\n"
        "\t==============================\n"
        "\tMenu Controle de rede social\n"
        "\t==============================\n"
        "\t1 - Cadastrar rede social\n"
        "\t2 - Exibir lista de rede social\n"
        "\t3 - Procurar rede social\n"
        "\t4 - Editar rede social\n"
        "\t5 - Excluir rede social\n"
        "\t0 - Sair\n"
        );
        return 0;
}

int menu_interesse(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");

        printf("\n"
        "\t==============================\n"
        "\tMenu Controle de Interesses\n"
        "\t==============================\n"
        "\t1 - Cadastrar Interesses\n"
        "\t2 - Exibir lista de Interesses\n"
        "\t3 - Procurar Interesse\n"
        "\t4 - Editar Interesse\n"
        "\t5 - Excluir Interesse\n"
        "\t0 - Sair\n"
        );
        return 0;
}

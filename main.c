#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Para explicações sobre o código, por favor verificar o arquivo
// detalhes.md


// Assinatura das funções:
int menu_principal();
int menu_clientes();
int menu_sobre();


int main() {
    setlocale (LC_ALL, "portuguese");

    char opcao = '\0';
    while (opcao != '0'){
        system("cls||clear");
        menu_principal();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao == '1'){
            menu_clientes();
        }
        if (opcao == '4'){
            menu_sobre();
        }
        printf("Aperte enter para continuar\n");
        getchar();
    }
    
    return 0;
}
int menu_principal(){
    setlocale (LC_ALL, "portuguese");
    printf("\n"
    "\t\t==============================\n"
    "\t\tPrograma Controle de Clientes\n"
    "\t\t==============================\n"
    "\t\t1 - Módulo clientes\n"
    "\t\t2 - Módulo em desenvolvimento\n"
    "\t\t3 - Módulo em desenvolvimento\n"
    "\t\t4 - Sobre e equipe\n"
    "\t\t0 - Encerrar\n"
    "\n"
    );
    
    return 0;
}

int menu_clientes(){
    system("cls||clear");
    setlocale (LC_ALL, "portuguese");

    printf("\n"
    "\t==============================\n"
    "\t\tMenu controle de clientes\n"
    "\t==============================\n"
    "\t1 - Cadastrar cliente\n"
    "\t2 - Exibir lista de cliente\n"
    "\t3 - Procurar cliente\n"
    "\t4 - Editar cliente\n"
    "\t5 - Excluir cliente\n"
    "\t0 - Sair\n"
    );

    printf("\n\nApenas o menu, sem funcionalidades ainda\n\n");


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
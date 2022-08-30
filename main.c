#include <stdio.h>
#include <locale.h>

// Para explicações sobre o código, por favor verificar o arquivo
// detalhes.md


int main() {
    setlocale (LC_ALL, "portuguese");

    menu_Principal();

    int opcao = 0;
    printf("Digite uma opção (por favor, digite um número):\n");
    scanf("%d", &opcao);

    while (opcao != 0){
        if (opcao == 4){
            menu_Sobre();
        }
        else{
            printf("Opção não dessenvolvida\n");
        }
        printf("\n\nDigite uma opção (por favor, digite um número):\n");
        scanf("%d", &opcao);
    }
    
    return 0;
}


int menu_Principal(){
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

int menu_Sobre(){
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

    printf("Aperte enter para continuar\n");
    getch(); // Aperte enter para continuar
    return 0;
}
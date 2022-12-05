#include <stdio.h>
#include <stdlib.h>


#include "funcoes_aux.h"
#include "modulo_usuario.h"
#include "modulo_redeSocial.h"
#include "modulo_midia.h"


void menu_relatorio(void);

void modulo_relatorio(){
    char opcao = '\0';

    do{
        system("cls||clear");
        menu_relatorio();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                printf("");
            }
            else {
                printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        else{
            printf("Voltando ao menu principal...\n");
        }
        
    } while (opcao != '0');

}
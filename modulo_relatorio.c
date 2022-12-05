#include <stdio.h>
#include <stdlib.h>


#include "funcoes_aux.h"
#include "modulo_usuario.h"
#include "modulo_redeSocial.h"
#include "modulo_midia.h"


void menu_relatorio(void);

void usuario_listar(void);






void modulo_relatorio(){
    char opcao = '\0';

    do{
        system("cls||clear");
        menu_relatorio();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                usuario_listar();
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

void usuario_listar(void){
    system("cls||clear");

    FILE* fp;
    Usuario* fulano_aqr;
    fulano_aqr = (Usuario*) malloc(sizeof(Usuario));

    int i;

    usuario_arq();

    printf(""
    "=================================\n"
    "======  Lista de Usuários  ======\n"
    "=================================\n"
    ""); 
    fp = fopen("arq_usuarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    i = 1;
    while(fread(fulano_aqr, sizeof(Usuario), 1, fp)) {
        if (fulano_aqr->status != 'x') {
            printf("\n= = = Usuario nº %d = = =\n",i);
            usuario_exibe(fulano_aqr);
            i+=1;
        }
    }

    fclose(fp);
    free(fulano_aqr);
}
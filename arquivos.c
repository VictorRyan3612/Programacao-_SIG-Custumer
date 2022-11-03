#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes_aux.h"

typedef struct usuario Usuario;

struct usuario {
    char nome[81];
    char cpf[13];
    char email[51];
    char telefone[15];
    char status;

};

void menuprincipal(void);
int main(void);
Usuario* preencheUsuario(void);
void gravaUsuario(Usuario*);



int main(void){
    system("cls||clear");
    Usuario* fulano;
    char opcao = '\0';

    do{
        menuprincipal();

        printf("Digite uma opção:\n");
        opcao = opcoes_pergunta();

        if (opcao == '1'){
            fulano = preencheUsuario();
            gravaUsuario(fulano);
            free(fulano);
        }
        else if (opcao == '2'){
            printf("\n");
        }
        else {
            printf("Opção não dessenvolvida ou inválida\n");
        }

        if (opcao == '0'){
            printf("Saindo do programa...\n");
        }

        printf("Aperte enter para continuar\n\n");
        getchar();
    }while (opcao != '0');
    return 0;
}

void menuprincipal(){
    printf(""
    "Programa para uso de arquivo\n"
    "1: Cadastra Usuario\n"
    "2: Pesquisar Usuario\n"
    );
}
void gravaUsuario(Usuario* fulano){
    printf("\n");
}

Usuario* preencheUsuario(void){
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));

    printf("Informe o nome do usuario:\n");
    scanf(" %81[^\n]", fulano->nome);
    printf("Informe o cpf do usuario:\n");
    scanf(" %13[^\n]", fulano->cpf);
    printf("Informe o email do usuario:\n");
    scanf(" %51[^\n]", fulano->email);
    printf("Informe o telefone do usuario:\n");
    scanf(" %15[^\n]", fulano->telefone);
    fulano->status = 'c';


    free(fulano);
    return fulano;
}
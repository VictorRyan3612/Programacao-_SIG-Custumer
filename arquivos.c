#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes_aux.h"

typedef struct usuario Usuario;

struct usuario {
    char nome[81];
    char cpf[51];
    char email[41];
    char telefone[21];

};

void menuprincipal(void);
int main(void);
Usuario* preencheUsuario(void);
void gravaUsuario(Usuario*);



int main(void){
    Usuario* fulano;
    char op;

    do{
        menuprincipal();

        printf("Digite uma opção:\n");
        op = opcoes_pergunta();
        
        if (op == '1'){
            fulano = preencheUsuario();
            gravaUsuario(fulano);
            free(fulano);
        }
        else if(op == '2'){
            printf("\n");
        }
    }
    while (op != '0');
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

    printf("\n");

    free(fulano);
    return fulano;
}
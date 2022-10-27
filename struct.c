#include <stdio.h>

struct usuario {
 char nome[81];
 char cpf[51];
 char email[41];
 char telefone[21];
};


int main(void){
    system("cls||clear");

    struct usuario fulano;
    printf("Programa Cadastro de usuarios\n\n");
    printf("Informe o nome do usuario: ");
    scanf(" %80[^\n]", fulano.nome);
    printf("Informe o cpf do usuario: ");
    scanf(" %50[^\n]", fulano.cpf);
    printf("Informe o e-mail do usuario: ");
    scanf(" %40[^\n]", fulano.email);
    printf("Informe o telefone do usuario: ");
    scanf(" %20[^\n]", fulano.telefone);



    printf("\n= = = usuario Cadastrado = = =\n");
    printf("Nome do usuario: %s\n", fulano.nome);
    printf("cpf: %s\n", fulano.cpf);
    printf("Ender eletrônico: %s\n", fulano.email);
    printf("telefone usuario SIGAA: %s\n", fulano.telefone);
    return 0;
}
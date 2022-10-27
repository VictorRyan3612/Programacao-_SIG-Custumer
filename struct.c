#include <stdio.h>
#include <stdlib.h>

int main(void){
    system("cls||clear");
    char nome[20];
    char cpf[20];
    char email[20];
    char telefone[20];

    printf("Programa Cadastro de usuarios\n\n");
    printf("Informe o nome do usuario: ");
    scanf(" %80[^\n]", nome);
    printf("Informe o cpf do usuario: ");
    scanf(" %50[^\n]", cpf);
    printf("Informe o e-mail do usuario: ");
    scanf(" %40[^\n]", email);
    printf("Informe o telefone do usuario: ");
    scanf(" %20[^\n]", telefone);



    printf("\n= = = usuario Cadastrado = = =\n");
    printf("Nome do usuario: %s\n", nome);
    printf("cpf: %s\n", cpf);
    printf("Ender eletrônico: %s\n", email);
    printf("telefone usuario SIGAA: %s\n", telefone);
    return 0;
}
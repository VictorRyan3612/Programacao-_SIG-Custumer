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
void gravaUsuario(Usuario* fulano);
Usuario* buscaUsuario(void);



int main(void){
    Usuario* fulano;
    char opcao = '\0';

    do{
        system("cls||clear");
        menuprincipal();
        printf("\n\n");

        printf("Digite uma opção:\n");
        opcao = opcoes_pergunta();

        if (opcao == '1'){
            fulano = preencheUsuario();
            gravaUsuario(fulano);
            free(fulano);
        }
        else if (opcao == '2'){
            buscaUsuario();
        }

        else if (opcao == '0'){
            printf("Saindo do programa...\n");
        }
        else {
            printf("Opção não dessenvolvida ou inválida\n");
        }

        enter();
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
    fulano->status = 'c'; // cadastreado


    free(fulano);
    return fulano;
}


void gravaUsuario(Usuario* fulano){
  FILE* fp;
  fp = fopen("usuario.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(fulano, sizeof(Usuario), 1, fp);
  fclose(fp);
}


// adaptado de flavius Gorgonio, professor de Programação da UFRN Caicó, link:
//https://replit.com/@flaviusgorgonio/AplicacaoComStructEArquivoBinarioc?v=1#main.c

Usuario* buscaUsuario(void){
    FILE* fp;
    Usuario* fulano;
    int cpf_busca;

    printf("\n = Busca usuario = \n"); 
    printf("Informe o CPF:\n"); 
    scanf("%d", &cpf_busca);
    fulano = (Usuario*) malloc(sizeof(Usuario));
    fp = fopen("usuarios.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
    }

    while(!feof(fp)) {
    fread(fulano, sizeof(Usuario), 1, fp);
    if ((fulano->cpf == cpf_busca) && (fulano->status != 'x')) {
        fclose(fp);
        return fulano;
    }
    }
    fclose(fp);
    return NULL;
    }
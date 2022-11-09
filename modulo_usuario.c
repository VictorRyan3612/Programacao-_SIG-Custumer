#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_usuario.h"
#include "funcoes_aux.h"

typedef struct usuario Usuario;

#define True 1
#define False 0

// Assinatura das funções:
int menu_usuario(void);
void menu_usuario_editar(void);
void menu_usuario_excluir(void);
int confirmacao(void);

void usuario_cadastro(void);
void usuario_grava(Usuario* fulano);
Usuario* usuario_busca(void);
void usuario_exibe(Usuario* fulano);
void usuario_listar(void);
void usuario_pesquisar(void);
void usuario_editar(void);
void usuario_excluir(void);






int modulo_usuario(void){
    
    char opcao = '\0';

    do{
        menu_usuario();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                usuario_cadastro();
            }
            else if (opcao == '2'){
                usuario_listar();
            }
            else if (opcao == '3'){
                usuario_pesquisar();
            }
            else if (opcao == '4'){
                usuario_editar();
            }
            else if (opcao == '5'){
                usuario_excluir();
            }
            
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        
        if (opcao == '0'){
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');
    return 0;
}



void usuario_cadastro(void){
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));

    int resp;
    int valido;

    system("cls||clear");
    printf("\n");

    //nome
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu nome:       ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%20[^\n]", fulano -> nome);
        getchar();

        resp = validar_nome(fulano -> nome);
        if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);


    // CPF
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu cpf:        ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%s", fulano -> cpf);
        getchar();
        
        resp = validar_num(fulano -> cpf);
        valido = validar_cpf(fulano -> cpf);
        if (resp != True){
            printf("Caractere inválido detectado, digite novamente:\n");
            }
        if (valido != True){
            printf("CPF inválido, digite novamente:\n");
        }
    } while ((resp != True) || (valido != True));


    //email
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu email:      ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%s", fulano -> email);
        getchar();
        
        resp = validar_email(fulano -> email);
        if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
    } while (resp != True);



    //telefone
    do {
        printf(""
            "=======================================\n"
            "====     Informe seu telefone:     ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%s", fulano -> telefone);
        getchar();

        resp = validar_telefone(fulano -> telefone);
        if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
    } while (resp != True);
    fulano -> status = 'c';
    usuario_grava(fulano);
}

void usuario_grava(Usuario* fulano){
  FILE* fp;
  fp = fopen("usuarios.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(fulano, sizeof(Usuario), 1, fp);
  fclose(fp);
}



Usuario* usuario_busca(void){
    FILE* fp;
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();

    fp = fopen("usuarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    while(!feof(fp)) {
        fread(fulano, sizeof(Usuario), 1, fp);
        if ((strcmp(fulano->cpf, cpf_busca_dig) == 0) && (fulano->status != 'x')){
            fclose(fp);
            return fulano;
        }
    }
    free(cpf_busca_dig);
    fclose(fp);
    return NULL;
    }

void usuario_exibe(Usuario* fulano){
    printf("\n");
    
    char situacao[20];

    if ((fulano == NULL) || (fulano->status == 'x')) {
        printf("\n= = = Usuario Inexistente = = =\n");
    } 
    else {
        printf("CPF: %s\n", fulano->cpf);
        printf("Nome do Usuario: %s\n", fulano->nome);
        printf("Endereço eletrônico: %s\n", fulano->email);
        printf("Telefone do usuario: %s\n", fulano->telefone);
        if (fulano->status == 'c') {
            strcpy(situacao, "Cadastrado");
        } 
        else if (fulano->status == 's') {
            strcpy(situacao, "Suspenso");
        } 
        else {
            strcpy(situacao, "Não informada");
        }
        printf("Situação do Usuario: %s\n", situacao);
    }

}

void usuario_listar(void){
    system("cls||clear");

    FILE* fp;
    Usuario* fulano_aqr;
    fulano_aqr = (Usuario*) malloc(sizeof(Usuario));

    int i;
    printf(""
    "=================================\n"
    "======  Lista de Usuários  ======\n"
    "=================================\n"
    ""); 
    fp = fopen("usuarios.dat", "rb");
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

void usuario_pesquisar(){
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));
    fulano = usuario_busca();
    usuario_exibe(fulano);
    enter();
}

void usuario_editar(){
    printf("\n");

    // char opcao;
    // int resp;
    
    // menu_usuario_editar();

    // printf("\n\n");
    // printf("Suas informações atualmente cadastradas são:\n");
    // usuario_vizualizar(fulano);

    // opcao = opcoes_pergunta();

    // // Editar nome
    // if (opcao == '1'){
    //     printf("Seu atual nome é esse:\n");
    //     printf("%s", fulano -> nome);
    //     printf("\n\n");
    //     do{
    //         printf(""
    //             "=======================================\n"
    //             "====      Informe o atualizado:    ====\n"
    //             "=======================================\n"
    //         );
    //         printf("\n");
    //         scanf("%20[^\n]", fulano -> nome);
    //         getchar();

    //         resp = validar_nome(fulano -> nome);
    //         if (resp != True){
    //             printf("Caractere inválido detectado, Digite novamente:\n");
    //         }
    //     } while (resp != True);
    // }
    // // Editar email
    // else if (opcao == '2'){
    //     printf("Seu atual email é esse:\n");
    //     printf("%s", fulano -> email);
    //     printf("\n\n");
    //     do{
    //         printf(""
    //             "=======================================\n"
    //             "====      Informe o atualizado:    ====\n"
    //             "=======================================\n"
    //         );
    //         printf("\n");
    //         scanf("%s", fulano -> email);
    //         getchar();
            
    //         resp = validar_email(fulano -> email);
    //         if (resp != True){
    //             printf("Caractere inválido detectado, Digite novamente:\n");
    //         }
    //     } while (resp != True);
    // }

        
    // // Editar telefone
    // else if (opcao == '3'){
    //     printf("Seu atual telefone é esse:\n");
    //     printf("%s", fulano -> telefone);
    //     printf("\n\n");
    //     do{
    //         printf(""
    //             "=======================================\n"
    //             "====      Informe o atualizado:    ====\n"
    //             "=======================================\n"
    //         );
    //         printf("\n");
    //         scanf("%s", fulano -> telefone);
    //         getchar();

    //         resp = validar_telefone(fulano -> telefone);
    //         if (resp != True){
    //             printf("Caractere inválido detectado, Digite novamente:\n");
    //         }
    //     } while (resp != True);
    // }
}

void usuario_excluir(void){
    printf("\n");
    // char conf;
    
    // FILE* fp;
    // Usuario* fulano_arq;
    // fulano_arq = (Usuario*) malloc(sizeof(Usuario));
    
    // char cpf_busca[13];
    // int achou = 0;

    // printf("Digite o cpf a buscar\n");
    // scanf("%s",cpf_busca);
    // getchar();

    // if (fulano_arq == NULL) {
    //     printf("Ops! O aluno informado não existe!\n");
    // }
    // else {
    //     fp = fopen("usuarios.dat", "r+b");
    //     if (fp == NULL) {
    //         printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    //         printf("Não é possível continuar este programa...\n");
    //         exit(1);
    //     }
    //     while(!feof(fp)) {
    //         fread(fulano_arq, sizeof(Usuario), 1, fp);
    //         if ((strcmp(fulano_arq->cpf, cpf_busca) == 0) && (fulano_arq->status != 'x')){
    //             achou = 1;

    //             conf =confirmacao();
    //             if (conf == True){
    //                 fulano_arq->status = 'x';
    //                 fseek(fp, -1*sizeof(Usuario), SEEK_CUR);
    //                 fwrite(fulano_arq, sizeof(Usuario), 1, fp);
    //                 printf("\nUsuario excluído com sucesso!\n");
    //             }

    //             else{
    //                 printf("Exclusão cancelada\n");
    //             }
    //         }
    //     }
    //     if (!achou) {
    //         printf("\nUsuario não encontrado!\n");
    //     }
    //     fclose(fp);
    //     free(fulano_arq);
    // }
}

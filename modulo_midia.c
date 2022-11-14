#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_usuario.h"
#include "modulo_midia.h"
#include "funcoes_aux.h"

#define True 1
#define False 0

typedef struct midia Midia;

///// Assinatura das funções:

char opcoes_pergunta(void);
int menu_midia(void);
void menu_midia_cadastro(void);
void menu_midia_editar(void);
void menu_midia_excluir(void);

void midia_cadastro(void);
void midia_vizualizar(void);
void midia_pesquisar(void);
void midia_editar(void);
void midia_excluir(void);

void midia_exibe(Midia* fulano);
void midia_listar(void);
Midia* midia_busca(void);


void modulo_midia(){

    
    char opcao = '\0';


    do{
        menu_midia();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                midia_cadastro();
            }
            else if (opcao == '2'){
                midia_listar();
            }
            else if (opcao == '3'){
                midia_pesquisar();
            }
            else if (opcao == '4'){
                midia_editar();
            }
            else if (opcao == '5'){
                midia_excluir();
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

}


void midia_cadastro(){

    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));

    Usuario* fulano_user;
    fulano_user = (Usuario*) malloc(sizeof(Usuario));

    int resp;
    int achou;
    char cpf_busca_dig[13];
    char confir;
    

    do{
        fulano_user = usuario_busca();
        if (fulano != NULL){
            achou = True;
        }
        else{
            printf("Não encontrado, Digite novamente\n");
        }
    }while(achou == False);


    strcpy(fulano -> cpf, fulano_user -> cpf);
    strcpy(cpf_busca_dig, fulano -> cpf);
    

    system("cls||clear");
    menu_midia_cadastro();



    //Jogo
    printf("Deseja Cadastrar um Jogo?\n");
    confir = confirmacao();
    if (confir == True){
        do {
            printf(""
                "=======================================\n"
                "====  Qual jogo está interessado?  ====\n"
                "=======================================\n"
                );
            printf("(use ; para mais de um)\n");
            printf("\n");
            scanf("%61[^\n]", fulano -> jogo);
            getchar();

            resp = validar_nomeMidia(fulano -> jogo);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }


    //Livro
    printf("Deseja Cadastrar um livro?\n");
    confir = confirmacao();
    if (confir == True){
        do {
            printf(""
                "=======================================\n"
                "====  Qual livro está interessado? ====\n"
                "=======================================\n"
                );
            printf("use ; para mais de um\n");
            printf("\n");
            scanf("%51[^\n]", fulano -> livro);
            getchar();

            resp = validar_nomeMidia(fulano -> livro);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }


    //Filme
    printf("Deseja Cadastrar uma filme?\n");
    confir = confirmacao();
    if (confir == True){
        do{
            printf(""
                "=======================================\n"
                "====  Qual Filme está interessado? ====\n"
                "=======================================\n"
                );
            printf("use ; para mais de um\n");
            printf("\n");
            scanf("%41[^\n]", fulano -> filme);
            getchar();

            resp = validar_nomeMidia(fulano -> filme);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }

    printf("Voltando ao menu principal...\n");
    getchar();

    fulano -> status = 'c'; //cadastrado

    midia_gravar(fulano);
    free(fulano);
}

void midia_gravar(Midia* fulano){
    FILE* fp;
    fp = fopen("Midias.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    fwrite(fulano, sizeof(Midia), 1, fp);
    fclose(fp);
}

void midia_exibe(Midia* fulano){
    printf("\n");

    char situacao[20];
    char status;

    if ((fulano == NULL) || (fulano->status == 'x')){
        printf("\n= = = Usuario Inexistente = = =\n");
    }
    else {
        printf("CPF do usuario: %s\n", fulano -> cpf);
        printf("Jogos do usuario: %s\n", fulano -> jogo);
        printf("Livros do Usuario: %s\n", fulano -> livro);
        printf("Filmes do usuario: %s\n", fulano -> filme);

        status = fulano->status;
        strcpy(situacao,status_exibe(status,situacao));
        printf("Situação das Midias: %s\n", situacao);

        enter();
    }
}


void midia_listar(void){
    system("cls||clear");

    FILE* fp;
    Midia* fulano_aqr;
    fulano_aqr = (Midia*) malloc(sizeof(Midia));

    int i;

    printf(""
        "=================================\n"
        "======   Lista de Midias   ======\n"
        "=================================\n"
    "");
    fp = fopen("Midias.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    i = 1;
    while(fread(fulano_aqr, sizeof(Midia), 1, fp)) {
        if (fulano_aqr->status != 'x') {
            printf("\n= = = Midias nº %d = = =\n",i);
            midia_exibe(fulano_aqr);
            i+=1;
        }
    }

    fclose(fp);
    free(fulano_aqr);
}


Midia* midia_busca(void){
    FILE* fp;
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));


    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();

    fp = fopen("Midias.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    while(!feof(fp)) {
        fread(fulano, sizeof(Midia), 1, fp);
        if ((strcmp(fulano->cpf, cpf_busca_dig) == 0) && (fulano->status != 'x')){
            fclose(fp);
            return fulano;
        }
    }
    free(cpf_busca_dig);
    fclose(fp);
    return NULL;
}


void midia_pesquisar(){
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));
    fulano = midia_busca();
    midia_exibe(fulano);
    enter();
}

void midia_editar(){
    system("cls||clear");

    FILE* fp;
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));

    char resp;
    int certeza;
    char continuar;
    char opcao;
    int achou = False;

    
    fp = fopen("Midias.dat", "r+b");

    if(fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    menu_midia_editar();


    do{
        fulano = midia_busca();
        if (fulano != NULL){
            achou = True;
        }
        else{
            printf("Não encontrado, Digite novamente\n");
        }
    }while(achou == False);


    do{
        system("cls||clear");
        menu_redeSocial_editar();
        redeSocial_exibe(fulano);

        printf("\n\n");
        printf("Digite qual campo deseja editar\n");
        opcao = opcoes_pergunta();

        if (opcao == '1'){
            printf("Seus atuais jogos são esses:\n");
            printf("%s", fulano -> jogo);
            printf("\n\n");

            printf("Deseja realmente editar?\n");
            certeza = confirmacao();
        }











    
    // // Editar Jogo
    // if (opcao == '1'){
    //     printf("Seu atual interesse em jogo é:\n");
    //     printf("%s", fulano -> jogo);
    //     printf("\n\n");
    //     do{
    //         printf(""
    //             "=======================================\n"
    //             "====        Atualize a lista       ====\n"
    //             "=======================================\n"
    //         );
    //         printf("\n");
    //         scanf("%20[^\n]", fulano -> jogo);
    //         getchar();

    //         resp = validar_nomeMidia(fulano -> jogo);
    //         if (resp != True){
    //             printf("Caractere inválido detectado, Digite novamente:\n");
    //         }
    //     } while (resp != True);
    // }
    
    // // Editar livro
    // else if (opcao == '2'){
    //     printf("Seu atual interesse em livro é:\n");
    //     printf("%s", fulano -> livro);
    //     printf("\n\n");
    //     do{
    //         printf(""
    //             "=======================================\n"
    //             "====        Atualize a lista       ====\n"
    //             "=======================================\n"
    //         );
    //         printf("\n");
    //         scanf("%20[^\n]", fulano -> livro);
    //         getchar();

    //         resp = validar_nomeMidia(fulano -> livro);
    //         if (resp != True){
    //             printf("Caractere inválido detectado, Digite novamente:\n");
    //         }
    //     } while (resp != True);
    // }

        
    // // Editar filme
    // else if (opcao == '3'){


    //     printf("Seu atual interesse em filme é:\n");
    //     printf("%s", fulano -> filme);
    //     printf("\n\n");
    //     do{
    //         printf(""
    //             "=======================================\n"
    //             "====        Atualize a lista       ====\n"
    //             "=======================================\n"
    //         );
    //         printf("\n");
    //         scanf("%20[^\n]", fulano -> filme);
    //         getchar();

    //         resp = validar_nomeMidia(fulano -> filme);
    //         if (resp != True){
    //             printf("Caractere inválido detectado, Digite novamente:\n");
    //         }
    //     } while (resp != True);
    // }
    // else{
    //     printf("Opção não dessenvolvida ou inválida\n");
    // }


}

void midia_excluir(){
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));

    // char opcao;
    // int resp;

    // menu_midia_excluir();

    // printf("\n\n");
    // printf("Suas informações atualmente cadastradas são:\n");
    // midia_vizualizar();

    // printf("Digite qual deseja:\n");
    // opcao = opcoes_pergunta();

    // resp = confirmacao();
    // if (resp == True){
    //     if (opcao == '1'){
    //         printf("Exluindo seu interesse em jogo\n");
    //         strcpy(fulano -> jogo, "");
    //         printf("Exluído com sucesso\n");

    //     }

    //     else if (opcao == '2'){
    //         printf("Exluindo seu livro interessado\n");
    //         strcpy(fulano -> livro, "");
    //         printf("Exluído com sucesso\n");

    //     }

    //     else if (opcao == '3'){
    //         printf("Exluindo seu filme interessado\n");
    //         strcpy(fulano -> filme, "");
    //         printf("Exluído com sucesso\n");
            
    //     }
    // }
}
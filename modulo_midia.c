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
void midia_pesquisar(void);
void midia_editar(void);
void midia_excluir(void);

void midia_exibe(Midia* fulano);
void midia_listar(void);
Midia* midia_busca(void);


int midia_existente(char fulano_cpf[12]);

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
    int achou_user;
    int achou_midia;
    char cpf_busca_dig[12];
    char confir;
    

    do{
        do{
            fulano_user = usuario_busca();
            if (fulano_user != NULL){
                achou_user = True;
            }
            else{
                printf("Não encontrado, Digite novamente\n");
                achou_user = False;
            }
        } while(achou_user == False);


        strcpy(fulano -> cpf, fulano_user -> cpf);
        strcpy(cpf_busca_dig, fulano -> cpf);
        
        strcpy(cpf_busca_dig,fulano -> cpf);
        achou_midia = midia_existente(cpf_busca_dig);

        if (achou_midia == True){
            printf("Midias já cadastradas para esse usuário, digite outro\n");
        }
    } while(achou_midia == True);


    system("cls||clear");
    menu_midia_cadastro();



    //Jogo
    printf("\n\nDeseja Cadastrar um Jogo?\n");
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
    printf("\n\nDeseja Cadastrar um livro?\n");
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
    printf("\n\nDeseja Cadastrar uma filme?\n");
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

int midia_existente(char fulano_cpf[12]){
    int achou;
    FILE* fp;

    Midia* fulano_aqr;
    fulano_aqr = (Midia*) malloc(sizeof(Midia));

    midia_arq();

    fp = fopen("arq_midias.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    while(!feof(fp)) {
        fread(fulano_aqr, sizeof(Midia), 1, fp);
            if ((strcmp(fulano_aqr->cpf, fulano_cpf) == 0) && (fulano_aqr->status != 'x')){
                fclose(fp);
                return achou = True;;
            }
        }

    fclose(fp);
    return achou = False;
}


void midia_arq(void){
    FILE* fp;
    fp = fopen("arq_midias.dat", "ab");
    fclose(fp);
}

void midia_gravar(Midia* fulano){
    FILE* fp;
    fp = fopen("arq_midias.dat", "ab");
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
    char vizualidar_midia[81];

    if ((fulano == NULL) || (fulano->status == 'x')){
        printf("\n= = = Usuario Inexistente = = =\n");
    }
    else {
        printf("CPF do usuario: %s\n", fulano -> cpf);


        printf("\n\n");
        printf("Jogos do usuario:\n");
        strcpy(vizualidar_midia , fulano -> jogo);
        vizualizar_lista(vizualidar_midia);


        printf("\n\n\n");
        printf("Livros do Usuario:\n");
        strcpy(vizualidar_midia , fulano -> livro);
        vizualizar_lista(vizualidar_midia);


        printf("\n\n\n");
        printf("Filmes do usuario:\n");
        strcpy(vizualidar_midia , fulano -> filme);
        vizualizar_lista(vizualidar_midia);


        printf("\n\n\n");
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

    midia_arq();

    printf(""
        "=================================\n"
        "======   Lista de Midias   ======\n"
        "=================================\n"
    "");
    fp = fopen("arq_midias.dat", "rb");
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

    midia_arq();
    
    fp = fopen("arq_midias.dat", "rb");
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

    
    midia_arq();
    
    fp = fopen("arq_midias.dat", "r+b");

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
        menu_midia_editar();
        midia_exibe(fulano);

        printf("\n\n");
        printf("Digite qual campo deseja editar\n");
        opcao = opcoes_pergunta();

        if (opcao == '1'){
            printf("Seus atuais jogos são esses:\n");
            printf("%s", fulano -> jogo);
            printf("\n\n");

            printf("Deseja realmente editar?\n");
            certeza = confirmacao();

            if (certeza == True){
                do{
                    printf(""
                        "=======================================\n"
                        "====        Atualize a lista       ====\n"
                        "=======================================\n"
                    );
                    printf("\n");
                    scanf("%s", fulano -> jogo);
                    getchar();
                    resp = validar_nomeMidia(fulano -> jogo);
                    if (resp != True){
                        printf("Caractere inválido detectado, Digite novamente:\n");
                    }
                } while (resp != True);
            }

        }

        //Livros
        if (opcao == '2'){
            printf("Seus atuais Livros são esses:\n");
            printf("%s", fulano -> livro);
            printf("\n\n");

            printf("Deseja realmente editar?\n");
            certeza = confirmacao();
            if (certeza == True){
                do{
                    printf(""
                        "=======================================\n"
                        "====        Atualize a lista       ====\n"
                        "=======================================\n"
                    );
                    printf("\n");
                    scanf("%s", fulano -> livro);
                    getchar();

                    resp = validar_nomeMidia(fulano -> livro);
                    if (resp != True){
                        printf("Caractere inválido detectado, Digite novamente:\n");
                    }
                } while (resp != True);
            }
        }

        // Filmes
        else if (opcao =='3'){
            printf("Seu atual nome é esse:\n");
            printf("%s", fulano -> filme);
            printf("\n\n");
            
            printf("Deseja realmente editar?\n");
            certeza = confirmacao();

            if (certeza == True){
                do{
                    printf(""
                        "=======================================\n"
                        "====        Atualize a lista       ====\n"
                        "=======================================\n"
                    );
                    printf("\n");
                    scanf("%s", fulano -> filme);
                    getchar();

                    resp = validar_nomeMidia(fulano -> filme);
                    if (resp != True){
                        printf("Caractere inválido detectado, Digite novamente:\n");
                    }
                } while (resp != True);
            }
        }

        else if (opcao == '0'){
            printf("Voltando ao menu principal...\n");
            getchar();
            continuar = False;
        }
        else{
            printf("Opção não dessenvolvida ou inválida\n");
        }
        if (opcao!='0'){
            printf("\nDeseja continuar?");
            continuar = confirmacao();
        }


    }while(continuar == True);

    int var = -1;
    fseek(fp, var*sizeof(Usuario), SEEK_CUR);
    fwrite(fulano, sizeof(Usuario), 1, fp);

    free(fulano);
    fclose(fp);
}

void midia_excluir(){
    system("cls||clear");

    FILE* fp;
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));


    int certeza;
    int achou = False;
    int var;

    midia_arq();

    fp = fopen("arq_midias.dat", "r+b");

    if(fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }


    menu_midia_excluir();


    do{
        fulano = midia_busca();
        if (fulano != NULL){
            achou = True;
        }
        else{
            printf("Não encontrado, Digite novamente\n");
        }
    }while(achou == False);

    midia_exibe(fulano);
    printf("\n\n\n");
    printf("Deseja realmente apagar este usuario?");
    certeza = confirmacao();
    if (certeza == True){

        fulano->status = 'x';
        var = -1;
        fseek(fp, var*sizeof(Midia), SEEK_CUR);
        fwrite(fulano, sizeof(Midia), 1, fp);
        printf("\nUsuario excluído com sucesso!!!\n");
    }
    else{
        printf("\nOk, os dados não foram alterados\n");
    }

  free(fulano);
  fclose(fp);
}
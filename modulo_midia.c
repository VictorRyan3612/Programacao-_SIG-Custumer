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
void rel_listar_midia(void);
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
                rel_listar_midia();
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
            
        
        else{
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');

}


void midia_cadastro(){
    FILE* fp_user;
    FILE* fp_midia;


    Midia* fulano_midia;
    fulano_midia = (Midia*) malloc(sizeof(Midia));

    Usuario* fulano_user;
    fulano_user = (Usuario*) malloc(sizeof(Usuario));

    int resp;
    int achou_user = False;
    int achou_midia = False;
    char confir;
    

    usuario_arq();
    midia_arq();


    fp_user = fopen("arq_usuarios.dat", "rb");
    fp_midia = fopen("arq_midias.dat", "r+b");

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();

    // Procura usuario
    while((!feof(fp_user)) && (achou_user == False)){
        fread(fulano_user, sizeof(Usuario), 1, fp_user);
        if ((strcmp(fulano_user->cpf, cpf_busca_dig) == 0) && (fulano_user->status != 'x')){
            achou_user = True;
        }
    }

    if (achou_user == False){
        printf("Usuario não encontrado\n");
    }
    else{

        // Procura Midias do usuario
        while(!feof(fp_midia) && achou_midia == False){
            fread(fulano_midia, sizeof(Midia), 1, fp_midia);
            if ((strcmp(fulano_midia->cpf, cpf_busca_dig) == 0) && (fulano_midia->status != 'x')){
                achou_midia = True;
            }
        }
    

        if (achou_midia == True){
            printf("Midias de usuario já cadastradas\n");
        }
    }
    if (achou_user == True && achou_midia == False){
        strcpy(fulano_midia -> cpf, fulano_user -> cpf);
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
                scanf("%101[^\n]", fulano_midia -> jogo);
                getchar();

                resp = validar_nomeMidia(fulano_midia -> jogo);
                if (resp != True){
                    printf("Caractere inválido detectado, Digite novamente:\n");
                }
            } while (resp != True);
        }
        else{
            strcpy(fulano_midia -> jogo,"");
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
                scanf("%101[^\n]", fulano_midia -> livro);
                getchar();

                resp = validar_nomeMidia(fulano_midia -> livro);
                if (resp != True){
                    printf("Caractere inválido detectado, Digite novamente:\n");
                }
            } while (resp != True);
        }
        else{
            strcpy(fulano_midia -> livro,"");
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
                scanf("%101[^\n]", fulano_midia -> filme);
                getchar();

                resp = validar_nomeMidia(fulano_midia -> filme);
                if (resp != True){
                    printf("Caractere inválido detectado, Digite novamente:\n");
                }
            } while (resp != True);
        }
        else{
            strcpy(fulano_midia -> filme,"");
        }


        printf("Voltando ao menu principal...\n");
        getchar();

        fulano_midia -> status = 'c'; //cadastrado
        midia_gravar(fulano_midia);
    }
    free(cpf_busca_dig);
    free(fulano_user);
    free(fulano_midia);

    fclose(fp_user);
    fclose(fp_midia);
}


void midia_arq(void){
    FILE* fp;
    fp = fopen("arq_midias.dat", "ab");
    fclose(fp);
}

void midia_gravar(Midia* fulano){
    FILE* fp;
    fp = fopen("arq_midias.dat", "ab");
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


        printf("\n");
        printf("Jogos do usuario:\n");
        strcpy(vizualidar_midia , fulano -> jogo);
        vizualizar_lista(vizualidar_midia);


        printf("\n\n");
        printf("Livros do Usuario:\n");
        strcpy(vizualidar_midia , fulano -> livro);
        vizualizar_lista(vizualidar_midia);


        printf("\n\n");
        printf("Filmes do usuario:\n");
        strcpy(vizualidar_midia , fulano -> filme);
        vizualizar_lista(vizualidar_midia);


        printf("\n\n");
        status = fulano->status;
        strcpy(situacao,status_exibe(status,situacao));
        printf("Situação das Midias: %s\n", situacao);

    }
}



Midia* midia_busca(void){
    FILE* fp;
    Midia* fulano;
    fulano = (Midia*) malloc(sizeof(Midia));


    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();

    midia_arq();
    
    fp = fopen("arq_midias.dat", "rb");
    

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

    FILE* fp_midia;
    Midia* fulano_midia;
    fulano_midia = (Midia*) malloc(sizeof(Midia));

    char resp;
    int certeza;
    char continuar;
    char opcao;
    int achou = False;

    menu_midia_editar();

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();
    
    midia_arq();
    fp_midia = fopen("arq_midias.dat", "r+b");


    while(!feof(fp_midia) && achou == False) {
        fread(fulano_midia, sizeof(Midia), 1, fp_midia);
        if ((strcmp(fulano_midia->cpf, cpf_busca_dig) == 0) && (fulano_midia->status != 'x')){
            achou = True;
        }
    }


    if (achou == False){
        printf("Mdias do usuario não concontradas\n");
    }

    else if (achou == True){

        do{
            system("cls||clear");
            menu_midia_editar();
            midia_exibe(fulano_midia);

            printf("\n\n");
            printf("Digite qual campo deseja editar\n");
            opcao = opcoes_pergunta();

            if (opcao == '1'){
                printf("#### Seus atuais jogos são esses: ####\n");
                printf("%s", fulano_midia -> jogo);
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
                        scanf("%101[^\n]", fulano_midia -> jogo);
                        getchar();
                        resp = validar_nomeMidia(fulano_midia -> jogo);
                        if (resp != True){
                            printf("Caractere inválido detectado, Digite novamente:\n");
                        }
                    } while (resp != True);
                }

            }

            //Livros
            if (opcao == '2'){
                printf("#### Seus atuais Livros são esses: ####\n");
                printf("%s", fulano_midia -> livro);
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
                        scanf("%101[^\n]", fulano_midia -> livro);
                        getchar();

                        resp = validar_nomeMidia(fulano_midia -> livro);
                        if (resp != True){
                            printf("Caractere inválido detectado, Digite novamente:\n");
                        }
                    } while (resp != True);
                }
            }

            // Filmes
            else if (opcao =='3'){
                printf("#### Seus atuais Filmes são esses: ####\n");
                printf("%s", fulano_midia -> filme);
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
                        scanf("%101[^\n]", fulano_midia -> filme);
                        getchar();

                        resp = validar_nomeMidia(fulano_midia -> filme);
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
        fseek(fp_midia, var*sizeof(Midia), SEEK_CUR);
        fwrite(fulano_midia, sizeof(Midia), 1, fp_midia);
    }

        free(cpf_busca_dig);
        free(fulano_midia);
        fclose(fp_midia);
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
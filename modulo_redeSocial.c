#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_usuario.h"
#include "modulo_redeSocial.h"
#include "funcoes_aux.h"

#define True 1
#define False 0

typedef struct redeSocial RedeSocial;

/////  Assinatura das funções:

char opcoes_pergunta(void);
int menu_redeSocial(void);
void menu_redeSocial_cadastro(void);
void menu_redeSocial_editar(void);
void menu_redeSocial_excluir(void);

void redeSocial_cadastro(void);
void redeSocial_listar(void);
RedeSocial* redeSocial_busca(void);
void redeSocial_pesquisar(void);
void redeSocial_editar(void);
void redeSocial_excluir(void);

void redeSocial_gravar(RedeSocial* fulano);
void redeSocial_exibe(RedeSocial* fulano);



void modulo_redeSocial(void){
    char opcao = '\0';

    do {
        menu_redeSocial();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                redeSocial_cadastro();
            }
            else if (opcao == '2'){
                redeSocial_listar();
            }
            else if (opcao == '3'){
                redeSocial_pesquisar();
            }
            else if (opcao == '4'){
                redeSocial_editar();
            }
            else if (opcao == '5'){
                redeSocial_excluir();
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


void redeSocial_cadastro(void){
    RedeSocial* fulano;
    fulano = (RedeSocial*) malloc(sizeof(RedeSocial));

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
    menu_redeSocial_cadastro();


    //steam
    printf("Deseja Cadastrar uma steam?\n");
    confir = confirmacao();
    if (confir == True){
        do {
            printf(""
                "=======================================\n"
                "====  Informe seu perfil da steam: ====\n"
                "=======================================\n"
                );

            printf("\n");
            scanf("%s",fulano -> steam);
            getchar();

            resp = validar_twitterSteam(fulano -> steam);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
    
    

    //twitter
    printf("Deseja Cadastrar um Twitter?\n");
    confir = confirmacao();
    if (confir == True){
    
        do {
            printf(""
                "=======================================\n"
                "====     Informe seu Twitter:      ====\n"
                "=======================================\n"
                );

            printf("\n");
            scanf("%s",fulano -> twitter);
            getchar();

            
            resp = validar_twitterSteam(fulano -> twitter);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
            
        
            } while (resp != True);
    }

    //youtube
    printf("Deseja Cadastrar um Youtube?\n");
    confir = confirmacao();
    if (confir == True){
        do {
            printf(""
                "=======================================\n"
                "====     Informe seu Youtube:      ====\n"
                "=======================================\n"
                );

            printf("\n");
            scanf("%s",fulano -> youtube);
            getchar();


            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
            
        }while (resp != True);
    }
    
    printf("Voltando ao menu principal...\n");
    getchar();

    fulano -> status = 'c'; //cadastrado

    redeSocial_gravar(fulano);
    free(fulano);
}


void redeSocial_gravar(RedeSocial* fulano){
    FILE* fp;
    fp = fopen("redesSociais.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    fwrite(fulano, sizeof(RedeSocial), 1, fp);
    fclose(fp);
}


void redeSocial_exibe(RedeSocial* fulano){
    printf("\n");

    char situacao[20];
    char status;

    if ((fulano == NULL) || (fulano->status == 'x')){
        printf("\n= = = Usuario Inexistente = = =\n");
    }
    else {
        printf("CPF do usuario: %s\n", fulano -> cpf);
        printf("Steam do usuario: %s\n", fulano -> steam);
        printf("Twitter do Usuario: %s\n", fulano -> twitter);
        printf("Youtube do usuario: %s\n", fulano -> youtube);

        status = fulano->status;
        strcpy(situacao,status_exibe(status,situacao));
        printf("Situação das Redes Sociais: %s\n", situacao);

        enter();
    }
}

void redeSocial_listar(void){
    system("cls||clear");

    FILE* fp;
    RedeSocial* fulano_aqr;
    fulano_aqr = (RedeSocial*) malloc(sizeof(RedeSocial));

    int i;

    printf(""
        "=================================\n"
        "==== Lista de Redes Sociais  ====\n"
        "=================================\n"
    "");
    fp = fopen("redesSociais.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    i = 1;
    while(fread(fulano_aqr, sizeof(RedeSocial), 1, fp)) {
        if (fulano_aqr->status != 'x') {
            printf("\n= = = Redes Sociais nº %d = = =\n",i);
            redeSocial_exibe(fulano_aqr);
            i+=1;
        }
    }

    fclose(fp);
    free(fulano_aqr);
}

RedeSocial* redeSocial_busca(void){
    FILE* fp;
    RedeSocial* fulano;
    fulano = (RedeSocial*) malloc(sizeof(RedeSocial));

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();
    
    fp = fopen("redesSociais.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    while(!feof(fp)) {
        fread(fulano, sizeof(RedeSocial), 1, fp);
        if ((strcmp(fulano->cpf, cpf_busca_dig) == 0) && (fulano->status != 'x')){
            fclose(fp);
            return fulano;
        }
    }
    free(cpf_busca_dig);
    fclose(fp);
    return NULL;
}




void redeSocial_pesquisar(void){
    RedeSocial* fulano;
    fulano = (RedeSocial*) malloc(sizeof(RedeSocial));
    fulano = redeSocial_busca();
    redeSocial_exibe(fulano);
    enter();
}

void redeSocial_editar(void){
    system("cls||clear");

    FILE* fp;
    RedeSocial* fulano;
    fulano = (RedeSocial*) malloc(sizeof(RedeSocial));

    char resp;
    int certeza;
    char continuar;
    char opcao;
    int achou = False;




    fp = fopen("redesSociais.dat", "r+b");

    if(fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    menu_redeSocial_editar();
    
    do{
        fulano = redeSocial_busca();
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

        // Steam
        if (opcao == '1'){
            printf("Seu atual perfil da steam é esse:\n");
            printf("%s", fulano -> steam);
            printf("\n\n");

            printf("Deseja realmente editar?\n");
            certeza = confirmacao();

            if (certeza == True){
                do{
                    printf(""
                        "=======================================\n"
                        "====      Informe o atualizado:    ====\n"
                        "=======================================\n"
                    );
                    printf("\n");
                    scanf("%s", fulano -> steam);
                    getchar();
                    resp = validar_twitterSteam(fulano -> steam);
                    if (resp != True){
                        printf("Caractere inválido detectado, Digite novamente:\n");
                    }
                } while (resp != True);
            }
        }

        // Twitter
        else if (opcao == '2'){
            printf("Seu atual twitter é esse:\n");
            printf("%s", fulano -> twitter);
            printf("\n\n");
            
            printf("Deseja realmente editar?\n");
            certeza = confirmacao();

            if (certeza == True){
                do{
                    printf(""
                        "=======================================\n"
                        "====      Informe o atualizado:    ====\n"
                        "=======================================\n"
                    );
                    printf("\n");
                    scanf("%s", fulano -> twitter);
                    getchar();

                    resp = validar_twitterSteam(fulano -> twitter);
                    if (resp != True){
                        printf("Caractere inválido detectado, Digite novamente:\n");
                    }
                } while (resp != True);
            }
        }

        // Youtube
        else if (opcao =='3'){
            printf("Seu atual nome é esse:\n");
            printf("%s", fulano -> youtube);
            printf("\n\n");
            
            printf("Deseja realmente editar?\n");
            certeza = confirmacao();

            if (certeza == True){
                do{
                    printf(""
                        "=======================================\n"
                        "====      Informe o atualizado:    ====\n"
                        "=======================================\n"
                    );
                    printf("\n");
                    scanf("%41[^\n]", fulano -> youtube);
                    getchar();

                    resp = validar_youtube(fulano -> youtube);
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

    } while(continuar == True);

    int var = -1;
    fseek(fp, var*sizeof(Usuario), SEEK_CUR);
    fwrite(fulano, sizeof(Usuario), 1, fp);

    free(fulano);
    fclose(fp);
}

void redeSocial_excluir(void){
    system("cls||clear");

    FILE* fp;
    RedeSocial* fulano;
    fulano = (RedeSocial*) malloc(sizeof(RedeSocial));


    int certeza;
    int achou = False;
    int var;


    fp = fopen("redesSociais.dat", "r+b");

    if(fp == NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }


    menu_redeSocial_excluir();


    do{
        fulano = redeSocial_busca();
        if (fulano != NULL){
            achou = True;
        }
        else{
            printf("Não encontrado, Digite novamente\n");
        }
    }while(achou == False);

    redeSocial_exibe(fulano);
    printf("\n\n\n");
    printf("Deseja realmente apagar este usuario?");
    certeza = confirmacao();
    if (certeza == True){

        fulano->status = 'x';
        var = -1;
        fseek(fp, var*sizeof(RedeSocial), SEEK_CUR);
        fwrite(fulano, sizeof(RedeSocial), 1, fp);
        printf("\nUsuario excluído com sucesso!!!\n");
    }
    else{
        printf("\nOk, os dados não foram alterados\n");
    }

  free(fulano);
  fclose(fp);
}

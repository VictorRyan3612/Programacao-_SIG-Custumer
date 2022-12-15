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
RedeSocial* redeSocial_busca(void);
void redeSocial_pesquisar(void);
void redeSocial_editar(void);
void redeSocial_excluir(void);

void redeSocial_gravar(RedeSocial* fulano);
void redeSocial_exibe(RedeSocial* fulano);

int redes_existente(char fulano_cpf[12]);


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
                rel_listar_redeSocial();
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
            
        
        else{
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');

}


void redeSocial_cadastro(void){
    FILE* fp_user;
    FILE* fp_rede;

    RedeSocial* fulano_rede;
    fulano_rede = (RedeSocial*) malloc(sizeof(RedeSocial));

    Usuario* fulano_user;
    fulano_user = (Usuario*) malloc(sizeof(Usuario));

    int resp;
    int achou_user = False;
    int achou_rede = False;
    char confir;

    usuario_arq();
    redeSocial_arq();
    fp_user = fopen("arq_usuarios.dat", "rb");
    fp_rede = fopen("arq_redes_Sociais.dat", "r+b");


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

        // Procura Rede social do usuario
        while(!feof(fp_rede) && achou_rede == False){
            fread(fulano_rede, sizeof(RedeSocial), 1, fp_rede);
            if ((strcmp(fulano_rede->cpf, cpf_busca_dig) == 0) && (fulano_rede->status != 'x')){
                achou_rede = True;
            }
        }

        if (achou_rede == True){
            printf("Redes sociais de usuario já cadastradas\n");
        }
    }
    if (achou_user == True && achou_rede == False){
        strcpy(fulano_rede -> cpf, fulano_user -> cpf);
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
                scanf("%21[^\n]",fulano_rede -> steam);
                getchar();

                resp = validar_twitterSteam(fulano_rede -> steam);
                if (resp != True){
                    printf("Caractere inválido detectado, Digite novamente:\n");
                }
            } while (resp != True);
        }
        else{
            strcpy(fulano_rede -> steam,"");
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
                scanf("%21[^\n]",fulano_rede -> twitter);
                getchar();

                
                resp = validar_twitterSteam(fulano_rede -> twitter);
                if (resp != True){
                    printf("Caractere inválido detectado, Digite novamente:\n");
                }
                
            
                } while (resp != True);
        }
        else{
            strcpy(fulano_rede -> twitter,"");
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
                scanf("%41[^\n]",fulano_rede -> youtube);
                getchar();


                if (resp != True){
                    printf("Caractere inválido detectado, Digite novamente:\n");
                }
                
            }while (resp != True);
        }
        else{
            strcpy(fulano_rede -> steam,"");
        }


        printf("Voltando ao menu principal...\n");
        getchar();

        fulano_rede -> status = 'c'; //cadastrado

        redeSocial_gravar(fulano_rede);
        free(cpf_busca_dig);
        free(fulano_user);
        free(fulano_rede);
        fclose(fp_user);
        fclose(fp_rede);
    }
}



void redeSocial_arq(void){
    FILE* fp;
    fp = fopen("arq_redes_Sociais.dat", "ab");
    fclose(fp);
}


void redeSocial_gravar(RedeSocial* fulano){
    FILE* fp;
    fp = fopen("arq_redes_Sociais.dat", "ab");
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

    }
}


RedeSocial* redeSocial_busca(void){
    FILE* fp;
    RedeSocial* fulano;
    fulano = (RedeSocial*) malloc(sizeof(RedeSocial));

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();
    
    redeSocial_arq();
    
    fp = fopen("arq_redes_Sociais.dat", "rb");
    

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

    FILE* fp_rede;
    RedeSocial* fulano_rede;
    fulano_rede = (RedeSocial*) malloc(sizeof(RedeSocial));

    char resp;
    int certeza;
    char continuar;
    char opcao;
    int achou = False;


    menu_redeSocial_editar();

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();
    
    redeSocial_arq();
    
    
    fp_rede = fopen("arq_redes_Sociais.dat", "r+b");
    

    while(!feof(fp_rede) && achou == False) {
        fread(fulano_rede, sizeof(RedeSocial), 1, fp_rede);
        if ((strcmp(fulano_rede->cpf, cpf_busca_dig) == 0) && (fulano_rede->status != 'x')){
            achou = True;
        }
    }


    
    if (achou == False){
        printf("Rede sociais do usuario não concontradas\n");
    }

    else if (achou == True){

        do{
            system("cls||clear");
            menu_redeSocial_editar();
            redeSocial_exibe(fulano_rede);

            printf("\n\n");
            printf("Digite qual campo deseja editar\n");
            opcao = opcoes_pergunta();

            // Steam
            if (opcao == '1'){
                printf("#### Seu atual perfil da steam é esse: ####\n");
                printf("%s", fulano_rede -> steam);
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
                        scanf("%s", fulano_rede -> steam);
                        getchar();
                        resp = validar_twitterSteam(fulano_rede -> steam);
                        if (resp != True){
                            printf("Caractere inválido detectado, Digite novamente:\n");
                        }
                    } while (resp != True);
                }
            }

            // Twitter
            else if (opcao == '2'){
                printf("#### Seu atual twitter é esse: ####\n");
                printf("%s", fulano_rede -> twitter);
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
                        scanf("%s", fulano_rede -> twitter);
                        getchar();

                        resp = validar_twitterSteam(fulano_rede -> twitter);
                        if (resp != True){
                            printf("Caractere inválido detectado, Digite novamente:\n");
                        }
                    } while (resp != True);
                }
            }

            // Youtube
            else if (opcao =='3'){
                printf("#### Seu atual nome é esse: ####\n");
                printf("%s", fulano_rede -> youtube);
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
                        scanf("%41[^\n]", fulano_rede -> youtube);
                        getchar();

                        resp = validar_youtube(fulano_rede -> youtube);
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
        fseek(fp_rede, var*sizeof(RedeSocial), SEEK_CUR);
        fwrite(fulano_rede, sizeof(RedeSocial), 1, fp_rede);

    }
    free(cpf_busca_dig);
    free(fulano_rede);
    fclose(fp_rede);
}

void redeSocial_excluir(void){
    system("cls||clear");

    FILE* fp_rede;
    RedeSocial* fulano_rede;
    fulano_rede = (RedeSocial*) malloc(sizeof(RedeSocial));


    int certeza;
    int var;
    int achou = False;


    menu_redeSocial_excluir();

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();
    
    redeSocial_arq();
    
    
    fp_rede = fopen("arq_redes_Sociais.dat", "r+b");
    

    while(!feof(fp_rede) && achou == False) {
        fread(fulano_rede, sizeof(RedeSocial), 1, fp_rede);
        if ((strcmp(fulano_rede->cpf, cpf_busca_dig) == 0) && (fulano_rede->status != 'x')){
            achou = True;
        }
    }

    if (achou == False){
        printf("Rede sociais do usuario não concontradas\n");
    }

    else if (achou == True){

        redeSocial_exibe(fulano_rede);
        printf("\n\n\n");
        printf("Deseja realmente apagar este usuario?");
        certeza = confirmacao();
        if (certeza == True){

            fulano_rede->status = 'x';
            var = -1;
            fseek(fp_rede, var*sizeof(RedeSocial), SEEK_CUR);
            fwrite(fulano_rede, sizeof(RedeSocial), 1, fp_rede);
            printf("\nRedes Sociais excluídas com sucesso!!!\n");
        }
        else{
            printf("\nOk, os dados não foram alterados\n");
        }
    }
  free(fulano_rede);
  fclose(fp_rede);
}

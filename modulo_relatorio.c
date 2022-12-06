#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoes_aux.h"
#include "modulo_usuario.h"
#include "modulo_redeSocial.h"
#include "modulo_midia.h"

#define True 1
#define False 0

void menu_relatorio(void);
void menu_listar_todos(void);

void rel_listar_usuario(void);
void rel_listar_redeSocial(void);
void rel_listar_midia(void);

void listar_todos();
void menu_listar_letra(void);

void listar_letra(void);
void rel_letra_usuario(void);
void rel_letra_redeSocial(void);
void rel_letra_midia(void);
void menu_letra_midia(void);
void menu_letra_rede(void);



void modulo_relatorio(){
    char opcao = '\0';

    do{
        system("cls||clear");
        menu_relatorio();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                listar_todos();
            }
            else if (opcao == '2'){
                listar_letra();
            }
            else {
                printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        else{
            printf("Voltando ao menu principal...\n");
        }

    } while (opcao != '0');

}

void listar_todos(void){
    char opcao = '\0';
    do{
        system("cls||clear");
        menu_listar_todos();

        opcao = opcoes_pergunta();
        if (opcao != '0'){
            if (opcao == '1'){
                rel_listar_usuario();
            }
            else if (opcao == '2'){
                rel_listar_redeSocial();
            }
            else if (opcao == '3'){
                rel_listar_midia();
            }
        
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        
        else{
            printf("Voltando\n");
        }



    }while (opcao != '0');
}

void listar_letra(void){
    char opcao = '\0';

    do{
        system("cls||clear");
        menu_listar_letra();
        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                rel_letra_usuario();
            }
            else if (opcao == '2'){
                rel_letra_redeSocial();
            }
            else if (opcao == '3'){
                rel_letra_midia();
            }
        
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        
        else{
            printf("Voltando\n");
        }



    }while(opcao != '0');  
}

void rel_listar_usuario(void){
    system("cls||clear");

    FILE* fp;
    Usuario* fulano_aqr;
    fulano_aqr = (Usuario*) malloc(sizeof(Usuario));

    int i;

    usuario_arq();

    printf(""
    "=================================\n"
    "======  Lista de Usuários  ======\n"
    "=================================\n"
    ""); 
    fp = fopen("arq_usuarios.dat", "rb");
    

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



void rel_listar_redeSocial(void){
    system("cls||clear");

    FILE* fp;
    RedeSocial* fulano_aqr;
    fulano_aqr = (RedeSocial*) malloc(sizeof(RedeSocial));
    

    int i;

    redeSocial_arq();

    printf(""
        "=================================\n"
        "==== Lista de Redes Sociais  ====\n"
        "=================================\n"
    "");
    fp = fopen("arq_redes_Sociais.dat", "rb");
    

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


void rel_listar_midia(void){
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


void rel_letra_usuario(void){
    system("cls||clear");

    FILE* fp;
    Usuario* fulano_aqr;
    fulano_aqr = (Usuario*) malloc(sizeof(Usuario));


    int i;
    char nome_dig;

    nome_dig = char_busca();

    usuario_arq();

    printf(""
    "=================================\n"
    "======  Lista de Usuários  ======\n"
    "=================================\n"
    ""); 
    fp = fopen("arq_usuarios.dat", "rb");
    

    i = 1;
    while(fread(fulano_aqr, sizeof(Usuario), 1, fp)) {

        if ((fulano_aqr->status != 'x') && 
        ((toupper(nome_dig) == fulano_aqr -> nome[0]) || (tolower(nome_dig) == fulano_aqr -> nome[0]))){
            printf("\n= = = Usuario nº %d = = =\n",i);
            usuario_exibe(fulano_aqr);
            i+=1;
        }
    }

    fclose(fp);
    free(fulano_aqr);
    enter();
}



void rel_letra_redeSocial(void){

    FILE* fp;
    redeSocial_arq();
    fp = fopen("arq_redes_Sociais.dat", "rb");

    RedeSocial* fulano_aqr;
    fulano_aqr = (RedeSocial*) malloc(sizeof(RedeSocial));
    

    int i = 1;
    char nome_dig;
    char opcao;

    
    do{
        system("cls||clear");
        menu_letra_rede();
        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                printf(""
                    "=================================\n"
                    "====     Lista de Steam      ====\n"
                    "=================================\n"
                "");
                nome_dig = char_busca();

                while(fread(fulano_aqr, sizeof(RedeSocial), 1, fp)) {
                    if ((fulano_aqr->status != 'x') && 
                    ((toupper(nome_dig) == fulano_aqr ->steam[0]) || (tolower(nome_dig) == fulano_aqr -> steam[0]))){
                        printf("\n= = = Jogo nº %d = = =\n",i);
                        redeSocial_exibe(fulano_aqr);
                        i+=1;
                    }
                }
            }

            else if (opcao =='2'){
                printf(""
                    "=================================\n"
                    "====     Lista de Twitter    ====\n"
                    "=================================\n"
                "");
                nome_dig = char_busca();

                while(fread(fulano_aqr, sizeof(RedeSocial), 1, fp)) {
                    if ((fulano_aqr->status != 'x') && 
                    ((toupper(nome_dig) == fulano_aqr ->twitter[0]) || (tolower(nome_dig) == fulano_aqr -> twitter[0]))){
                        printf("\n= = = Jogo nº %d = = =\n",i);
                        redeSocial_exibe(fulano_aqr);
                        i+=1;
                    }
                }
            }

            else if (opcao =='3'){
                printf(""
                        "=================================\n"
                        "====     Lista de Youtube    ====\n"
                        "=================================\n"
                    "");
                nome_dig = char_busca();

                while(fread(fulano_aqr, sizeof(RedeSocial), 1, fp)) {
                    if ((fulano_aqr->status != 'x') && 
                    ((toupper(nome_dig) == fulano_aqr ->youtube[0]) || (tolower(nome_dig) == fulano_aqr -> youtube[0]))){
                        printf("\n= = = Jogo nº %d = = =\n",i);
                        redeSocial_exibe(fulano_aqr);
                        i+=1;
                    }
                }
            }

            else {
                printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
        else{
            printf("Voltando...\n");
        }
    }while(opcao != '0');



    fclose(fp);
    free(fulano_aqr);
}



void rel_letra_midia(void){
    system("cls||clear");

    FILE* fp;
    midia_arq();
    fp = fopen("arq_midias.dat", "rb");

    Midia* fulano_aqr;
    fulano_aqr = (Midia*) malloc(sizeof(Midia));

    int i=1;
    char nome_dig;
    char opcao;

    do{
        menu_letra_midia();
        opcao = opcoes_pergunta();
        if (opcao != '0'){
            if (opcao == '1'){
                printf(""
                    "=================================\n"
                    "======    Lista de Jogos   ======\n"
                    "=================================\n"
                "");
                nome_dig = char_busca();

                while(fread(fulano_aqr, sizeof(Midia), 1, fp)) {
                    if ((fulano_aqr->status != 'x') && 
                    ((toupper(nome_dig) == fulano_aqr ->jogo[0]) || (tolower(nome_dig) == fulano_aqr -> jogo[0]))){
                        printf("\n= = = Jogo nº %d = = =\n",i);
                        midia_exibe(fulano_aqr);
                        i+=1;
                    }
                }
            }


            else if (opcao == '2'){
                printf(""
                    "=================================\n"
                    "======    Lista de Livros   ======\n"
                    "=================================\n"
                "");
                nome_dig = char_busca();

                while(fread(fulano_aqr, sizeof(Midia), 1, fp)) {
                    if ((fulano_aqr->status != 'x') && 
                    ((toupper(nome_dig) == fulano_aqr ->livro[0]) || (tolower(nome_dig) == fulano_aqr -> livro[0]))){
                        printf("\n= = = Livro nº %d = = =\n",i);
                        midia_exibe(fulano_aqr);
                        i+=1;
                    }
                }
            }


            else if (opcao == '3'){
                printf(""
                    "=================================\n"
                    "======   Lista de Filmes   ======\n"
                    "=================================\n"
                "");
                nome_dig = char_busca();

                while(fread(fulano_aqr, sizeof(Midia), 1, fp)) {
                    if ((fulano_aqr->status != 'x') && 
                    ((toupper(nome_dig) == fulano_aqr ->jogo[0]) || (tolower(nome_dig) == fulano_aqr -> jogo[0]))){
                        printf("\n= = = Filme nº %d = = =\n",i);
                        midia_exibe(fulano_aqr);
                        i+=1;
                    }
                }
            }

            else {
                printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
        else{
            printf("Voltando...\n");
        }

    }while(opcao != '0');
    

    fclose(fp);
    free(fulano_aqr);
}
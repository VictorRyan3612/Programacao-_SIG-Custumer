
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void redeSocial_pesquisar(void);
void redeSocial_editar(void);
void redeSocial_excluir(void);

void usuario_gravar(RedeSocial* fulano);
void usuario_exibe(RedeSocial* fulano);



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
                redeSocial_vizualizar();
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

    char opcao;
    int resp;

    menu_redeSocial_cadastro();
    opcao = opcoes_pergunta();


    //steam
    if (opcao == '1'){
        do {
            printf(""
                "=======================================\n"
                "====  Informe seu perfil da steam: ====\n"
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
    

    //twitter
    if (opcao == '2'){
        do {
            printf(""
                "=======================================\n"
                "====     Informe seu Twitter:      ====\n"
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

    //youtube
    if (opcao == '3'){
        do {
            printf(""
                "=======================================\n"
                "====     Informe seu Youtube:      ====\n"
                "=======================================\n"
                );
            printf("\n");
            scanf("%s", fulano -> youtube);
            getchar();

            resp = validar_youtube(fulano -> youtube);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        }while (resp != True);
}
    redesocial_gravar(fulano);
    free(fulano);
}
void usuario_gravar(RedeSocial* fulano){
  FILE* fp;
  fp = fopen("redeSocial.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(fulano, sizeof(RedeSocial), 1, fp);
  fclose(fp);
}

// RedeSocial* usuario_busca(void){
//     FILE* fp;
//     RedeSocial* fulano;
//     fulano = (RedeSocial*) malloc(sizeof(RedeSocial));

//     char cpf_busca[13];
//     printf("\n = Busca usuario = \n"); 
//     printf("Informe o CPF:\n"); 
//     scanf("%s", cpf_busca);
//     fp = fopen("redeSocial.dat", "rb");
//     if (fp == NULL) {
//         printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
//         printf("Não é possível continuar este programa...\n");
//         exit(1);
//     }

//     while(!feof(fp)) {
//         fread(fulano, sizeof(RedeSocial), 1, fp);
//         if ((strcmp(fulano->cpf, cpf_busca) == 0) && (fulano->status != 'x')){
//             fclose(fp);
//             return fulano;
//         }
//     }
//     fclose(fp);
//     return NULL;
//     }


void usuario_exibe(RedeSocial* fulano){
    printf("\n");
    
    char situacao[20];

    if (fulano == NULL) {
        printf("\n= = = Usuario Inexistente = = =\n");
    } 
    else {
        printf("Steam do usuario: %s\n", fulano->steam);
        printf("Twitter do Usuario: %s\n", fulano->twitter);
        printf("Youtube do usuario: %s\n", fulano->youtube);
    }

}

void redeSocial_pesquisar(void){
    printf("Busca não disponível\n");

}

void redeSocial_editar(void){
    printf("\n");
//     char opcao;
//     int resp;

//     menu_redeSocial_editar();
//     printf("\n\n");
//     printf("Suas informações atualmente cadastradas são:\n");
//     redeSocial_vizualizar(fulano);
//     opcao = opcoes_pergunta();

    
//     // Editar steam
//     if (opcao == '1'){
//         printf("Seu atual perfil da steam é esse:\n");
//         printf("%s", fulano -> steam);
//         printf("\n\n");
//         do{
//             printf(""
//                 "=======================================\n"
//                 "====      Informe o atualizado:    ====\n"
//                 "=======================================\n"
//             );
//             printf("\n");
//             scanf("%s", fulano -> steam);
//             getchar();
//             resp = validar_twitterSteam(fulano -> steam);
//             if (resp != True){
//                 printf("Caractere inválido detectado, Digite novamente:\n");
//             }
//         } while (resp != True);
// }
//     // Editar twitter
//     else if (opcao == '2'){
//         printf("Sua atual conta do twitter é essa:\n");
//         printf("%s", fulano -> twitter);
//         printf("\n\n");
//         do{
//             printf(""
//                 "=======================================\n"
//                 "====      Informe o atualizado:    ====\n"
//                 "=======================================\n"
//             );
//             printf("\n");
//             scanf("%s", fulano -> twitter);
//             getchar();

//             resp = validar_twitterSteam(fulano -> twitter);
//             if (resp != True){
//                 printf("Caractere inválido detectado, Digite novamente:\n");
//             }
//         } while (resp != True);
//     }

        
//     // Editar youtube
//     else if (opcao == '3'){
//         printf("Seu atual canal do youtube é esse:\n");
//         printf("%s", fulano -> youtube);
//         printf("\n\n");
//         do{
//             printf(""
//                 "=======================================\n"
//                 "====      Informe o atualizado:    ====\n"
//                 "=======================================\n"
//             );
//             printf("\n");
//             scanf("%s", fulano -> youtube);
//             getchar();

//             resp = validar_youtube(fulano -> youtube);
//             if (resp != True){
//                 printf("Caractere inválido detectado, Digite novamente:\n");
//             }
//         } while (resp != True);
//     }

}

void redeSocial_excluir(void){
    printf("\n");
//     char opcao;
//     int resp;

//     menu_redeSocial_excluir();

//     printf("\n\n");
//     printf("Suas informações atualmente cadastradas são:\n");

//     redeSocial_vizualizar(fulano);

//     printf("Digite qual deseja:\n");
//     opcao = opcoes_pergunta();

//     resp = confirmacao();
//     if (resp == True){
//         if (opcao == '1'){
            
//             printf("Exluindo seu perfil steam cadastrado\n");
//             strcpy(fulano -> steam, "");
//             printf("Exluído com sucesso\n");

//         }

//         else if (opcao == '2'){
//             printf("Exluindo seu perfil do twitter cadastrado\n");
//             strcpy(fulano -> twitter, "");
//             printf("Exluído com sucesso\n");

//         }
        
//         else if (opcao == '3'){
//             printf("Exluindo seu canal youtube cadastrado\n");
//             strcpy(fulano -> youtube, "");
//             printf("Exluído com sucesso\n");
            
//         }
//     }
}

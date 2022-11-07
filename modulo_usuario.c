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

int usuario_cadastro(Usuario* fulano);
void usuario_grava(Usuario* fulano);
int usuario_vizualizar(const Usuario* fulano);
int usuario_pesquisar(const Usuario* fulano);
int usuario_editar(Usuario* fulano);
int usuario_excluir(Usuario* fulano);






int modulo_usuario(void){
    
    
    Usuario fulano;
    char opcao = '\0';

    do{
        menu_usuario();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                usuario_cadastro(&fulano);
            }
            else if (opcao == '2'){
                usuario_vizualizar(&fulano);
            }
            else if (opcao == '3'){
                usuario_pesquisar(&fulano);
            }
            else if (opcao == '4'){
                usuario_editar(&fulano);
            }
            else if (opcao == '5'){
                usuario_excluir(&fulano);
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



int usuario_cadastro(Usuario* fulano){
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
        
        resp = validar_num(fulano-> cpf);
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

    usuario_grava(fulano);
    return 0;
}

void usuario_grava(Usuario* fulano){
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

int usuario_vizualizar(const Usuario* fulano){
    printf("\n");

    printf("Seu nome é esse:\n");
    printf("%s", fulano -> nome);
    printf("\n\n\n");

    printf("Seu cpf é esse:\n");
    printf("%s", fulano -> cpf);
    printf("\n\n\n");

    printf("Seu email é esse:\n");
    printf("%s", fulano -> email);
    printf("\n\n\n");


    printf("Seu telefone é esse:\n");
    printf("%s", fulano -> telefone);
    printf("\n\n\n");

    return 0;
}

int usuario_pesquisar(const Usuario* fulano){
    printf("Busca não disponível\n");

    return 0;
}

int usuario_editar(Usuario* fulano){
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

    return 0;
}

int usuario_excluir(Usuario* fulano){
    printf("\n");

    // char opcao;
    // int resp;

    // menu_usuario_excluir();

    // printf("\n\n");
    // printf("Suas informações atualmente cadastradas são:\n");
    // usuario_vizualizar(fulano);

    // printf("Digite qual deseja:\n");
    // opcao = opcoes_pergunta();

    // resp = confirmacao();
    // if (resp == True){
    //     if (opcao == '1'){
    //         printf("Exluindo seu nome\n");
    //         strcpy(fulano -> nome, "");
    //         printf("Exluído com sucesso\n");

    //     }

    //     else if (opcao == '2'){
    //         printf("Exluindo seu cpf cadastrado\n");
    //         strcpy(fulano -> cpf, "");
    //         printf("Exluído com sucesso\n");

    //     }
        
    //     else if (opcao == '3'){
    //         printf("Exluindo seu email cadastrado\n");
    //         strcpy(fulano -> email, "");
    //         printf("Exluído com sucesso\n");
            
    //     }
    // }
    //     else if (opcao == '4'){
    //         printf("Exluindo seu telefone cadastrado\n");
    //         strcpy(fulano -> telefone, "");
    //         printf("Exluído com sucesso\n");
            
    //     }
    return 0;
}

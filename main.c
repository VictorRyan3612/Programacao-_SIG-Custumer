#include <stdio.h>
#include <stdlib.h>


#include "modulo_usuario.h"
#include "modulo_redeSocial.h"
#include "modulo_midia.h"
#include "modulo_relatorio.h"
#include "funcoes_aux.h"


// Para explicações sobre o código, por favor verificar o arquivo
// detalhes.md


// Assinatura das funções:
int menu_principal(void);
int menu_sobre(void);
void modulo_usuario(void);
void modulo_redeSocial(void);
void modulo_midia(void);






int main(void){
    
    char opcao = '\0';
    do {
        system("cls||clear");
        menu_principal();
        printf("\n\n");
        opcao = opcoes_pergunta();

        if (opcao == '1'){
            modulo_usuario();
        }
        else if (opcao == '2'){
            modulo_redeSocial();
        }
        else if (opcao == '3'){
            modulo_midia();
        }
        else if (opcao == '4'){
            modulo_relatorio();
        }
        else if (opcao == '5'){
            menu_sobre();
        }
        else if (opcao == '0'){
            printf("Fechando...\n");
        }
        enter();
        }while (opcao != '0');
        
        return 0;
    }

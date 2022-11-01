#include <stdio.h>
#include <stdlib.h>

typedef struct redeSocial RedeSocial;

struct redeSocial {
    char steam[81];
    char twitter[51];
    char youtube[41];
};

void preenche_redeSocial(RedeSocial*);
void exibe_redeSocial(const RedeSocial*);


int modulo_redeSocial(void){
    system("cls||clear");
    RedeSocial fulano;


    preenche_redeSocial(&fulano);
    exibe_redeSocial(&fulano);
    
    return 0;
}


void preenche_redeSocial(RedeSocial* fulano) {
    printf("Programa Cadastro de rede socials\n\n");
    printf("Informe o steam do redeSocial: ");
    scanf(" %80[^\n]", fulano -> steam);
    printf("Informe o twitter do redeSocial: ");
    scanf(" %50[^\n]", fulano -> twitter);
    printf("Informe o e-mail do redeSocial: ");
    scanf(" %40[^\n]", fulano -> youtube);


}

void exibe_redeSocial(const RedeSocial* fulano){
    printf("\n= = = redeSocial Cadastrado = = =\n");
    printf("steam do redeSocial: %s\n", fulano -> steam);
    printf("twitter: %s\n", fulano -> twitter);
    printf("Ender eletrônico: %s\n", fulano -> youtube);
}
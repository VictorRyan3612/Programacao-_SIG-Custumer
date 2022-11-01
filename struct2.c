#include <stdio.h>
#include <stdlib.h>

typedef struct midia Midia;

struct midia {
    char jogo[81];
    char livro[51];
    char filme[41];
};

void preenche_midia(Midia*);
void exibe_midia(const Midia*);


int modulo_midia(void){
    system("cls||clear");
    Midia fulano;


    preenche_midia(&fulano);
    exibe_midia(&fulano);
    
    return 0;
}


void preenche_midia(Midia* fulano) {
    printf("Programa Cadastro de midias\n\n");
    printf("Informe o jogo do midia: ");
    scanf(" %80[^\n]", fulano -> jogo);
    printf("Informe o livro do midia: ");
    scanf(" %50[^\n]", fulano -> livro);
    printf("Informe o e-mail do midia: ");
    scanf(" %40[^\n]", fulano -> filme);

}

void exibe_midia(const Midia* fulano){
    printf("\n= = = midia Cadastrado = = =\n");
    printf("jogo do midia: %s\n", fulano -> jogo);
    printf("livro: %s\n", fulano -> livro);
    printf("Ender eletrônico: %s\n", fulano -> filme);
}
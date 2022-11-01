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
    printf("Informe o jogo de interesse: ");
    scanf(" %80[^\n]", fulano -> jogo);
    printf("Informe o livro de interesse: ");
    scanf(" %50[^\n]", fulano -> livro);
    printf("Informe o filme de interesse: ");
    scanf(" %40[^\n]", fulano -> filme);

}

void exibe_midia(const Midia* fulano){
    printf("\n= = = midia Cadastrado = = =\n");
    printf("Jogo  de interesse: %s\n", fulano -> jogo);
    printf("Livro de interesse: %s\n", fulano -> livro);
    printf("Filme de interesse: %s\n", fulano -> filme);
}
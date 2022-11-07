typedef struct midia Midia;

struct midia {
    char jogo[81];
    char livro[51];
    char filme[41];
};

int modulo_midia(void);
int midia_cadastro(Midia* fulano);
int midia_vizualizar(const Midia* fulano);
int midia_pesquisar(const Midia* fulano);
int midia_editar(Midia* fulano);
int midia_excluir(Midia* fulano);
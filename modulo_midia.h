typedef struct midia Midia;

struct midia {
    char jogo[81];
    char livro[51];
    char filme[41];
};

int modulo_midia(void);
int midia_cadastro(void);
int midia_vizualizar(void);
int midia_pesquisar(void);
int midia_editar(void);
int midia_excluir(void);
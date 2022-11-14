typedef struct midia Midia;

struct midia {
    char jogo[81];
    char livro[51];
    char filme[41];
};

void modulo_midia(void);
void midia_cadastro(void);
void midia_vizualizar(void);
void midia_pesquisar(void);
void midia_editar(void);
void midia_excluir(void);
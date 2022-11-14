typedef struct midia Midia;
struct midia {
    char cpf[13];
    char jogo[61];
    char livro[51];
    char filme[41];
    char status;
};


typedef struct usuario Usuario; 

void modulo_midia(void);
void midia_cadastro(void);
void midia_gravar(Midia* fulano);
void midia_listar(void);
void midia_pesquisar(void);
void midia_editar(void);
void midia_excluir(void);

void midia_exibe(Midia* fulano);
void midia_listar(void);
Midia* midia_busca(void);
typedef struct midia Midia;
struct midia {
    char cpf[12];
    char jogo[100];
    char livro[100];
    char filme[100];
    char status;
};


typedef struct usuario Usuario; 

void modulo_midia(void);
void midia_cadastro(void);
void midia_arq(void);
void midia_gravar(Midia* fulano);
void midia_listar(void);
void midia_pesquisar(void);
void midia_editar(void);
void midia_excluir(void);

void midia_exibe(Midia* fulano);
void midia_listar(void);
Midia* midia_busca(void);

int midia_existente(char fulano_cpf[12]);
typedef struct redeSocial RedeSocial;
struct redeSocial {
    char steam[81];
    char twitter[51];
    char youtube[41];
};


void modulo_redeSocial(void);

void redeSocial_cadastro(void);
void redeSocial_vizualizar(void);
void redeSocial_pesquisar(void);
void redeSocial_editar(void);
void redeSocial_excluir(void);
void usuario_gravar(RedeSocial* fulano);
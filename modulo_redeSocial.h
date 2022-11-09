typedef struct redeSocial RedeSocial;
struct redeSocial {
    char cpf[13];
    char steam[81];
    char twitter[51];
    char youtube[41];
    char status;
};

typedef struct usuario Usuario;
void modulo_redeSocial(void);

void redeSocial_cadastro(void);
void redeSocial_listar(void);
void redeSocial_pesquisar(void);
void redeSocial_editar(void);
void redeSocial_excluir(void);
void redesocial_gravar(RedeSocial* fulano);
void redeSocial_exibe(RedeSocial* fulano);
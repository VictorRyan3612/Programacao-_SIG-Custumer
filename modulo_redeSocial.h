typedef struct redeSocial RedeSocial;
struct redeSocial {
    char cpf[12];
    char steam[21];
    char twitter[21];
    char youtube[31];
    char status;
};

typedef struct usuario Usuario;
void modulo_redeSocial(void);

void redeSocial_cadastro(void);
void redeSocial_arq(void);
void redeSocial_gravar(RedeSocial* fulano);
void rel_listar_redeSocial(void);
RedeSocial* redeSocial_busca(void);
void redeSocial_pesquisar(void);
void redeSocial_editar(void);
void redeSocial_excluir(void);
void redeSocial_exibe(RedeSocial* fulano);

int redes_existente(char fulano_cpf[12]);
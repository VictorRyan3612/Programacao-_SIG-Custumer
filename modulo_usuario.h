typedef struct usuario Usuario;

struct usuario {
    char cpf[12];
    char nome[81];
    char email[41];
    char telefone[21];
    char status;
    Usuario* prox;
};

void modulo_usuario(void);

void usuario_cadastro(void);
void usuario_arq(void);
void usuario_gravar(Usuario* fulano);
Usuario* usuario_busca(void);
void usuario_exibe(Usuario* fulano);
void rel_listar_usuario(void);
void usuario_pesquisar(void);
void usuario_editar(void);
void usuario_excluir(void);

int usuario_existente(char fulano_cpf[12]);
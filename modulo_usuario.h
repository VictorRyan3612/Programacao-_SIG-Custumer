typedef struct usuario Usuario;

struct usuario {
    char cpf[13];
    char nome[81];
    char email[41];
    char telefone[21];
    char status;
};

int modulo_usuario(void);

int usuario_cadastro(Usuario* fulano);
void usuario_grava(Usuario* fulano);
int usuario_vizualizar(const Usuario* fulano);
int usuario_pesquisar(Usuario* fulano);
int usuario_editar(Usuario* fulano);
int usuario_excluir(Usuario* fulano);
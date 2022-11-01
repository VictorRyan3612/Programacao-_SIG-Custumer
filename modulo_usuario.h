typedef struct usuario Usuario;

int modulo_usuario(void);

int usuario_cadastro(Usuario* fulano);
int usuario_vizualizar(const Usuario* fulano);
int usuario_pesquisar(const Usuario* fulano);
int usuario_editar(Usuario* fulano);
int usuario_excluir(Usuario* fulano);
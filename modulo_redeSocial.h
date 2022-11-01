typedef struct redeSocial RedeSocial;

int modulo_redeSocial(void);

int redeSocial_cadastro(RedeSocial* fulano);
int redeSocial_vizualizar(const RedeSocial* fulano);
int redeSocial_pesquisar(const RedeSocial* fulano);
int redeSocial_editar(RedeSocial* fulano);
int redeSocial_excluir(RedeSocial* fulano);
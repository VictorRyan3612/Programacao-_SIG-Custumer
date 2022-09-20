//in main.c ↓

int menu_sobre(void);

int menu_principal(void);

int menu_usuario(void);

int menu_redeSocial(void);

int menu_interesse(void);

// in usuario.c

int modulo_usuario();

int usuario_cadastro();
int usuario_vizualizar();
int usuario_pesquisar();
int usuario_editar();
int usuario_excluir();

// in redeSocial.c

int modulo_redeSocial();
int redeSocial_cadastro();
int redeSocial_vizualizar();
int redeSocial_pesquisar();
int redeSocial_editar();
int redeSocial_excluir();

// in interesses.c

int modulo_interesse();
int interesse_cadastro();
int interesse_vizualizar();
int interesse_pesquisar();
int interesse_editar();
int interesse_excluir();
//in main.c ↓

int menu_sobre(void);

int menu_principal(void);

int menu_usuario(void);

int menu_redeSocial(void);

int menu_interesse(void);

int main(void);

// in usuario.c

int modulo_usuario(char a[], char b[], char c[]);

int usuario_cadastro(char a[], char b[], char c[]);
int usuario_vizualizar(char a[], char b[], char c[]);
int usuario_pesquisar(void);
int usuario_editar(char a[], char b[], char c[]);
int usuario_excluir(char a[], char b[], char c[]);

// in redeSocial.c

int modulo_redeSocial(void);
int redeSocial_cadastro(void);
int redeSocial_vizualizar(void);
int redeSocial_pesquisar(void);
int redeSocial_editar(void);
int redeSocial_excluir(void);

// in interesses.c

int modulo_interesse(void);
int interesse_cadastro(void);
int interesse_vizualizar(void);
int interesse_pesquisar(void);
int interesse_editar(void);
int interesse_excluir(void);
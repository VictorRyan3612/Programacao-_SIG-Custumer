//menus.c ↓

int menu_sobre(void);

int menu_principal(void);

int menu_usuario(void);

int menu_redeSocial(void);

int menu_interesse(void);

int main(void);

// funcoes_aux.c

char confirmacao(char);

// in usuario.c


int modulo_usuario(char a[], char b[], char c[]);

int usuario_cadastro(char a[], char b[], char c[]);
int usuario_vizualizar(char a[], char b[], char c[]);
int usuario_pesquisar(char a[], char b[], char c[]);
int usuario_editar(char a[], char b[], char c[]);
int usuario_excluir(char a[], char b[], char c[]);

// in redeSocial.c

int modulo_redeSocial(char a[], char b[], char c[]);
int redeSocial_cadastro(char a[], char b[], char c[]);
int redeSocial_vizualizar(char a[], char b[], char c[]);
int redeSocial_pesquisar(char a[], char b[], char c[]);
int redeSocial_editar(char a[], char b[], char c[]);
int redeSocial_excluir(char a[], char b[], char c[]);

// in interesses.c

int modulo_interesse(char a[], char b[], char c[]);
int interesse_cadastro(char a[], char b[], char c[]);
int interesse_vizualizar(char a[], char b[], char c[]);
int interesse_pesquisar(char a[], char b[], char c[]);
int interesse_editar(char a[], char b[], char c[]);
int interesse_excluir(char a[], char b[], char c[]);
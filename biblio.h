int main(void);

// funcoes_menus.c ↓

int menu_sobre(void);

int menu_principal(void);

int menu_usuario(void);
void menu_usuario_editar(void);
void menu_usuario_excluir(void);

int menu_redeSocial(void);
void menu_redeSocial_cadastro(void);
void menu_redeSocial_editar(void);
void menu_redeSocial_excluir(void);

int menu_interesse(void);
void menu_interesse_cadastro(void);
void menu_interesse_editar(void);
void menu_interesse_excluir(void);


// funcoes_aux.c

void enter(void);
char confirmacao(void);
char opcoes_pergunta(void);
void vizualizar_lista(char a[]);

char validar_nome(char a[]);
char validar_email(char a[]);
char validar_telefone(char a[]);
char validar_twitterSteam(char a[]);
char validar_youtube(char a[]);
char validar_nomeMidia(char a[]);
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
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

int menu_midia(void);
void menu_midia_cadastro(void);
void menu_midia_editar(void);
void menu_midia_excluir(void);


// funcoes_aux.c

void enter(void);
int confirmacao(void);
char opcoes_pergunta(void);
void vizualizar_lista(char a[]);

// validações
int validar_nome(char a[]);
int validar_email(char a[]);
int validar_telefone(char a[]);
int validar_twitterSteam(char a[]);
int validar_youtube(char a[]);
int validar_nomeMidia(char a[]);
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

// in midia.c

int modulo_midia(char a[], char b[], char c[]);
int midia_cadastro(char a[], char b[], char c[]);
int midia_vizualizar(char a[], char b[], char c[]);
int midia_pesquisar(char a[], char b[], char c[]);
int midia_editar(char a[], char b[], char c[]);
int midia_excluir(char a[], char b[], char c[]);
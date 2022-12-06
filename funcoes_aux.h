void enter(void);
int confirmacao(void);
char opcoes_pergunta(void);
void vizualizar_lista(char a[]);
char* cpf_busca(void);
char* status_exibe(char status,char* situacao);


// Conversões
int string_num(char a[]);

long string_long(char a[]);
long string_long2(char a[]);


// validações
int validar_cpf(char a[]);
int validar_num(char a[]);

int validar_nome(char a[]);
int validar_email(char a[]);
int validar_telefone(char a[]);

int validar_twitterSteam(char a[]);
int validar_youtube(char a[]);

int validar_nomeMidia(char a[]);
int validar_nome_char(char a);
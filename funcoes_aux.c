#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define True 1
#define False 0
typedef struct midia Midia;


int validar_nome_char(char a);


void enter(void){
    printf("\n");
    printf("Aperte ENTER para continuar\n");
    getchar();
}

int confirmacao(void){
    char resp;
    printf("\n");
    printf("Confirme se está correto (s para sim)...\n");
    scanf("%c", &resp);
    getchar();
    printf("\n");
    
    if ((resp == 's') || (resp == 'S')){
        return True;
    }
    else{
        return False;
    }
}

char opcoes_pergunta(void){
    char opcoes;
    scanf("%c", &opcoes);
    printf("\n\n");
    getchar();
    return opcoes;
}


void vizualizar_lista(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(a[i] == ';'){
            printf("\n");
        } else{
            printf("%c",a[i]);
        }
        i++;
    }
}

char* cpf_busca(void){
    char* cpf_busca_dig;

    cpf_busca_dig = (char*) malloc(12*sizeof(char));
    printf("\n ==== Busca usuario ==== \n"); 
    printf("Informe o CPF:\n"); 
    scanf("%s", cpf_busca_dig);
    getchar();
    
    return cpf_busca_dig;
}


char char_busca(void){
    int valido;
    char nome_dig;
    do{
        printf("Digite a letra que deseja buscar\n");
        scanf("%c", &nome_dig);
        getchar();

        valido = validar_nome_char(nome_dig);
        if (valido == False){
            printf("Caractere Inválido, digite outro\n\n");
        }
    
    }while(valido == False);
    return nome_dig;
}

char* status_exibe(char status, char* situacao){

    if (status == 'c') {
        strcpy(situacao, "Cadastrado");
    }
    else if (status == 's') {
        strcpy(situacao, "Suspenso");
    }
    else if (status == 'x'){
        strcpy(situacao, "Excluido");
    }
    else {
        strcpy(situacao, "Não informada");
    }
    return situacao;
}

/// Conversões

// adaptado de NadjibSoft no vídeo https://www.youtube.com/watch?v=d_M9PqPpTFI&t=50s
int string_num(char a[]){
    int digit, j=1,number=0; // j=casa decimal

    for (int i = strlen(a)-1; i>=0; i-=1){
        digit = a[i];
        digit = digit -48;
        number = number+(digit *j);
        j *= 10;
    }
    return number;
}

long int string_long(char a[]){
    int digit, j=1; // j=casa decimal
    long int number;

    for (int i = strlen(a)-1; i>=0; i-=1){
        digit = a[i];
        digit = digit -48;
        number = number+(digit *j);
        j *= 10;
    }
    return number;
}

long int string_long2(char a[]){
    long num =0;
    int i=0;

    while (a[i] >= '0' && a[i] <= '9'){
        num = num*10 + (a[i]- '0');
        i++;
    }
    return num;
}


// Validações

int validar_num(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if((a[i] >= '0' ) && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}



int validar_cpf(char x[]){
    char a[12];
    strcpy(a, x);

    // algoritmo a partir desse site: 
    //https://blog.dbins.com.br/como-funciona-a-logica-da-validacao-do-cpf

    // Parte 1, primeiro dígito verificador
    int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
    int bb = 0;
    int ff = 0;
    int num =10;
    int valido;

    for (int i = 0; i <=8; i+=1){
        a[i] = a[i]-48;
        printf("a[%d]=%d\t",i,a[i]);
        printf("%d",num);
        b += a[i] * num;
        num -= 1;
        printf("\tb[%d]=%d\n",i,b);
    }
    printf("b = %d\n",b);
    bb= b/11;
    c = b -(11*bb);
    printf("c = %d\n",c); // essencial
    if ((c == 0)||(c == 1)){
        c = 0;
        d = 0;
    }
    else if (c <= 1){
        d = 1;
    }
    else{
        d = 11 - c;
    }
    printf("d = %d\n",d); // essencial

    // Parte 2, segundo dígito verificador
    num = 11;
    a[9]= a[9]-48;
    a[10]= a[10]-48;
    for (int i = 0; i <= 9; i+=1){
        printf("a[%d]%d\t",i,a[i]);
        printf("%d",num);
        e += a[i] * num;
        printf("\te[%d]=%d\n",i,e);
        num -= 1;
    }
    printf("e = %d\n",e);
    ff = e/11;
    f= e -(11*ff);
    printf("f = %d\n",f); // essencial
    if ((f == 0)||(f == 1)){
        f = 0;
        g = 0;
    }
    else if (f <= 1){
        g = 1;
    }
    else{
        g = 11 - f;
    }
    printf("g = %d\n",g); // essencial

    // parte 3, verificar se os dígitos verificadores estão certos
    if ((a[9] == d) && (a[10] == g)){
        valido = True;
    }
    else{
        valido = False;
    }
    return valido;
}


// usado em usuario.c
// Adaptado de Daynne github: https://github.com/DayXL ↓
int validar_nome(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}
int validar_nome_char(char a){
    if(((a >= 'a' ) && (a <= 'z')) || (a == ' ')){
        return True;
    } 
    else if ((a >= 'A' ) && (a <= 'Z')){
        return True;
    }
    else{
        return False;
    }
    
    return True;
}
// usado em usuario.c
int validar_email(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= '@' ) && (a[i] <= 'z')) || (a[i] == '.')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em usuario.c
int validar_telefone(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if((a[i] >= '0' ) && (a[i] <= '9')){
            i += 1;
        } 
        else if ((a[i] == '(' ) || (a[i] <= ')' )){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em redeSocial.c
int validar_twitterSteam(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= '@' ) && (a[i] <= 'z')) || (a[i] == '.')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em redeSocial.c
int validar_youtube(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em interesse.c
int validar_nomeMidia(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ') || (a[i] == ';')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else if ((a[i] == '&') || (a[i] == '\'') || (a[i] == ':') || (a[i] == '.')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}
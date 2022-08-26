# Explicações sobre o código

As seguintes linhas:

/*
#include <locale.h>

setlocale (LC_ALL, "portuguese");

*/
fazem que os caracteres acentuados funcionem.

# Equivalencias C e python

## Captura de ENTER do teclado

### Em C

printf("Aperte ENTER para continuar\n");

getch();

### Em python

input("Aperte enter para continuar")


## Bloco de print

### Em C
printf(""
"    \n"
"    \n"
"    \n"
)

### em Python
print("""


""")

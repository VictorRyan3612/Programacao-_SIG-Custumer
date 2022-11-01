#include <stdio.h>
#include <stdlib.h>
#include "struct1.h"
#include "struct2.h"
#include "struct3.h"




int main(void){
    system("cls||clear");
    char op;

    printf("1:usuario\n");
    printf("2:Midia\n");
    printf("3:Rede Social\n");

    scanf("%c",&op);
    getchar();

    if (op =='1'){
        modulo_usuario();
    }

    if (op =='2'){
        modulo_midia();
    }
    if (op =='3'){
        modulo_redeSocial();
    }
}
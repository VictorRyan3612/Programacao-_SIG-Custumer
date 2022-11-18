#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_aux.h"

struct titanic{
    int pass_id;
    int sobre;
    int classe;
    char nome[80];
    char sex[7];
    int idade;
    char ipmarket;
    int q_irmaos;
    int q_fami;
    char ticket[20];
    int tarifa;
    char cabine[10];
    char embarque; 
    // (C = Cherbourg, Q = Queenstown, S = Southampton)
};


void estru_dinam(void){
    printf("\n");
    char linha[300];

    FILE* fp;
    fp = fopen("titanic.csv","rt");

    if (fp == NULL){
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }

    // fscanf("%[^,]");

    while (fscanf(fp,"%[^,]",linha) == 1) {
        printf("%s\n",linha);
        fgetc(fp);
    }




    fclose(fp);
    }



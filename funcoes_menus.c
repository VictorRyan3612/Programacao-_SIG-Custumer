#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


int menu_sobre(void){
    setlocale (LC_ALL, "portuguese");
    printf("\n"
    "\t\tSobre o projeto:\n"
    "\tSIG-Custumer: Um sistema de controle de cliente\n"
    "As empresas da atualidade utilizam complexos sistemas gerenciais para, "
    "entre várias outras funções, gerenciar e manter seus clientes, "
    "além de ajudar a conseguir novos clientes. "
    "O presente projeto tem como objetivo propor um software que implementa "
    "funcionalidades básicas relacionadas ao controle de clientes de uma empresa, "
    "facilitando a gestão.\n"
    "\n\n"

    "\t\tDiscente/Autor do Projeto:\n"
    "Victor Ryan Galvão Silva\n"
    "matrícula:20220035163\n"
    "email:\n"
    "vitorsilva3612@gmail.com\n"
    "ryan.silva.706@ufrn.edu.br\n"
    "\n"
    );
    return 0;
}



int menu_principal(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "|===================================================|\n"
        "|===================================================|\n"
        "|====                                           ====|\n"
        "|====       Programa Controle de Clientes       ====|\n"
        "|====                                           ====|\n"
        "|====                                           ====|\n"
        "|====            Digite qual deseja:            ====|\n"
        "|====           1 - Módulo Usuário              ====|\n"
        "|====           2 - Módulo Redes Sociais        ====|\n"
        "|====           3 - Módulo Interesses           ====|\n"
        "|====           4 - Sobre e equipe              ====|\n"
        "|====           0 - Encerrar                    ====|\n"
        "|====                                           ====|\n"
        "|===================================================|\n"
        "|===================================================|\n"
    );

    return 0;
}

int menu_usuario(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");

printf(""
        "===================================================\n"
        "===================================================\n"
        "====                                           ====\n"
        "====        Controle de conta de Usuário       ====\n"
        "====                                           ====\n"
        "====                                           ====\n"
        "====          Digite qual deseja:              ====\n"
        "====         1 - Cadastrar Usuário             ====\n"
        "====         2 - Vizualizar Usuário            ====\n"
        "====         3 - Procurar Usuário              ====\n"
        "====         4 - Editar Usuário                ====\n"
        "====         5 - Excluir Usuário               ====\n"
        "====         0 - Voltar                        ====\n"
        "====                                           ====\n"
        "====                                           ====\n"
        "===================================================\n"
        "===================================================\n"
    );
    return 0;
}

int menu_redeSocial(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");

printf(""
        "===================================================\n"
        "===================================================\n"
        "====                                           ====\n"
        "====        Controle das Redes Sociais         ====\n"
        "====                                           ====\n"
        "====                                           ====\n"
        "====          Digite qual deseja:              ====\n"
        "====         1 - Cadastrar Rede Social         ====\n"
        "====         2 - Vizualizar Redes Sociais      ====\n"
        "====         3 - Procurar Rede Social          ====\n"
        "====         4 - Editar Rede Social            ====\n"
        "====         5 - Excluir Rede Social           ====\n"
        "====         0 - Voltar                        ====\n"
        "====                                           ====\n"
        "====                                           ====\n"
        "===================================================\n"
        "===================================================\n"
    );
    return 0;
}

int menu_interesse(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");

    printf(""
        "===================================================\n"
        "===================================================\n"
        "====                                           ====\n"
        "====        Gerenciamento de  Interesse        ====\n"
        "====                                           ====\n"
        "====                                           ====\n"
        "====          Digite qual deseja:              ====\n"
        "====         1 - Cadastrar Interesse           ====\n"
        "====         2 - Vizualizar Interesse          ====\n"
        "====         3 - Procurar Interesse            ====\n"
        "====         4 - Editar Interesse              ====\n"
        "====         5 - Exlcuir Interesse             ====\n"
        "====         0 - Voltar                        ====\n"
        "====                                           ====\n"
        "====                                           ====\n"
        "===================================================\n"
        "===================================================\n"
    );
    printf("\n\n");
    return 0;
}

/////// Interesse
void menu_interesse_cadastro(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Cadastro de Interesse          ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Jogo:  1                    ####\n"
        "####               Livro: 2                    ####\n"
        "####               Filme: 3                    ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_interesse_editar(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####              Edição de Interesse          ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Jogo:  1                    ####\n"
        "####               Livro: 2                    ####\n"
        "####               Filme: 3                    ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_interesse_excluir(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Exclusão de Interesse          ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Jogo:  1                    ####\n"
        "####               Livro: 2                    ####\n"
        "####               Filme: 3                    ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}



////// Rede Social
void menu_redeSocial_cadastro(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Cadastro de Rede Social        ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Steam:   1                  ####\n"
        "####               Twitter: 2                  ####\n"
        "####               Youtube: 3                  ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_redeSocial_editar(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####              Edição de Rede Social        ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Steam:   1                  ####\n"
        "####               Twitter: 2                  ####\n"
        "####               Youtube: 3                  ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_redeSocial_excluir(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Exclusão de Rede Social        ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Steam:   1                  ####\n"
        "####               Twitter: 2                  ####\n"
        "####               Youtube: 3                  ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}




///// Usuário


void menu_usuario_cadastro(void){



}
void menu_usuario_editar(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####              Edição de Usuário            ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Nome:     1                 ####\n"
        "####               Email:    2                 ####\n"
        "####               telefone: 3                 ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_usuario_excluir(void){
    setlocale (LC_ALL, "portuguese");
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Exclusão de Usuário            ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####               Nome:     1                 ####\n"
        "####               Email:    2                 ####\n"
        "####               telefone: 3                 ####\n"
        "####                                           ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}
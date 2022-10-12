#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



//Declaração de variáveis de funções
int coletaOpcaoMenu();
void novoCadastro();
void consultaCadastro();
void alertaSonoro();
void exibeCabecalho();



// Menu de cadastro

void menuCadastro() {
int opcaoNum;
    do {

    exibeCabecalho();

    printf ("        ==================  Cadastro de Pacientes  ===================\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 1 -> Novo                                                ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 2 -> Consultar                                           ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 3 -> Voltar                                              ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        ==============================================================\n\n");
    printf ("        Entre com a opção desejada: ");

    opcaoNum = coletaOpcaoMenu();

    switch(opcaoNum) {
        case 1:
            system("cls");
            novoCadastro();
            break;

        case 2:
            system("cls");
            consultaCadastro();
            break;

        case 3:
            system("cls");
            return;

        default :
            system("cls");
            alertaSonoro();
            exibeCabecalho();
            printf ("\n                >>>>> Opção Inválida. Tente novamente <<<<<\n\n");
            printf("\n               >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
            getch();
            system("cls");
        }
    }
    while((opcaoNum < 1) || (opcaoNum > 4));

    menuCadastro();
    return;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//Declaração de variáveis e funções
int coletaOpcaoMenu();
void exibeCabecalho();
void alertaSonoro();
void relatorioGrupoRisco();
void listarDadosGravados();


/* Menu de relatórios */

void menuRelatorios() {
int opcaoNum;

    do {

    exibeCabecalho();

    printf ("        =====================  Menu Relatórios  ======================\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 1 -> Mostrar dados gravados com grupo de risco           ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 2 -> Gerar arquivo com grupo de risco                    ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 3 -> Voltar                                              ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        ==============================================================\n\n");
    printf ("        Entre com a opção desejada: ");

    opcaoNum = coletaOpcaoMenu();

    switch(opcaoNum) {
        case 1:
            system("cls");
            listarDadosGravados();
            break;

        case 2:
            system("cls");
            relatorioGrupoRisco();
            break;

        case 3:
            system("cls");
            return;
            break;

        default :
            system("cls");
            alertaSonoro();
            exibeCabecalho();
            printf ("\n                >>>>> Opção Inválida. Tente novamente <<<<<\n\n");
            printf("\n              >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
            getch();
            system("cls");
        }
    } while(opcaoNum < 1 || opcaoNum > 3);

    menuRelatorios();
    return;
}


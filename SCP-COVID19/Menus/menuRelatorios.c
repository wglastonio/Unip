#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//Declara��o de vari�veis e fun��es
int coletaOpcaoMenu();
void exibeCabecalho();
void alertaSonoro();
void relatorioGrupoRisco();
void listarDadosGravados();


/* Menu de relat�rios */

void menuRelatorios() {
int opcaoNum;

    do {

    exibeCabecalho();

    printf ("        =====================  Menu Relat�rios  ======================\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 1 -> Mostrar dados gravados com grupo de risco           ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 2 -> Gerar arquivo com grupo de risco                    ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 3 -> Voltar                                              ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        ==============================================================\n\n");
    printf ("        Entre com a op��o desejada: ");

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
            printf ("\n                >>>>> Op��o Inv�lida. Tente novamente <<<<<\n\n");
            printf("\n              >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
            getch();
            system("cls");
        }
    } while(opcaoNum < 1 || opcaoNum > 3);

    menuRelatorios();
    return;
}


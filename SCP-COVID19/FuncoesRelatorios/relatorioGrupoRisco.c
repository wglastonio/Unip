#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void relatorioGrupoRisco();
void exibeCabecalho();
void alertaSonoro();


void relatorioGrupoRisco() {

    exibeCabecalho();

    FILE *filePointerAux;
    filePointerAux = fopen("Grupo_de_Risco.txt","r");

    if (filePointerAux == NULL) {
        alertaSonoro();
        printf("\n     >>>>> N�o h� informa��es de pacientes para grava��o do arquivo <<<<<\n\n");
        printf("\n               >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
    } else {
        printf("\n            >>>>> Arquivo dispon�vel no diret�rio padr�o <<<<<\n\n");
        printf("\n             >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
        }
    fclose(filePointerAux);
    getch();
    system("cls");
}




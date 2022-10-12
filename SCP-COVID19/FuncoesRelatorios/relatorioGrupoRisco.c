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
        printf("\n     >>>>> Não há informações de pacientes para gravação do arquivo <<<<<\n\n");
        printf("\n               >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
    } else {
        printf("\n            >>>>> Arquivo disponível no diretório padrão <<<<<\n\n");
        printf("\n             >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
        }
    fclose(filePointerAux);
    getch();
    system("cls");
}




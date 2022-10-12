#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//Declara��o de vari�veis e fun��es
void listarDadosGravados();
void exibeCabecalho();
void alertaSonoro();


//Fun��o para apresentar dados gravados com grupo de risco
void listarDadosGravados() {
char linhaArquivo[20];

    exibeCabecalho();
    printf("\n          ----- Informa��es sobre pacientes no grupo de risco -----\n\n");


    FILE *filePointerAux;
    filePointerAux = fopen("Grupo_de_Risco.txt","r");

    if (filePointerAux == NULL) {
        alertaSonoro();
        printf("\n          >>>>> N�o h� informa��es de pacientes em arquivo <<<<<\n\n");
        printf("\n        >>>>> Informa��es sobre pacientes no grupo de risco <<<<<\n\n");
        printf("\n             >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
    } else {
        while (fgets(linhaArquivo, 20, filePointerAux) != NULL) {
            printf("              %s", linhaArquivo);
            }
            if (fgets(linhaArquivo, 20, filePointerAux) == NULL) {
                printf("\n\n          ------------------>   Fim de arquivo   <------------------\n\n\n");
                printf("\n             >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
            }
        }
    fclose(filePointerAux);
    getch();
    system("cls");

return;
}

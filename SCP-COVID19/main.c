#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>


/*
Sistema de Cadastro de Pacientes
Versão: 1.0
*/

//Declaração de variáveis e funções
char nomeUsuario[6];
char senhaUsuario[6];
void menuPrincipal();
void exibeCabecalho();
void alertaSonoro();



//Rotina principal de entrada
int main() {
setlocale(LC_ALL, "Portuguese");
int i;
int j;
int s;

    system("cls");
    while (1) {
        printf ("\n        ==============================================================\n");
        printf ("        ||                                                          ||\n");
        printf ("        ||        Sistema de Cadastro de Pacientes - Covid19        ||\n");
        printf ("        ||                          v1.0                            ||\n");
        printf ("        ||                                                          ||\n");
        printf ("        ||                                                          ||\n");
        printf ("        ||                                                          ||\n");
        printf ("        ||                  -- Login de Usuário --                  ||\n");
        printf ("        ||                                                          ||\n");
        printf ("        ||                                                          ||\n");
        printf ("        ||                                                          ||\n");
        printf ("        ||                      Unip Campinas                       ||\n");
        printf ("        ||                          2020                            ||\n");
        printf ("        ||                                                          ||\n");
        printf ("        ==============================================================\n\n");


        for (i = 3; i > 0; i--) {
            printf("\n         --> Usuário: ");
            fflush(stdin);
            fgets(nomeUsuario,6, stdin);
            nomeUsuario[strcspn(nomeUsuario, "\n")] = 0;

            if (strcmp(nomeUsuario,"unip") == 0) {

                for (j = 3; j > 0; j--) {
                    printf("\n         --> Senha  : ");
                    fflush(stdin);
                    fgets(senhaUsuario,6, stdin);
                    senhaUsuario[strcspn(senhaUsuario, "\n")] = 0;



                    if (strcmp(senhaUsuario,"unip") == 0) {
                        system("cls");
                        menuPrincipal();
                        exibeCabecalho();
                        printf ("        ==============================================================\n");
                        printf ("        ||                                                          ||\n");
                        printf ("        ||                                                          ||\n");
                        printf ("        ||          >>>>> Fim do programa. Até logo! <<<<<          ||\n");
                        printf ("        ||                                                          ||\n");
                        printf ("        ||       >>>>> Digite qualquer tecla para sair <<<<<        ||\n");
                        printf ("        ||                                                          ||\n");
                        printf ("        ||                                                          ||\n");
                        printf ("        ==============================================================\n\n");
                        getch();
                        return 0;
                    } else {
                        alertaSonoro();
                        printf ("             >>>>> Senha inválida. Mais %d tentativas <<<<<\n", j - 1);

                        if (j == 1) {
                            return 0;
                            }
                        }
                }
            } else {
                alertaSonoro();
                printf ("             >>>>> Usuário inválido. Mais %d tentativas <<<<<\n", i - 1);

                if (i == 1) {
                    return 0;
                    }
                }
        }
}

return 0;
}

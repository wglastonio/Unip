#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// Funções
int coletaOpcaoMenu();
void menuRelatorios();
void menuCadastro();
void exibeCabecalho();
void alertaSonoro();


// Estruturas de dados dos pacientes
struct endereco {
    char rua[41];
    char bairro[21];
    char cidade[21];
    char estado[3];
    char numeroResidencia[6];
    char cep[9];
} end;


struct comorbidades {
    char diabetes[2];
    char obesidade[2];
    char hipertensao[2];
    char tuberculose[2];
    char outraComorbidade[2];
} comorb;


struct cadastroPaciente {
    char nome[41];
    char dataNascimento[9];
    char email[41];
    char dataDiagnostico[9];
    struct endereco end;
    char cpf[12];
    char telefone[12];
    struct comorbidades comorb;
} campo;


/* Menu principal */
void menuPrincipal() {
int opcaoNum;
    do {

    exibeCabecalho();

    printf ("        ======================  Menu Principal  ======================\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 1 -> Cadastro de Pacientes                               ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 2 -> Relatórios                                          ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        || 3 -> Sair                                                ||\n");
    printf ("        ||                                                          ||\n");
    printf ("        ==============================================================\n\n");
    printf ("        Entre com a opção desejada: ");

    opcaoNum = coletaOpcaoMenu();

    switch(opcaoNum) {
        case 1:
            system("cls");
            menuCadastro();
            system("cls");
            break;

        case 2:
            system("cls");
            menuRelatorios();
            system("cls");
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
        } while ((opcaoNum < 1) || (opcaoNum > 3));

    menuPrincipal();
    return;
}

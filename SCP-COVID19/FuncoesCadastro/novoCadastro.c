#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>


// Lista de funções e variáveis
struct cadastroPaciente;
char snOption[3];
void exibeCabecalho();
void alertaSonoro();
int idade;
int anoAtual = 0;
int mesAtual = 0;
int diaAtual = 0;
int buscaAnoAtual();
int buscaMesAtual();
int buscaDiaAtual();
struct tm *dataHoraAtual;
time_t segundosAcumulados;
int i;
int entradaOK;
int arroba;
int ponto;
int grupoRisco;
int arquivoExiste = 0;



// Estruturas de dados dos pacientes
struct endereco {
    char rua[51];
    char bairro[31];
    char cidade[31];
    char estado[4];
    int numeroResidencia;
    char cep[11];
} ;


struct comorbidades {
    char diabetes[3];
    char obesidade[3];
    char hipertensao[3];
    char tuberculose[3];
    char outraComorbidade[3];
} ;


struct cadastroPaciente {
    char nome[51];
    int anoNascimento;
    int mesNascimento;
    int diaNascimento;
    int anoDiagnostico;
    int mesDiagnostico;
    int diaDiagnostico;
    int idade;
    char email[41];
    char dataDiagnostico[9];
    struct endereco end;
    char cpf[16];
    char telefone[17];
    struct comorbidades comorb;
};

struct cadastroPaciente campo = {0};
struct cadastroPaciente calculaIdade(struct cadastroPaciente temp);

// Rotina para coleta de dados do paciente
void novoCadastro() {
setlocale(LC_ALL, "Portuguese");

    exibeCabecalho();
    printf("         ----- Dados Pessoais -----\n");

    do {
        printf("               Nome: ");
        fflush(stdin);
        fgets(campo.nome,50,stdin);
        campo.nome[strcspn(campo.nome, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.nome[i] != '\0'; i++) {
            if (isalpha(campo.nome[i]) || isspace(campo.nome[i])) {
                campo.nome[i] = toupper(campo.nome[i]);
            } else {
                entradaOK = 0;
                }
        }
        if (strlen(campo.nome) == 0) {
            entradaOK = 0;
        }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

    do {
        printf("               CPF: ");
        fflush(stdin);
        fgets(campo.cpf, 16, stdin);
        campo.cpf[strcspn(campo.cpf, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.cpf[i] != '\0'; i++) {
            if (!isdigit(campo.cpf[i])) {
                entradaOK = 0;
            }
        }

        if (strlen(campo.cpf) != 11) {
            entradaOK = 0;
        }

        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

    for (i = 10; i > 8 ;i--) {
        campo.cpf[i+3] = campo.cpf[i];
    }
    for (i = 8; i > 5 ;i--) {
        campo.cpf[i+2] = campo.cpf[i];
    }

    for (i = 5; i > 3 ;i--) {
        campo.cpf[i+1] = campo.cpf[i];
    }
    campo.cpf[3] = '.';
    campo.cpf[7] = '.';
    campo.cpf[11] = '-';

    do {
        printf("               Telefone: ");
        fflush(stdin);
        fgets(campo.telefone, 17, stdin);
        campo.telefone[strcspn(campo.telefone, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.telefone[i] != '\0'; i++) {
            if (!isdigit(campo.telefone[i])) {
                entradaOK = 0;
            }
        }
        if (strlen(campo.telefone) != 10 && strlen(campo.telefone) != 11) {
            entradaOK = 0;
        }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

    if (strlen(campo.telefone) == 10) {
        for (i = 9; i > 5 ;i--) {
            campo.telefone[i+3] = campo.telefone[i];
        }
        for (i = 5; i > 1 ;i--) {
            campo.telefone[i+2] = campo.telefone[i];
        }
        for (i = 1; i >= 0 ;i--) {
            campo.telefone[i+1] = campo.telefone[i];
        }
        campo.telefone[0] = '(';
        campo.telefone[3] = ')';
        campo.telefone[8] = '-';
    }

        if (strlen(campo.telefone) == 11) {
        for (i = 10; i > 6 ;i--) {
            campo.telefone[i+3] = campo.telefone[i];
        }
        for (i = 6; i > 1 ;i--) {
            campo.telefone[i+2] = campo.telefone[i];
        }
        for (i = 1; i >= 0 ;i--) {
            campo.telefone[i+1] = campo.telefone[i];
        }
        campo.telefone[0] = '(';
        campo.telefone[3] = ')';
        campo.telefone[9] = '-';
    }

    do {
        printf("               Email: ");
        fflush(stdin);
        fgets(campo.email, 41, stdin);
        campo.email[strcspn(campo.email, "\n")] = 0;
        entradaOK = 1;
        arroba = 0;
        ponto = 0;

        for(i = 0; campo.email[i] != '\0'; i++) {
            if (!isalnum(campo.email[i]) && campo.email[i] != '@' && campo.email[i] != '.') {
                entradaOK = 0;
            }
            if (isspace(campo.email[i])) {
                entradaOK = 0;
            }

            if (campo.email[i+1] == '@') {
                arroba++;
                if (arroba > 1){
                    entradaOK = 0;
                }
            }

            if (campo.email[i+1] == '.') {
                ponto++;
            }

            if ((campo.email[i] == '@') && ((campo.email[i+1] == '@' || campo.email[i+1] == '.'))) {
                        entradaOK = 0;
            }

            if ((campo.email[i] == '.') && ((campo.email[i+1] == '@' || campo.email[i+1] == '.'))) {
                        entradaOK = 0;
            }
        }

        if (!isalnum(campo.email[0])) {
            entradaOK = 0;
        }

        if (arroba == 0 || ponto == 0) {
            entradaOK = 0;
        }

        if (strlen(campo.email) == 0) {
            entradaOK = 0;
        }

        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }

        if (entradaOK == 1) {
            campo.email[i] = toupper(campo.nome[i]);
        }

    } while (entradaOK == 0);

    do {
        printf("\n         ----- Data de Nascimento -----\n");
        printf("               Ano: (aaaa): ");
        fflush(stdin);
        scanf("%d", &campo.anoNascimento);

        if ((campo.anoNascimento <= 0) || (campo.anoNascimento > buscaAnoAtual())) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while ((campo.anoNascimento <= 0) || (campo.anoNascimento > buscaAnoAtual()));

    do {
        printf("               Mês (mm): ");
        fflush(stdin);
        scanf("%d", &campo.mesNascimento);

        if ((campo.mesNascimento <= 0) || campo.mesNascimento > 12){
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while ((campo.mesNascimento <= 0) || campo.mesNascimento > 12);

    do {
        printf("               Dia (dd): ");
        fflush(stdin);
        scanf("%d", &campo.diaNascimento);

        if ((campo.diaNascimento <= 0) || ((campo.mesNascimento == 2) && (campo.diaNascimento > 28)) ||
            ((campo.mesNascimento == 4 || campo.mesNascimento == 6 || campo.mesNascimento == 9 ||
              campo.mesNascimento == 11) && (campo.diaNascimento > 30)) || ((campo.mesNascimento == 1 ||
              campo.mesNascimento == 3 || campo.mesNascimento == 5 || campo.mesNascimento == 7 ||
              campo.mesNascimento == 8 || campo.mesNascimento == 10 || campo.mesNascimento == 12) &&
              campo.diaNascimento > 31)){
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while ((campo.diaNascimento <= 0) || ((campo.mesNascimento == 2) && (campo.diaNascimento > 28)) ||
            ((campo.mesNascimento == 4 || campo.mesNascimento == 6 || campo.mesNascimento == 9 ||
              campo.mesNascimento == 11) && (campo.diaNascimento > 30)) || ((campo.mesNascimento == 1 ||
              campo.mesNascimento == 3 || campo.mesNascimento == 5 || campo.mesNascimento == 7 ||
              campo.mesNascimento == 8 || campo.mesNascimento == 10 || campo.mesNascimento == 12) &&
              campo.diaNascimento > 31));

    if (((campo.mesNascimento > buscaMesAtual())) || (((campo.mesNascimento >= buscaMesAtual())) &&
        (campo.diaNascimento > buscaDiaAtual()))) {
        campo.idade = buscaAnoAtual() - campo.anoNascimento - 1;
    } else {
        campo.idade = buscaAnoAtual() - campo.anoNascimento;
        }

    do {
        printf("\n         ----- Endereço -----\n");
        printf("               Rua/Av: ");
        fflush(stdin);
        fgets(campo.end.rua, 41, stdin);
        campo.end.rua[strcspn(campo.end.rua, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.end.rua[i] != '\0'; i++) {
            if (isalnum(campo.end.rua[i]) || isspace(campo.end.rua[i])) {
                campo.end.rua[i] = toupper(campo.end.rua[i]);
            } else {
                entradaOK = 0;
                }
        }
        if (strlen(campo.end.rua) == 0) {
            entradaOK = 0;
        }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

     do {
        printf("               Número: ");
        fflush(stdin);
        scanf("%d", &campo.end.numeroResidencia);

        if (campo.end.numeroResidencia <= 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
     } while (campo.end.numeroResidencia <= 0);

    do {
        printf("               Bairro: ");
        fflush(stdin);
        fgets(campo.end.bairro, 21, stdin);
        campo.end.bairro[strcspn(campo.end.bairro, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.end.bairro[i] != '\0'; i++) {
            if (isalpha(campo.end.bairro[i]) || isspace(campo.end.bairro[i])) {
                campo.end.bairro[i] = toupper(campo.end.bairro[i]);
            } else {
                entradaOK = 0;
                }
        }
        if (strlen(campo.end.bairro) == 0) {
            entradaOK = 0;
        }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

     do {
        printf("               Cidade: ");
        fflush(stdin);
        fgets(campo.end.cidade, 21, stdin);
        campo.end.cidade[strcspn(campo.end.cidade, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.end.cidade[i] != '\0'; i++) {
            if (isalnum(campo.end.cidade[i]) || isspace(campo.end.cidade[i])) {
                campo.end.cidade[i] = toupper(campo.end.cidade[i]);
            } else {
                entradaOK = 0;
                }
        }
        if (strlen(campo.end.cidade) == 0) {
            entradaOK = 0;
        }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

     do {
        printf("               Estado: ");
        fflush(stdin);
        fgets(campo.end.estado, 4, stdin);
        campo.end.estado[strcspn(campo.end.estado, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.end.estado[i] != '\0'; i++) {
            if (isalpha(campo.end.estado[i])) {
                campo.end.estado[i] = toupper(campo.end.estado[i]);
            } else {
                entradaOK = 0;
                }
        }
        if (strlen(campo.end.estado) != 2) {
            entradaOK = 0;
        }

        if (strlen(campo.end.estado) == 0) {
            entradaOK = 0;
        }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

    do {
        printf("               CEP: ");
        fflush(stdin);
        fgets(campo.end.cep, 10, stdin);
        campo.end.cep[strcspn(campo.end.cep, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.end.cep[i] != '\0'; i++) {
            if (!isdigit(campo.end.cep[i])) {
                entradaOK = 0;
            }
        }
        if (strlen(campo.end.cep) != 8) {
            entradaOK = 0;
        }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

    for (i = 7; i > 4 ;i--) {
        campo.end.cep[i+2] =  campo.end.cep[i];
    }
    for (i = 4; i > 1 ;i--) {
        campo.end.cep[i+1] =  campo.end.cep[i];
    }
    campo.end.cep[2] = '.';
    campo.end.cep[6] = '-';

    do {
        printf("\n         ----- Data do Diagnóstico -----\n");
        printf("               Ano (aaaa): ");
        fflush(stdin);
        scanf("%d", &campo.anoDiagnostico);

        if ((campo.anoDiagnostico == 0 ) || (campo.anoDiagnostico < 2019) || (campo.anoDiagnostico > buscaAnoAtual())) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (campo.anoDiagnostico <= 0 || (campo.anoDiagnostico < 2019) || (campo.anoDiagnostico > buscaAnoAtual()));

    do {
        printf("               Mês (mm): ");
        fflush(stdin);
        scanf("%d", &campo.mesDiagnostico);
        entradaOK = 1;

        if ((campo.mesDiagnostico <= 0) || campo.mesDiagnostico > 12){
            entradaOK = 0;
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }

        if (campo.anoDiagnostico == buscaAnoAtual() && campo.mesDiagnostico > buscaMesAtual()) {
            entradaOK = 0;
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

    do {
        printf("               Dia (dd): ");
        fflush(stdin);
        scanf("%d", &campo.diaDiagnostico);
        entradaOK = 1;

        if ((campo.diaDiagnostico <= 0) || ((campo.mesDiagnostico == 2) && (campo.diaDiagnostico > 28)) ||
           ((campo.mesDiagnostico == 4 || campo.mesDiagnostico == 6 || campo.mesDiagnostico == 9 ||
             campo.mesDiagnostico == 11) && (campo.diaDiagnostico > 30)) || ((campo.mesDiagnostico == 1 ||
             campo.mesDiagnostico == 3 || campo.mesDiagnostico == 5 || campo.mesDiagnostico == 7 ||
             campo.mesDiagnostico == 8 || campo.mesDiagnostico == 10 || campo.mesDiagnostico == 12) &&
             campo.diaDiagnostico > 31)){
            entradaOK = 0;
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
        if (campo.anoDiagnostico == buscaAnoAtual() && campo.mesDiagnostico >= buscaMesAtual() &&
            campo.diaDiagnostico > buscaDiaAtual())  {
            entradaOK = 0;
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);

    printf("\n         ----- Verificar comorbidades -----\n");

    do {
        printf("               Diabetes (s/n): ");
        fflush(stdin);
        fgets(campo.comorb.diabetes, 3, stdin);
        campo.comorb.diabetes[strcspn(campo.comorb.diabetes, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.comorb.diabetes[i] != '\0'; i++) {
            if (!isalpha(campo.comorb.diabetes[i])) {
                entradaOK = 0;
            } else {
                campo.comorb.diabetes[i] = toupper(campo.comorb.diabetes[i]);
                }
        }

        if (strlen(campo.comorb.diabetes) != 1) {
            entradaOK = 0;
        }   else if ((int)campo.comorb.diabetes[0] != 78 && (int)campo.comorb.diabetes[0] != 83) {
                entradaOK = 0;
                }

        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);


    do {
        printf("               Obesidade (s/n): ");
        fflush(stdin);
        fgets(campo.comorb.obesidade, 3, stdin);
        campo.comorb.obesidade[strcspn(campo.comorb.obesidade, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.comorb.obesidade[i] != '\0'; i++) {
            if (!isalpha(campo.comorb.obesidade[i])) {
                entradaOK = 0;
            } else {
                campo.comorb.obesidade[i] = toupper(campo.comorb.obesidade[i]);
                }
        }

        if (strlen(campo.comorb.obesidade) != 1) {
            entradaOK = 0;
        }   else if ((int)campo.comorb.obesidade[0] != 78 && (int)campo.comorb.obesidade[0] != 83) {
                entradaOK = 0;
                }

        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);


    do {
        printf("               Hipertensao (s/n): ");
        fflush(stdin);
        fgets(campo.comorb.hipertensao, 3, stdin);
        campo.comorb.hipertensao[strcspn(campo.comorb.hipertensao, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.comorb.hipertensao[i] != '\0'; i++) {
            if (!isalpha(campo.comorb.hipertensao[i])) {
                entradaOK = 0;
            } else {
                campo.comorb.hipertensao[i] = toupper(campo.comorb.hipertensao[i]);
                }
        }

        if (strlen(campo.comorb.hipertensao) != 1) {
            entradaOK = 0;
        }   else if ((int)campo.comorb.hipertensao[0] != 78 && (int)campo.comorb.hipertensao[0] != 83) {
                entradaOK = 0;
                }

        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);


    do {
        printf("               Tuberculose (s/n): ");
        fflush(stdin);
        fgets(campo.comorb.tuberculose, 3, stdin);
        campo.comorb.tuberculose[strcspn(campo.comorb.tuberculose, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.comorb.tuberculose[i] != '\0'; i++) {
            if (!isalpha(campo.comorb.tuberculose[i])) {
                entradaOK = 0;
            } else {
                campo.comorb.tuberculose[i] = toupper(campo.comorb.tuberculose[i]);
                }
        }

        if (strlen(campo.comorb.tuberculose) != 1) {
            entradaOK = 0;
        }   else if ((int)campo.comorb.tuberculose[0] != 78 && (int)campo.comorb.tuberculose[0] != 83) {
                entradaOK = 0;
                }

        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);


    do {
        printf("               Outras (s/n): ");
        fflush(stdin);
        fgets(campo.comorb.outraComorbidade, 3, stdin);
        campo.comorb.outraComorbidade[strcspn(campo.comorb.outraComorbidade, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; campo.comorb.outraComorbidade[i] != '\0'; i++) {
            if (!isalpha(campo.comorb.outraComorbidade[i])) {
                entradaOK = 0;
            } else {
                campo.comorb.outraComorbidade[i] = toupper(campo.comorb.outraComorbidade[i]);
                }
        }

        if (strlen(campo.comorb.outraComorbidade) != 1) {
            entradaOK = 0;
        }   else if ((int)campo.comorb.outraComorbidade[0] != 78 && (int)campo.comorb.outraComorbidade[0] != 83) {
                entradaOK = 0;
                }

        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }
    } while (entradaOK == 0);


//Mostra informações coletadas para confirmação do usuário

    system("cls");
    exibeCabecalho();

    printf("         ----- Verificar as Informações do Paciente -----\n\n");
    printf("               Nome            : %s\n", campo.nome);
    printf("               CPF             : %s\n", campo.cpf);
    printf("               Telefone        : %s\n", campo.telefone);
    printf("               Email           : %s\n", campo.email);
    printf("               Data Nascimento : %02d/%02d/%d\n", campo.diaNascimento, campo.mesNascimento, campo.anoNascimento);
    printf("               Idade           : %d\n", campo.idade);

    printf("               Rua/Av          : %s\n", campo.end.rua);
    printf("               Número          : %d\n", campo.end.numeroResidencia);
    printf("               Bairro          : %s\n", campo.end.bairro);
    printf("               Cidade          : %s\n", campo.end.cidade);
    printf("               Estado          : %s\n", campo.end.estado);
    printf("               CEP             : %s\n", campo.end.cep);

    printf("               Data Nascimento : %02d/%02d/%d\n", campo.diaDiagnostico, campo.mesDiagnostico, campo.anoDiagnostico);

    printf("               Diabetes        : %s\n", campo.comorb.diabetes);
    printf("               Obesidade       : %s\n", campo.comorb.obesidade);
    printf("               Hipertensão     : %s\n", campo.comorb.hipertensao);
    printf("               Tuberculose     : %s\n", campo.comorb.tuberculose);
    printf("               Outras          : %s\n", campo.comorb.outraComorbidade);


// Se informações estiverem corretas, grava dados em arquivo
    do {
        printf("\n         >>>>> Confirma Gravação de Dados (s/n) ? ");
        fflush(stdin);
        fgets(snOption, 3, stdin);
        snOption[strcspn(snOption, "\n")] = 0;
        entradaOK = 1;

        for(i = 0; snOption[i] != '\0'; i++) {
            if (!isalpha(snOption[i])) {
                entradaOK = 0;
            }
        }

        if (strlen(snOption) != 1) {
            entradaOK = 0;
        }   else if ((int)snOption[0] != 78 && (int)snOption[0] != 83 && (int)snOption[0] != 110 && (int)snOption[0] != 115) {
                entradaOK = 0;
                }
            else if ((int)snOption[0] == 83 || (int)snOption[0] == 115) {
                FILE *filePointer;
                filePointer = fopen("Cadastro_De_Pacientes.txt","a");

                if (filePointer == NULL) {
                    alertaSonoro();
                    printf("\n                >>>>> Não foi possível ler o arquivo <<<<<\n\n");
                    break;
                }

                fprintf(filePointer,"%s\t%s\t%s\t%s\t%d/%d/%d\t%d\t%s\t%d\t%s\t%s\t%s\t%s\t%d/%d/%d\t%s\t%s\t%s\t%s\t%s\n",
                                campo.nome,campo.cpf,campo.telefone,campo.email,campo.diaNascimento,campo.mesNascimento,
                                campo.anoNascimento,campo.idade,campo.end.rua,campo.end.numeroResidencia,campo.end.bairro,
                                campo.end.cidade,campo.end.estado,campo.end.cep,campo.diaDiagnostico,campo.mesDiagnostico,
                                campo.anoDiagnostico,campo.comorb.diabetes,campo.comorb.obesidade,campo.comorb.hipertensao,
                                campo.comorb.tuberculose,campo.comorb.outraComorbidade);

                fclose(filePointer);

                //Verificar se paciente é grupo de risco e grava dados em arquivo

                grupoRisco = 0;
                if (campo.idade >= 65) {
                    grupoRisco = 1;
                }

                if ((int)campo.comorb.diabetes[0] == 83 || (int)campo.comorb.hipertensao[0] == 83 ||
                    (int)campo.comorb.obesidade[0] == 83 || (int)campo.comorb.tuberculose[0] == 83 ||
                    (int)campo.comorb.outraComorbidade[0] == 83) {
                    grupoRisco = 1;
                }

                FILE *filePointerAux;
                filePointerAux = fopen("Grupo_de_Risco.txt","r");
                if (filePointerAux == NULL) {
                        arquivoExiste = 0;
                    } else {
                        arquivoExiste = 1;
                        }
                fclose(filePointerAux);


                if (grupoRisco == 1) {
                    FILE *filePointer;
                    filePointer = fopen("Grupo_de_Risco.txt","a");

                    if (filePointer == NULL) {
                        alertaSonoro();
                        printf("\n                >>>>> Falha ao gravar arquivo de grupo de risco <<<<<\n\n");
                        break;
                    }

                    if (arquivoExiste == 0) {
                        fprintf(filePointer,"CEP\t\tIdade\n");
                        fprintf(filePointer,"%s\t%d\n",campo.end.cep,campo.idade);
                    } else if (arquivoExiste == 1) {
                        fprintf(filePointer,"%s\t%d\n",campo.end.cep,campo.idade);
                        }

                fclose(filePointer);
                }
                system("cls");
            }
            else if ((int)snOption[0] == 78 || (int)snOption[0] == 110) {
                system("cls");
            }
        if (entradaOK == 0) {
            alertaSonoro();
            printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        }

    } while(entradaOK == 0);

return;
}


//Funções para busca de data atual

int buscaAnoAtual() {
    time(&segundosAcumulados);
    dataHoraAtual = localtime(&segundosAcumulados);
    anoAtual = (dataHoraAtual->tm_year+1900);
    return anoAtual;
}

int buscaMesAtual() {
    time(&segundosAcumulados);
    dataHoraAtual = localtime(&segundosAcumulados);
    mesAtual = (dataHoraAtual->tm_mon+1);
    return mesAtual;
}

int buscaDiaAtual() {
    time(&segundosAcumulados);
    dataHoraAtual = localtime(&segundosAcumulados);
    diaAtual = (dataHoraAtual->tm_mday);
    return diaAtual;
}


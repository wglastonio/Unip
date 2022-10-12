#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>



// Lista de funções e variáveis
void exibeCabecalho();
int mostraInformacoes();
void alertaSonoro();
char estruturaDados();
int proximo = 0;
int tamanhoString;
char dadosPaciente[300];
struct paciente;


// Variáveis para armazenar dados dos pacientes
struct paciente {
    char nome[51];
    char cpf[18];
    char telefone[17];
    char email[41];
    char dataNascimento[12];
    char idade[4];
    char rua[51];
    char numeroResidencia[8];
    char bairro[31];
    char cidade[31];
    char estado[4];
    char cep[11];
    char dataDiagnostico[12];
    char obesidade[3];
    char diabetes[3];
    char hipertensao[3];
    char tuberculose[3];
    char outraComorbidade[3];
};

struct paciente dado = {0};

//Função mostra cadastro na tela

void consultaCadastro() {

    FILE *filePointer;
    filePointer = fopen("Cadastro_De_Pacientes.txt","r");

    if (filePointer == NULL) {
        alertaSonoro();
        exibeCabecalho();
        printf("\n          >>>>> Não há informações de pacientes para leitura <<<<<\n\n");
        printf("\n              >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
        getch();
        system("cls");
        return;
    } else {

            while (fgets(dadosPaciente, 300, filePointer) != NULL) {
                estruturaDados(dadosPaciente);
                mostraInformacoes();

                if (proximo != 83) {
                    system("cls");
                    break;
                }

            }
            if (fgets(dadosPaciente, 300, filePointer) == NULL) {
                return;
            }
    }
    fclose(filePointer);

return;
}


// Função para estruturar dados a serem apresentados

char estruturaDados() {
setlocale(LC_ALL, "Portuguese");

int i = 0;
int j = 0;

tamanhoString = strlen(dadosPaciente);

        for(i = 0; i < tamanhoString; i++) {
            if (dadosPaciente[i] != '\t') {
                dado.nome[j+1] = '\0';
                dado.nome[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.cpf[j+1] = '\0';
                dado.cpf[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.telefone[j+1] = '\0';
                dado.telefone[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.email[j+1] = '\0';
                dado.email[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.dataNascimento[j+1] = '\0';
                dado.dataNascimento[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.idade[j+1] = '\0';
                dado.idade[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.rua[j+1] = '\0';
                dado.rua[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.numeroResidencia[j+1] = '\0';
                dado.numeroResidencia[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.bairro[j+1] = '\0';
                dado.bairro[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                    dado.cidade[j+1] = '\0';
                dado.cidade[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.estado[j+1] = '\0';
                dado.estado[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.cep[j+1] = '\0';
                dado.cep[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.dataDiagnostico[j+1] = '\0';
                dado.dataDiagnostico[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.obesidade[j+1] = '\0';
                dado.obesidade[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.diabetes[j+1] = '\0';
                dado.diabetes[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.hipertensao[j+1] = '\0';
                dado.hipertensao[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.tuberculose[j+1] = '\0';
                dado.tuberculose[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }

        i++;
        j = 0;
        for(; i < tamanhoString; i++){
            if (dadosPaciente[i] != '\t') {
                dado.outraComorbidade[j+1] = '\0';
                dado.outraComorbidade[j] = dadosPaciente[i];
                j++;
            } else {
                break;
                }
        }
return 0;
}


// Função para mostrar informações lidas do arquivo na tela

int mostraInformacoes() {
char verProximo[3];
int entradaOK;
int i;

do {
    system("cls");
    exibeCabecalho();
    printf("         ----- Informações do Paciente -----\n\n");
    printf("               Nome            : %s\n", dado.nome);
    printf("               CPF             : %s\n", dado.cpf);
    printf("               Telefone        : %s\n", dado.telefone);
    printf("               Email           : %s\n", dado.email);
    printf("               Data Nascimento : %s\n", dado.dataNascimento);
    printf("               Rua/Av          : %s\n", dado.rua);
    printf("               Número          : %s\n", dado.numeroResidencia);
    printf("               Bairro          : %s\n", dado.bairro);
    printf("               Cidade          : %s\n", dado.cidade);
    printf("               Estado          : %s\n", dado.estado);
    printf("               CEP             : %s\n", dado.cep);
    printf("               Data Diagnóstico: %s\n", dado.dataDiagnostico);
    printf("               Diabetes        : %s\n", dado.obesidade);
    printf("               Obesidade       : %s\n", dado.diabetes);
    printf("               Hipertensão     : %s\n", dado.hipertensao);
    printf("               Tuberculose     : %s\n", dado.tuberculose);
    printf("               Outras          : %s\n", dado.outraComorbidade);
    printf("\n         -----> Ver proximo (s/n)? ");

    fflush(stdin);
    fgets(verProximo, 3, stdin);
    verProximo[strcspn(verProximo, "\n")] = 0;
    entradaOK = 1;

    for (i = 0; verProximo[i] != '\0'; i++) {
        verProximo[i] = toupper(verProximo[i]);
    }

    if (strlen(verProximo) != 1) {
        entradaOK = 0;
    }   else if ((int)verProximo[0] != 78 && (int)verProximo[0] != 83) {
            entradaOK = 0;
            }
        else if ((int)verProximo[0] == 83) {
            proximo = (int)verProximo[0];
            system ("cls");
            return (proximo);
            }
        else if ((int)verProximo[0] == 78) {
            proximo = (int)verProximo[0];
            system ("cls");
            return 0;
            }

    if (entradaOK == 0) {
        system("cls");
        alertaSonoro();
        exibeCabecalho();
        printf ("\n                >>>>> Valor inválido. Tente novamente <<<<<\n\n");
        printf("\n              >>>>> Digite qualquer tecla para continuar <<<<<\n\n");
        getch();
        system("cls");
    }

} while (entradaOK == 0);

return 0;
}

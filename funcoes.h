//
// Created by panta on 17/05/2021.
//

#ifndef LP1_PROJETO_FUNCOES_H
#define LP1_PROJETO_FUNCOES_H

#endif //LP1_PROJETO_FUNCOES_H

//declaração das estruturas
typedef struct{

    char cargo[25];
    int escolaridade;
    char sexo;
    int idadeMin;
    int idadeMax;
    float salario;
    int vagasDisponiveis;

} Vagas;

typedef struct{

    int idade;
    char sexo;
    float salario;
    int escolaridade;

} Dados;

//declaração das funções
int menuUm();
int menuDois();
int entrarIdade();
char entrarSexo();
float entrarSalario();
int entrarEscolaridade();
Dados buscarVaga(Dados d, Vagas v[], int tam);
void vagasDisponiveis(Vagas v[], int tam);
int leArquivo(Vagas v[], int tam);
void escreveArquivo(Vagas v[], int quantidadeVagas);

//inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//inclui a biblioteca das funções criadas
#include "funcoes.h"

//contrução das funções

//função que executa o menu 1 e retorna um valor inteiro
int menuUm(){

    //declaração das variáveis
    int iniciar = 0;

    //laço para que não seja aceito nenhum valor diferente dos desejados
    do{
        printf("Menu 1\n0 - Iniciar o programa\n1 - Finalizar o programa\n");
        scanf("%d", &iniciar);
        system("CLS");
    }while(iniciar != 0 && iniciar != 1);

    //retorna variável
    return iniciar;
}

//função que executa o menu 2 e retorna um valor inteiro
int menuDois() {

    //declaração das variaveis
    int opcao = 0;

    do{
        printf("Menu 2\nEntrada de dados do candidato:\n");
        printf("0 - Entrar com idade\n1 - Entrar com o sexo\n2 - Entrar com a pretensao salarial\n3 - Entrar com o nivel de escolaridade\n4 - Buscar vaga\n5 - Quantidade de vagas disponiveis\n6 - Voltar ao menu anterior\n");
        scanf("%d", &opcao);
        system("CLS");
    }while(opcao < 0 || opcao > 6);

    //retorna variável
    return opcao;
}

//a função recebe do usuario a idade e a retorna como um inteiro
int entrarIdade(){

    //declaração das variaveis
    int idade = 0;

    //laço para evitar que qualquer valor diferente do desejado seja aceito
    do{
        printf("Informe a sua idade: ");
        scanf("%d", &idade);
        system("CLS");
    }while(idade < 16);

    //retorna variável
    return idade;

}

//a função recebe do usuario sexo e o retorna como um char
char entrarSexo(){

    //declaração das variaveis
    char sexo = 's';

    //laço para evitar que qualquer valor diferente do desejado seja aceito
    do{
        printf("Informe o sexo, digite F para feminino ou M para masculino: ");
        sexo = getchar();
        system("CLS");
    }while(sexo != 'F' && sexo != 'M');

    //retorna variável
    return sexo;
}

// a funcao recebe do usuario o salario e o retorna como um float
float entrarSalario(){

    //declaração das variaveis
    float salario = 0;

    //laço para evitar que qualquer valor diferente do desejado seja aceito
    do{
        printf("Informe a sua pretencao salarial: ");
        scanf("%f", &salario);
        system("CLS");
    }while(salario <= 0);

    //retorna variável
    return salario;
}

//funcao recebe uma estrutura de Dados e preenche o campo da escolaridade
int entrarEscolaridade(){

    //declaração das variavei
    int escolaridade = 0;

    //laço para evitar que qualquer valor diferente do desejado seja aceito
    do{
        printf("Nivel de escolaridade:\n0 - fundamental completo\n1 - ensino medio completo\n2 - superior completo.\n");
        scanf("%d", &escolaridade);
        system("CLS");
    }while(escolaridade < 0 && escolaridade > 2);

    return escolaridade;

}

/*a funcao recebe três valores, a estrutura Dados, um vetor de inteiro e o tamanho do vetor em inteiro,
usando esse parametro, realiza uma busca pelas vagas que os atendam e as exibe*/
Dados buscarVaga(Dados d, Vagas v[], int tam){

    //declaração das variaveis
    int i, escolher = 0, disponivel[tam], escolha = 0, continuar = 0;

    //mostra as vagas caso as informações necessarias tenham sido informadas
    if(d.idade != 0 && d.sexo != 's' && d.salario != 0 && d.escolaridade != -1){

        //reinicia o vetor que é preenchido com um numero para cada vaga disponivel
        for(i = 0; i < tam; i++){
            disponivel[i] = 0;
        }

        //mostra as vagas disponiveis
        for(i = 0; i < tam; i++){
            if((((d.idade >= v[i].idadeMin) && (d.idade <= v[i].idadeMax)) || ((d.idade >= v[i].idadeMin) && (v[i].idadeMax == 0))) && ((d.sexo == v[i].sexo) || (v[i].sexo == 'X')) && (d.escolaridade >= v[i].escolaridade) && (v[i].vagasDisponiveis > 0)){
                printf("%d - %s. | Salario - R$ %.2f\n", i, v[i].cargo, v[i].salario);
                disponivel[i] = i + 1;
                escolher = 1;
            }
        }

        //informa se não houver vagas disponiveis
        if(escolher == 1){

            //laço para evitar que qualquer valor diferente do desejado seja aceito
            do{
                printf("Escolha a vaga ou digite %d para retornar ao Menu 2.\n", tam);
                scanf("%d", &escolha);

                //verifica se o numero informado é referente a alguma das vagas disponiveis
                for(i = 0; i < tam; i++){
                    if(escolha - disponivel[i] == -1) continuar = 1;
                }

            }while(continuar != 1 && escolha != tam);

            //diminui a quantidade de vagas dependendo da opção escolhida
            v[escolha].vagasDisponiveis -= 1;
            system("CLS");

        } else {
            printf("Nao ha vagas disponiveis.\n");
            printf("Pressione qualquer tecla...");
            getch();
            system("CLS");
        }

        //reinicia as váriaveis
        d.idade = 0;
        d.escolaridade = -1;
        d.sexo = 's';
        d.salario = 0;

        //informa se os dados necessarios não foram informados
    } else {
        printf("Todos os dados necessarios nao foram informados.\n\n");
        printf("Pressione qualquer tecla...");
        getch();
        system("CLS");
    }

    //retorna variável
    return d;
}

//a função que recebe um vetor tipo inteiro e o tamanho em inteiro e exibe a quatidade de vagas disponiveis
void vagasDisponiveis(Vagas v[], int tam){

    //declaração das variaveis
    int i, somaVagas = 0;

    //laço para somar as vagas
    for(i = 0; i < tam; i++){
        somaVagas += v[i].vagasDisponiveis;
    }

    //estrutura de seleção para mostrar se existem ou não vagas disponiveis.
    if(somaVagas > 0) {

        printf("Existem %d vagas disponiveis.\n", somaVagas);

        for(i = 0; i < tam; i++){
            if(v[i].vagasDisponiveis > 0){
                printf("%d vagas para %s.\n", v[i].vagasDisponiveis, v[i].cargo);
            }
        }

    } else printf("Nao existem vagas disponiveis.\n\n");

    //volta para o menu 2 assim que for pressionada qualquer tecla
    printf("Pressione qualquer tecla...");
    getch();
    system("CLS");

}

//função que le as informações do arquivo
int leArquivo(Vagas v[], int tam){

    //cria um ponteiro
    FILE *vagas;

    //declaração das variaveis
    int i = 0, k, cargos = 0;
    char aux[25], escolaridade1[20], escolaridade2[20], escolaridade3[20];

    //coloca a informação da escolaridade em variaveis
    strncpy(escolaridade1, "Fundamental", sizeof(escolaridade1));
    strncpy(escolaridade2, "Medio", sizeof(escolaridade2));
    strncpy(escolaridade3, "Superior", sizeof(escolaridade3));

    //informa que não foi possivel ler o arquivo e finaliza o programa
    if((vagas = fopen("vagas.txt", "r")) == NULL){
        printf("Erro ao ler o arquivo!\n");
        printf("Preciona qualquer tecla para finalizar o programa...");
        getch();
        system("CLS");
        cargos = -1;
    } else {
        //faz a leitura de linha por linha do arquivo e dentro do while já é feita a leitura da primeira linha do arquivo
        while((fgets(aux, sizeof(aux), vagas) != NULL)){

            //usa-se a variavel k e um while para colocar \0 onde tiver \n
            k = 0;
            while(aux[k] != '\n') k++;
            aux[k] = '\0';
            //copia a informação da variavel auxiliar para a variavel cargo
            strncpy(v[i].cargo, aux, sizeof(v[i].cargo));
            printf("VOLTA %d\n", i);
            printf("%s\n", v[i].cargo);

            //faz a leitura da segunda linha, referente a escolaridade
            fgets(aux, sizeof(aux), vagas);
            //usa-se a variavel k e um while para colocar \0 onde tiver \n
            k = 0;
            while(aux[k] != '\n') k++;
            aux[k] = '\0';
            //compara a escolaridade lida do arquivo com a escolaridade dentro das variaveis que foram criadas acima, colocando um numero referente a escolaridade lida dentro do vetor das vagas
            if(strcmp(aux, escolaridade1) == 0) v[i].escolaridade = 0;
            if(strcmp(aux, escolaridade2) == 0) v[i].escolaridade = 1;
            if(strcmp(aux, escolaridade3) == 0) v[i].escolaridade = 2;
            printf("%d\n", v[i].escolaridade);

            //faz a leita da tercera linha, referente ao sexo
            fgets(aux, sizeof(aux), vagas);
            //usa-se a variavel k e um while para colocar \0 onde tiver \n
            k = 0;
            while(aux[k] != '\n') k++;
            aux[k] = '\0';
            //copia a informação da viavel auxiliar para a variavel sexo
            v[i].sexo = aux[0];
            printf("%c\n", v[i].sexo);

            //faz a leita da tercera linha, referente a idade minima
            fgets(aux, sizeof(aux), vagas);
            //usa-se a variavel k e um while para colocar \0 onde tiver \n
            k = 0;
            while(aux[k] != '\n') k++;
            aux[k] = '\0';
            //copia a informação da viavel auxiliar para a variavel idadeMin
            v[i].idadeMin = atoi(aux);
            printf("%d\n", v[i].idadeMin);

            //faz a leita da tercera linha, referente ao idade maxima
            fgets(aux, sizeof(aux), vagas);
            //usa-se a variavel k e um while para colocar \0 onde tiver \n
            k = 0;
            while(aux[k] != '\n') k++;
            aux[k] = '\0';
            //copia a informação da viavel auxiliar para a variavel idadeMax
            v[i].idadeMax = atoi(aux);
            printf("%d\n", v[i].idadeMax);

            //faz a leita da tercera linha, referente ao salario
            fgets(aux, sizeof(aux), vagas);
            //usa-se a variavel k e um while para colocar \0 onde tiver \n
            k = 0;
            while(aux[k] != '\n') k++;
            aux[k] = '\0';
            //copia a informação da viavel auxiliar para a variavel salario
            v[i].salario = atof(aux);
            printf("%.2f\n", v[i].salario);

            //faz a leita da tercera linha, referente aos vagas disponiveis
            fgets(aux, sizeof(aux), vagas);
            //usa-se a variavel k e um while para colocar \0 onde tiver \n
            k = 0;
            while(aux[k] != '\n') k++;
            aux[k] = '\0';
            //copia a informação da viavel auxiliar para a variavel vagasDisponiveis
            v[i].vagasDisponiveis = atoi(aux);
            printf("%d\n\n", v[i].vagasDisponiveis);

            //le a linha em branco do arquivo
            fgets(aux, sizeof(aux), vagas);
            i++;
            cargos++;
        }

        printf("Os dados foram importados para o sistema com sucesso!\n");
        printf("Precione qualquer tecla para continuar...");
        getch();
        system("CLS");

    }
    //fecha o arquivo
    fclose(vagas);

    //retorna cargos
    return cargos;
}

void escreveArquivo(Vagas v[], int cargosPre){

    //cria um ponteiro
    FILE *vagas;

    //declaração das variasveis
    int i;
    char escolaridade[20];

    //informa se não foi possivel ler o arquivo
    if((vagas = fopen("vagas.txt", "w")) == NULL){

        printf("Nao foi possivel abrir o arquivo.\n");
        printf("As informações não serão gravadas no arquivo.");
        printf("Precisone qualquer tecla para finalizar o programa...");
        getch();
        system("CLS");

    } else {

        //escreve no arquivo as informações alteradas, atualiza o arquivo
        for(i = 0; i < cargosPre; i++){

            if(v[i].escolaridade == 0) strncpy(escolaridade, "Fundamental", sizeof(escolaridade));
            if(v[i].escolaridade == 1) strncpy(escolaridade, "Medio", sizeof(escolaridade));
            if(v[i].escolaridade == 2) strncpy(escolaridade, "Superior", sizeof(escolaridade));

            fprintf(vagas, "%s\n", v[i].cargo);
            fprintf(vagas, "%s\n", escolaridade);
            fprintf(vagas, "%c\n", v[i].sexo);
            fprintf(vagas, "%d\n", v[i].idadeMin);
            fprintf(vagas, "%d\n", v[i].idadeMax);
            fprintf(vagas, "%.2f\n", v[i].salario);
            fprintf(vagas, "%d\n", v[i].vagasDisponiveis);
            fputs("\n", vagas);

        }

        printf("As alteracoes de dados foram gravados no arquivo com sucesso!\n");
        printf("Precione qualquer tecla para finalizar o programa...");
        getch();
        system("CLS");
    }

    //fecha o arquivo
    fclose(vagas);

}
//inclui as bibliotecas necessárias
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "funcoes.h"

//inicia o main
int main(){

    //declaração das variaveis
    int iniciar = 0, opcao = 0, cargosPre = 0;
    Dados d = {0, 's', 0, -1};
    Vagas v[5];

    //le as informações do arquivo e retorna a quantidade de cargos lidos do arquivo
    cargosPre = leArquivo(v, 5);

    //finaliza o programa caso não seja possivel ler o arquivo
    if(cargosPre == -1) return 0;

    //executa o menu 1 enquanto não se escolhe a opção 1
    do{

        //coloca o retorno da função em uma variável
        iniciar = menuUm();

        //inicia a execução do menu 2 se for escolhido dar continuidade no programa
        if(iniciar == 0){

            //executa o menu 2 enquanto não se é escolhida a opção 6
            do{

                //executa a função e coloca o retorno da função em uma variável
                opcao = menuDois();

                //executa a opção escolhida
                switch(opcao){

                    case 0:
                        //executa a função e coloca o retorno da função em uma variável
                        d.idade = entrarIdade();
                        break;

                    case 1:
                        //executa a função e coloca o retorno da função em uma variável
                        d.sexo = entrarSexo();
                        break;

                    case 2:
                        //executa a função e coloca o retorno da função em uma variável
                        d.salario = entrarSalario();
                        break;

                    case 3:
                        //executa a função e coloca o retorno da função em uma variável
                        d.escolaridade = entrarEscolaridade();
                        break;

                    case 4:
                        //executa a função e coloca o retorno da função em uma estrutura
                        d = buscarVaga(d, v, 5);
                        break;

                    case 5:
                        //executa a função
                        vagasDisponiveis(v, 5);
                        break;

                        //termina o laco do menu 1 e volta para o menu 2
                    case 6:
                        //exibe a informação por alguns segundos antes de voltar para o menu 1
                        printf("Voltando para o meu 1...");
                        Sleep(500);
                        system("CLS");
                        break;

                        //exibe a informação caso nenhuma das opções validas tenham sido informadas
                    default:
                        printf("Entre com uma alternativa valida.\n\n");
                        printf("Pressione qualquer tecla...");
                        getchar();
                        system("CLS");
                }
            }while(opcao != 6);
        }
    }while(iniciar == 0);

    //escreve as informações alteradas no arquivo, somente se o arquivo foi lido
    if(cargosPre != 0) escreveArquivo(v, cargosPre);

    return 0;
}

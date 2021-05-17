#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define TAM 5

void main(){

    int vagas[TAM] = {5, 3, 2, 1, 2}, disponivel[TAM], idade, escolariedade, iniciar, opcao, somaVagas, posicao, escolha, continuar;
    char sexo;
    float salario;

    do{

    	//inicia o programa ou o encerra dependendo da opcao escolhida e usa um laço para evitar que qualquer valor diferente do desejado seja aceito.
    	do{
        	printf("Menu 1\n0 - Iniciar o programa\n1 - Finalizar o programa\n");
        	scanf("%d", &iniciar);
        	system("CLS");
    	}while(iniciar != 0 && iniciar != 1);

    	//inicia o meu 2.
    	if(iniciar == 0){

			//continua no menu 2 enquanto não se é escolhida a opção 6
	    	do{
		        printf("Menu 2\nEntrada de dados do candidato:\n");
		        printf("0 - Entrar com idade\n1 - Entrar com o sexo\n2 - Entrar com a pretensao salarial\n3 - Entrar com o nivel de escolaridade\n4 - Buscar vaga\n5 - Quantidade de vagas disponiveis\n6 - Voltar ao menu anterior\n");
		        scanf("%d", &opcao);
		        system("CLS");

				//executa a opção escolhida
		        switch(opcao){

		        	case 0:

		                //laço para evitar que qualquer valor diferente do desejado seja aceito.
		                do{
		                    printf("Informe a sua idade: ");
		                    scanf("%d", &idade);
		                    system("CLS");
		                }while(idade < 16);

		                break;

		            case 1:

		                //laço para evitar que qualquer valor diferente do desejado seja aceito.
		                do{
		                    printf("Informe o sexo, digite f para feminino ou m para masculino: ");
		                    sexo = getchar();
		                    system("CLS");
		                }while(sexo != 'f' && sexo != 'm');

		                break;

		            case 2:

		                //laço para evitar que qualquer valor diferente do desejado seja aceito.
		                do{
		                    printf("Informe a sua pretencao salarial: ");
		                    scanf("%f", &salario);
		                    system("CLS");
		                }while(salario <= 0);

		                break;

		            case 3:

		                //laço para evitar que qualquer valor diferente do desejado seja aceito.
		                do{
		                   printf("Nivel de escolaridade:\n0 - fundamental completo\n1 - ensino medio completo\n2 - superior completo.\n");
		                    scanf("%d", &escolariedade);
		                    system("CLS");
		                }while(escolariedade < 0 && escolariedade > 2);

		                break;

		            case 4:

		                //mostra as vagas caso as informações necessarias tenham sido informadas.
		                if(idade != 0 && sexo != 's' && salario != 0 && escolariedade != -1){

		                	//reinicia o vetor que é preenchido com um numero para cada vaga disponivel
		                	for(posicao = 0; posicao < TAM; posicao++){
									disponivel[posicao] = 0;
								}

		                    //mostra as vagas disponiveis que atendendem os requisitos necessarios.
							if(escolariedade > 0 && sexo == 'f' && idade >= 18 && salario <= 1500 && vagas[0] > 0) {
								printf("0 - Recepcionista. | Salario - R$ 1500\n");
								disponivel[0] = 1;
							}

							if(sexo == 'm' && idade >=16 && idade <= 20 && salario <= 900 && vagas[1] > 0) {
								printf("1 - Ajudante Geral. | Salario - R$ 900\n");
								disponivel[1] = 2;
							}

							if(escolariedade == 2 && idade >= 30 && salario <= 4500 && vagas[2] > 0) {
								printf("2 - Gerente de RH. | Salario - R$ 4500\n");
								disponivel[2] = 3;
							}

							if(escolariedade == 2 && idade >= 25 && salario <= 3500 && vagas[3] > 0){
								printf("3 - Analista de Sistemas. | Salario - R$ 3500\n");
								disponivel[3] = 4;
							}

							if(idade >= 35 && idade <= 50 && salario <= 1200 && vagas[4] > 0) {
								printf("4 - Porteiro. | Salario - R$ 1200\n");
								disponivel[4] = 5;
							}

							//pede para que a vaga seja escolhida, caso haja uma vaga disponivel
		                    if(disponivel[0] == 1 || disponivel[1] == 2 || disponivel[2] == 3 || disponivel[3] == 4 || disponivel[4] == 5){

								//laço para evitar que qualquer valor diferente do desejado seja aceito.
								do{
			                    	printf("Escolha a vaga ou digite 5 para retornar ao Menu 2.\n");
									scanf("%d", &escolha);

									//verifica se o numero informado é referente a alguma das vagas disponiveis
									for(posicao = 0; posicao < TAM; posicao++){
										if(escolha - disponivel[posicao] == -1) continuar = 1;
									}

								}while(continuar != 1 && escolha != 5);

								//reinicia a variavel
								continuar = 0;

								//diminui a quantidade de vagas dependendo da opção escolhida.
								if(escolha == 0) vagas[0] = vagas[0] - 1;
								if(escolha == 1) vagas[1] = vagas[1] - 1;
								if(escolha == 2) vagas[2] = vagas[2] - 1;
								if(escolha == 3) vagas[3] = vagas[3] - 1;
								if(escolha == 4) vagas[4] = vagas[4] - 1;

								system("CLS");

							//informa se não houver vagas disponiveis
							}else {
								printf("Nao ha vagas disponiveis.\n");
								printf("Pressione qualquer tecla...");
								getch();
								system("CLS");
							}

			                //reseta as variaveis que contém as informações dos candidatos
							idade = 0;
							escolariedade = -1;
							sexo = 's';
							salario = 0;

						//informa se os dados necessarios não foram informados.
						} else {
		                	printf("Todos os dados necessarios nao foram informados.\n\n");
		                	printf("Pressione qualquer tecla...");
							getch();
							system("CLS");
						}

		                break;

		            case 5:

		                //laço para somar as vagas.
		                for(posicao = 0; posicao < TAM; posicao++){
		                	somaVagas = somaVagas + vagas[posicao];
						}

		                //estrutura de seleção para mostrar se existem ou não vagas disponiveis.
						if(somaVagas > 0) {
							printf("Existem %d vagas disponiveis.\n", somaVagas);
							if(vagas[0] > 0) printf("%d vagas para recepcionista.\n", vagas[0]);
							if(vagas[1] > 0) printf("%d vagas para ajudante geral.\n", vagas[1]);
							if(vagas[2] > 0) printf("%d vagas para gerente de rh.\n", vagas[2]);
							if(vagas[3] > 0) printf("%d vagas para analista de sistemas.\n", vagas[3]);
							if(vagas[4] > 0) printf("%d vagas para porteiro.\n", vagas[4]);
						} else printf("Não existem vagas disponiveis.\n\n");

						printf("Pressione qualquer tecla...");
						getch();
						system("CLS");

						//reseta a variavel
		                somaVagas = 0;

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
						getch();
						system("CLS");
		        }

			}while(opcao != 6);
		}

    }while(iniciar == 0);
}

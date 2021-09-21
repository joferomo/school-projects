#include <stdio.h>

const char* channelState(int state){
	switch(state){
		case -1:
			return "/  \0";
		case 1:
			return "  \\\0";
		default:
			return NULL;
	}
}

int main(){
	int pontuacao, pontuacaoFeita, maiorPontuacao, qtdDeBolas, dnv, opc, ok, canalEscolhido;
	int canalA, canalB, canalC, canalD, canalE, canalF, canalG;
	const char* instrucoes = ""
		"Você deve escolher um canal inicial para a bola.\n"
		"A bola passará por todos os canais em seu percurso, trocando o seu sentido conforme o do canal.\n"
		"Após a bola passar, O canal também muda de sentido.\n"
		"Os canais no fundo mostram quantos pontos cada um vale.\n"
		"Quando a bola cair em algum, você recebe um quantidade de pontos equivalente ao valor do canal.\n"
		"O objetivo do jogo é conseguir o maior número de pontos.\n\0";

	ok = 0;
	while(ok == 0){
		printf("Jogo de canais\n");
		printf("1 - Iniciar 0 - Instruções\n");
		scanf("%d", &opc);
		if(opc >= 0 && opc <= 1){
			ok = 1;
		}
		else{
			printf("\nErro: Opção inválida\n");
		}
		printf("\n");
	}

	if(opc == 0){
		printf("%s\n", instrucoes);
	}

	maiorPontuacao = 0;
	dnv = 1;
	while(dnv == 1){
		pontuacao = 0;
		canalA = -1, canalB = -1, canalC = -1, canalD = -1, canalE = -1, canalF = -1, canalG = -1;

		for(qtdDeBolas = 5; qtdDeBolas > 0; qtdDeBolas--){
			printf("Bolas restantes: %d\n\n", qtdDeBolas);

			printf("  1   2   3  \n");
			printf("  A   B   C  \n");
			printf(" %s", channelState(canalA)); printf(" %s", channelState(canalB)); printf(" %s\n", channelState(canalC));

			printf("(   D   E   )\n");
			printf(" \\ %s", channelState(canalD)); printf(" %s /\n", channelState(canalE));

			printf("  \\   F   G\n");
			printf("   \\ %s", channelState(canalF)); printf(" %s\n", channelState(canalG));
			printf("    |10 |20 |5 \n\n");

			ok = 0;
			while(ok == 0){
				printf("Escolha um canal inicial (1, 2 ou 3)\n");
				scanf("%d", &canalEscolhido);
				if(canalEscolhido >= 1 && canalEscolhido <= 3){
					ok = 1;
				}
				else{
					printf("\nErro: Canal inválido\n");
				}
				printf("\n");
			}

			switch(canalEscolhido){
				case 1:
					if(canalA < 0){
						pontuacao += 10;
						pontuacaoFeita = 10;
					}
					else{
						if(canalD < 0){
							pontuacao += 10;
							pontuacaoFeita = 10;
						}
						else{
							if(canalF < 0){
								pontuacao += 10;
								pontuacaoFeita = 10;
							}
							else{
								pontuacao += 20;
								pontuacaoFeita = 20;
							}
							canalF *= -1;
						}
						canalD *= -1;
					}
					canalA *= -1;
					break;
				case 2:
					if(canalB < 0){
						if(canalD < 0){
							pontuacao += 10;
							pontuacaoFeita = 10;
						}
						else{
							if(canalF < 0){
								pontuacao += 10;
								pontuacaoFeita = 10;
							}
							else{
								pontuacao += 20;
								pontuacaoFeita = 20;
							}
							canalF *= -1;
						}
						canalD *= -1;
					}
					else{
						if(canalE < 0){
							if(canalF < 0){
								pontuacao += 10;
								pontuacaoFeita = 10;
							}
							else{
								pontuacao += 20;
								pontuacaoFeita = 20;
							}
							canalF *= -1;
						}
						else{
							if(canalG < 0){
								pontuacao += 20;
								pontuacaoFeita = 20;
							}
							else{
								pontuacao += 5;
								pontuacaoFeita = 5;
							}
							canalG *= -1;
						}
						canalE *= -1;
					}
					canalB *= -1;
					break;
				case 3:
					if(canalC < 0){
						if(canalE < 0){
							if(canalF < 0){
								pontuacao += 10;
								pontuacaoFeita = 10;
							}
							else{
								pontuacao += 20;
								pontuacaoFeita = 20;
							}
							canalF *= -1;
						}
						else{
							if(canalG < 0){
								pontuacao += 20;
								pontuacaoFeita = 20;
							}
							else{
								pontuacao += 5;
								pontuacaoFeita = 5;
							}
							canalG *= -1;
						}
						canalE *= -1;
					}
					else{
						if(canalG < 0){
							pontuacao += 20;
							pontuacaoFeita = 20;
						}
						else{
							pontuacao += 5;
							pontuacaoFeita = 5;
						}
						canalG *= -1;
					}
					canalC *= -1;
					break;
			}
			printf("+%d pontos\n\n", pontuacaoFeita);
		}

		if(pontuacao > maiorPontuacao){
			maiorPontuacao = pontuacao;
			printf("Novo recorde!\n");
		}
		printf("Pontuação: %d\n", pontuacao);
		printf("Maior pontuação: %d\n\n", maiorPontuacao);

		ok = 0;
		while(ok == 0){
			printf("Jogar novamente?\n");
			printf("1 - Sim 0 - Não\n");
			scanf("%d", &dnv);
			if(dnv >= 0 && dnv <= 1){
				ok = 1;
			}
			else{
				printf("\nErro: Opção inválida\n");
			}
			if(dnv != 0)
			{
				printf("\n");
			}
		}
	}
}

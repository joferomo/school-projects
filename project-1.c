#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM_MAT 5
#define DIM_VET DIM_MAT*DIM_MAT

int main(void){
	int matA[DIM_MAT][DIM_MAT], matB[DIM_MAT][DIM_MAT], matC[DIM_MAT][DIM_MAT];
	int numDeColunasA, numDeLinhasA, numDeColunasB, numDeLinhasB;
	int ok = 0, i, j, k, l, num, soma;

	srand(time(NULL));

	// Definição das dimensões de matA 
	ok = 0;
	while(ok == 0){
		printf("Entre com o número de colunas de matA\n");
		scanf("%d", &numDeColunasA);
		if(numDeColunasA >= 1 && numDeColunasA <= DIM_MAT){
			ok = 1;
		}
		else{
			printf("\nDigite um número de 1 a %d\n", DIM_MAT);
		}
		printf("\n");
	}
	ok = 0;
	while(ok == 0){
		printf("Entre com o número de linhas de matA\n");
		scanf("%d", &numDeLinhasA);
		if(numDeLinhasA >= 1 && numDeLinhasA <= DIM_MAT){
			ok = 1;
		}
		else{
			printf("\nDigite um número de 1 a %d\n", DIM_MAT);
		}
	}

	// Geração de valores únicos e aleatórios em matA
	for(i = 0; i < numDeLinhasA; i++){
		for(j = 0; j < numDeColunasA; j++){
			do{
				ok = 1;
				num = rand() % (DIM_VET * 2);
				for(k = 0; k < numDeLinhasA; k++){
					for(l = 0; l < numDeColunasA; l++){
						if(k == i && l == j)
						{
							k = numDeLinhasA;
							break;
						}
						if(num == matA[k][l]){
							ok = 0;
							k = numDeLinhasA;
							break;
						}
					}
				}
			} while(ok == 0);
			matA[i][j] = num;
		}
	}

	// Definição das dimensões de matB
	ok = 0;
	while(ok == 0){
		printf("\nEntre com o número de colunas de matB\n");
		scanf("%d", &numDeColunasB);
		if(numDeColunasB >= 1 && numDeColunasB <= DIM_MAT){
			ok = 1;
		}
		else{
			printf("\nDigite um número de 1 a %d\n", DIM_MAT);
		}
	}
	ok = 0;
	while(ok == 0){
		printf("\nEntre com o número de linhas de matB\n");
		scanf("%d", &numDeLinhasB);
		if(numDeLinhasB >= 1 && numDeLinhasB <= DIM_MAT){
			ok = 1;
		}
		else{
			printf("\nDigite um número de 1 a %d\n", DIM_MAT);
		}
	}

	// Geração de valores únicos e aleatórios em matB
	for(i = 0; i < numDeLinhasB; i++){
		for(j = 0; j < numDeColunasB; j++){
			do{
				ok = 1;
				num = rand() % (DIM_VET * 2);
				for(k = 0; k < numDeLinhasB; k++){
					for(l = 0; l < numDeColunasB; l++){
						if(k == i && l == j)
						{
							k = numDeLinhasB;
							break;
						}
						if(num == matB[k][l]){
							ok = 0;
							k = numDeLinhasB;
							break;
						}
					}
				}
			} while(ok == 0);
			matB[i][j] = num;
		}
	}

	// Cálculo do produto de linha A * coluna B
	ok = 0;
	if(numDeLinhasA == numDeColunasB){
		ok = 1;
		for(i = 0; i < numDeLinhasA; i++){
			soma = 0;
			for(k = 0; k < numDeLinhasB; k++){
				soma = soma + matB[k][i];
			}
			for(j = 0; j < numDeColunasA; j++){
				matC[i][j] = matA[i][j] * soma;
			}
		}
	}

	// Impressão dos valores
	printf("\nValores de matA\n");
	for(i = 0; i < numDeLinhasA; i++){
		for(j = 0; j < numDeColunasA; j++){
			printf("%d ", matA[i][j]);
		}
		printf("\n");
	}
	printf("\nValores de matB\n");
	for(i = 0; i < numDeLinhasB; i++){
		for(j = 0; j < numDeColunasB; j++){
			printf("%d ", matB[i][j]);
		}
		printf("\n");
	}
	if(ok == 1){
		int matCOrdenada[DIM_MAT][DIM_MAT], vetC[DIM_VET];
		int numDeColunasC = numDeColunasA, numDeLinhasC = numDeLinhasA, tamanhoVetorC;

		printf("\nValores de matC\n");
		for(i = 0; i < numDeLinhasC; i++){
			for(j = 0; j < numDeColunasC; j++){
				printf("%d ", matC[i][j]);
			}
			printf("\n");
		}

		// Ordenação dos elementos de matC
		for(i = 0, k = 0; i < numDeLinhasC; i++){
			for(j = 0; j < numDeColunasC; j++){
				vetC[k++] = matC[i][j];
			}
		}
		tamanhoVetorC = numDeLinhasC * numDeColunasC;
		for(i = 0; i < tamanhoVetorC; i++){
			for(j = tamanhoVetorC-1; j > i; j--){
				if(vetC[j] < vetC[i]){
					num = vetC[i];
					vetC[i] = vetC[j];
					vetC[j] = num;
				}
			}
		}
		for(i = 0, k = 0; i < numDeLinhasC; i++){
			for(j = 0; j < numDeColunasC; j++){
				matCOrdenada[i][j] = vetC[k++];
			}
		}
		printf("\nValores ordenados de matC\n");
		for(i = 0; i < numDeLinhasC; i++){
			for(j = 0; j < numDeColunasC; j++){
				printf("%d ", matCOrdenada[i][j]);
			}
			printf("\n");
		}

		if(numDeLinhasC == numDeColunasC){
			int vetP[DIM_VET], vetS[DIM_VET], vetR[DIM_VET], vetROrdenado[DIM_VET];
			int tamanhoVetorR;

			// Intercalação dos elementos na Diagonal Principal [\] e na Diagonal Secundária [/] de matC
			for(i = 0; i < numDeLinhasC; i++){
				vetP[i] = matC[i][i];
			}
			for(i = numDeLinhasC-1, j = 0; i >= 0; i--){
				vetS[i] = matC[i][j++];
			}
			tamanhoVetorR = numDeLinhasC*2;
			for(i = 0, j = 0; i < tamanhoVetorR; i++){
				vetR[j] = vetP[i];
				vetR[j+1] = vetS[i];
				j += 2;
			}

			printf("\nElementos de matC contidos na Diagonal Principal [\\]\n");
			for(i = 0; i < numDeLinhasC; i++){
				printf("%d ", vetP[i]);
			}
			printf("\n\nElementos de matC contidos na Diagonal Secundária [/]\n");
			for(i = 0; i < numDeLinhasC; i++){
				printf("%d ", vetS[i]);
			}
			printf("\n\nIntercalação dos dois elementos anteriores em um vetor vetR\n");
			for(i = 0; i < tamanhoVetorR; i++){
				printf("%d ", vetR[i]);
			}

			printf("\n\nDigite um elemento para ser buscado em vetR\n");
			scanf("%d", &num);
			for(i = 0; i < tamanhoVetorR; i++){
				if(num == vetR[i]){
					printf("\nO elemento %d foi achado na posição %d\n", num, i);
					break;
				}
				else if(i == (numDeLinhasC*2)-1){
					printf("\nO elemento %d não existe em vetR\n", num);
				}
			}

			// Ordenação dos elementos em vetR
			for(i = 0; i < tamanhoVetorR; i++){
				vetROrdenado[i] = vetR[i];
			}
			for(i = 0; i < tamanhoVetorR; i++){
				for(j = tamanhoVetorR-1; j > i; j--){
					if(vetROrdenado[j] < vetROrdenado[i]){
						num = vetROrdenado[i];
						vetROrdenado[i] = vetROrdenado[j];
						vetROrdenado[j] = num;
					}
				}
			}
			printf("\nImpressão ordenada de vetR\n");
			for(i = 0; i < numDeLinhasC*2; i++){
				printf("%d ", vetROrdenado[i]);
			}

			printf("\n\nVerificação de quais elementos de vetR são primos\n");
			for(i = 0; i < tamanhoVetorR; i++){
				ok = 1;
				for(num = vetR[i] - 1; num > 1; num--){
					if(vetR[i] % num == 0){
						printf("%d não é primo\n", vetR[i]);
						ok = 0;
						break;
					}
				}
				if(ok == 1){
					printf("%d é primo\n", vetR[i]);
				}
			}

			printf("\nCálculo do número de euler com n termos\n");
			// Onde i = iterador, j = número de termos, k = fatorial
			float euler;
			int fat;
			for(i = 0; i < tamanhoVetorR; i++){
				euler = 1.0f;
				for(j = vetR[i]; j >= 1; j--){
					fat = 1;
					for(k = j; k > 1; k--){
						fat = fat*k;
					}
					euler += 1.0f/fat;
				}
				printf("Um número de euler de %d termos é igual a %.12f\n", vetR[i], euler);
			}
		}
	}
	else{
		printf("\nNão é possível calcular o produto entre matA e matB pois não possuem:\n");
		printf("Número de colunas A = Número de linhas B\n");
		printf("Número de linhas A = Número de colunas B\n");
		printf("Número de linhas A diferente do número de colunas A\n");
		printf("Número de linhas B diferente do número de colunas B\n");
	}
}

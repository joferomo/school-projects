#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define DIM_MAX 100000

int vet[DIM_MAX], dim;
int i, j, ok;
struct timeval tempo_ini, tempo_fin;

int main(void){
	void ins_bin(void), ord_bol(void), sel_dir(void), busca_bin(void), busca_lin(void);
	int dnv, tipo_ord, tipo_busca, ordenar;

	srand(time(NULL));

	dnv = 1;
	while(dnv == 1){
		ok = 0;
		while(ok == 0){
			printf("Entre com a dimensão do vetor\n");
			scanf("%d", &dim);
			if(dim >= 1 && dim <= DIM_MAX){
				ok = 1;
			}
			else{
				printf("\nEntre com uma dimensão entre 1 e %d\n\n", DIM_MAX);
			}
		}

		ok = 0;
		while(ok == 0){
			printf("\nQual tipo de busca gostaria de realizar no vetor?\n");
			printf("0 - Linear, 1 - Binária\n");
			scanf("%d", &tipo_busca);
			if(tipo_busca >= 0 && tipo_busca <= 1){
				ok = 1;
			}
			else{
				printf("\nEntre com uma opção válida\n\n");
			}
		}

		// Geração aleatória ou geração aleatória sem elementos repetidos
		if(tipo_busca == 0){
			for(i = 0; i < dim; i++){
				vet[i] = rand()%dim;
			}
		}
		else{
			for(i = 0; i < dim; i++){
				vet[i] = rand()%DIM_MAX;
				for(j = i-1; j >= 0; j--){
					if(vet[j] == vet[i]){
						j = -1;
						i--;
					}
				}
			}
		}

		if(tipo_busca == 0){
			ok = 0;
			while(ok == 0){
				printf("\nGostaria de ordenar o vetor?\n");
				printf("0 - Não, 1 - Sim\n");
				scanf("%d", &ordenar);
				if(ordenar >= 0 && ordenar <= 1){
					ok = 1;
				}
				else{
					printf("\nEntre com uma opção válida\n\n");
				}
			}
		}
		else{
			ordenar = 1;
			ok = 1;
		}

		if(ordenar == 1){
			ok = 0;
			while(ok == 0){
				printf("\nQual ordenação gostaria de realizar no vetor?\n");
				printf("0 - Inserção Binária\n");
				printf("1 - Ordenação Bolha\n");
				printf("2 - Seleção Direta\n");
				scanf("%d", &tipo_ord);
				if(tipo_ord >= 0 && tipo_ord <= 2){
					ok = 1;
				}
				else{
					printf("\nEntre com uma opção válida\n\n");
				}
			}
			switch(tipo_ord){
				case 0 : ins_bin(); break;
				case 1 : ord_bol(); break;
				case 2 : sel_dir(); break;
			}
		}
		else{
			printf("\nImpressão do vetor sem ordenação:\n");
			for(i = 0; i < dim; i++){
				printf("%d ", vet[i]);
			}
			printf("\n");
		}

		if(tipo_busca == 0){
			busca_lin();
		}
		else{
			busca_bin();
		}

		ok = 0;
		while(ok == 0){
			printf("\nGostaria de executar o programa novamente?\n");
			printf("1 - Sim, 0 - Não\n");
			scanf("%d", &dnv);
			if(dnv >= 0 && dnv <= 1){
				ok = 1;
			}
			else{
				printf("\nEntre com uma opção válida\n\n");
			}
		}
		if(dnv == 1)
		{
			printf("\n");
		}
	}
}

double sub_tempo(struct timeval t, struct timeval t0){
	return (t.tv_sec - t0.tv_sec) + (t.tv_usec - t0.tv_usec) / 1000000.0;
}

void ins_bin(void){
	int lim_inf, lim_sup, pos, elem;

	gettimeofday(&tempo_ini, NULL);
	for(i = 1; i < dim; i++){
		lim_inf = 0, lim_sup = i;
		elem = vet[i];
		while(lim_inf < lim_sup){
			pos = (lim_inf+lim_sup)/2;
			if(vet[pos] > elem){
				lim_sup = pos;
			}
			else{
				lim_inf = pos+1;
			}
		}
		for(j = i; j > lim_sup; j--){
			vet[j] = vet[j-1];
		}
		vet[j] = elem;
	}
	gettimeofday(&tempo_fin, NULL);

	printf("\nImpressão do vetor ordenado por inserção binária:\n");
	for(i = 0; i < dim; i++){
		printf("%d ", vet[i]);
	}
	printf("\nTempo gasto pela inserção binária: %f segundos\n", sub_tempo(tempo_fin, tempo_ini));
}

void ord_bol(void){
	int troquei, ordenado, aux;

	ordenado = 0;
	gettimeofday(&tempo_ini, NULL);
	while(ordenado == 0){
		troquei = 0;
		for(i = 0; i < dim-1; i++){
			if(vet[i+1] < vet[i]){
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				troquei = 1;
			}
		}
		if(troquei == 0){
			ordenado = 1;
		}
	}
	gettimeofday(&tempo_fin, NULL);

	printf("\nImpressão do vetor ordenado pela ordenação bolha:\n");
	for(i = 0; i < dim; i++){
		printf("%d ", vet[i]);
	}
	printf("\nTempo gasto pela ordenação bolha: %f segundos\n", sub_tempo(tempo_fin, tempo_ini)); 
}

void sel_dir(void){
	int menor_elem, pos_troca;

	gettimeofday(&tempo_ini, NULL);
	for(i = 0; i < dim; i++){
		menor_elem = vet[i];
		pos_troca = i;
		for(j = i+1; j < dim; j++){
			if(vet[j] < menor_elem){
				menor_elem = vet[j];
				pos_troca = j;
			}
		}
		vet[pos_troca] = vet[i];
		vet[i] = menor_elem;
	}
	gettimeofday(&tempo_fin, NULL);

	printf("\nImpressão do vetor ordenado pela seleção direta:\n");
	for(i = 0; i < dim; i++){
		printf("%d ", vet[i]);
	}
	printf("\nTempo gasto pela seleção direta: %f segundos\n", sub_tempo(tempo_fin, tempo_ini));
}

void busca_bin(void){
	int lim_inf, lim_sup, elem, pos, buscando;
	lim_inf = 0, lim_sup = dim;

	printf("\nEntre com o elemento a ser buscado\n");
	scanf("%d", &elem);

	buscando = 1;
	while(buscando == 1){
		pos = (lim_inf+lim_sup)/2;

		if(lim_inf == lim_sup && vet[pos] != elem){
			printf("\nElemento %d não encontrado no vetor\n", elem);
			buscando = 0;
		}

		if(vet[pos] == elem){
			printf("\nElemento %d encontrado na posição %d do vetor\n", elem, pos);
			buscando = 0;
		}
		else{
			if(vet[pos] > elem){
				lim_sup = pos-1;
			}
			else{
				lim_inf = pos+1;
			}
		}
	}
}

void busca_lin(void){
	int cont, elem;
	cont = 0;

	printf("\nEntre com o elemento a ser contabilizado\n");
	scanf("%d", &elem);

	for(i = 0; i < dim; i++){
		if(vet[i] == elem){
			printf("\nElemento %d encontrado na posição %d\n", elem, i);
			cont++;
		}
	}

	switch(cont)
	{
		case 0:
		printf("\nElemento %d não encontrado no vetor\n", elem);
			break;
		case 1:
			printf("\nElemento %d encontrado 1 vez no vetor\n", elem);
			break;
		default:
			printf("\nElemento %d encontrado %d vezes no vetor\n", elem, cont);
			break;
	}
}

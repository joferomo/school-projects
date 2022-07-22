#include <stdio.h>
#include <string.h>
#include <math.h>
#define TAM_HEX 8

int main(void){
	int getDecimal(char numHex);
	char numHex[TAM_HEX];
	int hexLength;
	int vetorDecimal[TAM_HEX], vetorHex[TAM_HEX], vetorBinario[(TAM_HEX-2)*4];
	int i, ok, expoente, valorDecimal, quociente;

	do{
		ok = 1;
		printf("Entre com um valor hexadecimal de até %d digitos:\n", TAM_HEX-2);
		fgets(numHex, TAM_HEX, stdin);
		hexLength = strlen(numHex);
		if(numHex[hexLength-1] == '\n')
		{
			numHex[--hexLength] = '\0';
			for(i = 0; i < hexLength; i++){
				if((numHex[i] < 48 || numHex[i] > 57) && (numHex[i] < 65 || numHex[i] > 70) && (numHex[i] < 97 || numHex[i] > 102)){
					ok = 0;
					printf("\n");
					break;
				}
			}
		}
		else{
			ok = 0;
			printf("\n");
			while(getchar() != '\n');
		}
	} while(ok == 0);

	for(i = 0; i < hexLength; i++){
		vetorHex[i] = getDecimal(numHex[i]);
	}
	for(i = 0, expoente = hexLength - 1; i < hexLength; i++){
		vetorDecimal[i] = vetorHex[i] * pow(16, expoente--);
	}
	for(i = 0, valorDecimal = 0; i < hexLength; i++){
		valorDecimal += vetorDecimal[i];
	}
	printf("\nValor decimal:\n");
	printf("%d\n", valorDecimal);

	for(quociente = valorDecimal, i = 0; quociente >= 1; quociente /= 2){
		vetorBinario[i++] = quociente % 2;
	}
	vetorBinario[i] = quociente;
	printf("\nValor binário:\n");
	if(valorDecimal > 0)
	{
		for(i = i-1; i >= 0; i--){
			printf("%d", vetorBinario[i]);
		}
	}
	else
	{
		printf("0");
	}
	printf("\n");
}

int getDecimal(char numHex){
	switch(numHex){
		case 'a':
		case 'A':
			return 10;
		case 'b':
		case 'B':
			return 11;
		case 'c':
		case 'C':
			return 12;
		case 'd':
		case 'D':
			return 13;
		case 'e':
		case 'E':
			return 14;
		case 'f':
		case 'F':
			return 15;
	}
	return numHex - '0';
}

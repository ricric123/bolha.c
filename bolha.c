#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000

//prototipo
void preencheRandomico();
void mostraVetor();
void bolha();

//variavel global
int vet[TAM];



void mostraVetor(){
	int i;
	
	for(i=0;i<TAM;i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

 void bolha(){
	int i, aux, j, cont;
	cont=0;
	
	for(j=0;j<TAM;j++){
		cont=0;
		for(i=0;i<TAM-1;i++){
			if(vet[i]>vet[i+1]){
				aux=vet[i];
				vet[i]=vet[i+1];
				vet[i+1]=aux;
				cont++;
				mostraVetor();
			}
		}
		if(cont==0){
			break;
		}
	}
}

 void preencheRandomico(){
	int i, j;
	//controlar a posição onde será posionado o número randomico
	for(i=0;i<TAM;i++){
		vet[i]=rand()% TAM;
		
		//buscar o elemento no vetor
		for(j=0;j<i;j++){
			if(vet[i]==vet[j]){
				i--;
				break;
			}
		}
	}
}

main(){
	srand(time(NULL));
	preencheRandomico();
	mostraVetor();
	printf("\n");
	bolha();
}

#include <stdio.h>
#include <stdlib.h>

typedef struct manocontas{
	int num;
	void* endereco;
}Contador;

Contador* Vetorzao[500]; 
int contavetor=0;

void* malloc2(int n){
	Contador* particao = (Contador *)malloc(sizeof (Contador));//1
	particao->num = 1;
	Vetorzao[contavetor]=particao;
	contavetor++;
	void* conteudo=malloc(n);
	particao->endereco=conteudo;
	return particao->endereco;
	
}

void atualizaheap(int posicao){
	for(int i=posicao;i<contavetor;i++){
		Vetorzao[i]=Vetorzao[i+1];
	}
	contavetor--;	
}

void add (void *p, int cont) {
	for (int i=0; i<contavetor; i++)
	if (p == Vetorzao[i]->endereco) {
		Vetorzao[i]->num += cont;
		if (Vetorzao[i]->num == 0) {
			atualizaheap(i);
		}
		break;
	}
}

void atribui (void *esq, void *dir) {
	add (esq, -1);
	esq = dir;
	add (dir, +1);
}

void dump(){
	int *j;
	for (int i=0; i<contavetor; i++){
		j=(int*)Vetorzao[i]->endereco;
		printf("Endereco: %d\n Num.de aparicoes: %d\n ",j,Vetorzao[i]->num);
	}
}



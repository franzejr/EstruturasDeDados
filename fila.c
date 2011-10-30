/*
 Disciplina de Programação - UFC 2010.2
   Aluno: Francisco José Lins Magalhães
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	
	int valor;
	struct no* prox;
}no;

typedef no fila;


void enfilar(fila** p, int numero){

	fila* novo = (fila*)malloc(sizeof(fila));

	if(*p == NULL){ // A Pilha está vazia, é o primeiro elemento que vamos inserir nela.
		*p = novo;
		(*p)->valor = numero;
		(*p)->prox = NULL;

	}

	else{ // A Pilha não está vazia. Inserimos no final.
	
	fila* percorre;

	percorre = *p;

		
		while(percorre->prox != NULL ){

			percorre = percorre -> prox;
		}

	percorre -> prox = novo;
	novo -> valor = numero;
	novo -> prox = NULL;
	
	}
	
}
	


void desenfilar(fila** p){
	fila* excluido;
	excluido = *p;
	
	if(*p == NULL) printf("A Fila está vazia\n");
	else{
		*p = (*p)->prox;
		free(excluido);

	}
}

void imprimir(fila* p){

	fila* percorre;

	percorre = p;


	while(percorre != NULL){
		
		printf("Elemento: %d \n", percorre->valor);

		percorre = percorre -> prox;

	}

}


void esvaziarfila(fila **p){

	fila* aux;
	aux = *p;

	while(aux != NULL){
		
		*p = aux->prox;
		free(aux);
		aux = *p;

	}


 }


int main(){

	int opcao,elemento;

	fila* p =NULL;
	
	while(opcao != 0){

		system("clear");
		printf("################### FILA #################\n");
		printf("Aluno: Francisco José Lins Magalhães\n");
		printf("Matéria: Programação - UFC 2010.2\n");
		
		printf("\n");
		printf("0 - Sair\n");
		printf("1 - Enfilar\n");
		printf("2 - Desenfilar\n");
		printf("3 - Esvaziar Fila\n");
		printf("4 - Imprimir\n");
		printf(".:");

		scanf("%d", &opcao);


		switch(opcao){

			case 1: //Enfilando

				printf("Coloque o elemento que você deseja enfilar\n");
				scanf("%d", &elemento);
				__fpurge(stdin);

				enfilar(&p,elemento);

				printf("Imprimindo a fila após ser enfileirada com o novo elemento\n");

				imprimir(p);

				getchar();

			break;

			case 2: //Desenfilando

				printf("Vamos desenfilar\n");

				desenfilar(&p);

				printf("Imprimindo a fila após ser desenfileirada\n");

				imprimir(p);

				getchar();
				getchar();

			break;

			case 3: //Esvaziando fila
				printf("Esvaziando a fila\n");
				esvaziarfila(&p);

				getchar();
				getchar();

			break;

			case 4: //Imprimindo

				printf("Imprimindo a fila\n");

						
				imprimir(p);

				getchar();
				getchar();

			break;




		}

	}

}




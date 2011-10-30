#include <stdio.h>
#include <stdlib.h>

typedef struct no{	
	int valor;
	struct no *prox;
	struct no *ant;
}no;

typedef no lista;

/*Função Inicializar*/
void Inicializar(lista* l,lista* l2){
	l->prox = l2;
	l->ant = NULL;

	l2->prox = NULL;
	l2->ant = l;
}

/*Função Inserir*/
void Inserir(lista* linicio,lista* lfinal,int campo){
	lista* novo;
	novo = (lista*)malloc(sizeof(lista));
	
	novo->valor = campo;
	if(linicio == lfinal){
		linicio->prox = novo;
		lfinal->ant = novo;

		novo->ant = linicio;
		novo->prox = lfinal;


	}
	else{
		novo->prox = lfinal;
		novo->ant = lfinal->ant;

		lfinal->ant->prox = novo;
		lfinal->ant= novo;

	}

}

/*Função Remover*/
void Remover(lista* linicio,lista* lfinal, int elemento){
	lista* p;

	p = linicio->prox; //Para não remover a cabeça, neste caso não estamos contando com a cabeça.

	while((p != lfinal) && (p->valor !=elemento)){
		p = p->prox;
	}

	p->prox->ant = p->ant;
	p->ant->prox = p->prox;

	free(p);




}

/*Função Imprimir*/
void Imprimir(lista* linicio, lista* lfinal){
	lista* p;

	p = linicio->prox; //Para não imprimir a cabeça da lista

	while( p !=lfinal ){ //Para não imprimir a segunda cabeça da lista
		printf("Elemento: %d \n",p->valor);
		p = p->prox;
	}
}




/*Função Principal*/
int main(){
	lista* linicio;
	lista* lfinal;

	linicio = (lista*)malloc(sizeof(lista));
	lfinal = (lista*)malloc(sizeof(lista));
	
	Inicializar(linicio,lfinal);

	Inserir(linicio,lfinal,3);
	Inserir(linicio,lfinal,5);
	Inserir(linicio,lfinal,4);
	Imprimir(linicio,lfinal);
	Remover(linicio,lfinal,3);

	printf("Imprimindo após a remoção\n");
	Imprimir(linicio,lfinal);



return 0;
}

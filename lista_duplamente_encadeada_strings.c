#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	char *valor;
	struct no *prox;
	struct no *ant;
}no;

typedef no lista;

/*Função Inicializar*/
void Inicializar(lista* linicio, lista* lfinal){
	
	//Ajeitando os ponteiros de linicio e lfina

	linicio->prox = lfinal;
	linicio->ant = NULL;

	lfinal->prox = NULL;
	lfinal->ant = linicio;
}

/*Função Inserir*/
void Inserir(lista* linicio, lista* lfinal, char *string){
	
	//Alocar Espaço na memória para o novo nó que será adicionado
	lista* novo = (lista*)malloc(sizeof(lista));
	
	novo->valor = string;

	novo->prox = lfinal;
	novo->ant = lfinal->ant;

	lfinal->ant->prox = novo;
	lfinal->ant = novo;

}

/*Função Remover*/
void Remover(lista* linicio, lista* lfinal, char *string){

	lista* p; //Ponteiro que irá percorrer a lista.

	p = linicio->prox;

	/*for(p = linicio->prox; p!=lfinal; p = p->prox ){
		
		if((strcmp(string, p->valor))== 0) break;
	}*/
	
	while((p != lfinal) && (strcmp(string, p->valor) != 0) ){
                  p = p->prox;
        }
        

	if( p == lfinal){
		
		
		printf("O elemento %s que você quer remover não está na lista\n", string);  

		}
	else{

		p->ant->prox = p->prox;
		p->prox->ant = p->ant;
		free(p);

	}

}


/*Função Imprimir*/
void Imprimir(lista* linicio, lista* lfinal){
	
	lista* p = linicio->prox; //Ponteiro que vai percorrer a lista a partir do proximo depois da cabeça.

	while( p != lfinal){
		
		printf("Elemento: %s ",p->valor);
		p = p->prox;
	}

printf("\n");

}


/*Função Principal*/
int main(){
	
	//Inicializando as duas 'barreiras' da lista duplamente encadeada: o começo e o final.
	lista* linicio = (lista*)malloc(sizeof(lista));
	lista* lfinal = (lista*)malloc(sizeof(lista));
	
	Inicializar(linicio,lfinal);

	Inserir(linicio,lfinal,"gato");
	Inserir(linicio,lfinal,"cachorro");
	Inserir(linicio,lfinal,"cavalo");
	Imprimir(linicio, lfinal);


	printf("Tentativa de remover uma string que não se encontra na lista\n");
	Remover(linicio, lfinal, "franze");
	printf("Reimprimindo a lista\n");
	Imprimir(linicio, lfinal);
	

return 0;
}

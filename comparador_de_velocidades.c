/*
Aluno: Francisco José Lins Magalhães
Disciplina: Programação

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VETOR 100000
#define INTERVALO 1000000


/*Estrutura da Árvore*/
typedef struct no_arvore {
	int elem;
	int vazia;
	struct no_arvore *esq;
	struct no_arvore *dir;
}no_arvore;

/*Buscar na Árvore Binária
--Retorna 1 se deu certo,
--Retorna 0 se não deu certo.
*/
int BuscarArv(no_arvore** raiz, int valor){

	if(*raiz == NULL) return 0; //Não deu certo

	if((*raiz)->elem == valor) return 1; //Deu certo

	if(valor < (*raiz)->elem)return BuscarArv(&((*raiz)->esq), valor);
	else
		return BuscarArv(&((*raiz)->dir),valor);
}

/*Inserir na Árvore Binária
--Retorna 1 se deu certo,
--Retorna 0 se não deu certo.
*/
int InsereArv(no_arvore** raiz, int valor)
{



		
	if(*raiz == NULL){

			*raiz = (no_arvore*)malloc(sizeof(no_arvore));
			(*raiz)->elem = valor;
			(*raiz)->dir = NULL;
			(*raiz)->esq = NULL;
			
			return 1;

	}
			
	if( valor == (*raiz)->elem) return 0; //Elemento já se encontra na árvore.
		
	if(valor < (*raiz)->elem) 
	{
		return InsereArv(&((*raiz)->esq), valor);
	} 
	else
	{
		return InsereArv(&((*raiz)->dir),valor);
	}




}


/*Estrutura da Lista*/

typedef struct no_lista{	
	int valor;
	struct no_lista *prox;
	struct no_lista *ant;
}no_lista;


typedef no_lista lista;



/*Função Inicializar da Lista*/
void InicializarLista(lista* l,lista* l2){
	l->prox = l2;
	l->ant = NULL;

	l2->prox = NULL;
	l2->ant = l;
}

/*Função Inserir da Lista*/
void InserirLista(lista* linicio,lista* lfinal,int campo){
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

/*Função procurar na Lista*/
int ProcurarLista(lista* linicio, lista* lfinal, int buscar){

	lista* percorre;
	percorre = linicio;
	
	while (percorre!=lfinal)
	{
		if (percorre->valor==buscar) break;
		percorre=percorre->prox;
	}
}
	




int main(){

	system("clear");
	printf("Comparador de Busca entre ABB e Lista Encadeada\n");
	printf("Aluno: Francisco José Lins Magalhães\n\n\n");
	/*----Inicializando a lista e a árvore----*/

	lista* linicio;
	lista* lfinal;

	linicio = (lista*)malloc(sizeof(lista));
	lfinal = (lista*)malloc(sizeof(lista));
	
	InicializarLista(linicio,lfinal);

	no_arvore* raiz = NULL;
	
	/*----------------------------------*/

	int numero,contador=0, v[MAX_VETOR];
	
	double tempo;
	
	clock_t inicio, fim;

	srand ( time(NULL) );
	
	/*
		Tanto o vetor como a lista como o vetor terão números distintos. 
	*/
	
	int x;
	//Inserindo na lista e na ABB.
	while(contador<MAX_VETOR){
	
		numero = (rand()%INTERVALO)+1;
		
	
		
			x = InsereArv(&raiz,numero);
		if( x==1 ){
			
			InserirLista(linicio,lfinal,numero);
			contador++;
		
		}
	}
	
	
	//Inserindo no vetor.
	for (contador=0;contador<MAX_VETOR;contador++)
	{
		v[contador]=(rand()%INTERVALO)+1;
	}
	

	
	//Buscando os números do vetor na árvore.
	inicio=clock();
	for (contador=0;contador<MAX_VETOR;contador++) BuscarArv(&raiz,v[contador]);
	fim=clock();
	tempo=((double)(fim-inicio))/CLOCKS_PER_SEC;
	printf("Tempo de Busca na Árvore: %.10lf\n",tempo);
	

	inicio=clock();
	for (contador=0;contador<MAX_VETOR;contador++) ProcurarLista(linicio,lfinal,v[contador]);
	fim=clock();
	tempo=((double)(fim-inicio))/CLOCKS_PER_SEC;
	printf("Tempo de Busca na Lista: %.10lf\n",tempo);


return 0;
}

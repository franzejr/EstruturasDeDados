#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMO 100000
#define INTERVALO 1000000

typedef struct NodeBB
{
	long int val;
	struct NodeBB *dir, *esq;
}nodeBB;

typedef struct Node2
{
	long int val;
	struct Node2 *prox, *ant;
}node2;

int insereBB(nodeBB **l,int n)
{
	nodeBB *novo;
	if (*l==NULL)
	{
		novo = (nodeBB*)malloc(sizeof(nodeBB));
		novo->val=n;
		novo->esq=NULL;
		novo->dir=NULL;
		*l=novo;
		return 1;
	}
	if (n==(*l)->val) return 0;
	if (n<(*l)->val)
	{
		return insereBB(&((*l)->esq),n);
	}
	else
	{
		return insereBB(&((*l)->dir),n);
	}
}

int procuraBB(nodeBB **l,int n)
{
	if ((*l)==NULL) return 0;
	if ((*l)->val==n) return 1;
	if (n<(*l)->val) 
	{
		return procuraBB(&((*l)->esq),n);
	}
	else
	{
		return procuraBB(&((*l)->dir),n);
	}
}

void insere2(node2 **l,node2 **lultimo,int numero)
{
	node2 *novo;
	novo = (node2*)malloc(sizeof(node2));
	novo->val=numero;
	novo->ant=NULL;
	novo->prox=NULL;
	if (*(l)!=NULL)
	{
		novo->ant=*lultimo;
		(*lultimo)->prox=novo;
		(*lultimo)=novo;
	}
	else
	{
		*l=novo;
		*lultimo=novo;	
	}
}

void procura2(node2 **l,int numero)
{
	node2 *aux;
	aux=*l;
	while (aux!=NULL)
	{
		if (aux->val==numero) break;
		aux=aux->prox;
	}
}

int main()
{
	node2 *l2=NULL,*l2ultimo=NULL;
	nodeBB *aBB=NULL;
	int numero,count=0,v[MAXIMO];
	clock_t antes,depois;
	double tempo;
	srand(time(NULL));
	while (count<MAXIMO)
	{
		numero=(rand()%INTERVALO)+1;
		
		if (insereBB(&aBB,numero)==1);
		{
			insere2(&l2,&l2ultimo,numero);
			count++;
		}
	}
	for (count=0;count<MAXIMO;count++)
	{
		v[count]=(rand()%INTERVALO)+1;
	}
	
	antes=clock();
	for (count=0;count<MAXIMO;count++) procuraBB(&aBB,v[count]);
	depois=clock();
	tempo=(depois-antes)/CLOCKS_PER_SEC;
	printf("arvore: %.10lf\n",tempo);
	
	antes=clock();
	for (count=0;count<MAXIMO;count++) procura2(&l2,v[count]);
	depois=clock();
	tempo=(depois-antes)/CLOCKS_PER_SEC;
	printf("lista: %.10lf\n",tempo);
	
	return 0;
}

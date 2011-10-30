#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int valor;
	struct node *cima;
	struct node *baixo;
	struct node *esq;
	struct node *dir;
} node;

typedef struct node Matriz; 

Matriz *inicio_linha; //Variável Global que marca o inicio da matriz.

void declarar_matriz(Matriz *m, int tam_x, int tam_y)
{
	int i, j;
	Matriz *p;
	Matriz *aux;	/*Guarda o primeiro nó da linha*/
	

	p = m; // P aponta para a matriz que será criada

	
		
		node *novo1;	/*Primeiro nó da matriz*/	
		novo1 = (node*)malloc (sizeof (node));
		novo1->valor = 0;
		p = novo1;
		aux = p;
		inicio_linha = p;
		p->esq = NULL;
		p->cima = NULL;
		
	
		m = p; //m aponta para o primeiron nó da Matriz.
	
	
	/*A partir daqui são criados os outros nós da primeira linha da matriz*/
	for (j=2;j<=tam_y;j++){	

		node *novo;
		novo = (node*)malloc (sizeof (node));
		p->dir = novo;
		novo->valor = 0;
		novo->esq = p;
		novo->cima = NULL;
		p = p->dir;
	}
	//Esse é o último da linha, então a direita dele aponta pra NULL
	p->dir = NULL;
	if (tam_x != 1){
		
	
					//Criar os de baixo
					p = inicio_linha;
					node *novo;
					novo = (node*)malloc (sizeof(node));
					novo->valor = 0;
					p->baixo = novo;
					novo->cima = p;
					p = p->baixo;
					aux = p->cima;
					inicio_linha = p;
	
	
			/*A partir daqui são criados os outros nós da segunda linha em diante.*/
	
			for (i=2;i<tam_x;i++){
				
				for (j=2;j<=tam_y;j++){
			
					
				
					aux = aux->dir;
					node *novo;
					novo = (node*)malloc (sizeof (node));
					aux->baixo = novo;
					novo->cima = aux;
					p->dir = novo;
					novo->valor = 0;
					novo->esq = p;
					p = p->dir;
				}
		
				p->dir = NULL; // Faz o último da linha apontar pra NULL

				/*Aqui é criado o primeiro nó da linha abaixo da atual para que na próxima iteração seja criada a nova linha.*/
		
				p = inicio_linha;	
				node *novo;
				novo = (node*)malloc (sizeof(node));
				novo->valor = 0;
				p->baixo = novo;
				novo->cima = p;
				p = p->baixo;	/* p vai percorrer as linhas da matriz e aux percorre a 					linha anterior*/
				aux = novo->cima;
				inicio_linha = p;
			}
		
	
			//Fazendo a última linha
	
			p->esq = NULL;
			p->baixo = NULL;
	
			while (aux->dir != NULL){
	
				node* novo;
				novo = (node*)malloc(sizeof(node));
				p->dir = novo;
				aux = aux->dir;
				aux->baixo = novo;
				novo->esq = p;
				novo->baixo = NULL;
				novo->cima = aux;
				novo->valor = 0;
				p = p->dir;
			}
	
			p->dir = NULL;
	
	
	
			//Fazendo p voltar pro elemento a11 da matriz.
	
			p = inicio_linha;
	
			while(p->cima != NULL) p = p->cima;
			inicio_linha = p;
	
			//Agora p já se encontra no elemento a11 da matriz.
		
				m = inicio_linha;
	
	
	}
		
}




void imprimir (Matriz *m)
{
	Matriz *p;
	p = m; //Ponteiro que percorre
	Matriz *linha = inicio_linha, *coluna = inicio_linha;
	
	
	while(linha != NULL){
			while(coluna != NULL){
	
				printf("  %d  ", coluna->valor);
		
				coluna = coluna->dir;

			}
	
			linha = linha->baixo; // A linha está descendo...
	
			coluna = linha;
			printf("\n \n");
	}
	
}


void armazenar(Matriz *m, int x, int y, int valor){

	
		Matriz *p = inicio_linha; //Ponteiro que percorre a matriz, ele recebe o valor de inicio_linha, que é global.
		int i; //Para iteração.
	
		//Percorrendo as linhas
		for(i = 1; i <x; i++){
			if( x == 1) break;
			
			p = p->baixo;			

		}
		
		//Percorrendo as colunas
		for(i = 1; i <y; i++){
			if( y == 1) break;
			
			p = p->dir;	
			
		
		}
		
		//Saiu do for, então já está no lugar certo.
		
		p->valor = valor;
		
		printf("valor de m %d  \n", p->valor); 
		
}


int obter_valor(Matriz *m, int x, int y){

		Matriz *p = inicio_linha; //Ponteiro que percorre a matriz, ele recebe o valor de inicio_linha, que é global.
		int i; //Para iteração.
	
		//Percorrendo as linhas
		for(i = 1; i <x; i++){
			if( x == 1) break;
			
			p = p->baixo;			

		}
		
		//Percorrendo as colunas
		for(i = 1; i <y; i++){
			if( y == 1) break;
			
			p = p->dir;	
			
		
		}
		
		//Saiu do for, então já está no lugar certo.
		
		return p->valor;
		


}


int main()
{

	int valor_obtido;
	Matriz m;
	declarar_matriz (&m, 10, 10);
	imprimir(&m);
	
	while(opcao!=0){
	
		printf("===========MATRIZ ENCADEADA=============\n\n");
		printf("0 - Sair\n");
		printf("1 - Inserir Elementos na Matriz\n");
		printf("2 - Remover Elementos da Matriz\n");

		
		scanf("%d", &opcao);


		switch(opcao){

			case 1: //Inserir Elementos na Matriz

				printf("Coloque os Elementos que você deseja colocar na Matriz\n");

				scanf("%d", &elemento)

				//armazenar()


			break;


			case 2:


			break;


			case 3:


			break;



		}
	
	
	}
	
	printf("Vamos armazenar o número 1 no elemento 2 2\n");
	
	armazenar(&m,5,6,1);
	armazenar(&m,5,5,1);
	
	
		
	printf("Imprimindo a nova matriz apos inserir\n");
	imprimir(&m);
	
	printf("Obter valor\n");
	valor_obtido = obter_valor(&m, 5,6);
	printf("o valor obtido foi %d \n", valor_obtido);
	 
	
	
	
	return 0;
	
}


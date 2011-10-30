/*

Aluno: Francisco José Lins Magalhães
Programação - Prof.: Miguel Franklin - Universidade Federal do Ceará
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int elem;
	int vazia;
	struct no *esq;
	struct no *dir;
}no;


int BuscarArv(no** raiz, int valor){

	if(*raiz == NULL) return 0; //Não deu certo

	if((*raiz)->elem == valor) return 1; //Deu certo

	if(valor < (*raiz)->elem)return BuscarArv(&((*raiz)->esq), valor);
	else
		return BuscarArv(&((*raiz)->dir),valor);
}


int InsereArv(no** raiz, int valor)
{


	if(BuscarArv(raiz, valor) == 0){// O elemento não se encontra na árvore, então ele vai inserir.

		if(*raiz == NULL){

			*raiz = (no*)malloc(sizeof(no));
			(*raiz)->elem = valor;
			(*raiz)->dir = NULL;
			(*raiz)->esq = NULL;

		}
		
		
		
		
		if( valor == (*raiz)->elem) return 1; //Caso base da recursão
		
		else if(valor < (*raiz)->elem) {	InsereArv(&((*raiz)->esq), valor); } //Se for menor
		
		else	InsereArv(&((*raiz)->dir),valor); //Se for maior


	}
	return 0; // O elemento já se encontra na árvore.

}

node* maximo(node **x){
	
	node* pai;

	
	if((*x)->dir == NULL){
		pai = *x;
		
		*x = (*x)->esq;
		
		return pai;		
	
	}
	
	while((*x)->dir != NULL){
		pai = *x;
		*x = &((*x)->dir); 
	}
	
	pai->dir = (*x)->esq;

return *x;
}


node* minimo(node** x){

	node* pai;
	
	
	if((*x)->esq == NULL){
		pai = *x;
		
		*x = (*x)->dir;
		
		return pai;		
	
	}

	while((*x)->esq != NULL){
		pai = *x;
		*x = &((*x)->esq);
	}
	
	pai->esq = (*x)->dir;
return *x;
}



node* remover_abb(node** x, int valor){


	//Caso base da recursão
	if(x->elem == valor){
		/*
			Aqui teremos 4 casos:
				1) Quando tiver nenhum filho;
				2) Quando tiver só o filho da esquerda;
				3) Quando tiver só o filho da direita;
				4) Quando tiver os dois filhos:
					4.1)Ele substitui pelo antecessor;
					4.2)Ele substitui pelo sucessor.
			
		*/
		
		if((*x)->esq == NULL && (*x)->dir == NULL) *x = NULL;
		
		if((*x)->esq != NULL && (*x)->dir == NULL) *x = (*x)->esq;
		
		if((*x)->esq == NULL && (*x)->dir != NULL) *x = (*x)->dir;
		
		if((*x)->esq != NULL && (*x)->dir != NULL){
				
	printf("Nó a a ser removido possui dois filhos.\n1 - Substituir pelo antecessor \n2 - Substituir pelo sucessor\n");
		
		node* direita, esquerda, temp;
		
		direita = (*x)->dir;
		esquerda = (*x)->esq;
		
		
		int a;
			
		scanf("%d", &a);
		
		if(a == 1){
		 temp = maximo(&((*x)->esq)); //Vai pegar o máximo da esquerda
		 temp->dir = direita; //Nesse caso, a direita continua sendo a direita.
		 if(temp == esquerda) esquerda = temp->esq;
		 (*l) = temp;
		 (*l)->esq = esquerda;
			
		}		
		else{
		 temp = minimo(&((*x)->dir)); //Vai pegar o mínimo da direita
		 temp->esq = esquerda; //Nesse caso a esquerda, continua sendo a esquerda.
		 if(temp == direita) direita = temp->dir; //O que ele quer pegar é o primeiro.
		 (*l) = temp;
		 (*l)->dir = direita;
		}
		
		
	}	
		
		
		
		
	
	
	
	}
	
	//Caso em que ele não encontra ainda o valor em que ele deseja remover, então ele entra na recursão
	if(&((*x)->elem) < valor) return remover_abb(x->esq);
	if(&((*x)->elem) > valor) return remover_abb(x->dir);




}
	
	

void ImprimeSimetrica(no** raiz){
	no* percorre = *raiz;
	if(percorre != NULL){
		ImprimeSimetrica(&percorre->esq);
		printf("<%d> ", percorre->elem);
		ImprimeSimetrica(&percorre->dir);
	}

}

void ImprimePreOrdem(no** raiz){
	no*percorre = *raiz;
	if(percorre != NULL){
		printf("<%d>",percorre->elem);
		ImprimePreOrdem(&percorre->esq);
		ImprimePreOrdem(&percorre->dir);
	}
}

void ImprimePosOrdem(no** raiz){
	no* percorre = *raiz;
	if(percorre != NULL){
		ImprimePosOrdem(&percorre->esq);
		ImprimePosOrdem(&percorre->dir);
		printf("<%d>", percorre->elem);
	}
}






int main(){
	int opcao, valor=0, numero,retorno;
	no* raiz = NULL;

	do{
		system("clear");
		
		printf("============================================================\n");
		printf("Aluno: Francisco José Lins Magalhães - Matrícula 0322836\n");
		printf("Disciplina Programação - UFC 2010.2\n");
		printf("============================================================\n");
		printf("Árvore Binária de Busca\n");

		printf("MENU\n");
		printf("0 - Sair\n");
		printf("1 - Adicionar Elementos\n");
		printf("2- Buscar na Árvore\n");
		printf("Adicionais:\n");
		printf("3 - Imprimir em Ordem Simétrica\n");
		printf("4 - Imprimir em PreOrdem\n");
		printf("5 - Imprimir em PosOrdem\n");

		printf(".: ");
		

		scanf("%d", &opcao);


		switch(opcao){

			case 1: //Adicionar
				printf("Coloque o elemento que você deseja inserir na árvore\n");
				scanf("%d", &numero);

				printf("Inserindo elemento na árvore...\n");
				retorno = InsereArv(&raiz, numero);
				
				if(retorno == 1) printf("Elemento inserido com sucesso!!\n");
				else printf("Elemento não foi inserido!\n");

				printf("Pressione Enter para continuar\n");
				getchar();
				getchar();


			break;

			case 2://Buscar
				printf("Coloque o elemento que você deseja buscar na árvore\n");
				scanf("%d", &numero);

				printf("Buscando elemento na árvore...\n");
				retorno = BuscarArv(&raiz, numero);
				
				if(retorno == 1) printf("O Elemento %d encontrado com sucesso!!\n",numero);
				else printf("O Elemento %d não foi inserido!\n",numero);

				printf("Pressione Enter para continuar\n");
				getchar();
				getchar();

			break;


			case 3: //OrdemSimetrica

			printf("Imprimindo a árvore em Ordem Simétrica: \n\n");

			ImprimeSimetrica(&raiz);
			
			printf("\n");
			printf("Pressione Enter para continuar\n");
			getchar();
			getchar();
			break;


			case 4: //PreOrdem

			printf("Imprimindo a árvore em Pre Ordem: \n\n");

			ImprimePreOrdem(&raiz);

			printf("\n");
			printf("Pressione Enter para continuar\n");
			getchar();
			getchar();

			break;

			case 5: // PosOrdem
			
			printf("Imprimindo a árvore em Pos Ordem: \n\n");

			ImprimePosOrdem(&raiz);

			printf("\n");
			printf("Pressione Enter para continuar\n");
			getchar();
			getchar();


			break;

		}



	}
	while(opcao!=0);


return 0;
}

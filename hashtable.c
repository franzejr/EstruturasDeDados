/*
Aluno: Francisco José Lins Magalhães
Universidade Federal do Ceará.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	int chave;
	void *ponteiro;
	int tipo;
	struct no* esq;
	struct no* dir;

}no;


/*Inserir Inteiro na árvore binária
--Retorna 1 se deu certo,
--Retorna 0 se não deu certo.
*/
int inserirInt(no** raiz, int id, int elemento)
{

	no *novo;
	
	if(*raiz == NULL){

		novo = malloc(sizeof(no));
		novo->esq = NULL;
		novo->dir = NULL;
		int* inteiro;
		inteiro = malloc(sizeof(int));
		*inteiro = elemento;
		novo->ponteiro = inteiro;
		novo->chave = id;
		novo->tipo = 0;
		
		*raiz = novo;

	}else{
			
		if( id == (*raiz)->chave) return 0; //Elemento já se encontra na árvore.

		if(id < (*raiz)->chave) 
		{	

			return inserirInt(&((*raiz)->esq), id, elemento);
		} 
		else
		{
			return inserirInt(&((*raiz)->dir),id,elemento);
		}
	}
}


/*Inserir Float na árvore binária
--Retorna 1 se deu certo,
--Retorna 0 se não deu certo.
*/
int inserirFloat(no** raiz, int id, float elemento)
{
	no* novo;
	
	if(*raiz == NULL){

		novo = malloc(sizeof(no));
		novo->esq = NULL;
		novo->dir = NULL;
		float* floating;
		floating = malloc(sizeof(float));
		*floating = elemento;
		novo->ponteiro = floating;
		novo->chave = id;
		novo->tipo = 0;
		
		*raiz = novo;

	}
			
	if( id == (*raiz)->chave) return 0; //Elemento já se encontra na árvore.
		
	if(id < (*raiz)->chave) 
	{
		return inserirFloat(&((*raiz)->esq), id,elemento);
	} 
	else
	{
		return inserirFloat(&((*raiz)->dir),id,elemento);
	}
}



/*Inserir String na árvore binária
--Retorna 1 se deu certo,
--Retorna 0 se não deu certo.
*/
int inserirString(no** raiz, int id, char* String)
{
	int tamanho;
	
	if(*raiz == NULL){

			*raiz = (no*)malloc(sizeof(no));
			tamanho = strlen(String);
			char* nome = malloc(tamanho*sizeof(char));
			strcpy(nome,String);
			(*raiz)->chave = id;
			(*raiz)->tipo = 2;
			(*raiz)->ponteiro = nome;
			(*raiz)->dir = NULL;
			(*raiz)->esq = NULL;
			
			return 1;

	}
			
	if( id == (*raiz)->chave) return 0; //Elemento já se encontra na árvore.
		
	if(id < (*raiz)->chave) 
	{
		return inserirString(&((*raiz)->esq), id,String);
	} 
	else
	{
		return inserirString(&((*raiz)->dir),id, String);
	}
}


/*Procurar tipo
--Retorna -1 se não deu certo,
--Retorna 0 se o tipo é int.
--Retorna 1 se o tipo é float.
--Retorna 2 se o tipo é string.
*/
int procurarTipo(no** raiz, int id){

	if(*raiz == NULL) return -1; //Não deu certo

	if((*raiz)->chave == id){ //Deu certo
			if((*raiz)->tipo == 0) return 0; //Achou um int
			if((*raiz)->tipo == 1) return 1; //Achou um float
			if((*raiz)->tipo == 2) return 2; //Achou uma string
	 
	 }

	if(id < (*raiz)->chave)return procurarTipo(&((*raiz)->esq), id);
	else
		return procurarTipo(&((*raiz)->dir),id);
}

int* obterInt(no** raiz, int id){

		if(*raiz == NULL) return NULL; //Não deu certo

		if((*raiz)->chave == id){ //Deu certo
				return (int*)(*raiz)->ponteiro;
		 }

		if(id < (*raiz)->chave)return obterInt(&((*raiz)->esq), id);
		else
			return obterInt(&((*raiz)->dir),id);


}

float* obterFloat(no** raiz, int id){
		
		if(*raiz == NULL) return NULL; //Não deu certo

		if((*raiz)->chave == id){ //Deu certo
				return (float*)(*raiz)->ponteiro;
		 }

		if(id < (*raiz)->chave)return obterFloat(&((*raiz)->esq), id);
		else
			return obterFloat(&((*raiz)->dir),id);


}

char* obterString(no** raiz, int id){

		if(*raiz == NULL) return NULL; //Não deu certo

		if((*raiz)->chave == id){ //Deu certo
				return (char*)(*raiz)->ponteiro;
		 }

		if(id < (*raiz)->chave)return obterString(&((*raiz)->esq), id);
		else
			return obterString(&((*raiz)->dir),id);

}

no *maximo(no **l){
	
	no* pai;

	
	if((*l)->dir == NULL){
		pai = *l;
		
		*l = (*l)->esq;
		
		return pai;		
	
	}
	
	while((*l)->dir != NULL){
		pai = *l;
		*l = (*l)->dir; 
	}
	
	pai->dir = (*l)->esq;

return *l;
}


no *minimo(no** l){

	no* pai;
	
	
	if((*l)->esq == NULL){
		pai = *l;
		
		*l = (*l)->dir;
		
		return pai;		
	
	}

	while((*l)->esq != NULL){
		pai = *l;
		*l = (*l)->esq;
	}
	
	pai->esq = (*l)->dir;
return *l;
}




no *remover_recursivo(no **l, int n)
{
	if (*l==NULL) return NULL;
	if ((*l)->chave==n)
	{
		no *aux;
		aux=*l;
		
		if ((*l)->esq == NULL && (*l)->dir == NULL) *l=NULL;
		else
		if ((*l)->esq != NULL && (*l)->dir == NULL) *l=(*l)->esq;
		else
		if ((*l)->esq == NULL && (*l)->dir != NULL) *l=(*l)->dir;
		else
		if ((*l)->esq != NULL && (*l)->dir != NULL)
		{
			no *direita,*esquerda,*temp;
			direita = (*l)->dir;
			esquerda = (*l)->esq;
			printf("No a ser removido possui dois filhos.\n1 - substituir pelo antecessor\n2 - substituir pelo sucessor\n");
			int a;
			scanf("%d",&a);
			if (a==1)
			{
				temp=maximo(&((*l)->esq));
				temp->dir = direita;
				if (temp==esquerda) esquerda = temp->esq;
				(*l)=temp;
				(*l)->esq = esquerda;
			}
			else
			{
				temp=minimo(&((*l)->dir));
				temp->esq = esquerda;
				if (temp==direita) direita = temp->dir;
				(*l)=temp;
				(*l)->dir=direita;
			}
		}
		return aux;
	}
	if (n<(*l)->chave) 
	{
		return remover_recursivo(&((*l)->esq),n);
	}
	else
	{
		return remover_recursivo(&((*l)->dir),n);
	}
}

int remover(no **l,int chave)
{
	no *temp;
	int a;
	temp = remover_recursivo(l,chave);
	if ( temp == NULL) a=0;
	else
	{
		a=1;
		free(temp->ponteiro);
		free(temp);
	}
	return a;
}

void imprime_simetrico(no *l)
{
	if (l!=NULL)
	{
		imprime_simetrico(l->esq);
		printf("id: %d | elem: %d ",l->chave, *((int*)l->ponteiro));
		imprime_simetrico(l->dir);
	}
}



int main(){

	no* raiz = NULL;
	
	int opcao, tipagem,k;
	int numeroint, idnumeroint;
	float numerofloat, idnumerofloat;
	char string[100];
	int* x;
	float *y;
	char *z;
	
	do{
		system("clear");
		printf("\n**HashTable**\n\n");
		printf("===Main Menu===\n");
		printf(" [0] - Sair\n");
		printf(" [1] - Inserir\n");
		printf(" [2] - Procurar\n");
		printf(" [3] - Remover \n\n.: ");
		
		scanf("%d", &opcao);
		
		
		switch(opcao){
			case 0:
				exit(1);
				
				break;
			
			case 1: //Inserir
				printf("Que tipo de número você deseja inserir?\n");
					printf("0 - Inteiro\n");
					printf("1 - Float\n");
					printf("2 - String\n");
					
					scanf("%d", &tipagem);
				
					switch(tipagem){
				
						case 0: //Inserir Inteiro
							printf("Qual número inteiro você deseja inserir?\n");
							scanf("%d", &numeroint);
							printf("Qual ID para esse número?\n");
							scanf("%d",&idnumeroint);
							
							inserirInt(&raiz, idnumeroint, numeroint);
							
							printf("Elementos na HashTable "); imprime_simetrico(raiz);
					
							break;
						
						case 1: //Inserir Float
							printf("Qual número float você deseja inserir?\n");
							scanf("%f", &numerofloat);
							printf("Qual ID para esse número?\n");
							scanf("%f",&idnumerofloat);
					
							inserirFloat(&raiz, idnumerofloat,numerofloat);
							break;
						
						case 2: //Inserir uma String
						
							printf("Qual String você deseja inserir?\n");
							scanf("%s", string);
							printf("Qual ID para essa String?\n");
							scanf("%d", &numeroint);
					
							inserirString(&raiz, numeroint, string);
							break;

					}
				
				break;
				
			case 2: //Procurar
			
					printf("Que tipo de número você deseja procurar?\n");
					printf("0 - Inteiro\n");
					printf("1 - Float\n");
					printf("2 - String\n");
					
					scanf("%d", &tipagem);
				
					switch(tipagem){
				
						case 0: //Procurar um inteiro
						
							printf("Qual ID você gostaria de buscar?\n");
							scanf("%d", &idnumeroint);
							

							
							x = obterInt(&raiz, idnumeroint);
							if(x != NULL) { 
								printf("O elemento: %d \n", *x);
								printf(" Tipo dele é: %d \n", procurarTipo(&raiz, idnumeroint) );
							}
							else printf("O elemento nao se encontra\n");				
														
							getchar();
							getchar();
					
							break;
						
						case 1://Procurar um float
							
							printf("Qual ID você gostaria de buscar?\n");
							scanf("%d",&idnumeroint);
							
							y = obterFloat(&raiz, idnumeroint);
							if(y != NULL){
								printf("O elemento: %f \n", *y);
								printf(" Tipo dele é: %d \n", procurarTipo(&raiz, idnumeroint) );
							}
							else printf("O elemento não se encontra\n");
							
							
							getchar();
							getchar();
							break;
						
						case 2: //Procurar uma String
							
							printf("Qual ID que você gostaria de buscar?\n");
							scanf("%d", &idnumeroint);
							
							z = obterString(&raiz, idnumeroint);
							if(z != NULL){
								printf("O elemento: %s \n", z);
								printf("Tipo dele é %d \n", procurarTipo(&raiz, idnumeroint));
							}
							else printf("O elemento não se encontra\n");	

							getchar();
							getchar();
							break;

					}
			
				break;
				
				case 3: // remover
					printf("Qual ID você deseja remover? \n");
					scanf("%d", &idnumeroint);
					
					k = remover(&raiz, idnumeroint);
					if(k == 0 ) printf("chave nao encontrada\n");
				
					break;
				
				
				
			default:
				printf("Entrada Inválida\n");

				break;

		}//Término do switch

	}//Término do
	while( opcao !=0);

return 0;
}



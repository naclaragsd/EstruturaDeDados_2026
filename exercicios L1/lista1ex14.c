/* 14.Com base no exercício 12 (PILHA ORIGINAL), construa uma função que
retorne a quantidade de elementos maiores que 50 na pilha. */

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

typedef struct No{
	int num;
	struct No *prox;
}no;

void push(int item);
void pop();
void imprimir();
int existe(int item);
int maior();

no *top=NULL;
/* top sempre aponta para o topo REAL da pilha.
   Se alterarmos top, alteramos a estrutura da pilha */

//--------------------------------------------------------------------------
int main(){
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL)); /* Inicializa a semente dos números aleatórios.
  						 Deve ser chamada apenas UMA vez no programa */
	
	int i, item;
	
	printf("\nPilha de 15 valores aleatórios: ");
	
	for(i=0;i<15;i++){
		item=rand()%91+10; /* rand()%91 gera números entre 0 e 90
   							 somando 10, obtemos números entre 10 e 100. */
		
		/* Se o número já existir na pilha,
   		gera outro número até encontrar um que não esteja repetido. */
		while(existe(item)){
			item=rand()%91+10;
		}
		push(item);
	}		
	imprimir();
	
	printf("\nMaiores que 50: %d",maior());
	return 0;
}

//--------------------------------------------------------------------------

void push(int item){
	/* malloc cria um novo nó na memória.
   Sempre que criamos um novo elemento da pilha,
   precisamos alocar memória. */
	no *novo=malloc(sizeof(no));
	
	if(novo==NULL){
		printf("\nsem memória!");
		return;
	}else{
		novo->num=item;
		novo->prox=top; //novo no aponta para antigo topo
		top=novo; // novo no passa a ser o topo da pilha
	}
}

//--------------------------------------------------------------------------

void pop(){
	no *temp;
	
	if(top==NULL){
		printf("\nPilha vazia!");
		return;
	}
		temp=top; // guarda topo atual para que possa ser removido
		top=top->prox; // topo passa apontar para o proximo elemento
		free(temp); // libera memoria do no removido
	
}

//--------------------------------------------------------------------------

int existe(int item){
	no *temp=top;
	
	while(temp!=NULL){
		if(item==temp->num){
		return 1;
	}
		temp=temp->prox;
	}
	return 0;
}

/* temp é um ponteiro auxiliar usado apenas para percorrer,
   nunca usamos top para percorrer a pilha,
   pois isso alteraria a estrutura */

//--------------------------------------------------------------------------

void imprimir(){
	no *temp;
	temp = top;
	
	while(temp!=NULL){
		printf("\n[ %d ]",temp->num);
		temp=temp->prox;
	}
}

//percorre a pilha do topo ate a base

//--------------------------------------------------------------------------

int maior(){
	no *temp = top;
	int cont = 0; // contador de elementos maiores que 50.

	while(temp != NULL){

		printf("\nVerificando: %d", temp->num);

		if(temp->num > 50){
			cont++; /* soma 1 ao contador sempre que encontrar
   						um valor maior que 50*/
			printf(" -> maior que 50");
		}

		temp = temp->prox;
	}

	printf("\nContador final = %d\n", cont);

	return cont; //retorna a quantidade total de elementos maiores que 50
}

/*
ANOTAÇÕES

- quando usar malloc?
   -> Quando criar um novo nó.

- quando usar free?
   -> Quando remover um nó.

- quando usar top?
   -> Para alterar a pilha.

- quando usar temp?
   -> Para percorrer a pilha sem alterá-la.

- como percorrer uma pilha?

   no *temp = top;

   while(temp != NULL){
       ...
       temp = temp->prox;
   }

- diferença entre top e temp:

   top  = ponteiro principal da pilha.
   temp = ponteiro auxiliar.

- como gerar números entre 10 e 100?
   rand()%91 + 10

- como evitar números repetidos?

   while(existe(valor)){
       valor = rand()%91 + 10;
   }

- como contar elementos com determinada condição?

   int cont = 0;

   while(temp != NULL){

       if(condição){
           cont++;
       }

       temp = temp->prox;
   }

   return cont;
*/


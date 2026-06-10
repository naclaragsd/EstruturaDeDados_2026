/* 12.Construa um programa em linguagem c que monte uma pilha de 15
elementos com valores aleatórios (não repetidos) entre 10 e 100. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

typedef struct No{
	int num;
	struct No *prox;
}no;

void push(int valor);
void pop();
void imprimir();

no *top=NULL;

//----------------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");	
	srand(time(NULL)); //inicialia uma semente para numeros aleatorios
	
	int valor, i;
	
	printf("\nPilha de 15 elementos com valores aleatórios: \n");
	for(i=0;i<15;i++){
	valor=rand()%91+10; /* rand: gera um número enorme
							rand()%90 gera numero de 0 ate 90 
							rand()%91+10 gera números de 10 ate 100
							porque 0+10 = 10 e 90+10 = 100 */
	
	while(existe(valor)){
		valor=rand()%91+10;
	}
	push(valor);
	}
	imprimir();
	
}

//----------------------------------------------------------------------

void push(int valor){
	no *novo=malloc(sizeof(no));
	
	novo->num=valor;
	novo->prox=top;
	top=novo;
}
/* cria um novo no e aloca no topo da pilha, e o novo no passa a apontar
para o antigo topo */

//----------------------------------------------------------------------

void pop(){
	no *temp;
	
	if(top==NULL){
		printf("\nPilha vazia!");
		return;
	}
	
	temp=top;
	top=top->prox;
	free(temp);
}

//----------------------------------------------------------------------

void imprimir(){
	no *temp = top;
	
	while(temp!=NULL){
		printf("\n[ %d ]",temp->num);
		temp=temp->prox;
	}
}

// percorre a pilha do topo até a base sem alterar sua estrutura

//----------------------------------------------------------------------

int existe(int valor){
no *temp=top;
	
	while(temp!=NULL){
		if(valor==temp->num){
			return 1;
		}
		temp=temp->prox;
	}
	return 0;
}

/* usa um ponteiro auxiliar (temp) para percorrer a pilha. Nunca usamos
top para percorrer, pois ele aponta para o topo real da pilha, se alterar
o top, perdemos dados */

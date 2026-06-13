/* 16.Construa um programa em linguagem C que implemente uma PILHA através
de 10 elementos (entre 10 e 100) gerados randomicamente (não repetidos).
Posteriormente, apresente o conteúdo da pilha. */

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

typedef struct No{
	int dado;
	struct No *prox;
}no;

void push(int item);
void pop();
void mostrar();
int existe(int num);

/* 
void - função NAO retorna valor 
ex: push() pop() mostrar() : apenas executam ações

int - função RETORNA um valor inteiro
ex: int existe(int num) : vai retornar 1 se encontrou ou 0 se não encontrou

sempre que a função precisar responder uma pergunta, usa int
sempre que uma função executar uma tarefa, usa void
*/

no *top=NULL;

//--------------------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	
	int cont=0, num;
		
	printf("\nPilha de 10 elementos entre 10 e 100: \n");
	
	while(cont<10){
		num=rand()%91+10; // gera número entre 0 e 90 somando 10; De 10 até 100
						// o while vai gerar 10 números diferentes
		
		if(existe(num) == 0){
			push(num);
			cont++;
		}
	}
	mostrar();
	
	return 0;
}

//--------------------------------------------------------------------------

void push(int item){
	no *novo=malloc(sizeof(no));
	
	novo->dado=item;
	novo->prox=top;
	top=novo;
}
/* cria um novo nó.
   guarda o valor.
   faz o novo nó apontar para o topo atual.
   atualiza top.*/

//-------------------------------------------------------------------------

void pop(){
	no *temp;
	temp=top;
	
	if(top!=NULL){
		top=top->prox;
		free(temp);
	}
}

/* guarda o topo atual.
   move top para o próximo nó.
   libera a memória removida.*/

//------------------------------------------------------------------------

int existe(int num){
	no *temp=top;
	
	while(temp!=NULL){
		
		if(temp->dado==num){
			return 1;
		}
		temp=temp->prox;
	}
	return 0;
}

/* percorre toda a pilha procurando
o número recebido

	se encontrar:
		retorna 1.
	se não encontrar:
		retorna 0.
*/

//------------------------------------------------------------------------

void mostrar(){
	no *temp=top;
	
	while(temp!=NULL){
		printf("\n [%d] ",temp->dado);
		temp=temp->prox;
	}
}
// percorre toda a pilha exibindo os valores
//------------------------------------------------------------------------


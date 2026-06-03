/* Desenvolva um programa em C que simule uma PILHA com 20 valores
aleatorios entre 10 e 125. Posteriormente, remova todos os elementos
ímpares da pilha e apresente a pilha final ao usuário. Não esqueça de liberar
a pilha toda ao encerrar o programa. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

void num();		// gera 20 números aleatórios
void mostrar(); // mostra a pilha principal 
void impar();	// remove os ímpares usando a pilha auxiliar
void liberar(); // remove no na pilha

int pop();		// remove do topo da pilha principal
void push(int valor);	// adiciona na pilha principal

int pop2(); // remove do topo da pilha auxiliar
void push2(int valor);/* adiciona na pilha auxiliar 

							push: tem como paramentro int valor pq a função
							precisa saber qual valor será colocado na pilha
							já o pop não precisa pois quando vc remove um 
							elemento da pilha, ela ja sabe qual é o topo  
							
							void push: pq não retorna valor
							int pop: pq ele tem que saber qual valor foi removido */

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}no;

no *top = NULL;
no *top2 = NULL;

//------------------------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	int opcao, valor;
	do{
		printf("\n========================================================================================================================");
		printf("\n");
		printf("\nMenu:\n1. Gerar 20 números aleatórios entre 10 e 125\n2. Mostrar pilha \n3. Remover elementos ímpares da pilha \n4. Liberar pilha \n5. Sair");
		printf("\n");
		printf("\n========================================================================================================================");
		printf("\nEscolha uma opção: (1-4): ");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				liberar();
				num();
				break;
			case 2:
				mostrar();
				break;
			case 3:
				impar();
				printf("\nÍmpares removidos!");
				break;
			case 4:
				liberar();
				printf("\nPilha liberada!\n");
				break;
			case 5:
				printf("\nEncerrando programa...\n");
				break;
				
				default:
					printf("\nOpção inválida!\n");
		}
	} while(opcao!=5);
	
	liberar();
	
	return 0;
}

//------------------------------------------------------------------------------

void push(int valor){ //adiciona
	no *novo=malloc(sizeof(no));
	
	if(novo==NULL){
		printf("Sem memória disponível!\n");
		return;
	}else{
		novo->dado=valor;
		novo->proximo=top;
		top=novo;
	}
	
}

//------------------------------------------------------------------------------

void push2(int valor){ // adiciona pilha auxiliar
	no *novo=malloc(sizeof(no));
	
	if (novo==NULL){
		return;
	}else{
		novo->dado=valor;
		novo->proximo=top2;
		top2=novo;
	}
}

//------------------------------------------------------------------------------

int pop(){ //remove
	if(top==NULL){
		return-1;
	}
	no *temp=top;
	int valor=temp->dado;
	
	top=top->proximo;
	free(temp);
	
	return valor;
}

//------------------------------------------------------------------------------

int pop2(){ //remove pilha auxiliar
	if(top2==NULL){
		return-1;
	}
	no *temp=top2;
	int valor=temp->dado;
	
	top2=top2->proximo;
	free(temp);
	
	return valor;
}

//------------------------------------------------------------------------------

void impar(){
	int valor;
	
	while(top!= NULL){
		valor=pop();
		
		if(valor %2 == 0){
			push2(valor);
		}
	}
	
	while(top2 != NULL){
		valor = pop2();
		push(valor);
	}
}

/*	Essa função remove todos os números ímpares da pilha principal

Ela percorre toda a pilha principal removendo os elementos um a um
com pop()

	- se o valor removido for par, ele é armazenado na pilha auxiliar
	utilizando push2(); Se for ímpar ele é descartado do laço 
	
após analisar todos os elementos, os valores da pilha auxiliar 
são devolvidos para a pilha principal utilizando pop2() e push()

dessa forma, a pilha principal fica contendo apenas os números
pares e todos os ímpares são removidos
*/

//------------------------------------------------------------------------------

void mostrar(){
	no *aux=top;
	
	while(aux!=NULL){
		printf(" [%d] ",aux->dado);
		aux=aux->proximo;
	}
}

//------------------------------------------------------------------------------
void num(){
	int valor, i;
	printf("\nNúmeros gerados...");
	
	for( i=0;i<20;i++){
		 valor = rand()%116+10; // 125-10+1=116
		 push(valor);
		//printf(" [%d] ",valor);
	}
	printf("\n");
}

//-----------------------------------------------------------------------------

void liberar(){
	while(top != NULL){
		pop();
	}
	
	while(top2 != NULL){ //para garantir que a pilha auxiliar foi liberada
		pop2();
	}
}

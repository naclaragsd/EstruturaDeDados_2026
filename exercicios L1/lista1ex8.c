/* 8- Com base no exercicio anterior, faça o mesmo para uma FILA 

Desenvolva um programa em C que simule uma FILA com 20 valores
aleatorios entre 10 e 125. Posteriormente, remova todos os elementos
ímpares da FILA e apresente a FILA final ao usuário. Não esqueça de liberar
a FILA toda ao encerrar o programa. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

void num();
void mostrar();
void impar();
void liberar();

void enqueue(int valor);
int dequeue();

void enqueue2(int valor);
int dequeue2();


typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}no;

no *inicio = NULL;
no *fim = NULL;

/* FILA PRINCIPAL: vai armazenar 20 números aleatórios 
-inserção no final da fila (enqueue)
- remoção no início da fila (dequeue) */

no *inicio2 = NULL;
no *fim2 = NULL;

/* FILA AUXILIAR: utilizado para guardar temporariamente 
apenas os números pares */

int main(){
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	
	int opcao, valor;
	do{
		printf("\n========================================================================================================================");
		printf("\n");
		printf("\nMenu:\n1. Gerar 20 números aleatórios entre 10 e 125\n2. Mostrar fila \n3. Remover elementos ímpares da fila \n4. Liberar fila \n5. Sair");
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
				printf("\nfila liberada!\n");
				break;
			case 5:
				printf("\nEncerrando programa...\n");
				break;
				
				default:
					printf("\nOpção inválida!\n");
		}
	}while(opcao!=5);
	return 0;
}

//-----------------------------------------------------------------------------

void enqueue(int valor){ //insere um valor no final da fila
	no *novo = malloc(sizeof(no));
	
	if (novo == NULL){
		printf("\nsem memória disponível...");
		return;
	}
	
	novo->dado=valor;
	novo->proximo=NULL;
	
	if(inicio == NULL){
		inicio=novo;
		fim=novo;
	}else{
		fim->proximo=novo;
		fim=novo;
	}
}

//-----------------------------------------------------------------------------

void enqueue2(int valor){
	no *novo=malloc(sizeof(no));
	
	if(novo==NULL){
		return;
	}
	
	novo->dado=valor;
	novo->proximo=NULL;
	
	if(inicio2==NULL){
		inicio2=novo;
		fim2=novo;
	}else{
		fim2->proximo=novo;
		fim2=novo;
	}
}

//-----------------------------------------------------------------------------

int dequeue(){ //remove o primeiro elemento da fila e retorna o valor removido
	if(inicio == NULL){
		return -1;
	}
	
	no *temp = inicio;
	int valor = temp->dado;
	
	inicio=inicio->proximo;
	
	if(inicio==NULL){
		fim=NULL;
	}
	
	free(temp);
	return valor;
}

//-----------------------------------------------------------------------------

int dequeue2(){
	if (inicio2==NULL){
		return-1;
	}
	
	no *temp=inicio2;
	int valor = temp->dado;
	
	inicio2=inicio2->proximo;
	
	if(inicio2==NULL){
		fim2=NULL;
	}
	
	free(temp);
	return valor;
}

//-----------------------------------------------------------------------------

void mostrar(){ //percorre toda a fila usando um ponteiro auxiliar
	no *aux=inicio;
	
	while(aux != NULL){
		printf(" [%d] ", aux->dado);
		aux=aux->proximo;
	}
}

//-----------------------------------------------------------------------------

void impar(){
	int valor;
	
	while(inicio!=NULL){
		valor=dequeue();
		
		if(valor%2==0){
			enqueue2(valor);
		}
	}
	
	while(inicio2!=NULL){
		valor=dequeue2();
		enqueue(valor);
	}
}

/* remove todos os elementos da fila principal;
    - se o número for par envia para a fila auxiliar
	- se for ímpar descarta
	após terminar devolve rodos os pares para a fila principal */

//-----------------------------------------------------------------------------

void num(){
	int valor, i;
	printf("\nNúmeros gerados...");
	
	for(i=0;i<20;i++){
		valor=rand()%116+10;
		enqueue(valor);
	}
	printf("\n");
}

//------------------------------------------------------------------------------

void liberar(){ // remove todos os nos da memoria usando dequeue()
	
	while(inicio!=NULL){
		dequeue();
	}
	
	while(inicio2!=NULL){
		dequeue2();
	}
}

//------------------------------------------------------------------------------

	/* 
	
	FIFO (FIRST IN, FIRST OUT)
	o primeiro que entra é o primeiro que sai 
	
	malloc()
	reserva memória para um novo no 
	
	free()
	libera memória do no removido
	
	PONTEIROS:
	inicio: primeiro elemento da fila
	fim: último elemento da fila
	
	aux: usado para percorrer a fila sem alterar
	a estrutura original
	 
	*/

//------------------------------------------------------------------------------


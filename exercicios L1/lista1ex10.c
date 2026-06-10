/* 10.Construa um progama em linguagem C que implemente uma FILA
contendo o nome e idade de 10 pessoas fornecidas pelo usuário.
Posteriormente, monte mais duas filas (FILA2 e FILA3) onde a primeira
deverá conter as pessoas até 30 anos e a segunda acima de 30. Apresente
as duas novas filas ao usuário e posteriormente encerre o programa,
liberando a memória das três filas. Obs. A fila inicial deverá ser esvaziada ao
final do processo. */

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

//--------------------------------------------------------------

void enqueue(char nome[], int idade);
void dequeue(char nome[], int *idade);
void mostrar();
void mostrar2();
void mostrar3();

void liberar2();
void liberar3();

void enqueue2(char nome[], int idade);
void enqueue3(char nome[], int idade);

void separar();

//--------------------------------------------------------------

typedef struct no{
	char nome[50];
	int idade;
	struct no *prox;
}no;

// ponteiros da fila 1
no *frente = NULL; //primeiro elemento
no *fim = NULL;	   // último elemento

no *frente2 = NULL;
no *fim2 = NULL;

no *frente3 = NULL;
no *fim3 = NULL;

//---------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	
	int i;
	char nome[50];
	int idade;
	
	for(i=0;i<10;i++){
		printf("insera o %d nome: ",i+1);
		fgets(nome,50,stdin);
		nome[strcspn(nome, "\n")] = '\0';
		
		printf("insira a idade de %s: ",nome);
		scanf("%d", &idade);
		getchar();
		
		printf("\n");
		
		enqueue(nome,idade);
	}
	separar();
	printf("\n========== PESSOAS COM ATÉ 30 ANOS =========\n");
	mostrar2();
	printf("\n");
	printf("\n========== PESSOAS COM MAIS DE 30 ANOS ==========\n");
	mostrar3();
	
	liberar2();
	liberar3();
	
	return 0;
}

//---------------------------------------------------------------

void enqueue(char nome[50],int idade){
	// aloca memória para um novo no da fila 
	no *novo = malloc(sizeof(no));
	
	if (novo == NULL){
		printf("sem memória!\n");
		return;
	}
	
	// copia os dados recebidos para um novo no
	strcpy(novo->nome,nome);
	novo->idade = idade;
	novo->prox=NULL;
	
	if (fim == NULL){	// se a fila estiver vazia
		frente = novo;
		fim = novo;	   // o novo no sera o primeiro e o último
					   // elemento
	}else{
		fim->prox = novo;
		fim = novo;		// caso contrário, adiciona no final da fila
	}
}

//---------------------------------------------------------------

void dequeue(char nome[], int *idade){
	
	if(frente==NULL){
	printf("a fila esta vazia");
	return;
	
}else{
	//remove o peimeiro elemento da fila
	no *temp = frente;
	
	// retorna os dados removidos
	strcpy(nome, temp->nome);
	*idade = temp->idade;
	
	frente = frente->prox; //avança o inicio da fila
	
	if(frente == NULL){
	fim=NULL;			// se a fila ficou vazia, atualiza o fim
	}
	
	free(temp);
}
}

//-------------------------------------------------------------

void mostrar(){
	
	no *temp = frente;
	
	while(temp != NULL){
		printf ("\n\nNOME: %s \nIDADE: %d\n\n",temp->nome, temp->idade);
		temp=temp->prox;
	}
}

//--------------------------------------------------------------

void mostrar2(){
	no *temp = frente2;
	
	while(temp != NULL){
		printf("\nNOME: %s | IDADE: %d",temp->nome, temp->idade);
		temp=temp->prox;	
	}
}
//--------------------------------------------------------------

void mostrar3(){
	no *temp = frente3;
	
	while(temp != NULL){
		printf("\nNOME: %s | IDADE: %d",temp->nome, temp->idade);
		temp=temp->prox;
	}
}
//--------------------------------------------------------------


void enqueue2(char nome[], int idade){
	no *novo=malloc(sizeof(no));
	
	if (novo == NULL){
		printf("sem memória!\n");
		return;
	}
	
	strcpy(novo->nome,nome);
	novo->idade = idade;
	novo->prox=NULL;
	
	if (fim2 == NULL){
		frente2 = novo;
		fim2 = novo;
	}else{
		fim2->prox = novo;
		fim2 = novo;
	}

}

//--------------------------------------------------------------

void enqueue3(char nome[], int idade){
	no *novo = malloc(sizeof(no));
	
	if (novo == NULL){
		printf("sem memória!\n");
		return;
	}
	
	strcpy(novo->nome,nome);
	novo->idade = idade;
	novo->prox=NULL;
	
	if (fim3 == NULL){
		frente3 = novo;
		fim3 = novo;
	}else{
		fim3->prox = novo;
		fim3 = novo;
	}
}

//--------------------------------------------------------------

void separar(){
	char nome[50];
	int idade;
	
	// enquanto houver elementos na fila principal
	while(frente != NULL){
		dequeue(nome,&idade); // remove uma pessoa da fila 1
	
	if(idade <= 30){ // distribui para a fila 2 ou fila 3
		enqueue2(nome,idade);
	}else{
		enqueue3(nome,idade);
	}
}
}

//--------------------------------------------------------------

void liberar2(){ //percorre toda fila liberando cada no
	no *temp;
	
	while(frente2 != NULL){
		temp = frente2;
		frente2 = frente2->prox;
		free(temp);
	}
	fim2=NULL;
}

//--------------------------------------------------------------

void liberar3(){
	no *temp;
	
	while(frente3 != NULL){
		temp = frente3;
		frente3 = frente3->prox;
		free(temp);
	}
	fim3=NULL;
}
	

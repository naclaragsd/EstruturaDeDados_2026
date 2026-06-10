/* 11.Desenvolva um programa denominado PILHA1 em linguagem C que
implemente as operações de uma pilha (pop, push e imprimir) cujo nó deverá
conter nome[30] e idade. O usuário deverá ter a opção de empilhar,
desempilhar, mostrar pilha e sair. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct No{
	char nome[30];
	int idade;
	struct No *proximo; //aponta para o elemento abaixo
}no;

void push(char nome[], int idade);
void pop();
void imprimir();
void paradinha();

no *top=NULL; //ultimo elemento inserido

//-------------------------------------------------------------------------------------
int main(){
	setlocale(LC_ALL,"portuguese");
	
	int opcao, idade;
	char nome[30];
	
	do{
		system("cls");
		
		printf("\n=====================================================================\n");
		printf("\nMENU: \n1.Empilhar \n2.Desempilhar \n3.Mostrar pilha \n4.Sair\n");
		printf("\n=====================================================================\n");

		scanf("%d",&opcao);

		
		switch(opcao){
			case 1:
				system("cls");
				getchar();
				
				printf("\nInsira o nome a ser empilhado: ");
				fgets(nome,30,stdin); /* depois de ler essa opção, fica um \n no buffer
										 entao o fgets() pode ler apenas esse enter
										 por isso utiliza-se o getchar() antes disso */
				nome[strcspn(nome, "\n")] = '\0';
		
				printf("insira a idade de %s: ",nome);
				scanf("%d",&idade);
				
				push(nome,idade);
				
				printf("\nPessoa empilhada com sucesso!\n");
				
				paradinha();
				break;
				
			case 2:
				pop();
				paradinha();
				break;
				
			case 3:
				imprimir();
				paradinha();
				break;
				
			case 4:
				printf("encerrando programa...\n");
				break;
				
				default:
					printf("opção inválida!\n");
		}
	}while(opcao!=4);
	
	return 0;
}

//-------------------------------------------------------------------------------------

void push(char nome[], int idade){
	//aloca memória para um novo no
	no *novo=malloc(sizeof(no));
	
	if(novo==NULL){
		printf("sem memória disponível\n");
		return;
	}else{
		strcpy(novo->nome,nome);
		novo->idade=idade;
		novo->proximo=top; // novo no aponta para o antigo topo
		top=novo; // o novo no passa a ser o topo da pilha
	}	
}

//-------------------------------------------------------------------------------------

void pop(){
	no *temp;
	
	if(top == NULL){
		printf("pilha vazia\n");
		return;
	}
	temp=top; // guarda o topo atual para remove-lo
	top=top->proximo; // topo passa a ser o proximo elemento
	
	printf("\nRemovido: %s (%d anos)\n",temp->nome, temp->idade);
	free(temp); //libera memória do elemento removido
}

//-------------------------------------------------------------------------------------

void imprimir(){
	no *temp = top; //ponteiro auxiliar que vai percorrer a pilha
	
	if(top==NULL){
		printf("Pilha vazia!\n");
		return;
	}
	
	while(temp != NULL){ //percorre a pilha do topo até a base
		printf("\nNome: %s",temp->nome);
		printf("\nIdade: %d\n",temp->idade);
		
		temp=temp->proximo;
	}
}

//-------------------------------------------------------------------------------------

void paradinha(){
	printf("\nPressione ENTER para continuar...");
	getchar();
	getchar();
}

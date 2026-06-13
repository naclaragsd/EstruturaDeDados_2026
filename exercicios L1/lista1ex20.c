/* 20.Desenvolva um programa que leia uma expressão matemática e utilize
PILHA para verificar se:
parênteses;
colchetes;
chaves;
estão balanceados.
Exemplo:
( A + B ) * { C - D } */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
	char simbolo; //cada no vai armazenar um símbolo de abertura (,[ ou {
	struct No *prox;
}no;

void push (no **pilha,char c);
char pop(no **pilha);
int balanceada(char exp[]);

no *pilha=NULL; //ponteiro para o topo

//-------------------------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	
	char exp[100];
	
	printf("\nDigite a expressão: ");
	fgets(exp,100,stdin);
	
	if(balanceada(exp)){//chama a função que verifica se os símbolos estão balanceados
		printf("\nExpressão balanceada!\n");
	}else{
		printf("\nExpressão desbalanceada!");
	}
	
	return 0;
}

/* a função balanceada vai retornar 1 se a expressão for correta
e 0 se a expressão for incorreta

como C considera qualquer valor diferente de 0 como verdadeiro, 
pode-se usar diretamente: if(balanceada(exp))*/

//-------------------------------------------------------------------------------

void push(no **pilha,char c){
	no *novo=malloc(sizeof(no));
	
	if(novo){
		novo->simbolo=c;
		novo->prox=*pilha;
		*pilha=novo;
	}
}

//insere novo símbolo no topo da pilha

//-------------------------------------------------------------------------------

char pop(no **pilha){
	char aux;
	no *remover;
	
	if(*pilha == NULL){
		return '\0';
	}
	
	remover=*pilha;
	aux=remover->simbolo;
	
	*pilha=remover->prox;
	
	free(remover);
	
	return aux;
}
	//remove elemento que está  no topo e devolve seu valor
	
//-------------------------------------------------------------------------------

int balanceada(char exp[]){
	int i;
	char topo;
	
	for (i=0;exp[i] != '\0';i++){//percorre toda a expressão caractere por caractere
		
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
			push(&pilha,exp[i]); //se encontrar algum símbolo de abertura
		}						// ele é empilhado para ser comparado futuramente
		
		else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
			topo=pop(&pilha); //ao encontrar simbolo de fechamento, removemos
							// o topo da pilha para verificar se ele corresponde
							//ao símbolo esperado
			if(
					(exp[i] == ')' && topo != '(') ||
					(exp[i] == ']' && topo != '[') ||
					(exp[i] == '}' && topo != '{') 
					//cada fechamento deve corresponder exatamente ao símbolo
					// de abertura correto

			){
				return 0; //se houver qualquer incompatibilidade, 
						 // a expressão está balanceada
				/* depois de percorrer toda a expressão, a pilha deve estar vazia
				se ainda restar algum elemento, significa que existe abertura sem
				 fechamento*/
			}
		}
	}
	
	if(pilha==NULL){
		return 1; //todos os símbolos abriram e fecharam corretamente
	}
	
	return 0; //sobraram símbolos na pilha, expressão está incorreta
}

/*
RESUMINDO...

	- encontrou abertura?
  		 empilha

	- encontrou fechamento?
  		 desempilha e compara

	- símbolos diferentes?
  		 retorna 0

	- terminou a leitura?
  		 a pilha deve estar vazia

	- pilha vazia?
  		 retorna 1

	- sobrou algo na pilha?
  		 retorna 0.
*/



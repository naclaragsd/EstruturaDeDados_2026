/* 18.Construa uma FILA contendo 20 valores aleatórios entre 1 e 100.
Posteriormente:
• remova os valores múltiplos de 5;
• apresente a fila final. */

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

typedef struct No{
	int dado;
	struct No *prox;
}no;

void enqueue(int num);
void dequeue();
void mostrar();
void removeM();

no *ini=NULL; //aponta para o PRIMEIRO elemento da fila
no *fim=NULL; // aponta para o ÚLTIMO elemento da fila

//--------------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	int opcao, i;
	
	do{
			printf("\nMenu: \n1.Gerar 20 valores aleatórios entre 1 e 100 \n2.Remover múltiplos de 5 \n3.Mostrar fila \n4.Sair\n");
			scanf("%d",&opcao);
	
		switch(opcao){
			case 1:
				for(i=0;i<20;i++){
					enqueue(rand()%100+1); /*rand()%100 gera números entre 0 e 99 
											 somando +1: 1 até 100 Cada número gerado
											  é inserido no final da fila.*/
				}
				break;
			case 2:
				removeM();
				break;
			case 3:
				 printf("\n========================================\n");
    				printf("FILA ATUAL:\n");
    				mostrar();
   				 printf("\n========================================\n");
				break;
			case 4:
				break;
			default:
				printf("opção inválida!");
		}
		
		 if(opcao != 4){
        printf("\n\nPressione ENTER para voltar ao menu...");
        getchar();
        getchar(); 
    }
    
	}while(opcao!=4);
}

//--------------------------------------------------------------------

void enqueue(int num){ // inserção (enqueue) acontece no fim.
	no *novo=malloc(sizeof(no)); // cria um novo nó na memória
	novo->dado=num;
	novo->prox=NULL; //porque ele será o último elemento da fila
	
	if(ini==NULL){
		ini=novo;
		fim=novo; /* se a fila estiver vazia, o primeiro elemento é
					 ao mesmo tempo o início e o fim da fila.*/
	}else{
		fim->prox=novo; // caso contrário, atualiza quem é o novo fim
		fim=novo;
	}
}

//--------------------------------------------------------------------

void dequeue(){ // remoção (dequeue) acontece no início.
	if(ini == NULL){
		return;
	}
	no *temp=ini;
	ini=ini->prox; //avança o inicio para o proximo no
	free(temp);
	
	 if(ini == NULL){
        fim = NULL; /* se após a remoção a fila ficou vazia,
    				o ponteiro fim também deve ser NULL */
}
}

//--------------------------------------------------------------------

void mostrar(){
    no *aux = ini; /* percorrer a fila usando um ponteiro auxiliar
					 IMPORTANTE: munca usamos ini diretamente para percorrer,
    				senão perderíamos a referência do início da fila.
    */

    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox; //avança para o proximo no
    }
}

//--------------------------------------------------------------------

void removeM(){
    no *atual = ini; // no que estamos analisando
    no *anterior = NULL; // no anterior ao atual

    while(atual != NULL){

        if(atual->dado % 5 == 0){ // % retorna o resto da divisao

            no *temp = atual;

            if(anterior == NULL){ //se estiver removendo o rpimeiro no da fila
                ini = atual->prox;
                atual = ini;
            }
            else{ //faz no anterior "pular" o no atual
                anterior->prox = atual->prox;
                atual = atual->prox;
            }

            if(temp == fim){
                fim = anterior; // se o elemento removido for o ultimo, atualiza fim
            }

            free(temp);
        }
        else{
            anterior = atual;
            atual = atual->prox;
        }
    }
}

/*  usa ponteiros atual e anterior
 	remove no início, meio ou fim
	 atualiza fim quando necessário */

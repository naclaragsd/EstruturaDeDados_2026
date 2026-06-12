/* Construir um programa em linguagem C que implemente uma lista DUPLAMENTE encadeada.
O programa deverá possuir as seguintes opções no menu:
- inserir no inicio
- inserir no fim
- inserir no meio
- apresentar a quantidade de elementos da lista (criar funcao)
- inserir 10 elementos sorteados //sorteio inclusive se é inicio, meio ou fim)
- apresentar lista
- remover elemento
- sair	*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

typedef struct No{
	int valor;
	
	struct No *ant;
	struct No *prox;
}no;

no *lista=NULL;

void ins_ini(no **lista, int num);
void ins_fim(no **lista, int num);
void ins_meio(no **lista, int num, int antes);
int qtd_elementos(no *lista);
void ins_sorteados(no **lista);
void mostrar(no *lista);
void remover(no **lista, int valor);

//--------------------------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	
	int opcao, num, antes;
	
	do{
		printf("\n==============================================================\n");
		printf("\nMenu: \n1.Inserir no inicio \n2.Inserir no fim \n3.Inserir no meio \n4.Mostrar quantidade de elementos da lista \n5.Inserir 10 elementos sorteados \n6.Remover elemento \n7.Mostrar lista \n8.Sair \nOpção: ");
		printf("\n==============================================================\n");
		scanf("%d",&opcao);
		
		switch (opcao){
			case 1:
				printf("\nDigite um número a ser inserido no inicio: ");
				scanf("%d",&num);
				
				ins_ini(&lista,num); /* lista é um ponteiro para o primeiro nó,
   										como a função pode precisar alterar esse 
										ponteiro (por exemplo, quando a lista está
									    vazia),passamos seu endereço (&lista).
   										Por isso a função recebe no **lista. */
				break;
				
			case 2:
				printf("\nDigite um número a ser inserido no fim: ");
				scanf("%d",&num);
				
				ins_fim(&lista,num);
				break;
				
			case 3:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d",&num);
				printf("\nDigite o número anterior na qual deseja realizar a inserção: ");
				scanf("%d",&antes);
				
				ins_meio(&lista, num, antes);
				break;
				
			case 4:
				printf("\nQuantidade de elementos: %d\n",qtd_elementos(lista));
				break;
				//aqui é passado qtd_elementos(lista) e nao qtd_elementos(&lista)
				// pois essa função não altera a lista, ela apenas lê os elementos
				
			case 5:
				ins_sorteados(&lista);
				break;
				
			case 6:
				printf("\nDigite o valor a remover: ");
				scanf("%d",&num);
				
				remover(&lista,num);
				break;
			case 7:
				mostrar(lista);
				break;
				
			case 8:
				printf("\nPrograma encerrado!\n");
				break;
			default:
				printf("\nOpção inválida!");
		}
	}while(opcao!=8);
}

//--------------------------------------------------------------------------------

void ins_ini(no **lista, int num){
	no *novo=malloc(sizeof(no));
	
	if(novo){ //verifica alocação
		novo->valor=num; 
		novo->prox=*lista;
		novo->ant=NULL; //como será o primeiro no, não possui anterior
		
		if(*lista != NULL){ //se a lista já possuir elementos
			(*lista)->ant=novo; //antigo primeiro no passa a apontar para o novo
								// como anterior
		}
			*lista=novo; //atualiza o inicio da lista para novo no
	}else{
		printf("Erro ao alocar memória\n");
	}
}

//--------------------------------------------------------------------------------

void ins_fim(no **lista, int num){ /* no **lista recebe o endereço do ponteiro que
									 aponta para o início da lista */
									 
	no *aux, *novo=malloc(sizeof(no)); /* aux vai percorrer a lista
										  novo apontará para o recém no criado */
	
	if(novo){ // verifica se a alocação de memória funcionou
	
		novo->valor=num; 
		novo->prox=NULL; /* como vai ser inserido no final da lista, ele inicialmente
							não possui próximo */
		
		if(*lista == NULL){ // verifica se a lista esta vazia
			*lista=novo; // se sim, o primeiro no passa a seer o no recém criado
			novo->ant=NULL; //como ele é o primeiro elemento, não tem nada antes dele
			
		}else{ // caso a lista já possuir elementos
			aux=*lista; // o ponteiro auxiliar começa no inicio da lista
			
		while(aux->prox){ // enquanto existir proximo no, vai continuar percorrendo
			aux=aux->prox; // anda um no para frente
		}
			aux->prox=novo; // o último no passa a apontar para o novo no
			novo->ant=aux; // novo no aponta para o no anterior
		}
		
		}else{
			printf("Erro ao alocar memória\n"); // se a alocação de memória falhar
		}
}

/*  Cria novo nó.
	Vai até o último elemento.
	Liga o último ao novo.
	Liga o novo ao último.     */
	
//--------------------------------------------------------------------------------

void ins_meio(no **lista, int num, int antes){
	no *aux, *novo=malloc(sizeof(no));
	
	if(novo){
		novo->valor=num;
		
		if(*lista==NULL){ //se a lista estiver vazia
		//como será o unico elemento da lista, não possui nem ant nem prox
			novo->prox=NULL;
			novo->ant=NULL;
			*lista=novo; //novo passa a ser o primeiro da lista
			
		}else{
			aux=*lista; /*inicializa aux, que vai fazer a busca pelo valor
						após o qual o novo elemento será inserido */
			
			while(aux->valor != antes && aux->prox){
				aux=aux->prox;
					/* percorre a lista enquanto
				   - não encontrou o valor procurado E
				   - ainda existe o próximo no para visitar */
			}
			
			if(aux->valor == antes){ // verifica se o valor realmente foi encontrado
				novo->prox = aux->prox; /* novo no passa a apontar para quem vinha
										 depois de aux */
				novo->ant = aux; // novo no aponta para no anterior
				
				if(aux->prox){ //se existir um proximo no
					aux->prox->ant=novo;//ele deve apontar para o novo no como anterior
				}
				
				aux->prox=novo; //aux aponta para o novo no
				
			}else{
                printf("Valor nao encontrado!\n");
            }
        }
	}else{
		printf("Erro ao alocar memória\n");
	}
}
	
/*		RESUMINDO...
  -cria um novo nó.
 		-verifica se a lista está vazia.
 		-procura o valor de referência (antes) na lista.
			se encontrar:
   				- O novo nó aponta para o próximo de aux.
   				- O novo nó aponta para aux como anterior.
   				- O próximo nó (se existir) passa a apontar para o novo como anterior.
   				- aux passa a apontar para o novo como próximo.
		Se o valor não for encontrado, exibe uma mensagem.
 	Se o malloc falhar, exibe erro de alocação. 
*/
 	
//--------------------------------------------------------------------------------

int qtd_elementos(no *lista){
	int cont=0; //armazena quantidade de nos
	
	no *aux=lista; //ponteiro que vai percorrer lista
	
	while(aux){ //percorre ate chegar no final (NULL)
		cont++;
		aux=aux->prox; //avança no
	}
	return cont; //retorna a quantidade encontrada
}

//--------------------------------------------------------------------------------

void ins_sorteados(no **lista){
	int i, num, pos;
	
	for(i=0;i<10;i++){ //repete o processo 10 vezes
	
		num=rand()%100+1; //gera número aleatorio entre 1 e 100
		pos=rand()%3; // sorteia a posição de inserção 0=inicio 1=meio 2=fim
		
		switch(pos){
			case 0: // insere o número sorteado no início da lista
				ins_ini(lista,num);
				printf("\nNumero %d inserido no inicio", num);
				break;
				
			case 1: //se a lista estiver vazia, não existe posição intermediária
				if(*lista == NULL){
					ins_ini(lista,num); //insere no inicio
				 printf("\nNumero %d inserido no inicio", num);
				 
				}else{ //insere apos o primeiro elemento da lista
					// o valor do primeiro no é usado como referência para 
					// a função ins_meio
					ins_meio(lista, num,(*lista)->valor);
					 printf("\nNumero %d inserido no meio", num);
				}
				break;
				
			case 2:
				ins_fim(lista,num); //insere número sorteado no final da lista
				printf("\nNumero %d inserido no fim", num);
				break;
		}
	}
}

//--------------------------------------------------------------------------------

void mostrar(no *lista){
	no *aux=lista; 
	
	if(lista==NULL){
		printf("\nLista vazia!\n");
	}else{
		printf("\nLista: ");
		
		while(aux){ //percorre a lista ate chegar em null
			printf(" [%d] ",aux->valor);
			aux=aux->prox;
		}
		printf("\n");
	}
}

//--------------------------------------------------------------------------------

void remover(no **lista, int valor){
	no *aux=*lista;
	
	if(*lista==NULL){ //lista vazia
		printf("\nLista vazia!\n");
		return;
	}
	
	while(aux && aux->valor != valor){ //procura elemento
		aux=aux->prox;
	}
	
	if(aux==NULL){
		printf("\nValor não encontrado!\n");
		return;
	}
	
	if(aux->ant){ //se existir no anterior
		aux->ant->prox=aux->prox;
	}else{ //removeu o primeiro no
		*lista=aux->prox;
	}
	
	if(aux->prox){
		aux->prox->ant=aux->ant;
	}
	
	free(aux);
	
	printf("\nElemento removido com sucesso!\n");
}

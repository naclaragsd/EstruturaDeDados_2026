// Fila com prioridade

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}no;

void inserir(no **fila, int item){  /* funcao inserir que recebe como
									   parametro um ponteiro para ponteiro
									   do tipo no e um item 
									   
									   O no **fila é necessário porque a 
									   função pode alterar o início da fila.*/									     
									   
	no *aux, *novo = malloc(sizeof(no)); /* cria dois ponteiros do tipo no,
											e ALOCA MEMÓRIA APENAS para o *novo
											
											pois o *aux será usado apenas para
											percorrer a fila */
	if (novo){
		novo->dado=item;	//dado do ponteiro novo recebe valor digitado
		novo->proximo=NULL;	/* proximo do ponteiro novo recebe NULL pq será
								o último no da fila inicialmente */
								
		if(*fila == NULL)
		*fila = novo; 		/* se a fila estiver vazia, o ponteiro que 
								representa o início da fila, passará
								a apontar para um novo no 
								
								por isso foi utilizado o no **fila */
								
	else{
		aux=*fila;	// ponteiro aux recebe o endereço de onde o ponteiro fila está apontando
		while(aux->proximo) // enquanto existir um proximo no 
		aux=aux->proximo;	/* aux avança para o proximo no da fila
								esse laço vai percorrer a fila até chegar no último no */
								
		aux->proximo=novo; /* o campo proximo do último no, passará a apontar para
								o novo no */
	}
	}else 
	printf("\nErro ao alocar memória\n");
}

/* resumindo: cria um novo nó na memória;
	coloca o valor digitado dentro dele;
	define o próximo como NULL;
	verifica se a fila está vazia:
	se estiver, o novo nó vira o primeiro da fila;
	se não estiver, percorre a fila até o último nó e conecta o novo elemento no final. 
	
	é um enqueue, só que altera o inicio da fila usando **fila */

//--------------------------------------------------------

void inserirPri(no **fila, int item){   // **fila vai alterar o inicio da fila, item digitado 
	no *aux, *novo = malloc(sizeof(no)); //cria dois ponteiros e aloca memória em apenas um
	if(novo){
		novo->dado=item;		
		novo->proximo=NULL;		/* inicialmente o próximo do novo é NULL, pois ele ainda não
								    esta conectado na fila */
								    
		if(*fila==NULL)			
		*fila=novo;		// se a fila estiver vazia, ela vai receber o novo elemento digitado
		
		// esse if insere um novo elemento na fila
		
	else{
		if(item>59){ // se o item digitado for maior que 59
			if((*fila)->dado<60){	/* verifica se o PRIMEIRO elemento da fila é não 
										prioritário (menor que 60)	*/
										
				novo->proximo=*fila; // o novo no aponta para o antigo início da fila
				*fila=novo;			// novo no vira o início da fila
			}else{
				aux=*fila;			// ponteiro auxiliar começa apontando para o início da fila
				
				while(aux->proximo && aux->proximo->dado>59)/* enquanto existir o proximo no, e 
																o proximo no for prioritario */
																
				aux=aux->proximo; 	
				novo->proximo=aux->proximo; // o novo no aponta para o no que vinha depois do aux
				aux->proximo=novo;			// aux conecta novo no
			}
		}else{
			aux=*fila; // ponteiro auxiliar recebe onde fila esta apontando
			while(aux->proximo) // enquanto o ponteiro auxiliar proximo
			aux=aux->proximo;	// auxiliar recebe o proximo dele mesmo
			aux->proximo=novo;	// e o proximo recebe o novo
			//percorre a fila até o ultimo no e conecta o novo elemento no final
		}
	}
	}else
	printf("\nErro ao alocar memória \n");
}

/* resumindo: cria um novo no
   verifica se a fila está vazia
   se for prioritário (>59): 
   	- entra antes dos não prioritários 
	- mas respeitando a ordem dos prioritarios já existentes 
   se for normal:
   	- entra no final da fila */

//--------------------------------------------------------

no* remover(no **fila){ //a função remover, vai retornar um ponteiro do tipo no
	no *remove=NULL;	// guarda qual no foi removido da fila
	
	if(*fila){  //se a fila nao estiver vazia
		remove=*fila;	// remove aponta para o primeiro no da fila (que vai sair)
		*fila=remove->proximo; // avança a fila para o proximo
	}else
	printf("\nFila vazia\n");
	return remove;  // devolve o no removido para o programa usar/liberar
}

/* resumindo: verifica se a fila não está vazia;
	guarda o primeiro no em um ponteiro auxiliar (remove);
	faz o início da fila apontar para o proximo no;
	retorna o no removido para que ele possa ser usado ou liberado da memoria depois */

//--------------------------------------------------------

void imprimir(no *fila){
	while(fila){
		printf("%d\n",fila->dado);
		fila=fila->proximo;
	}
	printf("\n");
}

//--------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	no *r, *fila=NULL;
	int valor, opcao;
	
	do{
		printf("\n\nMenu\n1. Enfileirar \n2. Desenfileirar\n");
		printf("3. Imprimir \n4. Enfileirar prioridade\n5. Sair\n");
		printf("Opção: ");
		scanf("%d",&opcao);
		printf("\n");
		switch(opcao){
			case 1:
				printf("Digite um valor ");
				scanf("%d",&valor);
				inserir(&fila,valor); //enfileirar
				break;
			case 2:
				r=remover(&fila);
				if(r){
					printf("Removendo: %d\n",r->dado);
					free(r);
				}
				break;
			case 3:
				imprimir(fila);
				break;
			case 4:
				printf("Digite um valor: ");
				scanf("%d",&valor);
				inserirPri(&fila,valor);
				break;
				default:
					printf("\nOpção inválida \n");
		}
	}while (opcao!=5);
	system("pause");
	return 0;
}

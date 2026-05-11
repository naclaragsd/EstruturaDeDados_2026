#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* é importante informar para o programa cada função utilizada, antes do 
   int main() para que o programa ja "conheça" o código, antes de ser
   executado; evitando erros ao compilar o código */
   
void push(int item);
void pop();
void imprimir();
int entrada_dados();

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo; //ponteiro que guarda endereço dessa mesma estrutura
								//isso permite criar estruturas encadeadas 
}no;

no *top=NULL; //ponteiro global que apontará para o topo da pilha

int main(){
	setlocale(LC_ALL, "Portuguese");
	int n, opcao;
	do{
		system("cls"); //limpa a tela do terminal
		printf("\n\nMenu\n1. Empilhar \n2. Desempilhar\n3. Imprimir \n4. Sair");
		printf("\nEscolha uma opção (1-4): ");
		scanf("%d",&opcao);
		
		switch (opcao){
			
			case 1:
				n=entrada_dados();
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				imprimir();
				break;
		}
	}while (opcao != 4);
	system("pause"); //faz o programa parar e esperar apertar uma tecla
	return 0;
}
//----------------------------------------------------------------------

void push(int item){ //função que vai empilhar um valor recebido por parâmetro
	printf("\nEMPILHANDO...\n");
	no *novo=malloc(sizeof(no)); /*cria um ponteiro chamado "novo" que apontará para
								 um espaço na memória, capaz de guardar um no 
								 
								 novo é um ponteiro que aponta para uma struct
								 do tipo no */
	
	//verifica se tem memoria
	if(novo == NULL) {
		printf("Sem memória disponível!\n");
		return;
	}else{
		novo->dado=item; /* cada "novo" é uma struct que guarda um dado e um ponteiro;
		
							primeiro ele acessa o campo "dado" da struct que está sendo 
							apontado pelo "novo" */ 
							
		novo->proximo=top; /*  o ponteiro "proximo" do "novo" "no" passa a guardar
		  					 o endereço do antigo topo da pilha (que inicialmente
							 é declarado como NULL)*/
							  
		top=novo;	/*  o topo agora passa a apontar para o novo nó,
		   				que se torna o primeiro elemento da pilha */
					   
		printf("\nValor %d empilhado\n",novo->dado);
		system("pause");
	}
}

/* o "proximo" guarda o endereço do topo ANTIGO
	porque NAQUELE MOMENTO, "top" ainda apontava pro antigo topo */

//----------------------------------------------------------------------

void pop(){ // função que vai desempilhar 
	printf("\nDESEMPILHANDO...\n");
	
	// verifica se tem memória
	if(top==NULL){
		printf("A pilha está vazia\n");
	}else{
		no *temp; /* cria um ponteiro temporário que aponta para um
					 endereço de memória de um "nó" */
					 
		temp=top; /* recebe o ponteiro top que está sempre apontando
					para o topo da pilha */
					
		top=top->proximo; // top passa a apontar para o próximo "no" da pilha
							 
		printf("\n%d Desempilhado com sucesso\n",temp->dado);
		 /* será apresentado ao usuário o valor que foi desempilhado;
		 no caso o último elemento da pilha */
		 
		free(temp); //libera a memória do "no" que foi removido da pilha
	}
	system("pause");
}

/*  o ponteiro temporário guarda o endereço do topo atual da pilha,
   permitindo que o top seja movido para o próximo "no" sem perder
   a referência do elemento removido, possibilitando exibir seu valor
   e liberar sua memória corretamente */

//-------------------------------------------------------------------

void imprimir(){
	no *temp; // cria ponteiro temporário que irá percorrer cada elemento da pilha
	temp=top; // esse temp recebe o topo da pilha
	printf("\nIMPRIMINDO PILHA...\n");
	
	while(temp != NULL){ /* enquanto a pilha for diferente de NULL 
							(apontar para um "no" válido) a pilha ainda possui
							 elementos para mostrar*/
							
		printf("%d\n",temp->dado); //acessa e imprime o dado do "no" atual
		
		temp=temp->proximo; // temp passa a apontar para o próximo "no" da pilha
	}
	system("pause");
}

/*  ao final de cada repetição (while), temp passa a apontar
   para o próximo nó da pilha, permitindo que o while
   percorra todos os elementos até chegar em NULL */

//-----------------------------------------------------------------

int entrada_dados(){ //função que recebe um valor do usuário
	int valor; //armazena o valor digitado
	printf("\nEntre com valor a empilhar: ");
	scanf("%d",&valor); //le o valor digitado e armazena 
	return valor; /* retorna o valor digitado para a função que chamou
	  				 entrada_dados() */
}

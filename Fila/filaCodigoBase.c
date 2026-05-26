//FIFO - First in First Out

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void enqueue(int item); // enfileirar
void dequeue(); // desenfileirar
void imprimir();
int entrada_dados();

//------------------------------------------------------------

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;  // está apontando para  próprio no
}no;

no *frente = NULL;
no *fim = NULL;

int main(){
	setlocale(LC_ALL,"portuguese");
	int n, opcao;
	
	do{
		system("cls");
		printf("\n\nMenu\n1. Enfileirar \n2. Desenfileirar \n3. Imprimir \n4. Sair");
		printf("\nEscolha uma opção (0-4): ");
		scanf("%d",&opcao);
		switch (opcao){
			case 1:
				n=entrada_dados();
				enqueue(n);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				imprimir();
				break;
		}
	}while (opcao != 4);
	system("pause");
	return 0;
}
//------------------------------------------------------------

void enqueue(int item){
	printf("\nENFILEIRANDO...\n");
	no *novo = malloc(sizeof(no)); // aloca espaço na memória do tamanho de no
	novo->dado=item;	  // acessa o campo dado do no e da o valor de item
	novo->proximo=NULL;   // acessa o campo proximo do no e recebe NULL
	
	if (fim == NULL){   
		frente = novo;
		fim = novo;
	
	/* caso a fila esteja vazia, os ponteiros frente e fim, apontarão para
	    o novo elemento inserido pelo usuário */
		
	}else{
		fim ->proximo=novo;
		fim=novo;
	}
	
	/* 	Se a fila já possuir elementos:
	   - o campo proximo do último nó da fila (apontado por fim)
	     receberá o endereço do novo nó;
	   - depois, o ponteiro fim passa a apontar para o novo último nó */ 
		printf("\nValor %d enfileirado\n", novo->dado);
		system("pause");
}

//------------------------------------------------------------

void dequeue(){
	printf("\nDESENFILEIRANDO...\n");
	if (frente == NULL)
	printf("A fila está vazia\n");
	
	// informa se a fila estiver vazia
	
else{
	no *temp = frente;
	frente = frente->proximo;
	
	/* se a fila não estiver vazia; é criado um ponteiro temporário
	   do tipo no que recebe o endereço do primeiro elemento
	   frente passará a apontar para o próximo no da fila */
	   
	if(frente == NULL)
	fim = NULL;
	
	/* se frente for NULL após a remoção, significa que a fila
		ficou vazia, então fim também deve receber NULL */
	
	printf("\n%d desenfileirado com sucesso\n",temp->dado);
	free(temp);
	
	// libera da memória o primeiro no removido da fila
}
system("pause");
}

//------------------------------------------------------------

void imprimir(){
	no *temp = frente;
	printf("\nIMPRIMINDO FILA...\n");
	while(temp != NULL){
		printf("%d %d \n", temp->dado, temp->proximo);
		temp=temp->proximo;
	}
	system("pause");
	
	/* é definido um ponteiro temporario do tipo no recebendo o
	valor frente; 
	enquanto *temp for diferente de NULL, vai apresentar os dados
	de temp 
	temp recebe o endereço ao qual o proximo esta apontando */
}

//------------------------------------------------------------

int entrada_dados(){
	int valor;
	printf("\nEntre com valor a enfileirar: ");
	scanf("%d",&valor);
	return valor;
}

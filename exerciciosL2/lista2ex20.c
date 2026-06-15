/* 20) Exercício – Integração de Lista, Fila e Pilha
As turmas de Análise e Desenvolvimento de Sistemas (ADS) e Engenharia de
Software (ESOFT) da Unicesumar estão realizando uma promoção para arrecadar
recursos para a formatura.
Para a retirada das pizzas vendidas, foi realizado um sorteio com 10 participantes.
Os nomes dos sorteados deverão ser armazenados em uma LISTA, que
representará o cadastro das pessoas autorizadas a retirar as pizzas.
No dia da retirada, os participantes chegarão à pizzaria e serão atendidos por ordem
de chegada. Portanto, deverá ser utilizada uma FILA para organizar os sorteados
que aguardam atendimento.
A pizzaria produzirá as pizzas conforme sua disponibilidade. Cada pizza pronta será
embalada e colocada sobre as demais, formando uma PILHA de pizzas prontas para
entrega.
O funcionamento do sistema deverá seguir as seguintes regras:
• Cadastrar os 10 sorteados em uma LISTA.
• À medida que os sorteados chegarem à pizzaria, inseri-los na FILA de
atendimento.
• Conforme as pizzas forem ficando prontas, elas deverão ser EMPILHADAS na
PILHA de pizzas prontas.
• Quando ocorrer uma entrega:
1. A pessoa que está no início da FILA deverá ser atendida (desenfileiramento);
2. A pizza que estiver no topo da PILHA deverá ser retirada (desempilhamento);
3. Na LISTA de sorteados, a pessoa deverá ser marcada como "Pizza Retirada".
• O processo continua até que todas as pizzas tenham sido entregues.
O programa deverá permitir:
• Inserir e visualizar os sorteados da LISTA;
• Inserir e visualizar pessoas na FILA de atendimento;
• Inserir e visualizar pizzas na PILHA de pizzas prontas;
• Realizar a entrega de pizzas, efetuando simultaneamente o desenfileiramento
da pessoa e o desempilhamento da pizza;
• Consultar a LISTA de sorteados, identificando quais pessoas já retiraram sua
pizza e quais ainda não retiraram.

Observações
• As estruturas de dados (LISTA, FILA e PILHA) deverão ser implementadas
utilizando linguagem C.
• Cada aluno deverá definir livremente as structs necessárias, bem como seus
atributos, de acordo com sua interpretação da regra de negócio.
• É recomendado que as structs possuam informações suficientes para
identificar pessoas, pizzas e o status de retirada.
• A implementação deverá demonstrar claramente o uso correto das operações
fundamentais de cada estrutura de dados:
o Lista: inserção, consulta e atualização;
o Fila: enqueue (enfileirar) e dequeue (desenfileirar);
o Pilha: push (empilhar) e pop (desempilhar). */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/*=====

 primeiro é preciso entender, o que eu tenho que armazenar em cada estrutura
depois disso, é possível definir os campos das structs:
lista: nome da pessoa e se retirou a pizza
fila: saber quem está aguardando atendimento
pilha: só vai precisar identificar cada pizza


=====*/

// ----- ----- ----- ----- --LISTA DE SORTEADOS-- ----- ----- ----- ----- -----

typedef struct Pessoa{
	char nome[50]; 	//nome da pessoa sorteada
	int retirou;	// campo que vai definir se a pessoa retirou a pizza ou não
	struct Pessoa *prox; // ponteiro, para chamar a própria struct
}pessoa;

pessoa *lista = NULL; //define o início da lista

// ----- ----- ----- ----- --FILA DE ATENDIMENTO-- ----- ----- ----- ----- -----

typedef struct NoFila{
	char nome[50]; //struct vai armazanar o nome das pessoas que chegaram
	struct NoFila *prox;
}noFila;

noFila *frente=NULL; //frente da fila
noFila *fim=NULL;	//fim da fila

// ----- ----- ----- ----- --PILHA DE PIZZAS-- ----- ----- ----- ----- -----

typedef struct Pizza{
	int cod; // codigo da pizza
	struct Pizza *prox;
}pizza;

pizza *top=NULL;

//-------------------------------------------------------------------------------

void ins_p(pessoa **lista,char nome[50]);
void mostrarSorteados(pessoa *lista);

void enqueue(char nome[]);
void mostrarFila();
void dequeue(char nome[]);

void push(int cod);
void mostrarPilha();
void pop();

void retirada(char nome[]);
void entregarPizza();

//-------------------------------------------------------------------------------

int main(){
	setlocale(LC_ALL,"portuguese");
	int opcao, i, cod;
	char nome[50];
	
	do{
		printf("\n======================================================================\n");
		printf("\nMenu: \n1.Cadastrar sorteado \n2.Mostrar sorteados \n3.Chegada de pessoas \n4.Mostrar fila \n5.Pizza pronta \n6.Mostrar pilha \n7.Entregar pizza \n8.Consultar status dos sorteados \n9.sair");
		printf("\n======================================================================\n");

		scanf("%d",&opcao);
				
		switch(opcao){
			case 1:
				for(i=0;i<10;i++){
				printf("insira o nome da %d pessoa sorteada: ",i+1);
				scanf("%49s",nome);
				
				ins_p(&lista, nome);// endereço da variável lista
									//(permite que a função altere o início da lista)
			}
			break;
			
			case 2:
			mostrarSorteados(lista);
			break;

		case 3:
			printf("Nome da pessoa que chegou: ");
			scanf("%49s",nome);

			enqueue(nome);

			printf("Pessoa adicionada na fila!\n");
			break;

		case 4:
			mostrarFila();
			break;

		case 5:
			printf("Codigo da pizza: ");
			scanf("%d",&cod);

			push(cod);

			printf("Pizza adicionada na pilha!\n");
			break;

		case 6:
			mostrarPilha();
			break;

		case 7:
			entregarPizza();
			break;

		case 8:
			mostrarSorteados(lista);
			break;

		case 9:
			printf("Encerrando programa...\n");
			break;

		default:
			printf("Opcao invalida!\n");
	}

	}while(opcao != 9);
}

//-------------------------------------------------------------------------------

void ins_p(pessoa **lista, char nome[]){ /* recebe como parametro:
										pessoa **lista  endereço do ponteiro 
										que guarda o início da lista;
										*/
	pessoa *novo=malloc(sizeof(pessoa));
	
	if(novo){
		strcpy(novo->nome,nome); //strcpy para copiar a string
		novo->retirou=0; // ainda não retirou a pizza
		
		novo->prox= *lista;
		*lista=novo;
	}else{
		printf("\nerro ao alocar memória");
	}
}

//-------------------------------------------------------------------------------

void mostrarSorteados(pessoa *lista){
	pessoa *temp = lista;
	
	while(temp != NULL){
		if(temp->retirou == 0){
			printf("%s -> não retirou\n",temp->nome);
		}else{
			printf("%s -> retirou\n",temp->nome);
		}
		temp=temp->prox; //usa dados do no para percorrer a lista
	}
}

/* ANOTAÇÃO:
ponteiro simples - ex: *lista 
usar quando: apenas consultar, apenas percorrer, apenas mostrar

ponteiro duplo - ex **lista
usar quando: vai alterar o início da lista (inserir ou remover)*/

//-------------------------------------------------------------------------------

void enqueue(char nome[]){
/*       ou.....
void enqueue(noFila **frente, noFila **fim, char nome[])
porem, como frente e fim são variáveis globais, é possível acessa-los diretamente */

	noFila *novo=malloc(sizeof(noFila));

	if(novo){
		strcpy(novo->nome, nome); /*strcpy recebe destino e origem (nome está no 
									parametro)*/
		novo->prox = NULL;

	if(frente == NULL){
		frente=novo;
		fim=novo;
	}else{
		fim->prox=novo; //a estrutura aponta para o novo
		fim=novo;
	}
}else{
	printf("erro ao alocar memória\n");
}

}
/* novo->prox=fim; 
essa linha, faz com que o novo no aponte para trás
na FILA quem deve apontar para o novo no é o ultimo no atual*/

//-------------------------------------------------------------------------------

void dequeue(char nome[]){
	noFila *temp;
	
	if(frente == NULL){ 
		printf("\nfila vazia");
	}else{
		temp=frente;
		strcpy(nome,temp->nome); //guarda o nome da pessoa que saiu da fila
		
		frente=frente->prox; //avança frente para proximo no
		
		if(frente == NULL){ //atualiza o ponteiro fim, caso a fila fique vazia
			fim=NULL;
		}
		free(temp);
	}
}

//-------------------------------------------------------------------------------

void mostrarFila(){
	noFila *temp = frente;
	
	while(temp != NULL){
		printf("%s\n",temp->nome);
		temp=temp->prox;
	}
}

//-------------------------------------------------------------------------------

void push(int cod){
	pizza *novo=malloc(sizeof(pizza));
	
	if(novo){
		novo->cod=cod;
		novo->prox = top;
		top=novo; //novo elemento sempre entra no topo
	}else{
		printf("erro ao alocar memória\n");
	}
}
// "top" já é um ponteiro, por isso, não tem necessidade de usar "*top"

//-------------------------------------------------------------------------------

void pop(){
	pizza *temp=top;
	
	if(temp == NULL){ //verificar se a pilha está vazia
		printf("pilha vazia!\n");
	}else{
		top=top->prox;
		free(temp);
	}
}

//-------------------------------------------------------------------------------

void mostrarPilha(){
	pizza *temp=top;
	
	while(temp != NULL){
		printf("%d\n",temp->cod);
		temp=temp->prox;
	}
}

//-------------------------------------------------------------------------------

void retirada(char nome[]){
	pessoa *temp = lista;
	
	while(temp != NULL){
		
		// strcmp compara DUAS strings
		if(strcmp(nome,temp->nome) == 0){ // 0 = strings iguais
			temp->retirou = 1;
			break;
		}
		temp=temp->prox;
	}
}
/* 				ANOTAÇÕES...
	Essa função vai procurar uma pessoa na lista de sorteados e marcar que
ela já retirou sua pizza;
		-recebe o nome da pessoa atendida
		-percorre toda a lista de sorteados
		-compara o nome recebido com o nome armazenado em cada no da lista
		-quando encontrar a pessoa:
				encontrou = 1
		-encerra a busca
	Função será utilizada durante a entrega da pizza, para atualizar status
	da pessoa na lista
- - - - -
strcmp(str1, str2) retorna:
0 se as strings forem iguais
!= 0 strings diferentes*/

//-------------------------------------------------------------------------------

void entregarPizza(){
	char nome[50];
	
	//verifica se tem alguém esperando
	if(frente == NULL){
		printf("\não há pessoas na fila!\n");
		return;
	}
	
	//verifica se tem pizza pronta
	if (top == NULL){
		printf("\nnão há pizzas prontas!\n");
		return;
	}
	
	dequeue(nome); //remove a pessoa da fila
	pop(); //remove a pizza da pilha
	retirada(nome);//marca na lista que retirou
	
	printf("\npizza entregue para %s!\n",nome);
}
//essa função demonstra a integração das três estruturas de dados

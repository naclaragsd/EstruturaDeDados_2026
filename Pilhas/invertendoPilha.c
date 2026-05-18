#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/* criei um tipo chamado "dados" que guarda as informações 
de um aluno*/
typedef struct{
	char nome [50];
	float nota1;
	float nota2;
	float sub;
}dados;

typedef struct apelido{
	struct  apelido *proximo; /* ponteiro que aponta para outro elemento do mesmo
								 tipo (apelido), fazendo com que a estrutura encadeada
								 funcione */
								 
	dados da; // variável chamada da, do tipo dados que guarda informações do aluno
}no;
/* ou seja, cada no da pilha possui os dados do aluno
   e o endereço do próximo no */

no *top=NULL; /* ponteiro que vai sempre apontar para o 
				topo da pilha (o primeiro no) */

//protótipos das funções para "avisar" o compilador
void pop();
void esvazia();
void push(dados n);
void imprimir();
void inverte();
dados entrada_dados();

int main(){
	setlocale(LC_ALL,"portuguese");
	
	int opcao;
	dados n;
	do{
		system("cls");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Imprimir\n");
		printf("4 - Inverter pilha\n");
		printf("5 - Sair\n");
		printf("    OPÇÂO: ");
		scanf("%d",&opcao);
		
		switch(opcao){
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
			case 4:
				inverte();
				break;
		}
	}while (opcao != 5);
	esvazia();
}

void pop(){
	if (top !=NULL){
		no *temp;
		temp = top;
		top=top->proximo;
		free(temp);
	}
}
/* é criado um ponteiro auxiliar na qual guarda o no do topo 
   o topo anda para o proximo no, entao o topo antigo deixa 
   de ser o topo; e então é liberado a memória do nó removido
   evitando o vazamento de memória */

void esvazia(){
	while (top!=NULL)
	pop();
}
/* enquanto existir algum no na pilha, chama a função pop()
 que vai remover um por um; e como o pop já atualiza o top
 e libera a memória com o free(); A pilha vai sendo desmontada
 corretamente, sem vazamento de memória 
 
 - faz o processo correto de esvaziamento da memória, porque
 memória alocada com malloc() PRECISA ser liberada manualmente
 com free() */

dados entrada_dados(){
	dados dat; //criou variável chamada dat, do tipo dados
	system ("cls"); //limpa a tela do terminal
	fflush(stdin); printf(" nome: "); scanf("%s",&dat.nome); 
	fflush(stdin); printf("nota1: "); scanf("%f",&dat.nota1);
	fflush(stdin); printf("nota2: "); scanf("%f",&dat.nota2);
	fflush(stdin); printf("  sub:"); scanf("%f",&dat.sub);
	//stdin é a entrada padrão do teclado "limpa buffer do teclado"
	
	return dat;
}
/* cria variável chamada dat, pede nome/notas, guarda tudo 
 dentro de dat e devolve dat */

void push (dados n){ /* recebe parametro n do tipo dados 
	"n" contém as informações do aluno vindas da entrada_dados() */
	
	no *novo=malloc(sizeof(no)); /* malloc(sizeof(no)) reserva memória
	                               suficiente para um nó inteiro,
								   e novo guarda o endereço dessa memória */
								   
	if (novo == NULL){
		printf("Erro ao alocar memória \n");
		system("pause");
	} else {
		novo->da=n; /* novo aponta para um novo no, "da" é a struct "dados"
						dentro do no, ela recebe n; Então as informações
						do aluno são copiadas dentro do novo nó */
						
		novo->proximo=top; /* ponteiro proximo do novo no passa a apotar
								para o antigo topo */
								
		top=novo; // o topo passa a apontar para o novo nó
	}
}

void imprimir(){
	no *temp=top; // cria ponteiro auxiliar que começa apontando para o topo da pilha
	system("cls");
	while (temp!=NULL){
		printf("%s %5.1f %5.1f %5.1f\n",
		temp->da.nome,
		temp->da.nota1,
		temp->da.nota2,
		temp->da.sub);
		/* temp acessa o nó atual, da acessa os dados do aluno e 
		pega nome/notas/sub; e então ele imprime os dados do aluno
		daquele nó */
		
		temp=temp->proximo;
		// ponteiro auxiliar "anda" para o proximo nó da pilha; até chegar em NULL
	}
	system("pause");
}

void inverte(){
	if(top !=NULL){
		no *temp=top; //percorre pilha original 
		no *top2=NULL; //segunda pilha vazia (que se´ra a pilha invertida)
		
		while (temp!=NULL){ //enquanto existir elemento na pilha original
			no *novo=malloc(sizeof(no)); //cria um novo nó na memória
			novo->da=temp->da; /*copia dados do no atual da pilha original
								 para novo no*/
								 
			novo->proximo=top2;
			top2=novo;
			// o novo no entra NO TOPO da segunda pilha
			temp=temp->proximo;
			//vai repetindo
		}
		esvazia(); //apaga completamente a pilha original
		top=top2; //agora o topo oficial passa a ser a pilha invertida
	}
}

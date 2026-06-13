/* 15.Utilizando linguagem C, construa um programa que possua um menu (inserir,
remover, imprimir e sair) e contemple uma FILA contendo nome e idade. O
nome não poderá ter tamanho fixo, ou seja, deverá ser alocado dinamicamente. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct No{
	char *nome;
	int idade;
	
	struct No *prox;
}no;

void enqueue(char *nome, int idade);
void dequeue();
void imprimir();
void liberar();

no *ini=NULL;
no *fim=NULL;

//---------------------------------------------------------------------------

int main(){
	char nome[50];
	int idade, opcao;
	
	do{
		system("cls");
		printf("\n====================================================================\n");
		printf("\nMENU: \n1.Inserir na fila \n2.Remover da fila \n3.Imprimir fila \n4.Sair\n");
		printf("\n====================================================================\n");

		scanf("%d",&opcao);
		getchar();
		
		switch(opcao){
			case 1:
				printf("\nNome: ");
				fgets(nome,50,stdin);
				nome[strcspn(nome,"\n")] = '\0';
				
				printf("Idade: ");
				scanf("%d",&idade);
				getchar();
				enqueue(nome,idade);
				break;
			case 2:
				dequeue();
				system("cls");
				break;
			case 3:
				imprimir();
				 printf("\n\nPressione ENTER para continuar...");
  			     getchar();
				 system("cls");
				break;
			case 4:
				liberar();
				printf("\nSaindo...");
				break;
			default:
				printf("opção inválida!");
				break;
		}
	}while(opcao!=4);
}

//---------------------------------------------------------------------------

void enqueue(char *nome, int idade){
	no *novo=malloc(sizeof(no));
		
	novo->nome=malloc(strlen(nome)+1);
	strcpy(novo->nome,nome);
	
	novo->idade=idade;
	novo->prox=NULL;
	
	if(ini==NULL){
		ini=novo;
		fim=novo;
	}else{
		fim->prox=novo;
		fim=novo;
	}
}

//---------------------------------------------------------------------------

void dequeue(){
	
	if(ini == NULL){
		printf("\nFila vazia!");
		return;
	}
	
	no *temp = ini;
	ini=ini->prox;
	
	free(temp->nome);
	free(temp);
	
	if(ini == NULL){
		fim=NULL;
	}
}

//---------------------------------------------------------------------------

void imprimir(){
	no *aux = ini;
	
	while(aux!=NULL){
		printf("\nNome: %s\nIdade: %d\n",aux->nome,aux->idade);
		aux=aux->prox;
	}
}

//---------------------------------------------------------------------------

void liberar(){
	while(ini!=NULL){
		dequeue();
	}
}

//---------------------------------------------------------------------------
/*
ANOTAÇÕES:

Numa fila:
- entra no fim
- sai do início

Se a fila estiver vazia:
ini e fim apontam para o mesmo nó.

Se já existir elementos:
o último nó aponta para o novo nó.

fim->prox = novo;

Depois atualizamos o fim:

fim = novo;

-----

Todo último elemento da fila deve apontar para NULL,
se não inicializar esse ponteiro:

novo->prox

ele conterá lixo de memória.

Ao percorrer a fila poderemos acessar
endereços inválidos e causar erro

-----

Em uma FILA removemos sempre o PRIMEIRO elemento.
Passos:

1) Guardar o início em temp.
2) Avançar o início para o próximo nó.
3) Liberar o nó antigo.

-----

Como o nome foi criado usando malloc(),
ele ocupa uma região separada da memória.

Precisamos liberar:

1) A string
2) O nó

Caso contrário ocorrerá vazamento de memória

-----

Ao encerrar o programa ainda podem existir
nós armazenados na fila.

A solução é chamar dequeue()
repetidamente até que a fila fique vazia.

-----------------------------------------------------------

O exercício pede que o nome NÃO tenha tamanho fixo.

ERRADO:
char nome[50];

Nesse caso, todos os nós reservam 50 posições para o nome,
mesmo que a pessoa tenha apenas 3 letras no nome.

CORRETO:
char *nome;

Aqui estamos armazenando apenas um ponteiro.
A quantidade de memória será definida dinamicamente através
de malloc(), usando exatamente o tamanho necessário para a string.

Exemplo:

Nome digitado: "Ana"

strlen("Ana") = 3

Precisamos de:
3 posições para as letras
+
1 posição para '\0'

Total = 4 bytes

malloc(strlen(nome)+1);

----------------------------------

Toda string termina com '\0'.

Exemplo:

"Ana"

Memória:

'A'
'n'
'a'
'\0'

strlen("Ana") retorna 3.

Mas precisamos de 4 posições.

Por isso usamos:

strlen(nome)+1

O +1 é para armazenar o caractere terminador '\0'

-------------------------------

fgets() captura também o ENTER digitado pelo usuário.
Se o usuário digitar:

Ana

A string ficará:

"Ana\n"

Isso pode causar problemas ao imprimir ou comparar strings.

strcspn(nome,"\n")
localiza a posição do ENTER.

Depois substituímos:

'\n'

por

'\0'

Transformando:

"Ana\n"

em

"Ana"

-------------------------------------------------

Após scanf(), o ENTER continua armazenado no buffer.
Exemplo:

Usuário digita:

1 ENTER

scanf() lê apenas o número 1.

O ENTER continua guardado.

Se logo em seguida usar fgets(),
ele lerá apenas esse ENTER.

Resultado:
a string ficará vazia.

Por isso usamos getchar()
para consumir o ENTER restante.
*/

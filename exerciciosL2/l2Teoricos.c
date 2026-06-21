/* 

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

//------------------------------------------------------------------------------

void inseriMeio(Lista *lista, int num, int ant){

    No *aux;
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
        	}
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else{
        printf("Erro ao alocar memoria.\n");
    }
}

//------------------------------------------------------------------------------

void imprimi(Lista lista){

    No *no = lista.inicio;
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
}

//------------------------------------------------------------------------------

int main(){

    Lista lista;
    lista.inicio = NULL;

    inseriMeio(&lista, 10, 15);
    inseriMeio(&lista, 20, 0);
    inseriMeio(&lista, 30, 10);
    inseriMeio(&lista, 40, 20);
    inseriMeio(&lista, 50, 40);
    imprimi(lista);

    return 0;
}


1) Com base no código fonte acima escrito em linguagem C, apresente
exatamente o resultado que será apresentado ao usuário após a execução completa
do programa. 
RESPOSTA: Será apresentado os valores 10->20->25->30

código comentado:

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista.
// Cada nó possui um valor e um ponteiro para o próximo nó.
typedef struct no{
    int valor;
    struct no *proximo;
}No;

// Estrutura da lista.
// Guarda apenas o endereço do primeiro elemento.
typedef struct{
    No *inicio;
}Lista;

//------------------------------------------------------------------------------

// Insere um novo valor após o valor informado em "ant".
// Exemplo:
// Lista: 10 -> 20 -> 30
//
// inseriMeio(&lista, 25, 20);
//
// Resultado:
// 10 -> 20 -> 25 -> 30
void inseriMeio(Lista *lista, int num, int ant){

    // Ponteiro auxiliar usado para percorrer a lista.
    No *aux;

    // Aloca memória para o novo nó.
    No *novo = malloc(sizeof(No));

    if(novo){

        // Armazena o valor recebido.
        novo->valor = num;

        // Caso a lista esteja vazia.
        if(lista->inicio == NULL){

            // O novo nó será o único elemento da lista.
            novo->proximo = NULL;

            // O início passa a apontar para ele.
            lista->inicio = novo;
        }
        else{

            // Auxiliar começa apontando para o início da lista.
            aux = lista->inicio;

            // Percorre a lista procurando o valor "ant".
            //
            // Continua enquanto:
            // 1) o valor atual for diferente de "ant"
            // 2) existir próximo nó
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }

            // Essas duas linhas realizam a inserção.
            //
            // Exemplo:
            //
            // 10 -> 20 -> 30
            //
            // Inserir 25 após 20
            //
            // Primeiro:
            // 25 -> 30
            novo->proximo = aux->proximo;

            // Depois:
            // 20 -> 25
            aux->proximo = novo;

            // Resultado:
            // 10 -> 20 -> 25 -> 30
        }
    }
    else{
        printf("Erro ao alocar memoria.\n");
    }
}

//------------------------------------------------------------------------------

// Percorre a lista mostrando todos os elementos.
void imprimi(Lista lista){

    // Começa pelo primeiro nó.
    No *no = lista.inicio;

    // Enquanto existir nó.
    while(no){

        // Mostra o valor armazenado.
        printf("%d ", no->valor);

        // Avança para o próximo nó.
        no = no->proximo;
    }
}

//------------------------------------------------------------------------------

int main(){

    Lista lista;

    // Inicialmente a lista está vazia.
    lista.inicio = NULL;

    // Insere 10.
    // Como a lista está vazia, ele vira o primeiro elemento.
    inseriMeio(&lista, 10, 15);

    // Procura o valor 0.
    // Como ele não existe, nada muda.
    inseriMeio(&lista, 20, 0);

    // Procura o valor 10.
    // Encontra e insere 30 após ele.
    //
    // Lista:
    // 10 -> 30
    inseriMeio(&lista, 30, 10);

    // Procura o valor 20.
    // Não encontra.
    inseriMeio(&lista, 40, 20);

    // Procura o valor 40.
    // Não encontra.
    inseriMeio(&lista, 50, 40);

    // Exibe a lista final.
    imprimi(lista);

    return 0;
}

//================================================================================
//================================================================================


2) Utilizando linguagem C, apresente apenas a estrutura mínima do nó de uma
lista circular.
RESPOSTA:

typedef struct no{
int valor;
struct no *proximo;
}No;

a característica de ser circular não está na struct, mas sim na forma como os
ponteiros são ligados

//================================================================================
//================================================================================

3) Analise o código abaixo e implemente uma função chamada sair() que seja
responsável por liberar corretamente toda a memória alocada dinamicamente antes
da finalização do programa.

#include <stdlib.h>
#include <stdio.h>

// Estrutura do nó da pilha
typedef struct apelido_no{
    int dado;
    struct apelido_no *proximo;
}no;

// Ponteiro para o topo da pilha
no *top = NULL;

//------------------------------------------------------------

// Lê um valor digitado pelo usuário
int entrada_dados(){
    int valor;

    printf("\nValor a empilhar: ");
    scanf("%d",&valor);

    return valor;
}

//------------------------------------------------------------

// PUSH = empilhar
// Insere um novo elemento no topo da pilha
void push(int item){

    // Aloca memória para um novo nó
    no *novo = malloc(sizeof(no));

    // Verifica se a memória foi alocada
    if(novo){

        // Armazena o valor
        novo->dado = item;

        // Novo nó aponta para o topo atual
        novo->proximo = top;

        // Novo nó passa a ser o topo
        top = novo;
    }

    system("pause");
}

//------------------------------------------------------------

// POP = desempilhar
// Remove o elemento que está no topo
void pop(){

    if(top == NULL){

        printf("A pilha esta vazia\n");

    }else{

        no *temp;

        temp = top;

        // Topo passa para o próximo elemento
        top = top->proximo;

        // Libera memória do nó removido
        free(temp);
    }

    system("pause");
}

//------------------------------------------------------------

int main(){

    int n, opcao;

    do{

        system("cls");

        printf("\nMenu\n1. Empilha");
        printf("\n2. Desempilha\n3. Sair");

        printf("\nOpcao (0-3):");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:
                n = entrada_dados();
                push(n);
                break;

            case 2:
                pop();
                break;

            case 3:
                // sair();
                break;
        }

    }while(opcao != 3);

    system("pause");
    return 0;
}

RESPOSTA: 
// Libera todos os nós da pilha
void sair(){

    no *temp;

    while(top != NULL){

        temp = top;

        // Avança para o próximo nó
        top = top->proximo;

        // Libera o nó atual
        free(temp);
    }

    printf("\nMemoria liberada com sucesso!\n");
}

E no switch:

case 3:
    sair();
    break;
    
    
    A função sair() percorre toda a pilha removendo
um elemento por vez.

Enquanto existir nó:

1) Guarda o topo em temp.
2) Avança o topo.
3) Libera temp.

Quando top chegar em NULL,
todos os nós foram removidos da memória.

//================================================================================
//================================================================================

4) Considerando as estruturas e a função buscar abaixo, explique a lógica
implementada na linha 5 da função para uma busca sequencial em uma lista
simplesmente encadeada.

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

RESPOSTA:

No* buscar(Lista *lista, int num){

    No *aux, *no = NULL;

    // Começa pelo primeiro elemento
    aux = lista->inicio;

    // Percorre a lista enquanto:
    // existir nó
    // e o valor atual for diferente do procurado
    while(aux && aux->valor != num)

        aux = aux->proximo;

    // Se encontrou o elemento
    if(aux)
        no = aux;

    return no;
}

Linha 5:
while(aux && aux->valor != num)
aux - verifica se ainda existe um no válido
aux->valor!=num - verifica se o valor procurado ainda não foi encontrado
o while continua enquanto existe no na lista E o valor atual é diferente do procurado

//================================================================================
//================================================================================

5) Uma lista simplesmente encadeada é uma estrutura de dados em que cada
elemento, chamado de nó, contém um valor e uma referência para o próximo nó
na sequência. Os nós são encadeados um após o outro, formando uma lista
linear. O último nó da lista tem sua referência de próximo como nula, indicando o
final da lista. Uma lista simplesmente encadeada oferece uma maneira eficiente
de inserir e remover elementos no início da lista, já que apenas os ponteiros
precisam ser atualizados. No entanto, o acesso direto a um elemento em uma
posição específica requer percorrer a lista a partir do primeiro nó.

Diante do contexto apresentado, considere uma lista simplesmente encadeada
que contém os seguintes elementos: 10 ? 20 ? 30 ? 40 ? 50 e apresente a
sequência da lista após a lista receber NULL e a remoção do elemento 30.

RESPOSTA:

lista inicial: 10->20->30->40->50->NULL
depois de remover o elemento 30, o no anterior (20) passa a apontar diretamente
para o no seguinte (40). Com isso o resultado da lista será:
10->20->40->50->NULL
o elemento 30 vai ser removido da estrutura e a memória deve ser liberada

//================================================================================
//================================================================================

6) Apresente as características acerca de Listas Circulares, bem como, um
modelo prático do nosso dia a dia.

RESPOSTA:

As listas circulares são estruturas de dados na qual o último no aponta
para o primeiro no da lista, formando assim um ciclo, diferente das 
listas simplesmente encadeadas, que não existe um ponteiro NULL indicando o final
da lista. Entre suas características estão a navegação contínua pelos elementos,
a facilidade de implementar processos repetitivos e a utilização eficiente em 
aplicações cíclicas. Um exemplo prático do dia a dia é uma playlist de músicas
em modo repetição, na qual, após a última música ser reproduzida, a execução
retorna automaticamente para a primeira música da lista

//================================================================================
//================================================================================

7) Analise o código abaixo desenvolvido em linguagem C e APRESENTE a
representação gráfica (desenhando a estrutura) após a execução completa do
programa, inclusive sinalizando onde a variável *p estará apontando.

#include <stdlib.h>

// Estrutura do nó da pilha.
// Cada nó armazena um dado e o endereço do próximo nó.
typedef struct no{
    int dado;
    struct no *proximo;
}NO;

// Ponteiro para o topo da pilha.
// Quando a pilha está vazia, aponta para NULL.
NO *p = NULL;

//------------------------------------------------------------

// Função para empilhar um elemento (PUSH).
// O valor recebido é inserido no topo da pilha.
void acao_1(int v){

    // Cria um novo nó na memória.
    NO *novo = malloc(sizeof(NO));

    // Armazena o valor recebido.
    novo->dado = v;

    // O novo nó aponta para o antigo topo.
    novo->proximo = p;

    // O novo nó passa a ser o topo da pilha.
    p = novo;
}

//------------------------------------------------------------

// Função para desempilhar um elemento (POP).
// Remove o elemento que está no topo da pilha.
void acao_2(){

    // Verifica se a pilha está vazia.
    if(p == NULL){

        printf("pilha vazia\n");

    }else{

        NO *temp;

        // Guarda o topo atual.
        temp = p;

        // O topo passa a ser o próximo elemento.
        p = p->proximo;

        // Libera a memória do antigo topo.
        free(temp);
    }
}

//------------------------------------------------------------

int main(){

    int n, opcao;

    system("cls");

    // Empilha 71
    acao_1(71);

    // Empilha 8
    acao_1(8);

    // Empilha 15
    acao_1(15);

    // Remove o topo (15)
    acao_2();

    // Empilha 19
    acao_1(19);

    system("pause");
    return 0;
}

RESPOSTA:


LÓGICA DA PILHA

PUSH:
novo->proximo = p;
p = novo;

O novo elemento entra no topo.

---------------------------------

POP:
temp = p;
p = p->proximo;
free(temp);

O elemento do topo é removido.

---------------------------------

EXECUÇÃO DO EXERCÍCIO

Pilha vazia

Empilha 71
71

Empilha 8
8 -> 71

Empilha 15
15 -> 8 -> 71

Desempilha
8 -> 71

Empilha 19
19 -> 8 -> 71

Resultado final:
19 -> 8 -> 71

p aponta para 19.

//================================================================================
//================================================================================

8) Uma pilha é uma estrutura de dados fundamental em ciência da computação.
Ela segue uma política de acesso aos elementos que permite adicionar e remover
elementos de uma extremidade específica.

Observando as afirmações abaixo, assinale qual das seguintes alternativas abaixo
descreve corretamente a principal característica de uma pilha:

a) Em uma pilha, os elementos são inseridos e removidos de qualquer
posição.
b) Uma pilha é uma estrutura de dados em que o primeiro elemento inserido
é o primeiro a ser removido (FIFO).
c) Em uma pilha, os elementos podem ser removidos de qualquer posição,
mas só podem ser inseridos no topo.
d) Uma pilha é uma estrutura de dados que segue o princípio de último a
entrar, primeiro a sair (LIFO).
e) Em uma pilha, a remoção de elementos só é permitida no final, enquanto a
inserção é permitida em qualquer posição.

RESPOSTA: D

//================================================================================
//================================================================================

9) Na abordagem da estrutura de dados do tipo lista, existe uma diversidade,
que pode ser implementada de três formas, simplesmente encadeada, duplamente
encadeada e circular. Partindo da implementação de uma lista simplesmente
encadeada, assinale a alternativa que corresponde a estrutura de um nó para uma
lista simplesmente encadeada.
a) Percorre a lista nos dois sentidos, do início para o fim e do fim para o
início.
b) Cada nó possui dois ponteiros, um para o próximo nó e um para o nó
anterior.
c) Tem como característica principal que o último nó da lista aponta para o
primeiro nó da lista.
d) Na implementação, o programador deve ter o cuidado para que a
estrutura não entre um loop infinito.
e) Possui um nó inicial e a partir dele é possível percorrer toda a lista em
uma única direção, do início para o fim.

RESPOSTA: E

//================================================================================
//================================================================================

10) A estrutura de dados fila é amplamente utilizada em sistemas
computacionais para organizar elementos de forma ordenada. Considerando o
funcionamento de uma fila, assinale a alternativa correta:
a) A inserção e a remoção ocorrem sempre no topo da estrutura.
b) A fila segue o princípio LIFO (Last In, First Out).
c) O primeiro elemento inserido é o primeiro elemento removido da fila.
d) Os elementos podem ser removidos de qualquer posição da fila.
e) A fila permite inserções apenas no início da estrutura.

RESPOSTA: C

//================================================================================
//================================================================================

11) As listas duplamente encadeadas possuem características específicas que as
diferenciam das listas simplesmente encadeadas. Assinale a alternativa correta:
a) Cada nó possui apenas um ponteiro para o próximo elemento.
b) O último nó aponta obrigatoriamente para o primeiro nó.
c) A lista permite percorrer os elementos apenas do início para o fim.
d) Cada nó possui referência para o próximo e para o elemento anterior.
e) Os elementos não podem ser removidos da estrutura.

RESPOSTA: D

//================================================================================
//================================================================================

12) Em uma pilha, as operações básicas recebem nomes específicos. Assinale a
alternativa que apresenta corretamente a operação responsável por remover um
elemento do topo da pilha:
a) Enqueue
b) Insert
c) Pop
d) Push
e) Peek

RESPOSTA: C

//================================================================================
//================================================================================

13) As filas circulares são utilizadas para otimizar o aproveitamento de memória
em determinadas aplicações. Sobre filas circulares, assinale a alternativa correta:
a) O último elemento inserido nunca poderá ser removido.
b) O final da fila pode se conectar novamente ao início da estrutura.
c) A fila circular permite apenas uma inserção de dados.
d) Os elementos são acessados aleatoriamente.
e) A fila circular elimina completamente o conceito FIFO.

RESPOSTA: B

//================================================================================
//================================================================================

14) As listas simplesmente encadeadas apresentam vantagens e limitações.
Assinale a alternativa que representa corretamente uma característica dessa
estrutura:
a) Cada nó possui ponteiro para o próximo e para o anterior.
b) A lista pode ser percorrida apenas em uma direção.
c) O último nó aponta obrigatoriamente para o primeiro.
d) Os elementos só podem ser inseridos no final da lista.
e) A estrutura utiliza obrigatoriamente memória sequencial.

RESPOSTA: B

//================================================================================
//================================================================================

15) Em relação às pilhas, assinale a alternativa que apresenta uma aplicação
prática dessa estrutura de dados:
a) Controle de impressão em uma impressora.
b) Gerenciamento de processos paralelos.
c) Controle de chamadas telefônicas.
d) Histórico de navegação de páginas em navegadores.
e) Armazenamento permanente em banco de dados.

RESPOSTA: D

//================================================================================
//================================================================================

16) As filas são frequentemente utilizadas em sistemas operacionais. Assinale a
alternativa que melhor representa uma aplicação típica de filas:
a) Controle de recursividade em funções.
b) Processamento de impressão de documentos.
c) Armazenamento de variáveis locais.
d) Implementação de árvores binárias.
e) Controle de memória cache LIFO.

RESPOSTA: B

//================================================================================
//================================================================================

17) Em uma lista circular, existe uma característica importante relacionada ao
último elemento da estrutura. Assinale a alternativa correta:
a) O último nó não possui ligação com nenhum elemento.
b) O último nó aponta para o nó anterior.
c) O último nó aponta para o primeiro nó da lista.
d) O último nó armazena obrigatoriamente valor nulo.
e) A lista circular não possui nó inicial.

RESPOSTA: C

//================================================================================
//================================================================================

18) Considerando as operações realizadas em pilhas, assinale a alternativa que
descreve corretamente a operação Push:
a) Remove o elemento do topo da pilha.
b) Consulta o elemento da base da pilha.
c) Insere um novo elemento no topo da pilha.
d) Remove todos os elementos da pilha.
e) Ordena os elementos da pilha automaticamente.

RESPOSTA: C

//================================================================================
//================================================================================

19) As estruturas de dados do tipo lista permitem diferentes formas de
implementação. Sobre listas encadeadas, assinale a alternativa correta:
a) Os elementos precisam estar armazenados em posições sequenciais de
memória.
b) Cada elemento da lista é chamado de nó.
c) Listas encadeadas não permitem inserção dinâmica de elementos.
d) O acesso aos elementos ocorre exclusivamente de trás para frente.
e) As listas encadeadas não utilizam ponteiros.

RESPOSTA: B

//================================================================================
//================================================================================

20) CODIGO.

*/

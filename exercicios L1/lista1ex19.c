#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
    char letra;
    struct No *prox;
}no;
/* cada no da pilha vai armazaner uma letra da palavra */

void push(no **pilha, char c);
char pop(no **pilha);
int palindromo(char palavra[]);

int main(){
    setlocale(LC_ALL,"portuguese");

    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if(palindromo(palavra)){
        printf("É palíndromo!\n");
    }else{
        printf("Não é palíndromo!\n");
    }

    return 0;
}

void push(no **pilha, char c){
    no *novo = malloc(sizeof(no));

    if(novo){
        novo->letra = c; //armazena letra recebida
        novo->prox = *pilha; //novo no passa a apontar para o antigo topo da pilha
        *pilha = novo; //atualiza o topo da pilha para o novo no inserido
    }
}

char pop(no **pilha){
    no *remover; //valor padrao caso a pilha esteja vazia
    char letra = '\0';

    if(*pilha){ //só remove se existir algum elemento
        remover = *pilha; //guarda topo atual
        letra = remover->letra;//salva letra antes de remover
        *pilha = remover->prox;//topo passa a ser o proximo no
        free(remover);
    }

    return letra;
}

int palindromo(char palavra[]){
    no *pilha = NULL;
    int i;
	
	//empilha todas as letras da palavra
    for(i = 0; palavra[i] != '\0'; i++){
        push(&pilha, palavra[i]);
    }
	
	 /*
        compara a palavra original com as
        letras retiradas da pilha
        como a pilha devolve os elementos na
        ordem inversa, estaremos comparando
        a palavra com sua versão invertida.
    */
    for(i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] != pop(&pilha)){
            return 0;
        }
    }

    return 1;
}

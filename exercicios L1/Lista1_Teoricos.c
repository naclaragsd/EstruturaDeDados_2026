#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int opcao;

    do {
        system("cls");

        printf("=============================================================\n");
        printf("     EXERCICIOS TEORICOS LISTA 1 - ESTRUTURA DE DADOS\n");
        printf("                    SOBRE: PILHAS E FILAS\n");
        printf("=============================================================\n\n");

        printf(" 1. Questao 1\n");
        printf(" 2. Questao 2\n");
        printf(" 3. Questao 3\n");
        printf(" 4. Questao 4\n");
        printf(" 5. Questao 5\n");
        printf(" 6. Questao 6\n");
        printf(" 7. Questao 7\n");
        printf(" 8. Questao 8\n");
        printf(" 9. Questao 9\n");
        printf("10. Questao 10\n");
        printf("11. Questao 11\n");
        printf("12. Questao 12\n");
        printf("13. Questao 13\n");
        printf("14. Questao 14\n");
        printf("15. Questao 15\n");
        printf("16. Questao 16\n");
        printf("17. Questao 17\n");
        printf("18. Questao 18\n");
        printf("19. Questao 19\n");
        printf("20. Questao 20\n");
        printf(" 0. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {

        case 1:
            printf("====================== QUESTAO 1 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("1. Cite dois exemplos praticos de PILHA ao qual\n");
            printf("utilizamos no dia a dia na area computacional.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("-Desfazer acoes (Ctrl + z): as acoes realizadas pelo usuario\n");
            printf(" sao armazenadas em uma pilha, permitindo desfazer a ultima\n");
            printf(" acao executada\n\n");
            printf("-Historico de navegacao do navegador: as paginas visitadas\n");
            printf(" ficam organizadas em uma pilha possibilitando retornar a\n");
            printf(" pagina acessada anteriormente atraves do botao \"voltar\"\n");
            printf("=======================================================\n");
            break;

        case 2:
            printf("====================== QUESTAO 2 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("2. Como funcionam as operacoes (insercao e remocao)\n");
            printf("em uma PILHA e de uma FILA? Explique.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("pilha - operacao Push insere um elemento no topo da\n");
            printf("estrutura e a operacao Pop remove o elemento que esta no\n");
            printf("topo. Dessa forma, a pilha segue o principio LIFO\n");
            printf("(Last in, First Out), ou seja, o ultimo elemento inserido\n");
            printf("e o primeiro a ser removido\n\n");
            printf("fila - operacao enqueue adiciona um elemento ao final da\n");
            printf("fila e a operacao dequeue remove o elemento do inicio da\n");
            printf("fila. Assim, a fila segue o principio FIFO\n");
            printf("(First in, First Out), onde o primeiro elemento inserigo\n");
            printf("e o primeiro a ser removido\n");
            printf("=======================================================\n");
            break;

        case 3:
            printf("====================== QUESTAO 3 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("3. Utilizando a linguagem c, apresente a estutura\n");
            printf("minima de um no em uma FILA.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("typedef struct apelido_no{\n");
            printf("    int dado;\n");
            printf("    struct apelido_no *proximo;\n");
            printf("}no;\n\n");
            printf("dado - armazena informacoes do no\n");
            printf("proximo - aponta para o proximo no da fila\n");
            printf("=======================================================\n");
            break;

        case 4:
            printf("====================== QUESTAO 4 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("4. Em uma PILHA necessitamos definir uma variavel de\n");
            printf("ponteiro independente dos demais dados contidos no no.\n");
            printf("Qual deve ser o tipo de ponteiro para apontar para o\n");
            printf("proximo no e quanto ele consumira de memoria? Justifique\n");
            printf("sua resposta.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("o ponteiro que e utilizado para apontar para o proximo no\n");
            printf("deve ser do tipo da propria estrutura, por exemplo\n");
            printf("struct no *proximo, pois ele armazenara o endereco de\n");
            printf("memoria de outro no da pilha.\n\n");
            printf("O consumo de memoria desse ponteiro nao depende da\n");
            printf("quantidade de dados armazenados na estrutura, mas sim da\n");
            printf("arquitetura do sistema. Em um sistema de 32 bits ele\n");
            printf("normalmente ocupa 4 bytes, enquanto em um sistema de\n");
            printf("64 bits ocupa 8 bytes. E importante lembrar que um\n");
            printf("ponteiro guarda apenas o endereco.\n");
            printf("=======================================================\n");
            break;

        case 5:
            printf("====================== QUESTAO 5 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("5. Quais as possiveis operacoes que podemos efetuar\n");
            printf("em uma PILHA? Explique.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("podemos utilizar as operacoes push e pop.\n\n");
            printf("A operacao push e responsavel por inserir um novo\n");
            printf("elemento no topo da pilha, atualizando o ponteiro para\n");
            printf("esse novo elemento.\n\n");
            printf("Ja a operacao pop remove o elemento abaixo dele\n");
            printf("=======================================================\n");
            break;

        case 6:
            printf("====================== QUESTAO 6 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("6. Em uma pilha, o que acontece se atribuirmos NULL\n");
            printf("para o ponteiro que aponta para o topo da PILHA?\n\n");
            printf("---- RESPOSTA ----\n");
            printf("ao atribuir NULL ao ponteiro que aponta para o topo da\n");
            printf("pilha, a pilha passa a ser considerada vazia, pois nao\n");
            printf("existe mais referencia para os seus elementos.\n\n");
            printf("Caso existam nos armazenados na pilha e eles nao sejam\n");
            printf("liberados antes dessa atribuicao, ocorrera perda de acesso\n");
            printf("aos dados e possivel vazamento de memoria\n");
            printf("=======================================================\n");
            break;

        case 7:
            printf("====================== QUESTAO 7 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 8:
            printf("====================== QUESTAO 8 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 9:
            printf("====================== QUESTAO 9 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("9. Utilizando a linguagem c, apresente a estutura\n");
            printf("minima de um no em uma PILHA.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("typedef struct apelido_no{\n");
            printf("    int dado;\n");
            printf("    struct apelido_no *proximo;\n");
            printf("}no;\n\n");
            printf("dado - armazena informacoes do no\n");
            printf("proximo - aponta para o proximo no da fila\n");
            printf("=======================================================\n");
            break;

        case 10:
            printf("====================== QUESTAO 10 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 11:
            printf("====================== QUESTAO 11 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 12:
            printf("====================== QUESTAO 12 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 13:
            printf("====================== QUESTAO 13 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("13. Com base nessa sequencia de instrucoes, apresente\n");
            printf("o valor final da variavel soma.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("| soma = 0 |\n");
            printf("remove o topo (5) e guarda em x\n");
            printf("soma = 5\n");
            printf("x = 10\n");
            printf("empilha 10\n");
            printf("x = 12\n");
            printf("empilha 12\n");
            printf("remove 12\n");
            printf("remove 10\n");
            printf("soma = 15\n");
            printf("=======================================================\n");
            break;

        case 14:
            printf("====================== QUESTAO 14 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 15:
            printf("====================== QUESTAO 15 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 16:
            printf("====================== QUESTAO 16 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 17:
            printf("====================== QUESTAO 17 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("17.Dada a sequencia de operacoes abaixo, indique o\n");
            printf("conteudo final da PILHA (do topo para a base), supondo\n");
            printf("que ela se inicie vazia: push('A'), push('B'), pop(),\n");
            printf("push('C'), push('D'), pop(), pop(), push('E'), pop(),\n");
            printf("push('A'), push('Z'), push('K'), pop(), pop().\n\n");
            printf("---- RESPOSTA ----\n");
            printf("push(A) -> A\n");
            printf("push(B) -> B A\n");
            printf("pop() -> A\n");
            printf("push(C) -> C A\n");
            printf("push(D) -> D C A\n");
            printf("pop() -> C A\n");
            printf("pop() -> A\n");
            printf("push(E) -> E A\n");
            printf("pop() -> A\n");
            printf("push(A) -> A A\n");
            printf("push(Z) -> Z A A\n");
            printf("push(K) -> K Z A A\n");
            printf("pop() -> Z A A\n");
            printf("pop() -> A A\n");
            printf("=======================================================\n");
            break;

        case 18:
            printf("====================== QUESTAO 18 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 19:
            printf("====================== QUESTAO 19 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO ok\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO OK\n");
            printf("=======================================================\n");
            break;

        case 20:
            printf("====================== QUESTAO 20 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("CÓDIGO\n\n");
            printf("---- RESPOSTA ----\n");
            printf("CODIGO\n");
            printf("=======================================================\n");
            break;

        case 0:
            printf("Encerrando programa...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

        if(opcao != 0) {
            printf("\n\nPressione ENTER para voltar ao menu...");
            getchar();
            getchar();
        }

    } while(opcao != 0);

    return 0;
}

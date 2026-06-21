#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int opcao;

    do {
        system("cls");

        printf("=============================================================\n");
        printf("     EXERCICIOS TEORICOS LISTA 2 - ESTRUTURA DE DADOS\n");
        printf("               SOBRE: LISTAS, PILHAS E FILAS\n");
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
            printf("1. Com base no codigo fonte acima escrito em linguagem C,\n");
            printf("apresente exatamente o resultado que sera apresentado ao\n");
            printf("usuario apos a execucao completa do programa.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("Sera apresentado os valores: 10->20->25->30\n");
            printf("=======================================================\n");
            break;

        case 2:
            printf("====================== QUESTAO 2 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("2. Utilizando linguagem C, apresente apenas a estrutura\n");
            printf("minima do no de uma lista circular.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("typedef struct no{\n");
            printf("    int valor;\n");
            printf("    struct no *proximo;\n");
            printf("}No;\n\n");
            printf("Nota: A caracteristica de ser circular nao esta na struct,\n");
            printf("mas sim na forma como os ponteiros sao ligados.\n");
            printf("=======================================================\n");
            break;

        case 3:
            printf("====================== QUESTAO 3 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("3. Analise o codigo abaixo e implemente uma funcao chamada\n");
            printf("sair() que seja responsavel por liberar corretamente toda\n");
            printf("a memoria alocada dinamicamente antes da finalizacao.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("void sair(){\n");
            printf("    no *temp;\n");
            printf("    while(top != NULL){\n");
            printf("        temp = top;\n");
            printf("        top = top->proximo;\n");
            printf("        free(temp);\n");
            printf("    }\n");
            printf("    printf(\"\\nMemoria liberada com sucesso!\\n\");\n");
            printf("}\n\n");
            printf("E no switch:\n");
            printf("case 3:\n");
            printf("    sair();\n");
            printf("    break;\n\n");
            printf("Explicacao: A funcao sair() percorre toda a pilha removendo\n");
            printf("um elemento por vez. Enquanto existir no: guarda o topo\n");
            printf("em temp, avanca o topo e libera temp.\n");
            printf("=======================================================\n");
            break;

        case 4:
            printf("====================== QUESTAO 4 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("4. Considerando as estruturas e a funcao buscar abaixo,\n");
            printf("explique a logica implementada na linha 5 da funcao para\n");
            printf("uma busca sequencial em uma lista simplesmente encadeada.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("Linha 5: while(aux && aux->valor != num)\n\n");
            printf("- aux: verifica se ainda existe um no valido.\n");
            printf("- aux->valor != num: verifica se o valor procurado\n");
            printf("  ainda nao foi encontrado.\n\n");
            printf("O while continua enquanto existir no na lista E o valor\n");
            printf("atual for diferente do procurado.\n");
            printf("=======================================================\n");
            break;

        case 5:
            printf("====================== QUESTAO 5 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("5. Apresente a sequencia da lista apos a lista receber\n");
            printf("NULL e a remocao do elemento 30.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("Lista inicial: 10->20->30->40->50->NULL\n\n");
            printf("Depois de remover o elemento 30, o no anterior (20)\n");
            printf("passa a apontar diretamente para o no seguinte (40).\n");
            printf("Com isso o resultado da lista sera:\n");
            printf("10->20->40->50->NULL\n\n");
            printf("O elemento 30 vai ser removido da estrutura e a\n");
            printf("memoria deve ser liberada.\n");
            printf("=======================================================\n");
            break;

        case 6:
            printf("====================== QUESTAO 6 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("6. Apresente as caracteristicas acerca de Listas\n");
            printf("Circulares, bem como, um modelo pratico do dia a dia.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("Nas listas circulares o ultimo no aponta para o primeiro\n");
            printf("no da lista, formando um ciclo. Nao existe um ponteiro\n");
            printf("NULL indicando o final da lista.\n\n");
            printf("Caracteristicas: navegacao continua e utilizacao eficiente\n");
            printf("em aplicacoes ciclicas.\n\n");
            printf("Exemplo pratico: Uma playlist de musicas em modo repeticao,\n");
            printf("na qual, apos a ultima musica ser reproduzida, a execucao\n");
            printf("retorna automaticamente para a primeira musica da lista.\n");
            printf("=======================================================\n");
            break;

        case 7:
            printf("====================== QUESTAO 7 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("7. Analise o codigo desenvolvido em C e APRESENTE a\n");
            printf("representacao grafica apos a execucao completa,\n");
            printf("sinalizando onde a variavel *p estara apontando.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("EXECUCAO PASSO A PASSO:\n");
            printf("- Pilha vazia\n");
            printf("- Empilha 71  ->  [71]\n");
            printf("- Empilha 8   ->  [8] -> [71]\n");
            printf("- Empilha 15  ->  [15] -> [8] -> [71]\n");
            printf("- Desempilha  ->  [8] -> [71]\n");
            printf("- Empilha 19  ->  [19] -> [8] -> [71]\n\n");
            printf("REPRESENTACAO GRAFICA FINAL:\n");
            printf(" p ---> [19] ---> [8] ---> [71] ---> NULL\n\n");
            printf("O ponteiro 'p' aponta para o no com valor 19.\n");
            printf("=======================================================\n");
            break;

        case 8:
            printf("====================== QUESTAO 8 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("8. Qual alternativa descreve corretamente a principal\n");
            printf("caracteristica de uma pilha?\n\n");
            printf("a) Elementos sao inseridos e removidos de qualquer posicao.\n");
            printf("b) Estrutura em que o primeiro inserido e o primeiro\n");
            printf("   removido (FIFO).\n");
            printf("c) Removidos de qualquer posicao, mas inseridos no topo.\n");
            printf("d) Estrutura que segue o principio de ultimo a entrar,\n");
            printf("   primeiro a sair (LIFO).\n");
            printf("e) Remocao permitida no final, insercao em qualquer posicao.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: D\n");
            printf("=======================================================\n");
            break;

        case 9:
            printf("====================== QUESTAO 9 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("9. Assinale a alternativa que corresponde a estrutura de\n");
            printf("um no para uma lista simplesmente encadeada:\n\n");
            printf("a) Percorre a lista nos dois sentidos (inicio/fim, fim/inicio).\n");
            printf("b) Cada no possui dois ponteiros (proximo e anterior).\n");
            printf("c) O ultimo no da lista aponta para o primeiro no.\n");
            printf("d) Deve ter o cuidado para nao entrar em loop infinito.\n");
            printf("e) Possui um no inicial e permite percorrer toda a lista\n");
            printf("   em uma unica direcao, do inicio para o fim.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: E\n");
            printf("=======================================================\n");
            break;

        case 10:
            printf("====================== QUESTAO 10 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("10. Considerando o funcionamento de uma fila, assinale\n");
            printf("a alternativa correta:\n\n");
            printf("a) A insercao e a remocao ocorrem sempre no topo.\n");
            printf("b) A fila segue o principio LIFO (Last In, First Out).\n");
            printf("c) O primeiro elemento inserido e o primeiro removido.\n");
            printf("d) Os elementos podem ser removidos de qualquer posicao.\n");
            printf("e) A fila permite insercoes apenas no inicio da estrutura.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: C\n");
            printf("=======================================================\n");
            break;

        case 11:
            printf("====================== QUESTAO 11 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("11. As listas duplamente encadeadas possuem caracteristicas\n");
            printf("especificas. Assinale a alternativa correta:\n\n");
            printf("a) Cada no possui apenas um ponteiro para o proximo.\n");
            printf("b) O ultimo no aponta obrigatoriamente para o primeiro.\n");
            printf("c) Permite percorrer elementos apenas do inicio para o fim.\n");
            printf("d) Cada no possui referencia para o proximo e para o anterior.\n");
            printf("e) Os elementos nao podem ser removidos da estrutura.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: D\n");
            printf("=======================================================\n");
            break;

        case 12:
            printf("====================== QUESTAO 12 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("12. Assinale a alternativa que apresenta corretamente a\n");
            printf("operacao responsavel por remover um elemento do topo:\n\n");
            printf("a) Enqueue\n");
            printf("b) Insert\n");
            printf("c) Pop\n");
            printf("d) Push\n");
            printf("e) Peek\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: C\n");
            printf("=======================================================\n");
            break;

        case 13:
            printf("====================== QUESTAO 13 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("13. Sobre filas circulares, assinale a alternativa correta:\n\n");
            printf("a) O ultimo elemento inserido nunca podera ser removido.\n");
            printf("b) O final da fila pode se conectar novamente ao inicio.\n");
            printf("c) A fila circular permite apenas uma insercao de dados.\n");
            printf("d) Os elementos sao acessados aleatoriamente.\n");
            printf("e) A fila circular elimina completamente o conceito FIFO.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: B\n");
            printf("=======================================================\n");
            break;

        case 14:
            printf("====================== QUESTAO 14 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("14. Assinale a alternativa que representa corretamente uma\n");
            printf("caracteristica de uma lista simplesmente encadeada:\n\n");
            printf("a) Cada no possui ponteiro para o proximo e para o anterior.\n");
            printf("b) A lista pode ser percorrida apenas em uma direcao.\n");
            printf("c) O ultimo no aponta obrigatoriamente para o primeiro.\n");
            printf("d) Os elementos so podem ser inseridos no final da lista.\n");
            printf("e) A estrutura utiliza obrigatoriamente memoria sequencial.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: B\n");
            printf("=======================================================\n");
            break;

        case 15:
            printf("====================== QUESTAO 15 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("15. Em relacao as pilhas, assinale a alternativa que\n");
            printf("apresenta uma aplicacao pratica dessa estrutura:\n\n");
            printf("a) Controle de impressao em uma impressora.\n");
            printf("b) Gerenciamento de processos paralelos.\n");
            printf("c) Controle de chamadas telefonicas.\n");
            printf("d) Historico de navegacao de paginas em navegadores.\n");
            printf("e) Armazenamento permanente em banco de dados.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: D\n");
            printf("=======================================================\n");
            break;

        case 16:
            printf("====================== QUESTAO 16 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("16. Assinale a alternativa que melhor representa uma\n");
            printf("aplicacao tipica de filas:\n\n");
            printf("a) Controle de recursividade em funcoes.\n");
            printf("b) Processamento de impressao de documentos.\n");
            printf("c) Armazenamento de variaveis locais.\n");
            printf("d) Implementacao de arvores binarias.\n");
            printf("e) Controle de memoria cache LIFO.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: B\n");
            printf("=======================================================\n");
            break;

        case 17:
            printf("====================== QUESTAO 17 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("17. Em uma lista circular, existe uma caracteristica\n");
            printf("importante relacionada ao ultimo elemento. Assinale:\n\n");
            printf("a) O ultimo no nao possui ligacao com nenhum elemento.\n");
            printf("b) O ultimo no aponta para o no anterior.\n");
            printf("c) O ultimo no aponta para o primeiro no da lista.\n");
            printf("d) O ultimo no armazena obrigatoriamente valor nulo.\n");
            printf("e) A lista circular nao possui no inicial.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: C\n");
            printf("=======================================================\n");
            break;

        case 18:
            printf("====================== QUESTAO 18 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("18. Considerando as operacoes realizadas em pilhas,\n");
            printf("assinale a alternativa que descreve corretamente o Push:\n\n");
            printf("a) Remove o elemento do topo da pilha.\n");
            printf("b) Consulta o elemento da base da pilha.\n");
            printf("c) Insere um novo elemento no topo da pilha.\n");
            printf("d) Remove todos os elementos da pilha.\n");
            printf("e) Ordena os elementos da pilha automaticamente.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: C\n");
            printf("=======================================================\n");
            break;

        case 19:
            printf("====================== QUESTAO 19 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("19. Sobre listas encadeadas, assinale a alternativa correta:\n\n");
            printf("a) Elementos precisam estar em posicoes sequenciais de memoria.\n");
            printf("b) Cada elemento da lista e chamado de no.\n");
            printf("c) Listas encadeadas nao permitem insercao dinamica.\n");
            printf("d) O acesso aos elementos ocorre exclusivamente de tras para frente.\n");
            printf("e) As listas encadeadas nao utilizam ponteiros.\n\n");
            printf("---- RESPOSTA ----\n");
            printf("RESPOSTA CORRETA: B\n");
            printf("=======================================================\n");
            break;

        case 20:
            printf("====================== QUESTAO 20 ======================\n\n");
            printf("---- ENUNCIADO ----\n");
            printf("20. CODIGO\n\n");
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

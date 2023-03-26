#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 500

int main() {
    int vetor[MAX], numero;
    int i;

    //povoando o vetor
    for (i=0;i<MAX;i++) {
        vetor[i] = rand() % 1000;
        //printf("%d ",vetor[i]);
    }

    //número a ser buscado
    printf("\nDigite o número a ser buscado\n");
    scanf("%d",&numero);

    //busca sequencial
    int encontrou = 0;
    printf("Resultado da busca sequencial\n");
    for (i=0; i<MAX && !encontrou; i++) {
        if (vetor[i] == numero)
            printf("Número encontrado na posição %d\n", i);
            encontrou = 1;
    }
    if (!encontrou)
        printf("Número não encontrado");

    //ordenação do vetor
    int j, aux, trocou = 1;
    for (i=MAX-1; i>0 && trocou; i--) {
        trocou = 0;
        for (j=0; j<i; j++) {
            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                trocou = 1;
            }
        }
    }

    //busca binária
    encontrou = 0;
    int iteracoesMAX = (int) floor(log(MAX)+4);
    int index = MAX/2, fim = MAX, inicio = 0;
    for (i=0; i<iteracoesMAX && !encontrou; i++) {
        if (vetor[index] == numero) {
            printf("Número encontrado na %dº iteração(%d posição)", i+1, index);
            encontrou = 1;
        } else if (numero > vetor[index]) {
            inicio = index;
            index = (index + fim)/2;
        } else {
            fim = index;
            index = (index + inicio)/2;
        }
    }
    if (!encontrou)
        printf("Número não encontrado");

    return 0;
}
//Ex. 2
/*
    Pergunta:
        Faça um programa que preencha vetor com oito númerosinteiros,
        calcule e mostre dois vetores resultantes. O primeiro vetor
        deve conter os números positivos e o segundo deve conter os
        números negativos. Atenção: cada vetor terá no máximo oito
        posições, que podem não ser completamente usadas. Não deve
        haver posições vazias entre dois valores. Por exemplo:
        Vetor principal: 8 -2 3 1 -5 7 -14 10
        Vetor psoitivo: 8 3 1 7 10
        Vetor negativo: -2 -5 -14
    Resposta:
        #include <stdio.h>

        int main() {
            int vet[8] = {0}, vetpos[8] = {0}, vetneg[8] = {0};
            int v, p = 0, n = 0;
            for (v=0;v<8;v++) {
                printf("Digite um número inteiro\n");
                scanf("%d", vet[v]);
                if (vet[v] >= 0)
                    vetpos[p++] = vet[v];
                else
                    vetneg[n++] = vet[v];
            }
            for (v=0;v<8;v++) {
                printf("%d ", vet[v]);
                if (vetpos[v] != 0 && v > p)
                    printf("%d ", vetpos[v]);
                else
                    printf("  ");
                if (vetneg[v] != 0 && v > n)
                    prinntf("%d ", vetneg[v]);
                else
                    printf(" \n");
            }
            return 0;
        }
*/

//Ex. 2
/*
    Pergunta:
        Faça um programa que preencha dois vetores A e B com dez
        elementos numéricos cada um calcule e apresente um
        vetor C resultante da intercalação deles. Por exemplo:
        Vetor A: 8 3 1 7 10 12 77 100 33 54
        Vetor B: -2 -5 -14 5 6 12 17 20 66 16
        Vetor C: 8 -2 3 -5 1 -14 7 5 10 6 12 12 77 17 100 20 33 66 54 16
    Resposta:
        #include <stdio.h>

        int main() {
            int vetA[10], vetB[10], vetC[20];
            int i;
            for (i=0;i<10;i++) {
                vetA[i] = 2*i+1;
                vetB[i] = 2*i;
            }
            for (i=0;i<10;i++) {
                vetC[2*i] = vetA[i];
                vetC[2*i+1] = vetB[i];
            }
            for (i=0;i<10;i++)
                printf("%d %d\n", vetA[i], vetB[i]);
            for (i=0;i<20;i++)
                printf("%d ", vetC[i]);
            return 0;
        }
*/

//Ex. 3
/*
    Pergunta:
        Crie um programa que preencha uma matriz 3x3 de números inteiros
        e verifique se a matriz é simétrica. A matriz será simétrica se
        e somente se todo elemento A[i,j] = A[j,i]. Segue um exemplo de
        matriz simétrica:

            [3 2 4]
        P = [2 5 8]
            [4 8 6]

    Resposta:
        #include <stdio.h>

        int main() {
            int mat[3][3], i, j, simetrica = 1;
            for (i=0;i<3;i++)
                for (j=0;j<3;j++)
                    mat[i][j] = i+j;
            for (i=0;i<3;i++)
                for (j=0;j<3;j++) {
                    if (mat[i][j] != mat[j][i])
                        simetrica = 0;
                }
            if (!simetrica)
                printf("A matriz não é simetrica!");
            else
                printf("A matriz é simetrica");
            return 0;
        }
*/

//Ex. 4
/*
    Pergunta:
        Faça um programa que crie uma matriz A de tamanho n x n de valores
        inteiros informados pelo usuário. O programa deverá verificar se A
        é uma matriz identidade e imprimir uma mensagem informando o usuário.
        Considere que a matriz identidade possui todos os elementos da diagonal
        principal iguais a 1 e os demais elementos iguais a 0, como no exemplo:

                [1 0 0]
            I = [0 1 0]
                [0 0 1]

    Resposta:
        #include <stdio.h>

        int main() {
            int i, j, n = 3, mat[n][n], identidade = 1;
            for (i=0;i<n;i++)
                for (j=0;j<n;j++) {
                    printf("Digite um número\n");
                    scanf("%d", &mat[i][j]);
                }
            for (i=0;i<n;i++)
                for (j=0;j<n;j++) {
                    if (i == j && mat[i][j] != 1)
                        identidade = 0;
                    else if (i != j && mat[i][j] != 0)
                        identidade = 0;
                }
            if (!identidade)
                printf("A matriz não é identidade");
            else
                printf("A matriz é identidade");
            return 0;
        }
*/

//Ex. 5
/*
    Pergunta:
        Faça um programa que crie uma matriz A de dimensão m x n e
        outra matriz B de dimensão n x p. O programa deverá calcular
        e apresentar a multiplicação de A por B, como segue no exemplo:

                [2  3]
            A = [0  1]      B = [1  2  3]
                [-1 4]          [-2 0  4]

                  [2  3]                [2.1+3.-2    2.2+3.0   2.3+3.4]   [-4  4 18]
            A.B = [0  1] . [1  2  3] =  [0.1+1.-2    0.2+1.0   0.3+1.4] = [-2  0  4]
                  [-1 4]   [-2 0  4]    [-1.1+4.-2  -1.2+4.0  -1.3+4.4]   [-9 -2 13]

    Resposta:
        #include <stdio.h>

        int main() {
            int m = 3, n = 2, p = 3, i, j, k;
            int matA[m][n], matB[n][p], matAB[m][p];
            printf("Digite números para a matriz A\n");
            for (i=0;i<m;i++)
                for (j=0;j<n;j++) {
                    printf("Digite um número\n");
                    scanf("%d", &matA[i][j]);
                }
            
            printf("Digite números para a matriz B\n");
            for (i=0;i<n;i++)
                for (j=0;j<p;j++) {
                    printf("Digite um número\n");
                    scanf("%d", &matB[i][j]);
                }
            
            for (i=0;i<m;i++) {
                for (j=0;j<p;j++) {
                    matAB[i][j] = 0;
                    for (k=0;k<n;k++)
                        matAB[i][j] = matAB[i][j] + matA[i][k]*matB[k][j];
                    printf("%d ", matAB[i][j]);
                }
                printf("\n");
            }
            return 0;
        }
*/
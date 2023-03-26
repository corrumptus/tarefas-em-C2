//Ex. 1
/*
    Pergunta:
        Faça uma função recursiva para encontrar a
        soma dos elementos de uma lista L de
        tamanho n.
        – Se definirmos a soma dos valores de L por s(L),
        com indices de 0 a k (L[0..k]), podemos escrever:
            s(0) = L[0]
            s(k) = s(k-1) + L[k], 1 <= k < n
    Resposta:
        #include <stdio.h>
        #include <stdlib.h>

        int S(int *lista, int index) {
            if (index)
                return *(lista + index) + S(lista, index-1);
            return *(lista+index);
        }

        int main() {
            int i, n;
            int *L;

            printf("Digite o tamanho da lista\n");
            scanf("%d", &n);

            int *aux = (int *) malloc(n*sizeof(int));
            if (aux == NULL)
                printf("Erro\n");
            else {
                L = aux;
                for (i=0; i<n; i++) {
                    *(L+i) = rand() % 10;
                    printf("%d\n", *(L+i));
                }

                printf("A soma dos %d elementos da lista é %d\n", n, S(L, n));
            }

            return 0;
        }
*/

//Ex 2
/*
    Pergunta:
        Faça uma função recursiva para encontrar a 
        potência positiva (n>=0) de um número X. 
        Considere:
            x^n = 1 se n=0
            x^n = x * x^n-1 se n>0
    Resposta:
        #include <stdio.h>

        int Pot(int n, int p) {
            if (p > 0)
                return n*Pot(n, p-1);
            return 1;
        }

        int main() {
            int numero, potencia;
            printf("Digite o número\n");
            scanf("%d", &numero);
            printf("Digite a potencia\n");
            scanf("%d", &potencia);
            if (potencia >= 0)
                printf("%d elevado a %d resulta em %d\n", numero, potencia, Pot(numero, potencia));
            else
                printf("Potencia não positiva\n");
        }
*/

//Ex. 3
/*
    Pergunta:
        Faça uma função recursiva para calcular o 
        MDC entre dois números x e y. Considere:
            mdc(x; y) = y, se x >= y e x mod y = 0
            mdc(x; y) = mdc(y; x), se x < y
            mdc(x; y) = mdc(y; x mod y), caso contrário
    Resposta:
        #include <stdio.h>

        int MDC(int x, int y) {
            if (x >= y && x % y == 0)
                return y;
            else if (x < y)
                return MDC(y, x);
            return MDC(y, x % y);
        }

        int main() {
            int x, y;
            printf("Digite o primeiro número\n");
            scanf("%d", &x);
            printf("Digite o segundo número\n");
            scanf("%d", &y);
            printf("O MDC entre %d e %d é de %d", x, y, MDC(x, y));
        }
*/
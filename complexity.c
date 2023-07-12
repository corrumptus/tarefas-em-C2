//Ex. 1
/*
Pergunta:
    Qual a complexidade do algoritmo abaixo?

    int funcao01 (int *lista, int n) {
        int i = 0;
        int r = 1
        for (i = 0; i < n; i++) {
            r = r * lista[i];
        }
        return r;
    }
Resposta:
    linear, O(n)
*/

//Ex. 2
/*
Pergunta:
    Qual a complexidade do algoritmo abaixo?

    int funcao02(int *lista, int n) {
        int i = 0;
        int r = 1
        for (i = 0; i < n; i = i + 2) {
            r = r * lista[i];
        }
        return r;
    }
Resposta:
    linear, O(n)
*/

//Ex. 3
/*
Pergunta:
    Qual a complexidade do algoritmo abaixo?

    int funcao03(int *lista, int n) {
        int i = 0;
        int r = 1
        for (i = 1; i <= n; i = i * 2) {
            r = r * lista[i];
        }
        return r;
    }
Resposta:
    linear, O(n)
*/

//Ex. 4
/*
Pergunta:
    Qual a complexidade do algoritmo abaixo?

    int funcao04(int *lista, int n) {
        int i = 0;
        int r = 1
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                r = r + (lista[i] + lista[j])
            }
        }
        return r;
    }
Resposta:
    quadrática, O(n²)
*/

//Ex. 5
/*
Pergunta:
    Qual a complexidade do algoritmo abaixo?

    int funcao05(int *lista, int n) {
        int i = 0;
        int r = 1
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                r = r + (lista[i] + lista[j]);
            }
        }
        return r;
    }
Resposta:
    quadrática, O(n²)
*/

//Ex. 6
/*
Pergunta:
    Qual a complexidade do algoritmo abaixo?

    void move(int n, int origem, int destino, int via) {
        if (n > 0) {
            move(n - 1, origem, via, destino);
            printf(“Mover da haste %d para haste %d\n", origem, destino);
            move(n - 1, via, destino, origem);
        }
    }
Resposta:
    exponencial, O(2^n)
*/
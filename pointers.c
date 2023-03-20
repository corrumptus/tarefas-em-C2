//Ex. 1
/*
    Pergunta:
        Pratique a declaração e a utilização de ponteiros.
        – defina e inicialize uma variável inteira
        – defina um ponteiro para inteiro
        – modifique o valor da variável através do ponteiro
        – verifique o novo valor da variável usando printf
    Resposta:
        #include <stdio.h>

        int main() {
            int var = 10;
            int *pvar;
            pvar = &var;
            *pvar = 20;
            printf("%d", var);
            return 0;
        }
*/

//Ex. 2
/*
    Pergunta:
        V ou F: ao passar um valor para uma função, o endereço
        deste valor é passado para os parâmetros da função?
    Resposta:
        F
*/

//Ex. 3
/*
    Pergunta:
        Qual a maneira correta de referenciar ch, assumindo que
        o endereço de ch é o conteúdo do ponteiro p?
        a) *p
        b) int *p
        c) ch
        d) *ch
        e) &p
        f) &ch
    Resposta:
        a) *p
*/

//Ex. 4
/*
    Pergunta:
        Assumindo que o endereço da variável var foi
        atribuído a um ponteiro pv, escreva uma expressão
        que divida o valor de var por 5 usando apenas o
        ponteiro pv.
    Resposta:
        *pv = *pv/5;
*/

//Ex. 5
/*
    Pergunta:
        Na expressão float *fptr; float é o tipo:
        a) da variável fptr
        b) do endereço de fptr
        c) da variável apontada por fptr
        d) nenhuma das anteriores
    Resposta:
        c) da variável apontada por fptr
*/

//Ex. 6
/*
    Pergunta:
        O programa a seguir está correto? Se não estiver, o que
        deve ser modificado para que ele funcione corretamente?
        main()
        {
            int j, *ptrj;
            *ptrj = 3;
        }
    Resposta:
        não, deve-se adicionar um comando para que ptrj aponte para um endereço,
        tendo em vista que ptrj começa não apontando para nada. ptrj, ao que tudo
        indica, deveria estar apontando para a variável j, logo nós podemos fazer
        o apontamento de 2 formas: atribuindo o endereço de j logo na declaração
        de ptrj ou adicionando uma nova linha de comando que atribua o endereço.
*/

//Ex. 7
/*
    Pergunta:
        Assumindo que queremos ler o valor de x,
        e o endereço de x foi atribuído a ptrx, a
        instrução seguinte é correta? Se não for,
        corrija-a.
        scanf("%d", *ptrx);
    Resposta:
        não, scanf("%d", ptrx);
*/

//Ex. 8
/*
    Pergunta:
        Indique as afirmações verdadeiras e as falsas:
        a) NULL é outro nome dado ao delimitador de strings ‘\0’?
        b) X é um inteiro e p é um ponteiro para inteiro.
        Ambos contêm o valor 100. Então, x+1 e ptr+1 apresentarão o
        número 101.
        c) O operador * permite saber qual o valor de um ponteiro.
    Resposta:
        a) verdadeiro
        b) falso, pois ptr é um endereço, portanto a soma com ele
        se da de forma diferente. quando se soma um número a um
        endereço, esse número é multiplicado pelo número de bytes
        do tipo do endereço (por exemplo, ptr+1 = 104, pois int
        ocupa 4 bytes)
        c) falso, pois * permite saber qual é o valor guardado no
        endereço apontado
*/

//Ex. 9
/*
    Pergunta:
        Pratique a declaração e a utilização de
        ponteiros para referenciar os elementos de
        um vetor.
        – defina um vetor de 10 elementos inteiros
        – defina um ponteiro para inteiro
        – preencha o vetor usando o ponteiro definido para
        referenciar cada posição do vetor
        – imprima os elementos do vetor usando o ponteiro
    Resposta:
        #include <stdio.h>

        int main() {
            int vetor[10];
            int *p;
            p = vetor;
            while (p < vetor+10)
                *p++ = 1;
            while (p > vetor)
                printf("%d ", *--p);
        }
*/

//Ex. 10
/*
    Pergunta:
        Qual a saída do seguinte programa?
        //...
        main() {
            int x = 4, y = 7;
            int *px, *py;
            printf(“Valor de x: %d Valor de y: %d”, x, y);
            px = &x; // inicializando o ponteiro px
            py = &y; // inicializando o ponteiro py
            *px = *px + 10;
            *py = *px + 10;
            printf(“\nValor de x: %d Valor de y: %d”, x, y);
        }
    Resposta:
        Valor de x: 4 Valor de y: 7
        Valor de x: 14 Valor de y: 17
*/

//Ex. 11
/*
    Pergunta:
        O que faz o programa abaixo quando executado?
        main() {
            int i, *ptr, mat[] = {4, 5, 6};
            ptr = mat;
            for (i=0; i<3 ;i++) {
                printf("%d ", *ptr);
                ptr++;
            }
        }
    Resposta:
        - inicializa a variável i, o ponteiro ptr e o vetor mat de 3 posições,
        ambos inteiros.
        - atribui o endereço inicial do vetor mat ao ponteiro ptr.
        - inicia um loop for controlado por i no qual irá executar a sequencia de
        instruções abaixo em um total de 3 vezes:
            - imprime o valor do conteúdo do endereço apontado por ptr e um espaço.
            - incrementa o valor de ptr em 1 tamanho de inteiro.
*/

//Ex. 12
/*
    Pergunta:
        O que faz o programa abaixo quando executado?
        main() {
            int i, mat[] = {4, 5, 6};
            for (i=0; i<3; i++)
                printf("%d ",mat+i);
        }
    Resposta:
        - inicializa a variável i e o vetor mat de 3 posições, ambos inteiros.
        - inicia um loop for controlado por i no qual irá executar a sequencia de
        instruções abaixo em um total de 3 vezes:
            - imprime o valor do endereço resultante da soma entre mat e i, com i
            sendo multiplicado pelo tamanho de um inteiro e um espaço.
*/

//Ex. 13
/*
    Pergunta:
        Faça um subprograma que receba um vetor de inteiros por parâmetro
        e imprima os elementos desse vetor na ordem inversa, acessando os
        elementos por meio de um ponteiro.
    Resposta:
        void inverte(int vetor[], int lenvetor) {
            int *p = vetor+lenvetor;
            while (p != vetor) printf("%d ", *--p);
        }
*/

//Ex. 14
/*
    Pergunta:
        Faça um subprograma que receba uma string por parâmetro
        e troca todas suas consoantes por asterisco (*), acessando
        os elementos por meio de um ponteiro. A nova string deverá
        ser impressa no programa principal.
    Resposta:
        #include <stdio.h>
        #include <string.h>
        
        void strjv(char string[]) {
            char *p, vogais[] = "AEIOU aeiou";
            p = string;
            while (*p != '\0') {
                if (strchr(vogais, *p) == NULL)
                    *p = '\*';
                p++;
            }
        }

        int main() {
            char string[100];
            printf("Digite alguma coisa\n");
            gets(string);
            strjv(string);
            puts(string);
            return 0;
        }
*/

//Ex. 15
/*
    Pergunta:
        Verifique o programa abaixo. Encontre o(s)
        seu(s) erro(s) e corrija-o(s) para que o mesmo
        escreva o número 10 na tela.
        #include <stdio.h>

        int main() {
            int x, *p, **q;
            p = *x;
            q = &p;
            x = 10;
            printf("\n%d\n", &q);
        }
    Resposta:
        - erro na expressão "p = *x;". o correto seria "p = &x;", pois p
        espera um endereço assim como o operador de conteúdo.
        - erro na expressão "printf("\n%d\n", &q);". o correto seria
        "printf("\n%d\n", **q);", pois para que se imprima o número 10
        é preciso acessar o conteúdo de x, que é referenciado por p, que
        é referenciado por q. logo usa-se 2 operadores de conteúdo.
*/

//Ex. 16
/*
    Pergunta:
        Implemente uma função que receba por parâmetro
        uma matriz A de N x M elementos, um vetor B de M
        elementos e devolve um vetor C de N elementos
        que representa a multiplicação de a por b. Use
        ponteiros para referenciar os elementos da matriz e
        dos vetores.
        Ex. de protótipo da função:
        void mult_mat_vet(float a[ ][M], float *B, float *C, int N, int M);
    Resposta:
        void multiplica(int N, int M, int matrizA[][M], int vetorB[], int vetorC[]) {
            int *pA = matrizA, *pB = vetorB, *pC = vetorC;
            while (pC != vetorC+N) {
                pB = vetorB;
                while (pB != vetorB+M)
                    *pC = *pC + (*pA++)*(*pB++);
                pC++;
            }
        }
*/

//Ex. 17
/*
    Pergunta:
        Implemente duas funções StrLen() e StrCat() que
        funcionem como as funções strlen() e strcat()
        disponíveis na biblioteca string.h, respectivamente.
        Os protótipos estão definidos a seguir.
        Obs: Você não deve usar as funções strlen() e strcat()
        já prontas. Use ponteiros para referenciar os elementos
        dos vetores.
        Protótipos: int StrLen(char *s);
                    void StrCat(char *str1, char *str2);
    Resposta:
        int StrLen(char *s) {
            int len = 0;
            while (*s != '\0')
                len++;
                return len;
        }

        void StrCat(char *str1, char *str2) {
            while (*str1 != '\0')
                str1++;
            while (*str2 != '\0')
                *str1++ = *str2++;
            *str1 = *str2;
        }
*/
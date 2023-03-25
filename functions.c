//Ex. 1
/*
    Pergunta:
        Crie um programa para resolver equações do 2º grau. Implemente
        uma função para calcular o delta, uma função para calcular uma
        raíz real e outra função para calcular duas raízes reais.
        Considere: ax² + bx + c = 0 Obs: a deve ser diferente de 0.
        delta = b² - 4 * a * c
        Se delta < 0, não existe raiz real
        Se delta = 0, existe uma raiz real:
        x = (-b) / (2 * a)
        Se delta > 0, existem duas raízes reais:
        x1 = (- b + raiz quadrada de delta) / (2 * a)
        x2 = (- b - raiz quadrada de delta) / (2 * a)
        Atenção: Os resultados produzidos por cada função deverão ser impressos
        pela função main() e nunca dentro das funções. Não use variáveis globais.
    Resposta:
        #include <stdio.h>
        #include <math.h>

        float calcdelta(float a, float b, float c) {
            float delta;
            delta = b*b - (4*a*c);
            return delta;
        }

        float umaraiz(float a, float b) {
            float x;
            x = -b / (2*a);
            return x;
        }

        float duasraizes(float a, float b, float delta, int raiz) {
            float x;
            if (raiz == 1)
                x = -b + sqrt(delta) / (2*a);
            else if (raiz == 2)
                x = -b - sqrt(delta) / (2*a);
            return x;        
        }

        int main() {
            float a, b, c, delta, x, x1, x2;
            printf("Digite os valores de a, b e c da equação do segundo grau(ax² + bx + c)\n");
            scanf("%f%f%f", &a, &b, &c);
            if (a != 0) {
                delta = calcdelta(a, b, c);
                if (delta < 0)
                    printf("A equação não possui raízes reais");
                else if (delta == 0) {
                    x = umaraiz(a, b);
                    printf("A equação possui 2 raízes reais e iguais a %.2f", x);
                } else if (delta > 0) {
                    x1 = duasraizes(a, b, delta, 1);
                    x2 = duasraizes(a, b, delta, 2);
                    printf("A equação possui 2 raízes reais distintas iguais a %.2f e %.2f", x1, x2);
                }
            } else
                printf("A equação não é do segundo grau");
            return 0;
        }
*/

//Ex. 2
/*
    Pergunta:
        A prefeitura de uma cidade fez uma pesquisa entre seus habitantes,
        coletando dados sobre salário, sexo, idade e numero de filhos. Crie
        um registro capaz de armazenar os dados de um habitante e defina um
        vetor com capacidade para até 500 habitantes. O programa deverá ler
        os dados de cada habitante e implementar funções para calcular:
        – A média de salários da população;
        – O número médio de filhos;
        – O maior salário e o menor salário;
        – O percentual de mulheres com salário superior a R$1.500,00.
        Atenção: Os resultados produzidos por cada função deverão ser impressos
        pela função main() e nunca dentro das funções. Não use variáveis globais.
    Resposta:
        #include <stdio.h>
        #include <float.h>

        struct habitante {
            float salario;
            char sexo;
            int idade;
            int num_depen;
        };

        float mediasal(struct habitante vetor[]) {
            int i;
            float salario = 0;
            for (i=0;i<500;i++)
                salario = salario + vetor[i].salario;
            salario = salario/500;
            return salario;
        }

        float mediafilhos(float *total, int num_depen, int i) {
            if (i != 500-1)
                *total = *total + num_depen;
            else {
                *total = *total + num_depen;
                *total = *total/(i+1);
            }
        }

        void menormaiorsal(float *menor, float *maior, struct habitante vetor[]) {
            int i;
            for (i=0;i<500;i++) {
                if (*menor > vetor[i].salario)
                    *menor = vetor[i].salario;
                if (*maior < vetor[i].salario)
                    *maior = vetor[i].salario;
            }
        }

        float percenmul(struct habitante vetor[]) {
            int i;
            float percentual = 0;
            for (i=0;i<500;i++) {
                if (vetor[i].sexo == 'm' && vetor[i].salario > 1500)
                    percentual++;
            }
            percentual = percentual/5;
            return percentual;
        }

        int main() {
            struct habitante habitantes[500];
            float mediasalario = 0, nummediodepen = 0;
            float menorsal = FLT_MAX, maiorsal = -FLT_MAX;            
            int i;
            for (i=0;i<500;i++) {
                printf("Digite o salário do %dº habitante\n", i+1);
                scanf("%f", &habitantes[i].salario);
                printf("Digite o sexo do %dº habitante\n", i+1);
                scanf(" %c", &habitantes[i].sexo);
                printf("Digite a idade do %dº habitante\n", i+1);
                scanf("%d", &habitantes[i].idade);
                printf("Digite número de filhos do %dº habitante\n", i+1);
                scanf("%d", &habitantes[i].num_depen);
                mediafilhos(&nummediodepen, habitantes[i].num_depen, i);
            }
            mediasal(habitantes);
            menormaiorsal(&menorsal, &maiorsal, habitantes);
            printf("A média de salário da população é de %f", mediasalario);
            printf("O número médio de filhos é de %f", nummediodepen);
            printf("O maior salário é de %f e o maior salário é de %f", maiorsal, menorsal);
            printf("O percentual de mulheres com salário maior que R$ 1.500,00 é de %f%", percenmul(habitantes));
            return 0;
        }
*/

//Ex. 3
/*
    Pergunta:
        Faça uma função que receba por parâmetro uma string S e
        um caractere C, lidos no programa principal e remove a
        primeira ocorrência de C em S(se existir). A função
        deverá alterar a própria string, que será impressa depois
        pelo programa principal. Crie um programa principal que
        use a função criada.
    Resposta:
        #include <stdio.h>

        void modificaS(char S[], char C) {
            int i, j, modificada = 0;
            for (i=0;S[i] != '\0' && !modificada;i++) {
                if (S[i] == C) {
                    for (j=i;S[j] != '\0';j++)
                        S[j] = S[j+1];
                    modificada = 1;
                }
            }
        }

        int main() {
            char S[100], C;
            printf("Digite um conjunto de letras\n");
            gets(S);
            printf("Digite uma letra\n");
            scanf(" %c", &C);
            modificaS(S, C);
            printf("O conjunto de letras ficou: %s", S);
            return 0;
        }
*/

//Ex. 4
/*
    Pergunta:
        Crie uma função que receba como parâmetro um vetor A de
        10 números inteiros e substitua todos os valores negativos
        de A por zero. O vetor resultante será mostrado pelo programa principal.
    Resposta:
        #include <stdio.h>

        void COALESCE(int vet[]) {
            int i;
            for (i=0;i<10;i++) {
                if (vet[i] < 0) {
                    vet[i] = 0;
                }
            }
        }

        int main() {
            int zinteiros[10], i;
            printf("Digite 10 valores\n");
            for (i=0;i<10;i++)
                scanf("%d", zinteiros[i]);
            COALESCE(zinteiros);
            for (i=0;i<10;i++)
                printf("%d ", zinteiros[i]);
            return 0;
        }
*/

//Ex. 5
/*
    Pergunta:
        Faça uma função chamada calcularSerie() que calcule e
        apresente os primeiros 10 termos da série a seguir.
        Soma = 100/0! + 99/1! + 98/2! + 97/3! + ...
        A função deverá chamar outra função que receba um inteiro >= 0
        como parâmetro e retorne o seu fatorial, para calcular cada termo.
        Além de apresentar os termos da série, a função deverá ainda retornar
        a soma total dos termos, que será impressa pelo programa principal.
    Resposta:
        #include <stdio.h>

        int fat(int n) {
            int i, fatorial = 1;
            for (i=0;i<n;i++)
                fatorial = fatorial * (i+1);
            return fatorial;
        }

        float calcularSerie() {
            float soma = 0;
            int i;
            printf("Soma = ");
            for (i=0;i<10;i++) {
                soma = soma + (((float) 100-i) / ((float) fat(i)));
                printf("%d/%d! ", 100-i, i);
                if (i != 9)
                    printf("+ ");
            }
            return soma;
        }

        int main() {
            printf("= %.2f", calcularSerie());
        }
*/

//Ex. 6
/*
    Pergunta:
        Um anagrama é uma palavra que é feita a partir da transposição
        das letras de outra palavra ou frase. Por exemplo, “Iracema” é
        um anagrama para “America”. Escreva uma função que receba duas
        strings e verifica se a primeira string é um anagrama da segunda,
        ignorando os espaços em branco e acentuação. A função deverá retornar
        1, caso seja um anagrama e 0, caso contrário. A mensagem informando se
        as strings formam um anagrama ou não deverá ser impressa pelo programa principal.
        OBS: ignore maiúsculas e minúsculas.
    Resposta:
        //C não é uma linguagem boa para se trabalhar com outras codificações não a ASCII
        //então essa resposta não é perfeita, tendo em vista que ela não tira o acento devidamente
        //mas ela é capaz de analizar se duas palavras com o mesmo acento e mesmo case são anagramas

        #include <stdio.h>

        int toLower(int c) {
            int ASCII_INT_A_UPPER = 65, ASCII_INT_Z_UPPER = 90;
            int ASCII_INT_DIFERENCE_OF_A_AND_Z = 32;

            if (c >= ASCII_INT_A_UPPER && c <= ASCII_INT_Z_UPPER)
                return c+ASCII_INT_DIFERENCE_OF_A_AND_Z;
            else
                return c;
        }

        int main() {
            int frase1[100] = {0}, frase2[100] = {0};
            int i, j, i1 = 0, i2 = 0;
            int caracter = 0, anagrama = 1;
            printf("Digite a primeira palavra ou frase (termine ela com um ponto final)\n");

            while (caracter != '.') {
                //como não é óbvio, o espaço na string é obrigatório para que o enter não entre
                scanf("%c ", &caracter); 
                if (caracter != '.' && caracter != ' ')
                    frase1[i1++] = toLower(caracter);
            }

            while (caracter != '.') {
                scanf("%c", &caracter);
                if (caracter != '.' && caracter != ' ')
                    frase2[i2++] = toLower(caracter);
            }

            for (i=0; i<i1; i++) {
                for (j=0; j<i2; j++) {
                    if (frase1[i] == frase2[j])
                        frase2[j] = 0;
                }
            }

            for (i=0; i<i2; i++)
                if (frase2[i] != 0)
                    anagrama = 0;

            if (anagrama)
                printf("Sim");
            else
                printf("Nao");

            return 0;
        }
*/
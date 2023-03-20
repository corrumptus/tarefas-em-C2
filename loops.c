//Ex. 1
/*
    Pergunta:
        Em um campeonato de futebol existem 5 times com 11
        jogadores cada. Faça um programa que receba a
        idade, o peso e a altura de cada um dos jogadores,
        calcule e mostre:
        - A média de idade dos jogadores de cada time
        - A quantidade de jogadores com menos de 18 anos
        - A altura média de todos os jogadores do campeonato 
        - A porcentagem de jogadores de todos os times com mais de 80 quilos
    Resposta:
        #include <stdio.h>
        
        int main() {
            int times = 5, jogadores = 11, t, j;
            int idade; float peso, altura;
            int quantimenos = 0; float mediaidades = 0, mediaaltura = 0, porcemais = 0;
            for (t=0;t<times;t++) {
                mediaidades = 0;
                for (j=0;j<jogadores;j++) {
                    printf("Digite a idade do jogador\n");
                    scanf("%d", &idade);
                    printf("Digite o peso do jogador\n");
                    scanf("%f", &peso);
                    printf("Digite a altura do jogador\n");
                    scanf("%f", &altura);
                    if (idade < 18)
                        quantimenos++;
                    mediaidades = mediaidades + idade;
                    if (peso > 80)
                        porcemais++;
                    mediaaltura = mediaaltura + altura;
                }
                printf("O %dº time possui uma media de idades de: %f\n", t, mediaidades);
            }
            mediaaltura = mediaaltura/(5*11);
            porcemais = porcemais/(5*11)*100;
            printf("A quantidade de jogadores com menos de 18 anos presentes é de %d\n", quantimenos);
            printf("A altura média dos jogadores do campeonato é de %f%\n", mediaaltura);
            printf("A porcentagem de jogadores com mais de 80Kg é de %f%\n", porcemais);
            return 0;
        }
*/

//Ex. 2
/*
    Pergunta:
        Faça um programa que receba um número inteiro
        maior que 1 e verifique se o número é primo.
        Considere que um número primo é divisível apenas por
        1 e por ele mesmo.
        Obs: Faça três versões do programa, uma para
        cada estrutura de repetição (for, while e do- while).
    Resposta:
        #include <stdio.h>

        int main() {
            int n, primo = 1, i;
            printf("Digite um número\n");
            scanf("%d", &n);
            if (n <= 1)
                printf("O número não é primo");
            else {
                for (i=2;i<n;i++) {
                    if (n%i == 0)
                        primo = 0;
                }
                if (primo == 1)
                    printf("O número é primo");
                else
                    printf("O número não é primo");
            }
            return 0;
        }

        #include <stdio.h>

        int main() {
            int n, primo = 1, i;
            printf("Digite um número\n");
            scanf("%d", &n);
            if (n <= 1)
                printf("O número não é primo");
            else {
                i = 2;
                while (i<n) {
                    if (n%i++ == 0)
                        primo = 0;
                }
                if (primo == 1)
                    printf("O número é primo");
                else
                    printf("O número não é primo");
            }
            return 0;
        }

        #include <stdio.h>

        int main() {
            int n, primo = 1, i;
            printf("Digite um número\n");
            scanf("%d", &n);
            if (n <= 1)
                printf("O número não é primo");
            else {
                i = 1;
                do {
                    if (n%i == 0 && i != 1)
                        primo = 0;
                } while (++i<n);
                if (primo == 1)
                    printf("O número é primo");
                else
                    printf("O número não é primo");
            }
            return 0;
        }
*/

//Ex. 3
/*
    Pergunta:
        Faça um programa para mostrar a tabuada dos números de 1 a 10.
    Resposta:
        #include <stdio.h>
        
        int main() {
            int i, j;
            for (i=0;i<10;i++)
                for (j=0;j<10;j++) {
                    printf("%d * %d = %d\n", i+1, j+1, (i+1)*(j+1));
                }
            return 0;
        }
*/

//Ex. 4
/*
    Pergunta:
        Faça um programa que leia um número inteiro >= 0 e
        calcule o seu fatorial.
    Resposta:
        #include <stdio.h>

        int main() {
            int n, i, fatorial = 1;
            printf("Digite um número\n");
            scanf("%d", &n);
            if (n < 0)
                printf("O número %d não possui um fatorial", n);
            else {
                for (i=n;i>0;i--)
                    fatorial = fatorial*i;
                printf("O fatorial de %d é %d", n, fatorial);
            }
            return 0;
        }
*/

//Ex. 5
/*
    Pergunta:
        Fazer um programa que leia um conjunto de valores
        correspondentes às notas que alunos obtiveram em
        uma prova. Quando o valor fornecido for um número
        negativo, significa que não existem mais pontos para
        serem lidos. Após isso seu programa deverá:
        a) Escrever quantas notas são maiores ou iguais a 6.0
        b) Escrever quantas notas são maiores ou iguais a 4.0 e menores que 6.0
        c) Escrever quantos notas são menores que 4.0
    Resposta:
        #include <stdio.h>

        int main() {
            float nota = 0;
            int quantimenor = 0, quantientre = 0, quantimaior = 0;
            while (nota >= 0) {
                printf("Digite uma nota\n");
                scanf("%f", &nota);
                if (nota >= 6)
                    quantimaior++;
                else if (nota < 6 && nota >= 4)
                    quantientre++;
                else if (nota < 4 && nota >= 0)
                    quantimenor++;
            }
            printf("Tivemos:\n");
            printf("%d notas maiores ou iguais a 6\n", quantimaior);
            printf("%d notas menores que 6 e maiores ou iguais a 4\n", quantientre);
            printf("%d notas menores que 4\n", quantimenor);
            printf("em um total de %d alunos", quantimaior+quantientre+quantimenor);
            return 0;
        }
*/

//Ex. 6
/*
    Pergunta:
        Faça um programa que receba um numero N fornecido
        pelo usuário e mostre os N termos da série a seguir:
        S = 1/1 + 2/3 + 3/5 + 4/7 + 5/9 + ... + n/m
        Por fim, imprima a soma total da série.
    Resposta:
        #include <stdio.h>

        int main() {
            float S = 0, num = 1, den = 1;
            int n, i;
            printf("Digite o número de termos\n");
            scanf("%d", &n);
            if (n >= 0) {
                for (i=1;i<n+1;i++) {
                    num = i;
                    den = 2*i - 1;
                    S = S + num/den;
                }
                printf("O resultado da soma dos %d primeiros termos de série S é %f", n, S);
            } else
                printf("Número de termos inválido");
            return 0;
        }
*/

//Ex. 7
/*
    Pergunta:
        Faça um programa que mostre os 8 primeiros termos
        da sequência de Fibonacci.
        Ex: 0, 1, 1, 2, 3, 5, 8,13, 21,34, 55...
    Resposta:
        #include <stdio.h>
        
        int main() {
            int i = 0, j = 1, k, n;
            printf("%d %d ", i, j);
            for (n=0;n<6;n++) {
                k = i;
                i = j;
                j = k + j;
                printf("%d ", j);
            }
            return 0;
        }
*/
//Ex. 1
/*
    Pergunta:
        Verdadeiro ou falso:
        a) 1 > 2
        b) ‘a’ < ‘b’
        c) 3 == 2
        d)‘1’ == ‘1’
        e) 3 >= 2
        f)‘j’ != ‘j’
    
    Resposta:
        a) falso
        b) verdadeiro
        c) falso
        d) verdadeiro
        e) verdadeiro
        f) falso
*/

//Ex. 2
/*
    Pergunta:
        Identifique se há erros no programa a seguir:
        Main() {
            int a=1; b=2; c=3;
            printf(“Os numeros são: %d %d %d\n, a, b, c, d);
        }
    Resposta:
        Erros:
            - main com o "m" em caixa alta.
            - falta de inicialização do tipo das variáveis b e c.
            - falta de uma aspas para o fechamento da string na função printf().
            - indicando uma nova variável sem inicializa-la.
        Semi-erros:
            - falta de indicação de tipo para a função main.
            - uso de virgula e ponto, quando na verdade, se deveria usar virgula.
            - falta de uma mascara de formatação para a variável d.
            - falta de return.
        P.s.: foi suposto que a biblioteca <stdio.h> já estivesse incluida no código.
*/

//Ex. 3
/*
    Pergunta:
        Como será interpretada a expressão
        x+++y?
        a) x++ + y
        b) x + ++y
    Resposta:
        será interpretada como x++ + y, pois o operador de incrementação tem maior precedencia
        sobre o operador de soma.
*/

//Ex. 4
/*
    Pergunta:
        Qual é o valor de k?
        j = 3;
        K = j == 3;
    Resposta:
        o operador de igualdade tem maior precedencia sobre o operador de atribuição, portanto,
        a  expressão se desenvolve da seguinte forma: K = (j == 3); -> K = (3 == 3); -> K = 1;.
        Logo, K vale 1.
*/

//Ex. 5
/*
    Pergunta:
        Dados três valores X, Y e Z, verifique se eles podem
        ser os comprimentos dos lados de um triângulo. Se
        forem, verifique se é um triângulo equilátero,
        isósceles ou escaleno. Se não formarem um
        triângulo, escreva uma mensagem informando que
        não é triângulo. Considere que:
        – O comprimento de cada lado do triângulo é menor do que a soma dos outros dois lados.
        – O triângulo equilátero tem três lados iguais.
        – O triângulo isósceles tem o comprimento de dois lados iguais.
        – O triângulo escaleno tem os três lados diferentes.
    Resposta:
        #include <stdio.h>
        int main() {
            float x, y, z;
            printf("Digite 3 valores\n");
            scanf("%f%f%f", &x, &y, &z);
            printf("Os valores %f, %f e %f ", x, y, z);
            if (x < y + z && y < x + z && z < x + y) {
                if (x == y && y == z && z == x)
                    printf("formam um triângulo equilátero.");
                else if (x == y || y == z || z == x)
                    printf("formam um triângulo isóceles");
                else if (x != y && y != z && z != x)
                    printf("formam um triângulo escaleno");
            } else
                printf("não são capazes de formar um triangulo");
            return 0;
        }
*/

//Ex. 6
/*
    Pergunta:
        Faça um programa para resolver equações
        do 2o grau. Considere: ax² + bx + c = 0
        Obs: a deve ser diferente de 0.
             delta = b² - 4 * a * c.
             Se delta < 0, não existe raiz real.
             Se delta = 0, existe uma raiz real
             x = (-b) / (2 * a).
             Se delta > 0, existem duas raízes reais
             x1 = (- b + raiz quadrada de delta) / (2 * a)
             x2 = (- b - raiz quadrada de delta) / (2 * a).
    Resposta:
        #include <stdio.h>

        int main() {
            float a, b, c, delta, x, x1, x2;
            printf("Digite os valores de a, b e c da equação do segundo grau(ax² + bx + c)\n");
            scanf("%f%f%f", &a, &b, &c);
            if (a != 0) {
                delta = b*b - (4*a*c);
                if (delta < 0)
                    printf("A equação não possui raízes reais");
                else if (delta == 0) {
                    x = -b/(2*a);
                    printf("A equação possui 2 raízes reais e iguais a %f", x);
                } else if (delta > 0) {
                    x1 = -b+delta/(2*a);
                    x2 = -b-delta/(2*a);
                    printf("A equação possui 2 raízes reais distintas iguais a %f e %f", x1, x2);
                }
            } else
                printf("A equação não é do segundo grau");
            return 0;
        }
*/

//Ex. 7
/*
    Pergunta:
        Faça um programa que receba dois números e
        execute uma das operações listadas a seguir, de
        acordo com a escolha do usuário. Se for digitada
        uma opção inválida, mostre a mensagem de erro e
        finalize o programa. As opções são:
        1. Primeiro número elevado ao segundo número;
        2. Raiz quadrada de cada número;
        3. Raiz cúbica de cada número;
        4. Produto dos números;
        OBS: Usar comando de seleção múltipla (case)
    Resposta:
        #include <stdio.h>
        #include <math.h>

        int main() {
            int opcao;
            float x, y, result;
            printf("Digite 2 números\n");
            scanf("%f%f", &x, &y);
            printf("1 - primeiro número elevado ao segundo número\n");
            printf("2 - raiz quadrada de cada número\n");
            printf("3 - raiz cúbica de cada número\n");
            printf("4 - o produto do primeiro número pelo segundo\n");
            printf("Digite a opção desejada\n");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    result = pow(x, y);
                    printf("%f", result);
                    break;
                case 2:
                    result = sqrt(x);
                    printf("%f\n", result);
                    result = sqrt(y);
                    printf("%f", result);
                    break;
                case 3:
                    result = cbrt(x);
                    printf("%f\n", result);
                    result = cbrt(y);
                    printf("%f", result);
                    break;
                case 4:
                    result = x * y;
                    printf("%f", result);
                    break;
                default:
                    printf("Opção inválida");
            }
            return 0;
        }
*/
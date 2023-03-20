//Ex. 1
/*
    Pergunta:
        Faça um programa que receba uma palavra e verifique
        se ela é um palíndromo, ou seja, se escrita do fim
        para o começo é igual à palavra escrita do começo
        para o fim. Exemplo: RENNER, ANA, MIRIM, OVO, etc.
    Resposta:
        #include <stdio.h>

        int main() {
            int i, tamanho, palindromo = 1;
            char palavra[100];
            printf("Digite uma palavra\n");
            scanf("%s", &palavra);
            tamanho = strlen(palavra);
            for (i=0;i<tamanho;i++) {
                if (palavra[i] != palavra[tamanho-i-1])
                    palindromo = 0;
            }
            if (!palindromo)
                printf("A palavra %s não é um palindromo", palavra);
            else
                printf("A palavra %s é um palindromo", palavra);
            return 0;
        }
*/

//Ex. 2
/*
    Pergunta:
        Faça um programa que leia um nome e imprima as 4 primeiras letras.
    Resposta:
        #include <stdio.h>

        int main() {
            char nome[100];
            int i;
            printf("Digite um nome\n");
            gets(nome);
            for (i=0;i<4;i++)
                printf("%c", nome[i]);
            return 0;
        }
*/

//Ex. 3
/*
    Pergunta:
        Faça um programa que leia 10 nomes, ordene-os de forma
        crescente e mostre-os na tela.
    Resposta:
        #include <stdio.h>
        #include <string.h>

        int main() {
            char vetnomes[10][100], nome[100];
            int i, j;
            for (i=0;i<10;i++) {
                printf("Digite um nome\n");
                scanf("%s", &vetnomes[i]);
            }
            for (i=0;i<10;i++)
                for (j=0;j<9;j++) {
                    if (strcmp(vetnomes[j], vetnomes[j+1]) > 0) {
                        strcpy(nome, vetnomes[j]);
                        strcpy(vetnomes[j], vetnomes[j+1]);
                        strcpy(vetnomes[j+1], nome);
                    }
                }
            for (i=0;i<10;i++)
                printf("%s ", vetnomes[i]);
            return 0;
        }
*/

//Ex. 4
/*
    Pergunta:
        Altere o programa 3) para imprimir todos os nomes que contenham
        uma letra qualquer fornecida pelousuário.
    Resposta:
        #include <stdio.h>
        #include <string.h>

        int main() {
            char vetnomes[10][100], nome[100], letra;
            int i, j, n = 0;
            printf("Digite uma letra\n");
            scanf("%c", &letra);
            fflush(stdin);
            for (i=0;i<10;i++) {
                printf("Digite um nome\n");
                scanf("%s", &nome);
                if (strchr(nome, letra) != NULL)
                    strcpy(vetnomes[n++], nome);
            }
            for (i=0;i<n;i++)
                for (j=0;j<n-1;j++) {
                    if (strcmp(vetnomes[j], vetnomes[j+1]) > 0) {
                        strcpy(nome, vetnomes[j]);
                        strcpy(vetnomes[j], vetnomes[j+1]);
                        strcpy(vetnomes[j+1], nome);
                    }
                }
            for (i=0;i<n;i++)
                printf("%s ", vetnomes[i]);
            return 0;
        }
*/

//Ex. 5
/*
    Pergunta:
        Faça um programa que leia um nome e escreva o
        numero de letras que ele possui.
    Resposta:
        #include <stdio.h>
        #include <string.h>

        int main() {
            char nome[100];
            printf("Digite um nome\n");
            scanf("%s", &nome);
            printf("O nome %s possui %d letras", nome, strlen(nome));
            return 0;
        }
*/

//Ex. 6
/*
    Pergunta:
        Faça um programa que leia o nome e o sobrenome de uma pessoa separadamente.
        O programa deve juntar as duas strings em uma só e escrever na tela: a nova
        string, o seu número de caracteres, a sua primeira e a última letra.
    Resposta:
        #include <stdio.h>
        #include <string.h>

        int main() {
            char nome[100], sobrenome[100], nomecompleto[201];
            printf("Digite um nome\n");
            scanf("%s", &nome);
            printf("Digite um sobrenome\n");
            scanf("%s", &sobrenome);
            strcpy(nomecompleto, nome);
            strcat(nomecompleto, " ");
            strcat(nomecompleto, sobrenome);
            printf("O nome completo é %s com %d caracteres, ", nomecompleto, strlen(nomecompleto));
            printf("sendo o primeiro caracter a letra %c ", nomecompleto[0]);
            printf("e o último a letra %c.", nomecompleto[strlen(nomecompleto)-1]);
            return 0;
        }
*/

//Ex. 7
/*
    Pergunta:
        Faça um programa que leia um nome completo e o imprima de duas formas:
        com todas as letras em minúsculas e com todas as letras em maiúsculas.
    Resposta:
        #include <stdio.h>
        #include <string.h>

        int main() {
            char nomecompleto[200];
            printf("Digite um nome completo\n");
            gets(nomecompleto);
            strlwr(nomecompleto);
            printf("Nome minusculo: %s", nomecompleto);
            strupr(nomecompleto);
            printf("Nome maiusculo: %s", nomecompleto);
            return 0;
        }
*/
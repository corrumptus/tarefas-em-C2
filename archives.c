//Ex. 1
/*
    Pergunta:
        Considere um arquivo texto denominado “votos.txt” que contém, em cada
        linha, o voto de um eleitor, representado pelo código de identificação do
        candidato. Suponha que existam 5 candidatos, cujos códigos de identificação
        são: 100, 200, 300, 400, 500.
        Faça um programa para apurar o resultado final da eleição. O programa
        deverá implementar funções para:
        a) Calcular e apresentar a quantidade de votos por candidato
        b) Calcular e apresentar a quantidade de votos do candidato mais
        votado
        c) Calcular a quantidade de votos do candidato menos votado
        d) Calcular e apresentar a quantidade de votos nulos (um voto nulo é
        um voto cujo código de identificação é inválido).
        Obs: as funções deverão retornar os resultados para serem impressos no programa
        principal. Utilize parâmetros para fazer a transferência de dados entre as funções.
        NÃO USE VARIÁVEIS GLOBAIS.
    Resposta:
        #include <stdio.h>
        #include <stdlib.h>

        void apura_candidatos(int candidatos[]) {
            FILE *p;
            char numero[4];
            p = fopen("votos.txt", "r");
            if (p == NULL) {
                printf("ocorreu um problema :(");
                exit(1);
            }
            while (!feof(p)) {
                fgets(numero, 4, p);
                p = p+2;
                if (atoi(numero)%100 == 0)
                    candidato[atoi(numero)/100-1]++;
            }
            fclose(p);
        }

        int apura_maisvotado() {
            FILE *p;
            char numero[4];
            int vet[5] = {0}, *maior = vet, i;
            p = fopen("votos.txt", "r");
            if (p == NULL) {
                printf("ocorreu um problema :(");
                exit(1);
            }
            while (!feof(p)) {
                fgets(numero, 4, p);
                p = p+2;
                if (atoi(numero)%100 == 0 && atoi(numero) < 501 && atoi(numero) > 99)
                    candidato[atoi(numero)/100-1]++;
            }
            for (i=1;i<5;i++) {
                if (*maior < vet[i])
                    maior = &vet[i];
            }
            fclose(p);
            return ((int) (maior - vet) + 1) * 100;
        }

        int apura_menosvotado() {
            FILE *p;
            char numero[4];
            int vet[5] = {0}, *menor = vet, i;
            p = fopen("votos.txt", "r");
            if (p == NULL) {
                printf("ocorreu um problema :(");
                exit(1);
            }
            while (!feof(p)) {
                fgets(numero, 4, p);
                p = p+2;
                if (atoi(numero)%100 == 0  && atoi(numero) < 501 && atoi(numero) > 99)
                    candidato[atoi(numero)/100-1]++;
            }
            for (i=1;i<5;i++) {
                if (*maior > vet[i])
                    maior = &vet[i];
            }
            fclose(p);
            return ((int) (maior - vet) + 1) * 100;
        }

        int apura_nulos() {
            FILE *P;
            char numero[4];
            int nulos = 0;
            p = fopen("votos.txt", "r");
            if (p == NULL) {
                printf("ocorreu um problema :(");
                exit(1);
            }
            while (!feof(p)) {
                fgets(numero, 4, p);
                p = p+2;
                if (!(numero[1] =='0' && numero[2] == '0' && numero[0] > '0' && numero[0] < '6'))
                    nulos++;
            }
            fclose(p);
            return nulos;
        }

        int main() {
            int candidatos[5], opcao = 1, i;
            while (opcao) {
                printf("\tApuração das eleições\n");
                printf("Escolha uma opção\n");
                printf("1 - votos de cada candidato\n");
                printf("2 - candidato mais votado\n");
                printf("3 - candidato menos votado\n");
                printf("4 - votos nulos\n");
                printf("0 - sair");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1:
                        system("cls");
                        apura_candidatos(candidatos);
                        printf("Votos por candidato\n");
                        for (i=0;i<5;i++)
                            printf("O candidato %d teve %d\n", (i+1)*100, candidatos[i]);
                        printf("\n");
                        break;
                    case 2:
                        system("cls");
                        printf("O candidato mais votado foi o candidato: %d\n\n", apura_maisvotado());
                        break;
                    case 3:
                        system("cls");
                        printf("O candidato menos votado foi o candidato: %d\n\n", apura_menosvotado());
                        break;
                    case 4:
                        system("cls");
                        printf("A votação teve um total de %d votos nulos\n\n", apura_nulos());
                        break.;
                    case 0:
                        system("cls");
                        printf("Desligando sistema\n");
                        break;
                    default:
                        system("cls");
                        printf("Opção inválida");
                }
            }
            return 0;
        }
*/

//Ex. 2
/*
    Pergunta:
        Faça um programa modularizado que preencha um
        vetor dinâmico com a média semestral de cada aluno
        que cursou AP2S2. Após criar o vetor, o programa deverá
        percorrê-lo, gravando cada nota em um arquivo chamado
        notas_AP2S2.txt.
        Obs: Utilize parâmetros para fazer a transferência de dados entre as
        funções. NÃO USE VARIÁVEIS GLOBAIS.
    Resposta:
        #include <stdio.h>
        #include <stdlib.h>

        int aloca_vet(float *vet, int quantidade) {
            vet = (float *) malloc (sizeof(float)*quantidade)
            if (vet == NULL)
                return 0;
            return 1;
        }

        void preenche_vet(float *notas, int tamanho) {
            int i;
            for (i=0;i<tamanho;i++)
                *(notas+i) = (float) (rand() % 100) / 10;
        }

        void preenche_arq(float *notas, int tamanho) {
            FILE *p;
            int i;
            p = fopen("notas_AP2S2.txt", "w");
            if (p == NULL) {
                printf("Ocorreu um erro na abertura do arquivo\n");
                exit(1);
            }
            for (i=0;i<tamanho;i++)
                fprintf(p, "%.2f\n", *(notas+i));
            fclose(p);
        }

        int main() {
            float *notas;
            int alunos;
            printf("Digite quantos alunos possui a classe\n");
            scanf("%d", &alunos);
            
            if (aloca_vet(notas, alunos)) {
                preenche_vet(notas, alunos);
                preenche_arq(notas, alunos);
            } else
                printf("Ocorreu um erro na alocação de memória\n");
            return 0;
        }
*/

//Ex. 3
/*
    Pergunta:
        Faça um programa que leia o arquivo notas_AP2S2.txt,
        criado no Exercício 2, calcule e apresente:
        a) a média geral da turma
        b) a porcentagem de alunos com média >= 6.0 (aprovados)
        c) a porcentagem de alunos com média inferior a 4.0 (reprovados)
        d) a porcentagem de alunos que farão IFA (média entre 4.0 e 5.9)
        Dica: use a função atof(), para converter a nota (string) lida
        do arquivo para número real (float).
        Ex. de uso: char str [] = “8.5”;
                    float nota;
                    nota = atof(str);
    Resposta:
        #include <stdio.h>
        #include <stdlib.h>

        void carrega_vet(float *notas, int *max) {
            FILE *p;
            int i=0;
            float *aux;
            char nota[5];
            p = fopen("notas_AP2S2.txt", "r");
            if (p == NULL) {
                printf("Ocorreu um erro na abertura do arquivo\n");
                exit(1);
            }
            while (!feof(p)) {
                if (i != *max) {
                    fscanf(p, "%s ", nota);
                    *(notas+i++) = (float) atof(nota);
                } else {
                    aux = (float *) realloc (notas, (*max)+1);
                    if (aux != NULL) {
                        notas = aux;
                        (*max)++;
                    } else {
                        printf("Ocorreu um erro na alocação de memória e a lista está incompleta\n");
                        return;
                    }
                }
            }
        }

        int main() {
            float *notas;
            int numNotas = 1, i;
            float media_turma = 0, porcentagem_aprovados = 0;
            float porcentagem_IFA = 0, porcentagem_reprovados = 0;
            notas = (float *) calloc (numNotas, sizeof(float));
            carrega_vet(notas, &numNotas);
            for (i=0; i<numNotas; i++) {
                media_turma += *(notas+i);
                if (*(notas+i) >= 6)
                    porcentagem_aprovados++;
                else if (*(notas+i) >= 4)
                    porcentagem_IFA++;
                else
                    porcentagem_reprovados++;
            }
            printf("Média: %.2f\n", media_turma/numNotas);
            printf("porcentagem de aprovados: %.2f\n", porcentagem_aprovados*100/numNotas);
            printf("porcentagem de IFAs: %.2f\n", porcentagem_IFA*100/numNotas);
            printf("porcentagem de reprovados: %.2f\n", porcentagem_reprovados*100/numNotas);
        }
*/

//Ex. 4
/*
    Pergunta:
        Faça um programa que crie um arquivo binário
        denominado “Notas_AP2S2.bin” com registros de alunos
        que cursaram a disciplina de AP2S2. Cada linha do arquivo
        terá o nome de um aluno, o seu prontuário, a nota de cada
        uma das 3 provas realizadas na disciplina, bem como dos 2
        trabalhos, conforme no exemplo a seguir:
            Maria sc365987 6.5 4.0 7.5 5.0 7.8
            Roberto sc569874 4.5 3.0 6.0 5.0 8.6
            Carlos sc222222 7.0 8.0 9.0 10.0 10.0
            Pedro sc112141 9.0 6.0 10.0 7.0 5.0
        O programa deverá ler o arquivo criado e deverá implementar
        funções para:
        a) Calcular e apresentar a média semestral de cada estudante
        (os pesos de cada avaliação devem ser fornecidos pelo
        usuário);
        b) Apresentar o nome e a média dos estudantes que
        obtiveram média final menor que 6.0;
        c) Apresentar o nome e a média do estudante que obteve a
        menor média final (se houver mais de um aluno, a função
        deverá exibir todos);
        d) Apresentar o nome e a média do estudante que obteve a
        maior média final (se houver mais de um aluno, a função
        deverá exibir todos).
    Resposta:
        #include <stdio.h>
        #include <stdlib.h>

        #define todasNotas 5

        typedef struct aluno {
            char nome[50];
            char prontuario[10];
            float notas[todasNotas];
        } Aluno;

        int cadastraAlunos() {
            FILE *f = fopen("Notas_AP2S2.bin", "w");
            int quantidade = 0, i, j;
            if (f == NULL)
                return quantidade;

            printf("Digite a quantidade de alunos\n");
            scanf("%d", &quantidade);

            Aluno *alunos = (Aluno *) malloc (quantidade*sizeof(Aluno));

            for (i=0;i<quantidade;i++) {
                printf("Digite o nome do aluno\n");
                gets((alunos+i)->nome);
                printf("Digite o prontuario do aluno\n");
                gets((alunos+i)->prontuario);
                printf("Digite a nota das 3 provas\n");
                for (i=0;i<3;i++)
                    scanf("%f", &(alunos+i)->notas[i]);
                printf("Digite a nota dos 2 trabalhos\n");
                for (i=3; i<todasNotas; i++)
                    scanf("%f", &(alunos+i)->notas[i]);
            }

            int n = fwrite(alunos, sizeof(Aluno), quantidade, f);
            fclose(f);
            free(alunos);
            return n;
        }

        int carregaAlunos(Aluno *alunos, int max) {
            FILE *f = fopen("Notas_AP2S2.bin", "r");
            int n;
            Aluno *alunos = (Aluno *) malloc (max * sizeof(Aluno));
            
            if (f == NULL || alunos == NULL)
                return NULL;
            n = fread(alunos, sizeof(Aluno), max, f);
            fclose(f);
            return n;
        }

        void carregaMedias(float *medias, Aluno *alunos, int quantidade, int pesos[], int pesoTotal) {
            float media;
            int i, j;
            for (i=0; i< quantidade; i++) {
                media = 0;
                for (j=0; j<todasNotas; j++)
                    media += (alunos+i)->notas[j]*pesos[j];
                *(medias+i) = media/pesoTotal;
            }
        }

        void mostraMedias(Aluno *alunos, int quantidade, float *medias) {
            int i;
            for (i=0; i< quantidade; i++) {
                printf("%s: %f\n", (alunos+i)->nome, *(medias+i));
            }
        }

        void mostrarAbaixosMedia(Aluno *alunos, int quantidade, float *medias) {
            int i;
            for (i=0; i< quantidade; i++) {
                if (*(medias+i) < 6)
                    printf("%s: %f\n", (alunos+i)->nome, *(medias+i));
            }
        }

        void mostrarMenorMedia(Aluno *alunos, int quantidade, float *medias, int n) {
            int i;
            float menorMedia = n*10;
            for (i=0; i<quantidade; i++) {
                if (menorMedia > *(medias+i))
                    menorMedia = *(medias+i);
            }

            for (i=0; i<quantidade; i++) {
                if (*(medias+i) == menorMedia)
                    printf("%s: %f\n", (alunos+i)->nome, *(medias+i));
            }
        }

        void mostrarMaiorMedia(Aluno *alunos, int quantidade, float *medias) {
            int i;
            float menorMedia = 0;
            for (i=0; i<quantidade; i++) {
                if (menorMedia < *(medias+i))
                    menorMedia = *(medias+i);
            }

            for (i=0; i<quantidade; i++) {
                if (*(medias+i) == menorMedia)
                    printf("%s: %f\n", (alunos+i)->nome, *(medias+i));
            }
        }

        int main() {
            int quantidadeAlunos = cadastraAlunos();
            Aluno *alunos;
            int alunosLidos = carregaAlunos(alunos, quantidadeAlunos);
            int pesos[todasNotas], pesoTotal, i, j;
            float *mediaAlunos = (float *) malloc (alunosLidos*sizeof(float));
            if (alunosLidos && mediaAlunos) {
                printf("Digite os pesos referentes a cada uma das 5 avaliações\n");
                for (i=0; i<todasNotas; i++) {
                    scanf("%d", &pesos[i]);
                    pesoTotal += pesos[i];
                }
                carregaMedias(mediaAlunos, alunos, alunosLidos, pesos, pesoTotal);
                printf("Medias dos alunos:\n");
                mostraMedias(alunos, alunosLidos, mediaAlunos);
                printf("Alunos com média abaixo de 6\n");
                mostrarAbaixosMedia(alunos, alunosLidos, mediaAlunos);
                printf("Aluno(s) que tirou(aram) a(s) menor(es) média(s)\n");
                mostrarMenorMedia(alunos, alunosLidos, mediaAlunos, pesoTotal);
                printf("Aluno(s) que tirou(aram) a(s) maior(es) média(s)\n");
                mostrarMaiorMedia(alunos, alunosLidos, mediaAlunos);
            }

            return 0;
        }
*/
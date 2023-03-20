//Ex. 1
/*
    Pergunta:
        - Defina um registro de Funcionário capaz de armazenar o código, o cargo,
        o nome, o número de dependentes e o salário de um funcionário.
        - Crie um funcionário do tipo do registro criado e solicite seus dados,
        preenchendo o registro.
        - Imprima todos os dados do funcionário criado.
        - Solicite do usuário um novo cargo e um novo salário e atualize o registro criado.
        - Imprima novamente o registro.
    Resposta:
        #include <stdio.h>
        #include <stdlib.h>

        struct funcionario {
            int codigo;
            char cargo[40];
            char nome[100];
            int num_depen;
            float salario;
        };

        int main() {
            struct funcionario funcionario;
            printf("Digite o nome do funcionário\n");
            gets(funcionario.nome);
            printf("Digite o código do funcionário\n");
            scanf("%d", &funcionario.codigo);
            printf("Digite o salario do funcionário\n");
            scanf("%f", &funcionario.salario);
            printf("Digite o cargo do funcionário\n");
            scanf("%s", &funcionario.cargo);
            printf("Digite o número de dependentes do funcionário\n");
            scanf("%d", &funcionario.num_depen);
            printf("Nome: %s\n", funcionario.nome);
            printf("Código: %d\n", funcionario.codigo);
            printf("Salário: %f\n", funcionario.salario);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Número de dependentes: %d\n", funcionario.num_depen);
            printf("Digite um novo cargo para o funcionário\n");
            scanf("%s", &funcionario.cargo);
            printf("Digite um novo salário para o funcionário\n");
            scanf("%f", &funcionario.salario);
            printf("Nome: %s\n", funcionario.nome);
            printf("Código: %d\n", funcionario.codigo);
            printf("Salário: %f\n", funcionario.salario);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Número de dependentes: %d\n", funcionario.num_depen);
            return 0;
        }
*/

//Ex. 2
/*
    Pergunta:
        - A prefeitura de uma cidade fez uma pesquisa entre seus habitantes,
        coletando dados sobre salário, sexo, idade e número de filhos.
        - Crie um registro capaz de armazenar os dados de um habitante e
        defina um vetor com capacidade para até 20 habitantes.
        - Crie um programa para ler os dados de cada habitante, calcular
        e mostrar:
            – A média de salários da população;
            – O número médio de filhos;
            – O maior salário e o menor salário;
            – O percentual de mulheres com salário superior a R$1.500,00.
    Resposta:
        #include <stdio.h>
        #include <float.h>

        struct habitante {
            float salario;
            char sexo;
            int idade;
            int num_depen;
        };
        
        int main() {
            struct habitante habitantes[20];
            int i;
            float mediasalario = 0, nummediodepen = 0;
            float menorsal = FLT_MAX, maiorsal = -FLT_MAX, percentualmulheres = 0;
            for (i=0;i<20;i++) {
                printf("Digite o salário do %dº habitante\n", i+1);
                scanf("%f", &habitantes[i].salario);
                printf("Digite o sexo do %dº habitante\n", i+1);
                scanf(" %c", &habitantes[i].sexo);
                printf("Digite a idade do %dº habitante\n", i+1);
                scanf("%d", &habitantes[i].idade);
                printf("Digite número de filhos do %dº habitante\n", i+1);
                scanf("%d", &habitantes[i].num_depen);
                mediasalario = mediasalario + habitantes[i].salario;
                nummediodepen = nummediodepen + habitantes[i].num_depen;
                if (menorsal > habitantes[i].salario)
                    menorsal = habitantes[i].salario;
                if (maiorsal < habitantes[i].salario)
                    maiorsal = habitantes[i].salario;
                if (habitantes[i].sexo == 'm' && habitantes[i].salario > 1500)
                    percentualmulheres++;
            }
            mediasalario = mediasalario/20;
            nummediodepen = nummediodepen/20;
            percentualmulheres = percentualmulheres/20;
            printf("A média de salário da população é de %f", mediasalario);
            printf("O número médio de filhos é de %f", nummediodepen);
            printf("O maior salário é de %f e o maior salário é de %f", maiorsal, menorsal);
            printf("O percentual de mulheres com salário maior que R$ 1.500,00 é de %f%", percentualmulheres*100);
            return 0;
        }
*/
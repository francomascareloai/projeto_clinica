#include "C:\Users\eduar\OneDrive - FTEC FACULDADES\Algoritmos\projeto_clinica\include\medicamento.hpp"
#include <stdio.h>
#include <cstring>
#include "C:\Users\eduar\OneDrive - FTEC FACULDADES\Algoritmos\projeto_clinica\include\estoque.hpp"


void cadastrarMedicamento(Medicamento estoque[], int *totalMedicamentos) {

    if (*totalMedicamentos >= 100) {
        printf("Erro: estoque cheio!\n");
        return;
    }

    Medicamento m;

    m.id = *totalMedicamentos + 1; // gerando ID simples

    printf("Digite o nome do medicamento: ");
    fflush(stdin);        // limpar buffer
    fgets(m.nome, 50, stdin);

    // remover quebra de linha do fgets
    int len = strlen(m.nome);
    if (m.nome[len - 1] == '\n') {
        m.nome[len - 1] = '\0';
    }

    printf("Quantidade: ");
    scanf("%d", &m.quantidade);

    printf("Quantidade minima: ");
    scanf("%d", &m.quantidadeMinima);

    printf("Validade (dia mes ano): ");
    scanf("%d %d %d", &m.dia, &m.mes, &m.ano);

    estoque[*totalMedicamentos] = m;    // coloca no vetor
    (*totalMedicamentos)++;             // incrementa

    printf("\nMedicamento cadastrado com sucesso!\n");

    printf("Hello world\n");
}


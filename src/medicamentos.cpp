#include <stdio.h>
#include "C:\Users\eduar\OneDrive - FTEC FACULDADES\Algoritmos\projeto_clinica\include\medicamento.hpp"

void exibirMedicamento(Medicamento m) {
    printf("ID: %d\n", m.id);
    printf("Nome: %s\n", m.nome);
    printf("Quantidade: %d\n", m.quantidade);
    printf("Quantidade Minima: %d\n", m.quantidadeMinima);
    printf("Validade: %02d/%02d/%04d\n", m.dia, m.mes, m.ano);
}
#include <cstdio>
#include "C:\Users\eduar\OneDrive - FTEC FACULDADES\Algoritmos\projeto_clinica\include\estoque.hpp"
#include "C:\Users\eduar\OneDrive - FTEC FACULDADES\Algoritmos\projeto_clinica\include\medicamento.hpp"

#define MAX_MEDICAMENTOS 100

int main() {

    Medicamento estoque[MAX_MEDICAMENTOS];
    int totalMedicamentos = 0;

    printf("=== Testando cadastro ===\n");

    cadastrarMedicamento(estoque, &totalMedicamentos);

    printf("\nTotal atual de medicamentos: %d\n", totalMedicamentos);

    printf("\n=== Exibindo o que foi cadastrado ===\n");
    exibirMedicamento(estoque[0]);

    return 0;
}
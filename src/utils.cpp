#include <stdio.h>
#include "../include/utils.hpp"
#include "../include/estoque.hpp"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void vazioPorEnquanto(Medicamento lista[], int total) {
        if (total == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }
}


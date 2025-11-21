#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    int quantidadeMinima;
    int dia, mes, ano; // validade
} Medicamento;

void cadastrarMedicamento(Medicamento lista[], int *total);
void listarMedicamentos(Medicamento lista[], int total);
void emitirAlertas(Medicamento lista[], int total);
void mostrarEstatisticas(Medicamento lista[], int total);
void simularVenda(Medicamento lista[], int total);
void exportarInventario(Medicamento lista[], int total);

#endif
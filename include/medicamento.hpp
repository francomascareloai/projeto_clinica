#ifndef medicamento_hpp
#define medicamento_hpp

struct Medicamento {
    int id;
    char nome[50];
    int quantidade;
    int quantidadeMinima;
    int dia, mes, ano;
};

void exibirMedicamento(Medicamento m);

#endif
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "../include/estoque.hpp"
#include "../include/utils.hpp"

void cadastrarMedicamento(Medicamento lista[], int *total) {
    printf("\n========================================\n");
    printf("\nCadastro de Medicamento\n");
    
    // ID automático baseado no total de medicamentos cadastrados
    lista[*total].id = *total + 1;

    // Nome do medicamento
    do {
        printf("\nDigite o nome do medicamento: ");
        fgets(lista[*total].nome, sizeof(lista[*total].nome), stdin);
        if (strlen(lista[*total].nome) <= 1) {
            printf("\nNome inválido. Por favor, tente novamente.");
        }
    } while (strlen(lista[*total].nome) <= 1); // Garante que o nome não seja vazio
    
    // Remove o caractere de nova linha lido pelo fgets  
    lista[*total].nome[strcspn(lista[*total].nome, "\n")] = '\0';

    // Quantidade do medicamento
    do {
        printf("\nDigite a quantidade do medicamento: ");
        scanf("%d", &lista[*total].quantidade);
        limparBuffer();
        if (lista[*total].quantidade < 0) {
            printf("\nQuantidade inválida. Por favor, tente novamente.");
        }
    } while (lista[*total].quantidade < 0); // Garante que a quantidade não seja negativa
 
    // Quantidade mínima do medicamento
    do {
        printf("\nDigite a quantidade mínima do medicamento: ");
        scanf("%d", &lista[*total].quantidadeMinima);
        limparBuffer();
        if (lista[*total].quantidadeMinima < 0) {
            printf("\nQuantidade mínima inválida. Por favor, tente novamente.");
        }
    } while (lista[*total].quantidadeMinima < 0); // Garante que a quantidade mínima não seja negativa

    // Data de validade do medicamento
    do {
    printf("\nDigite a data de validade do medicamento (DD MM AAAA): ");
    scanf("%d %d %d", &lista[*total].dia, &lista[*total].mes, &lista[*total].ano);
    limparBuffer();
    if (lista[*total].dia < 1 || lista[*total].dia > 31 || 
        lista[*total].mes < 1 || lista[*total].mes > 12 || 
        lista[*total].ano < 2024) {
        printf("\nData de validade inválida. Por favor, tente novamente.");
    }
    } while (lista[*total].dia < 1 || lista[*total].dia > 31 || 
             lista[*total].mes < 1 || lista[*total].mes > 12 || 
             lista[*total].ano < 2024); // Garante que a data seja válida

    // Incrementa o total de medicamentos cadastrados
    (*total)++;
    
    printf("\nMedicamento cadastrado com sucesso!\n");
    printf("\n========================================\n");
}

void listarMedicamentos(Medicamento lista[], int total) {
    // Retorno Vazio por enquanto
    vazioPorEnquanto(lista, total);

    // Lista os medicamentos cadastrados
    printf("\n========================================\n");
    printf("\nLista de Medicamentos Cadastrados:\n");
    for (int i = 0; i < total; i++) {
        printf("\nID: %d\n", lista[i].id);
        printf("Nome: %s\n", lista[i].nome);
        printf("Quantidade: %d\n", lista[i].quantidade);
        printf("Quantidade Mínima: %d\n", lista[i].quantidadeMinima);
        printf("Data de Validade: %02d/%02d/%04d\n", lista[i].dia, lista[i].mes, lista[i].ano);
    }
    printf("\nFim da listagem de medicamentos!\n");
    printf("\n========================================\n");
}

void emitirAlertas(Medicamento lista[], int total) {
    // Implementação futura
}

void mostrarEstatisticas(Medicamento lista[], int total) {
    // Retorno vazio por enquanto
    vazioPorEnquanto(lista, total);

    // Declaração de variáveis para estatísticas
    int somaEstoque = 0;
    int medicamentosAbaixoMinimo = 0;
    int maiorEstoque = 0;
    int indiceMaior = 0;
    int menorEstoque = 0;
    int indiceMenor = 0;

    // Cálculo das estatísticas
    for (int i = 0; i < total; i++) {
        
        // Soma do estoque
        somaEstoque += lista[i].quantidade;

        // Contagem de medicamentos abaixo do estoque mínimo
        if (lista[i].quantidade < lista[i].quantidadeMinima) {
            medicamentosAbaixoMinimo++;
        }

        // Verificação do maior e menor estoque
        if (i == 0 || lista[i].quantidade > maiorEstoque) {
            maiorEstoque = lista[i].quantidade;
            indiceMaior = i;
        }

        if (i == 0 || lista[i].quantidade < menorEstoque) {
            menorEstoque = lista[i].quantidade;
            indiceMenor = i;
        }
    }

    // Media do estoque
    double mediaEstoque = (double)somaEstoque / total;

    // Exibição das estatísticas
    printf("\n========================================\n");
    printf("\nTotal de medicamentos cadastrados: %d\n", total);
    printf("Quantidade total em estoque: %d\n", somaEstoque);
    printf("Quantidade média em estoque: %.2f\n", mediaEstoque);
    printf("Medicamentos abaixo do estoque minimo: %d\n", medicamentosAbaixoMinimo);
    printf("Medicamento com maior estoque: %s (Quantidade: %d)\n", lista[indiceMaior].nome, maiorEstoque);
    printf("Medicamento com menor estoque: %s (Quantidade: %d)\n", lista[indiceMenor].nome, menorEstoque);
    printf("\n========================================\n");
}

void simularVenda(Medicamento lista[], int total) {
    printf("\n========================================\n");
    printf("\nSimulação de Venda de Medicamento\n");
    
    // Retorno vazio por enquanto
    vazioPorEnquanto(lista, total);

    // Leitura do ID do medicamento a ser vendido
    int idVenda;
    
    do { 
        printf("\nDigite o ID do medicamento a ser vendido: ");
        scanf("%d", &idVenda);
        limparBuffer();
        if (idVenda < 1 || idVenda > total + 1) {
            printf("\nID inválido. Por favor, tente novamente.");
        }
    } while (idVenda < 1 || idVenda > total + 1); // Garante que o ID seja válido

    // Busca do medicamento pelo ID
    int indiceVenda = idVenda - 1;
    printf("\nMedicamento selecionado: %s (Quantidade em estoque: %d)\n", lista[indiceVenda].nome, lista[indiceVenda].quantidade);
    int quantidadeVenda;
    
    // Leitura da quantidade a ser vendida
    do {
        printf("\nDigite a quantidade a ser vendida: ");
        scanf("%d", &quantidadeVenda);
        limparBuffer();
        if (quantidadeVenda < 1 || quantidadeVenda > lista[indiceVenda].quantidade) {
            printf("\nQuantidade inválida. Por favor, tente novamente.");
        }
    } while (quantidadeVenda < 1 || quantidadeVenda > lista[indiceVenda].quantidade); 
    // Garante que a quantidade seja positiva e não exceda o estoque

    // Atualização do estoque
    lista[indiceVenda].quantidade -= quantidadeVenda;
    printf("\nVenda realizada com sucesso!\n");
    
    // Checa se o estoque está abaixo do mínimo
    if (lista[indiceVenda].quantidade < lista[indiceVenda].quantidadeMinima) {
        printf("\nAlerta!!! O estoque do medicamento %s está abaixo do mínimo!\n", lista[indiceVenda].nome);
    }
    printf("\n========================================\n");
}

void exportarInventario(Medicamento lista[], int total) {
    // Implementação futura
}

/*
================================================================================
PROJETO: Sistema de Gerenciamento de Clinica
DISCIPLINA: Algoritmos e Programacao I
ALUNOS: Eduardo Luiz Wittmann, Nicolas Bizinotto Lacerda, Franco Mascarelo Ortiz
PROFESSORA: Me Neiva Larisane Kuyven
DATA: Novembro/2025

Este arquivo contem as funcoes de estoque de medicamentos: cadastrar, listar, alertas,
estatisticas, simular venda, exportar e importar inventario.
================================================================================
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "../include/estoque.hpp"
#include "../include/utils.hpp"

void cadastrarMedicamento(Medicamento lista[], int *total) {
    // Puxar informacoes do CSV para lista (se necessario)
    importarInventario(lista, total);
    
    printf("\n========================================\n");
    printf("\nCadastro de Medicamento\n");
    
    // ID automatico baseado no total de medicamentos cadastrados
    lista[*total].id = *total + 1;

    // Nome do medicamento
    do {
        printf("\nDigite o nome do medicamento: ");
        fgets(lista[*total].nome, sizeof(lista[*total].nome), stdin);
        if (strlen(lista[*total].nome) <= 1) {
            printf("\nNome invalido. Por favor, tente novamente.");
        }
    } while (strlen(lista[*total].nome) <= 1); // Garante que o nome nao seja vazio
    
    // Remove o caractere de nova linha lido pelo fgets  
    lista[*total].nome[strcspn(lista[*total].nome, "\n")] = '\0';

    // Quantidade do medicamento
    do {
        printf("\nDigite a quantidade do medicamento: ");
        scanf("%d", &lista[*total].quantidade);
        limparBuffer();
        if (lista[*total].quantidade <= 0) {
            printf("\nQuantidade invalida. Por favor, tente novamente.");
        }
    } while (lista[*total].quantidade <= 0); // Garante que a quantidade nao seja negativa
 
    // Quantidade minima do medicamento
    do {
        printf("\nDigite a quantidade minima do medicamento: ");
        scanf("%d", &lista[*total].quantidadeMinima);
        limparBuffer();
        if (lista[*total].quantidadeMinima < 0) {
            printf("\nQuantidade minima invalida. Por favor, tente novamente.");
        }
    } while (lista[*total].quantidadeMinima < 0); // Garante que a quantidade minima nao seja negativa

    // Data de validade do medicamento
    do {
    printf("\nDigite a data de validade do medicamento (DD MM AAAA): ");
    printf("\nExemplo: 25 11 2025 (separe dia, mes e ano com ESPACOS): ");
    scanf("%d %d %d", &lista[*total].dia, &lista[*total].mes, &lista[*total].ano);
    limparBuffer();
    if (lista[*total].dia < 1 || lista[*total].dia > 31 || 
        lista[*total].mes < 1 || lista[*total].mes > 12 || 
        lista[*total].ano < 2024) {
        printf("\n*** ERRO: Data invalida! ***");
        printf("\n    - Dia deve estar entre 01 e 31");
        printf("\n    - Mes deve estar entre 01 e 12");
        printf("\n    - Ano deve ser maior ou igual a 2024");
        printf("\n    - NAO esqueca dos ESPACOS entre os numeros!\n");
    }
    } while (lista[*total].dia < 1 || lista[*total].dia > 31 || 
             lista[*total].mes < 1 || lista[*total].mes > 12 || 
             lista[*total].ano < 2024); // Garante que a data seja valida

    // Incrementa o total de medicamentos cadastrados
    (*total)++;
    
    printf("\nMedicamento cadastrado com sucesso!\n");
    printf("\n========================================\n");

    exportarInventario(lista, *total);
}

void listarMedicamentos(Medicamento lista[], int total) {
    // Puxar informacoes do CSV para lista (se necessario)
    importarInventario(lista, &total);

    // Lista os medicamentos cadastrados
    printf("\n========================================\n");
    printf("\nLista de Medicamentos Cadastrados:\n");
    for (int i = 0; i < total; i++) {
        printf("\nID: %d\n", lista[i].id);
        printf("Nome: %s\n", lista[i].nome);
        printf("Quantidade: %d\n", lista[i].quantidade);
        printf("Quantidade Minima: %d\n", lista[i].quantidadeMinima);
        printf("Data de Validade: %02d/%02d/%04d\n", lista[i].dia, lista[i].mes, lista[i].ano);
    }
    printf("\nFim da listagem de medicamentos!\n");
    printf("\n========================================\n");
}

void emitirAlertas(Medicamento lista[], int total) {
    // Puxar informacoes do CSV para lista (se necessario)
    importarInventario(lista, &total);

    // Le a data atual
    int diaAtual, mesAtual, anoAtual;
    printf("\nDigite a data atual (DD MM AAAA): ");
    scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);
    limparBuffer();

    // Verifica e exibe os medicamentos com estoque abaixo do minimo
    printf("\n========================================\n");
    printf("\nAlertas de Medicamentos com Estoque Abaixo do Minimo:\n");
    
    bool encontrouAlerta = false;
    for (int i = 0; i < total; i++) {
        if (lista[i].quantidade < lista[i].quantidadeMinima) {
            printf("\nID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Quantidade: %d\n", lista[i].quantidade);
            printf("Quantidade Minima: %d\n", lista[i].quantidadeMinima);
            printf("Data de Validade: %02d/%02d/%04d\n", lista[i].dia, lista[i].mes, lista[i].ano);
            encontrouAlerta = true;
        }
    }
    if (!encontrouAlerta) {
        printf("\nNenhum medicamento com estoque abaixo do minimo.\n");
    }
    printf("\n========================================\n");

    // Verifica e exibe os medicamentos com validade proxima (dentro de 30 dias)
    printf("\nAlertas de Medicamentos com Validade Proxima (dentro de 30 dias):\n");
    encontrouAlerta = false;
    for (int i = 0; i < total; i++) {
        // Simulacao de verificacao de validade proxima
        if (lista[i].ano == anoAtual && lista[i].mes == mesAtual) { 
            printf("\nID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Quantidade: %d\n", lista[i].quantidade);
            printf("Quantidade Minima: %d\n", lista[i].quantidadeMinima);
            printf("Data de Validade: %02d/%02d/%04d\n", lista[i].dia, lista[i].mes, lista[i].ano);
            encontrouAlerta = true;
        }
    }
    if (!encontrouAlerta) {
        printf("\nNenhum medicamento com validade proxima.\n");
    }
    printf("\n========================================\n");

    // Verifica e exibe os medicamentos vencidos
    printf("\nAlertas de Medicamentos Vencidos:\n");
    encontrouAlerta = false;
    for (int i = 0; i < total; i++) {
        // Simulacao de verificacao de medicamentos vencidos
        if (lista[i].ano < anoAtual || 
           (lista[i].ano == anoAtual && lista[i].mes < mesAtual) || 
           (lista[i].ano == anoAtual && lista[i].mes == mesAtual && lista[i].dia < diaAtual)) {
            printf("\nID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Quantidade: %d\n", lista[i].quantidade);
            printf("Quantidade Minima: %d\n", lista[i].quantidadeMinima);
            printf("Data de Validade: %02d/%02d/%04d\n", lista[i].dia, lista[i].mes, lista[i].ano);
            encontrouAlerta = true;
        }
    }
    if (!encontrouAlerta) {
        printf("\nNenhum medicamento vencido.\n");
    }
    printf("\n========================================\n");

    // Fim dos alertas
}

void mostrarEstatisticas(Medicamento lista[], int total) {
    // Puxar informacoes do CSV para lista (se necessario)
    importarInventario(lista, &total);

    // Declaracao de variaveis para estatisticas
    int somaEstoque = 0;
    int medicamentosAbaixoMinimo = 0;
    int maiorEstoque = 0;
    int indiceMaior = 0;
    int menorEstoque = 0;
    int indiceMenor = 0;

    // Calculo das estatisticas
    for (int i = 0; i < total; i++) {
        
        // Soma do estoque
        somaEstoque += lista[i].quantidade;

        // Contagem de medicamentos abaixo do estoque minimo
        if (lista[i].quantidade < lista[i].quantidadeMinima) {
            medicamentosAbaixoMinimo++;
        }

        // Verificacao do maior e menor estoque
        if (i == 0 || lista[i].quantidade > maiorEstoque) {
            maiorEstoque = lista[i].quantidade;
            indiceMaior = i;
        }

        if (i == 0 || lista[i].quantidade < menorEstoque) {
            menorEstoque = lista[i].quantidade;
            indiceMenor = i;
        }
    }

    // Verifica se existe algum medicamento cadastrado
    if (total == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        printf("\n========================================\n");
        return;
    }

    // Media do estoque
    double mediaEstoque = (double)somaEstoque / total;

    // Exibicao das estatisticas
    printf("\n========================================\n");
    printf("\nTotal de medicamentos cadastrados: %d\n", total);
    printf("Quantidade total em estoque: %d\n", somaEstoque);
    printf("Quantidade media em estoque: %.2f\n", mediaEstoque);
    printf("Medicamentos abaixo do estoque minimo: %d\n", medicamentosAbaixoMinimo);
    printf("Medicamento com maior estoque: %s (Quantidade: %d)\n", lista[indiceMaior].nome, maiorEstoque);
    printf("Medicamento com menor estoque: %s (Quantidade: %d)\n", lista[indiceMenor].nome, menorEstoque);
    printf("\n========================================\n");
}

void simularVenda(Medicamento lista[], int total) {
    // Puxar informacoes do CSV para lista (se necessario)
    importarInventario(lista, &total);
    
    printf("\n========================================\n");
    printf("\nSimulacao de Venda de Medicamento\n");
    
    // Retorno vazio por enquanto
    vazioPorEnquanto(lista, total);

    // Leitura do ID do medicamento a ser vendido
    int idVenda;
    
    do { 
        printf("\nDigite o ID do medicamento a ser vendido: ");
        scanf("%d", &idVenda);
        limparBuffer();
        if (idVenda < 1 || idVenda > total + 1) {
            printf("\nID invalido. Por favor, tente novamente.");
        }
    } while (idVenda < 1 || idVenda > total + 1); // Garante que o ID seja valido

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
            printf("\nQuantidade invalida. Por favor, tente novamente.");
        }
    } while (quantidadeVenda < 1 || quantidadeVenda > lista[indiceVenda].quantidade); 
    // Garante que a quantidade seja positiva e nao exceda o estoque

    // Atualizacao do estoque
    lista[indiceVenda].quantidade -= quantidadeVenda;
    printf("\nVenda realizada com sucesso!\n");
    
    // Checa se o estoque esta abaixo do minimo
    if (lista[indiceVenda].quantidade < lista[indiceVenda].quantidadeMinima) {
        printf("\nAlerta!!! O estoque do medicamento %s esta abaixo do minimo!\n", lista[indiceVenda].nome);
    }
    printf("\n========================================\n");

    // Exporta o inventario atualizado
    exportarInventario(lista, total);
}

void exportarInventario(Medicamento lista[], int total) {
    // Exportacao para arquivo CSV (salva em data/ no diretorio do projeto)
    MKDIR("data");
    const char *caminho = "data\\inventario_medicamentos.csv";
    FILE *arquivo = fopen(caminho, "w");
    
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("\nErro ao criar o arquivo de inventario.\n");
        return;
    }

    // Cabecalho do arquivo CSV
    fprintf(arquivo, "ID;Nome;Quantidade;QuantidadeMinima;DataValidade\n");

    // Escrita dos dados dos medicamentos no arquivo
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%d;%s;%d;%d;%02d/%02d/%04d\n", 
                lista[i].id, 
                lista[i].nome, 
                lista[i].quantidade, 
                lista[i].quantidadeMinima, 
                lista[i].dia, 
                lista[i].mes, 
                lista[i].ano);
    }
    fclose(arquivo);
    printf("\nInventario exportado com sucesso para '%s'!\n", caminho);
    printf("\n========================================\n");
}

void importarInventario(Medicamento lista[], int *total) {
    // Carregamento do arquivo CSV (se existir)
    // Tenta carregar do diretorio de dados primario (../data/) e cai para o cwd
    const char *caminho1 = "data\\inventario_medicamentos.csv";
    const char *caminho2 = "inventario_medicamentos.csv";
    FILE *arquivo = fopen(caminho1, "r");
    if (arquivo == NULL) {
        arquivo = fopen(caminho2, "r");
    }
    if (arquivo == NULL) {
        // Arquivo nao existe, nada a carregar
        printf("\nNenhum inventario encontrado para carregar.\n");
        return;
    }

    // Retorno vazio por enquanto
    vazioPorEnquanto(lista, *total);

    char linha[200];
    // Ignora o cabecalho
    fgets(linha, sizeof(linha), arquivo);
    *total = 0;
    // Le cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        Medicamento med;
        // Parse da linha lida
        sscanf(linha, "%d;%49[^;];%d;%d;%d/%d/%d", 
               &med.id, 
               med.nome, 
               &med.quantidade, 
               &med.quantidadeMinima, 
               &med.dia, 
               &med.mes, 
               &med.ano);
        // Adiciona o medicamento a lista
        lista[*total] = med;
        (*total)++;
    }

    fclose(arquivo);

    printf("\nInventario carregado com sucesso!\n");
    printf("\n========================================\n"); 
}

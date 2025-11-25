#include <iostream>
#include <cstring>
#include <stdio.h>
#include "../include/estoque.hpp"
#include "../include/utils.hpp"
#ifdef _WIN32
    #include <windows.h>  // Para SetConsoleOutputCP e SetConsoleCP
#endif

void cadastrarMedicamento(Medicamento lista[], int *total) {
    // Puxar informações do CSV para lista (se necessário)
    importarInventario(lista, total);
    
    printf("\n========================================\n");
    printf("\nCadastro de Medicamento\n");
    
    // ID automático baseado no total de medicamentos cadastrados
    lista[*total].id = *total + 1;

    // Nome do medicamento
    do {
        printf("\nDigite o nome do medicamento: ");
        fgets(lista[*total].nome, sizeof(lista[*total].nome), stdin);
        if (strlen(lista[*total].nome) <= 1) {
            printf("\nNome invalido. Por favor, tente novamente.");
        }
    } while (strlen(lista[*total].nome) <= 1); // Garante que o nome não seja vazio
    
    // Remove o caractere de nova linha lido pelo fgets  
    lista[*total].nome[strcspn(lista[*total].nome, "\n")] = '\0';

    // Quantidade do medicamento
    do {
        printf("\nDigite a quantidade do medicamento: ");
        scanf("%d", &lista[*total].quantidade);
        limparBuffer();
        if (lista[*total].quantidade <= 0) {
            printf("\nQuantidade inválida. Por favor, tente novamente.");
        }
    } while (lista[*total].quantidade <= 0); // Garante que a quantidade não seja negativa
 
    // Quantidade mínima do medicamento
    do {
        printf("\nDigite a quantidade minima do medicamento: ");
        scanf("%d", &lista[*total].quantidadeMinima);
        limparBuffer();
        if (lista[*total].quantidadeMinima < 0) {
            printf("\nQuantidade minima invalida. Por favor, tente novamente.");
        }
    } while (lista[*total].quantidadeMinima < 0); // Garante que a quantidade mínima não seja negativa

    // Data de validade do medicamento
    do {
    printf("\nDigite a data de validade do medicamento (DD MM AAAA): ");
    printf("\nExemplo: 25 11 2025 (separe dia, mês e ano com ESPAÇOS): ");
    scanf("%d %d %d", &lista[*total].dia, &lista[*total].mes, &lista[*total].ano);
    limparBuffer();
    if (lista[*total].dia < 1 || lista[*total].dia > 31 || 
        lista[*total].mes < 1 || lista[*total].mes > 12 || 
        lista[*total].ano < 2024) {
        printf("\n*** ERRO: Data invalida! ***");
        printf("\n    - Dia deve estar entre 01 e 31");
        printf("\n    - Mês deve estar entre 01 e 12");
        printf("\n    - Ano deve ser maior ou igual a 2024");
        printf("\n    - NÃO esqueça dos ESPAÇOS entre os números!\n");
    }
    } while (lista[*total].dia < 1 || lista[*total].dia > 31 || 
             lista[*total].mes < 1 || lista[*total].mes > 12 || 
             lista[*total].ano < 2024); // Garante que a data seja válida

    // Incrementa o total de medicamentos cadastrados
    (*total)++;
    
    printf("\nMedicamento cadastrado com sucesso!\n");
    printf("\n========================================\n");

    exportarInventario(lista, *total);
}

void listarMedicamentos(Medicamento lista[], int total) {
    // Puxar informações do CSV para lista (se necessário)
    importarInventario(lista, &total);
    
    // Retorno Vazio por enquanto
    vazioPorEnquanto(lista, total);

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
    // Puxar informações do CSV para lista (se necessário)
    importarInventario(lista, &total);
    
    // Retorno vazio por enquanto
    vazioPorEnquanto(lista, total);

    // Lê a data atual
    int diaAtual, mesAtual, anoAtual;
    printf("\nDigite a data atual (DD MM AAAA): ");
    scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);
    limparBuffer();

    // Verifica e exibe os medicamentos com estoque abaixo do mínimo
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
        printf("\nNenhum medicamento com estoque abaixo do mínimo.\n");
    }
    printf("\n========================================\n");

    // Verifica e exibe os medicamentos com validade próxima (dentro de 30 dias)
    printf("\nAlertas de Medicamentos com Validade Próxima (dentro de 30 dias):\n");
    encontrouAlerta = false;
    for (int i = 0; i < total; i++) {
        // Simulação de verificação de validade próxima
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
        printf("\nNenhum medicamento com validade próxima.\n");
    }
    printf("\n========================================\n");

    // Verifica e exibe os medicamentos vencidos
    printf("\nAlertas de Medicamentos Vencidos:\n");
    encontrouAlerta = false;
    for (int i = 0; i < total; i++) {
        // Simulação de verificação de medicamentos vencidos
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
    // Puxar informações do CSV para lista (se necessário)
    importarInventario(lista, &total);
    
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
    // Puxar informações do CSV para lista (se necessário)
    importarInventario(lista, &total);
    
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
            printf("\nQuantidade invalida. Por favor, tente novamente.");
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

    // Exporta o inventário atualizado
    exportarInventario(lista, total);
}

void exportarInventario(Medicamento lista[], int total) {
    // Exportação para arquivo CSV (salva em ../data)
    MKDIR("..\\data");  
    const char *caminho = "..\\data\\inventario_medicamentos.csv";
    FILE *arquivo = fopen(caminho, "w");
    
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("\nErro ao criar o arquivo de inventario.\n");
        return;
    }

    // Cabeçalho do arquivo CSV
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
    printf("\nInventário exportado com sucesso para '%s'!\n", caminho);
    printf("\n========================================\n");
}

void importarInventario(Medicamento lista[], int *total) {
    // Retorno vazio por enquanto
    vazioPorEnquanto(lista, *total);
    
    // Carregamento do arquivo CSV (se existir)
    FILE *arquivo = fopen("inventario_medicamentos.csv", "r");
    if (arquivo == NULL) {
        // Arquivo não existe, nada a carregar
        printf("\nNenhum inventario encontrado para carregar.\n");
        return;
    }

    char linha[200];
    // Ignora o cabeçalho
    fgets(linha, sizeof(linha), arquivo);
    *total = 0;
    // Lê cada linha do arquivo
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
        // Adiciona o medicamento à lista
        lista[*total] = med;
        (*total)++;
    }

    fclose(arquivo);

    printf("\nInventário carregado com sucesso!\n");
    printf("\n========================================\n"); 
}

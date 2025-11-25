/*
================================================================================
PROJETO: Sistema de Gerenciamento de Clinica
DISCIPLINA: Algoritmos e Programacao I
ALUNOS: Eduardo Luiz Wittmann, Nicolas Bizinotto Lacerda, Franco Mascarelo Ortiz
PROFESSORA: Me Neiva Larisane Kuyven
DATA: Novembro/2025

Este arquivo contem o menu principal e a interface do sistema.
Responsavel por exibir opcoes e chamar as funcoes de estoque e dosagem.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifdef _WIN32
    #include <windows.h>  // Para SetConsoleOutputCP e SetConsoleCP
#endif
#include "../include/estoque.hpp"
#include "../include/dosagem.hpp"

// ===========================================
// FUNCOES DE INTERFACE
// ===========================================

// Limpa a tela do console
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #endif
}

// Aguarda o usuario pressionar ENTER
void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Exibe o cabecalho do sistema
void mostrarCabecalho() {
    printf("========================================================\n");
    printf("                                                        \n");
    printf("         SISTEMA DE GERENCIAMENTO DE CLINICA            \n");
    printf("         Controle de Estoque de Medicamentos            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
}

// Exibe o menu com todas as opcoes
void mostrarMenuPrincipal() {
    printf("+------------------------------------------------------+\n");
    printf("|                  MENU PRINCIPAL                      |\n");
    printf("+------------------------------------------------------+\n");
    printf("|                                                      |\n");
    printf("|   1 - Cadastrar Medicamento                          |\n");
    printf("|   2 - Listar Medicamentos                            |\n");
    printf("|   3 - Emitir Alertas de Estoque                      |\n");
    printf("|   4 - Mostrar Estatisticas                          |\n");
    printf("|   5 - Simular Venda                                  |\n");
    printf("|   6 - Exportar Inventario                           |\n");
    printf("|   7 - Importar Inventario                           |\n");
    printf("|   8 - Calcular Dosagem de Medicamento               |\n");
    printf("|                                                      |\n");
    printf("|   0 - Sair do Sistema                                |\n");
    printf("|                                                      |\n");
    printf("+------------------------------------------------------+\n");
    printf("\n  Digite sua opcao: ");
}

// Le a opcao do menu e valida se e um numero
int lerOpcao() {
    int opcao, resultado;
    
    while (1) {
        resultado = scanf("%d", &opcao);
        while (getchar() != '\n');  // Limpa o buffer
        
        if (resultado == 1) {
            return opcao;
        }
        printf("\n  Entrada invalida! Digite um numero: ");
    }
}

// Exibe um titulo formatado
void mostrarTituloOpcao(const char* titulo) {
    printf("========================================================\n");
    printf("  %s\n", titulo);
    printf("========================================================\n");
    printf("\n");
}

// ===========================================
// FUNCAO PRINCIPAL
// ===========================================

int main() {
    // Configuracao para aceitar acentos (á, é, í, ó, ú, ã, õ, ç)
    setlocale(LC_ALL, "Portuguese");
    
    #ifdef _WIN32
        // Configura console do Windows para UTF-8 (entrada e saida)
        system("chcp 65001 > nul");
        // Configura modo de saida do console para UTF-8
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
    #endif
    
    // Declaracao de variaveis
    Medicamento lista[100];  // Vetor para armazenar ate 100 medicamentos
    int total = 0;           // Contador de medicamentos cadastrados
    int opcao;               // Opcao escolhida pelo usuario
    int continuar = 1;       // Controla o loop do menu (1 = continua, 0 = sai)
    
    // Loop principal do sistema
    while (continuar) {
        limparTela();
        mostrarCabecalho();
        mostrarMenuPrincipal();
        opcao = lerOpcao();
        
        limparTela();
        mostrarCabecalho();
        
        // Switch-case para executar a funcao escolhida
        switch (opcao) {
            case 1:
                mostrarTituloOpcao("CADASTRAR NOVO MEDICAMENTO");
                cadastrarMedicamento(lista, &total);  // &total = passagem por referencia
                pausar();
                break;
                
            case 2:
                mostrarTituloOpcao("LISTA DE MEDICAMENTOS");
                listarMedicamentos(lista, total);
                pausar();
                break;
                
            case 3:
                mostrarTituloOpcao("ALERTAS DE ESTOQUE");
                emitirAlertas(lista, total);
                pausar();
                break;
                
            case 4:
                mostrarTituloOpcao("ESTATISTICAS DO ESTOQUE");
                mostrarEstatisticas(lista, total);
                pausar();
                break;
                
            case 5:
                mostrarTituloOpcao("SIMULAR VENDA");
                simularVenda(lista, total);
                pausar();
                break;
                
            case 6:
                mostrarTituloOpcao("EXPORTAR INVENTARIO");
                exportarInventario(lista, total);
                pausar();
                break;
                
            case 7:
                mostrarTituloOpcao("IMPORTAR INVENTARIO");
                importarInventario(lista, &total);
                pausar();
                break;
                
            case 8:
                mostrarTituloOpcao("CALCULAR DOSAGEM DE MEDICAMENTO");
                calcularDoseMedicamento();
                pausar();
                break;
                
            case 0:
                mostrarTituloOpcao("ENCERRANDO SISTEMA");
                printf("  Obrigado por usar o Sistema de Clinica!\n");
                printf("  Ate a proxima!\n");
                printf("\n");
                continuar = 0;  // Para o loop
                break;
                
            default:
                mostrarTituloOpcao("ERRO - OPCAO INVALIDA");
                printf("  Por favor, escolha uma opcao entre 0 e 8.\n");
                pausar();
                break;
        }
    }
    
    return 0;
}

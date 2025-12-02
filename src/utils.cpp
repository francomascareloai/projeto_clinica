/*
================================================================================
PROJETO: Sistema de Gerenciamento de Clinica
DISCIPLINA: Algoritmos e Programacao I
ALUNOS: Eduardo Luiz Wittmann, Nicolas Bizinotto Lacerda, Franco Mascarelo Ortiz
PROFESSORA: Me Neiva Larisane Kuyven
DATA: Novembro/2025

    Este arquivo contem as funcoes de utilidades gerais: limpar buffer, retorno vazio, etc.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../include/utils.hpp"
#include "../include/estoque.hpp"

// ===========================================
// FUNCOES GERAIS
// ===========================================

// Limpa o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Retorno vazio por enquanto
void vazioPorEnquanto(Medicamento lista[], int total) {
        if (total == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }
}

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
    printf("|   4 - Mostrar Estatisticas                           |\n");
    printf("|   5 - Simular Venda                                  |\n");
    printf("|   6 - Exportar Inventario                            |\n");
    printf("|   7 - Importar Inventario                            |\n");
    printf("|   8 - Calcular Dosagem de Medicamento                |\n");
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

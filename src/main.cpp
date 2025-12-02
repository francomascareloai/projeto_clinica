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
#include "../include/utils.hpp"

// ===========================================
// FUNCAO PRINCIPAL
// ===========================================

int main() {
    // Configuracao para aceitar acentos (a, e, i, o, u, a, o, c)
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

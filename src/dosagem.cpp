/*
================================================================================
PROJETO: Sistema de Gerenciamento de Clinica
DISCIPLINA: Algoritmos e Programacao I
ALUNOS: Eduardo Luiz Wittmann, Nicolas Bizinotto Lacerda, Franco Mascarelo Ortiz
PROFESSORA: Me Neiva Larisane Kuyven
DATA: Novembro/2025

Este arquivo contem as funcoes de dosagem de medicamentos: calculo de dose baseado 
em idade, peso, genero e sintomas.
================================================================================
*/

#include <stdio.h>
#include <math.h> 
#include <ctype.h>

void calcularDoseMedicamento() {
    int idade = 0, medic;
    float dose = 0, peso = 0;
    char genero, sinto, repetir;
    
  printf("\n=========================================\n");
    printf("\nBem-vindo a Calculadora de Dosagem de Medicamentos!\n");
   
    // Loop principal para permitir multiplos calculos
  do {
      // Entrada de dados do paciente
      do { // Idade em meses
          printf("\nQual a idade do paciente em meses?\n");
          scanf("%d", &idade);
          if (idade < 0 || idade > 1440) {
              printf("Digite uma idade valida!!\n");
          }
      } while (idade < 0 || idade > 1440);

    do { // Genero do paciente
          printf("\nQual o genero do paciente (M/F)?\n");
          scanf(" %c", &genero);
          genero = toupper(genero);

          if (genero == 'M') {
              printf("Genero: Masculino\n");
          } else if (genero == 'F') {
              printf("Genero: Feminino\n");
          } else {
              printf("Opcao invalida!!\n");
          }
      } while (genero != 'M' && genero != 'F'); 

      do { // Sintomas do paciente
          printf("Paciente apresenta sintomas? (S/N)\n");
          scanf(" %c", &sinto);
          if (sinto != 'S' && sinto != 's' && sinto != 'N' && sinto != 'n') {
              printf("Opcao invalida! Digite S para sim ou N para nao.\n");
          }
      } while (sinto != 'S' && sinto != 's' && sinto != 'N' && sinto != 'n');

      do { // Peso do paciente
          printf("Qual o peso do paciente (em kg)?\n");
          scanf("%f", &peso);
          if (peso < 1) {
              printf("Peso invalido! O peso deve ser maior que 1 kg.\n");
          }
      } while (peso < 1);

    // Calculo da dosagem caso o paciente apresente sintomas
      if (sinto == 'S' || sinto == 's') { 
          
        // Selecao do medicamento
        printf("Escolha uma medicacao para calcular \n");
        printf(" 1 - Paracetamol \n 2 - Ibuprofeno \n 3 - Amoxicilina \n 4 - Dipirona \n 5 - Metformina \n 6 - Prednisona \n 7 - Salbutamol \n 8 - Omeprazol \n 9 - Loratadina \n 10 - Dexametasona\n");
        scanf("%d", &medic);
		
        
        switch (medic){ 
            case 1: // Paracetamol
                if (idade >= 3) { // Idade em meses
                    dose = peso * 15;
                    printf("\nCalculo para Paracetamol:\n");
                    printf("A dose recomendada e de %.2f mg por dose.\n", dose);
                    printf("Posologia: A cada 6 horas.\n");
                } else {
                    printf("\nParacetamol nao e recomendado para menores de 3 meses. Consulte um medico.\n");
                }
              break; 

            case 2: // Ibuprofeno
                if (idade >= 6) { // Idade em meses
                    dose = peso * 10;
                    printf("\nCalculo para Ibuprofeno:\n");
                    printf("A dose recomendada e de %.2f mg por dose.\n", dose);
                    printf("Posologia: A cada 6 a 8 horas.\n");
                } else {
                    printf("\nIbuprofeno nao e recomendado para menores de 6 meses. Consulte um medico.\n");
                }
                break;

            case 3: // Amoxicilina
                dose = (peso * 25) / 2;
                printf("\nCalculo para Amoxicilina:\n");
                printf("A dose recomendada e de aproximadamente %.2f mg por dose.\n", dose);
                printf("Posologia: A cada 12 horas.\n");
                printf("AVISO: A dose de antibioticos deve ser SEMPRE confirmada por um medico.\n");
                break;

            case 4: // Dipirona
                dose = peso * 20;
                printf("\nCalculo para Dipirona:\n");
                printf("A dose recomendada e de %.2f mg por dose.\n", dose);
                printf("Posologia: A cada 6 horas.\n");
                break;

            case 5: // Metformina
                if (idade >= 120) { // 120 meses = 10 anos
                    dose = (peso * 12.5) / 2;
                    printf("\nCalculo para Metformina:\n");
                    printf("A dose de exemplo e de aproximadamente %.2f mg por dose.\n", dose);
                    printf("Posologia: Duas vezes ao dia, com as refeicoes.\n");
                    printf("AVISO: Uso exclusivo para tratamento de Diabetes Tipo 2 sob estrita supervisao medica.\n");
                } else {
                    printf("\nMetformina nao e indicada para esta faixa etaria. Consulte um medico.\n");
                }
                break;

            case 6: // Prednisona
                dose = peso * 1.5;
                printf("\nCalculo para Prednisona:\n");
                printf("A dose recomendada e de aproximadamente %.2f mg por dia.\n", dose);
                printf("Posologia: A dose diaria pode ser dividida em 1 ou 2 tomadas.\n");
                printf("AVISO: Corticoide deve ser usado com cautela e apenas por indicacao medica.\n");
                break;

            case 7: // Salbutamol
                dose = peso * 0.15;
                printf("\nCalculo para Salbutamol (oral):\n");
                printf("A dose recomendada e de aproximadamente %.3f mg por dose.\n", dose);
                printf("Posologia: A cada 6 a 8 horas. A forma inalatoria e mais comum.\n");
                break;

            case 8: // Omeprazol
                dose = peso * 1.5;
                printf("\nCalculo para Omeprazol:\n");
                printf("A dose recomendada e de aproximadamente %.2f mg por dia.\n", dose);
                printf("Posologia: 1 vez ao dia, antes do cafe da manha.\n");
                break;

            case 9: // Loratadina
                if (peso >= 30) {
                  dose = 10;
                } else {
                  dose = 5;
                }
                printf("\nCalculo para Loratadina:\n");
                printf("A dose recomendada e de %.2f mg por dia.\n", dose);
                printf("Posologia: 1 vez ao dia.\n");
                break;

            case 10: // Dexametasona
                dose = peso * 0.2;
                printf("\nCalculo para Dexametasona:\n");
                printf("A dose recomendada e de aproximadamente %.3f mg por dia.\n", dose);
                printf("Posologia: A dose diaria pode ser dividida. Uso estrito sob indicacao medica.\n");
                break;

            default: // Opcao invalida
                printf("\nOpcao de medicamento invalida!\n");
                break;
        }
      } else {
          // Caso o paciente nao apresente sintomas
          printf("\nComo o paciente nao apresenta sintomas, nenhuma dosagem sera indicada.\n");
      }
	
    // Pergunta se o usuario deseja repetir o calculo
    printf("\nDeseja calcular a dose para outro paciente? (S/N)\n");
    scanf(" %c", &repetir);

  } while (repetir == 'S' || repetir == 's'); // Fim do loop principal

  printf("\nPrograma finalizado. Obrigado!\n");
  printf("\n=========================================\n");
}

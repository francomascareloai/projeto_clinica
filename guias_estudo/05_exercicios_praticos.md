# EXERCICIOS PRATICOS COMBINADOS - Dev-C++

## PADRAO DEV-C++
- Declarar variaveis no INICIO
- Usar `system("pause");` antes do return
- Incluir `<stdlib.h>`

---

## EXERCICIO 1: VETOR - Ler N numeros e mostrar estatisticas
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[100];
    int n, i, soma, maior, menor, pares, impares;
    float media;
    
    soma = 0;
    pares = 0;
    impares = 0;
    
    printf("Quantos numeros? ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    maior = numeros[0];
    menor = numeros[0];
    
    for (i = 0; i < n; i++) {
        soma = soma + numeros[i];
        
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
        if (numeros[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    
    media = (float)soma / n;
    
    printf("\n=== ESTATISTICAS ===\n");
    printf("Soma: %d\n", soma);
    printf("Media: %.2f\n", media);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 2: VETOR - Ordenar e mostrar
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[10];
    int i, j, temp;
    
    printf("Digite 10 numeros:\n");
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    printf("\nOriginal: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    /* Bubble Sort - Crescente */
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    
    printf("\nCrescente: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    /* Bubble Sort - Decrescente */
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (vetor[j] < vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    
    printf("\nDecrescente: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 3: VETOR - Busca e contagem
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[10] = {5, 3, 8, 5, 2, 5, 9, 1, 5, 7};
    int busca, i, contador, posicoes[10], qtdPos;
    
    qtdPos = 0;
    
    printf("Vetor: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\n\nDigite o numero para buscar: ");
    scanf("%d", &busca);
    
    contador = 0;
    for (i = 0; i < 10; i++) {
        if (vetor[i] == busca) {
            posicoes[qtdPos] = i;
            qtdPos++;
            contador++;
        }
    }
    
    if (contador > 0) {
        printf("Encontrado %d vez(es)\n", contador);
        printf("Posicoes: ");
        for (i = 0; i < qtdPos; i++) {
            printf("%d ", posicoes[i]);
        }
        printf("\n");
    } else {
        printf("Nao encontrado\n");
    }
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 4: VETOR - Remover duplicados
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[10] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    int resultado[10];
    int i, j, existe, tamResultado;
    
    tamResultado = 0;
    
    printf("Original: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    for (i = 0; i < 10; i++) {
        existe = 0;
        for (j = 0; j < tamResultado; j++) {
            if (resultado[j] == vetor[i]) {
                existe = 1;
                break;
            }
        }
        
        if (existe == 0) {
            resultado[tamResultado] = vetor[i];
            tamResultado++;
        }
    }
    
    printf("\nSem duplicados: ");
    for (i = 0; i < tamResultado; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 5: LACOS - Calcular series
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float soma1, soma2, soma3;
    
    soma1 = 0;
    soma2 = 0;
    soma3 = 0;
    
    printf("Digite N: ");
    scanf("%d", &n);
    
    /* Serie 1: 1 + 2 + 3 + ... + N */
    for (i = 1; i <= n; i++) {
        soma1 = soma1 + i;
    }
    
    /* Serie 2: 1 + 1/2 + 1/3 + ... + 1/N */
    for (i = 1; i <= n; i++) {
        soma2 = soma2 + 1.0 / i;
    }
    
    /* Serie 3: 1 - 1/2 + 1/3 - 1/4 + ... */
    for (i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            soma3 = soma3 + 1.0 / i;
        } else {
            soma3 = soma3 - 1.0 / i;
        }
    }
    
    printf("\n1 + 2 + ... + %d = %.0f\n", n, soma1);
    printf("1 + 1/2 + ... + 1/%d = %.4f\n", n, soma2);
    printf("1 - 1/2 + 1/3 - ... = %.4f\n", soma3);
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 6: LACOS - Numeros perfeitos
```c
#include <stdio.h>
#include <stdlib.h>

/* Numero perfeito: soma dos divisores = numero
   Ex: 6 = 1 + 2 + 3 */

int main() {
    int n, i, j, soma;
    
    printf("Numeros perfeitos ate: ");
    scanf("%d", &n);
    
    printf("Numeros perfeitos: ");
    for (i = 2; i <= n; i++) {
        soma = 0;
        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                soma = soma + j;
            }
        }
        
        if (soma == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 7: MATRIZ - Ler e mostrar estatisticas
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3];
    int i, j, soma, maior, menor;
    int maiorLin, maiorCol, menorLin, menorCol;
    float media;
    
    soma = 0;
    
    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    
    maior = matriz[0][0];
    menor = matriz[0][0];
    maiorLin = 0;
    maiorCol = 0;
    menorLin = 0;
    menorCol = 0;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            soma = soma + matriz[i][j];
            
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                maiorLin = i;
                maiorCol = j;
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                menorLin = i;
                menorCol = j;
            }
        }
    }
    
    media = (float)soma / 9;
    
    printf("\n=== ESTATISTICAS ===\n");
    printf("Soma: %d\n", soma);
    printf("Media: %.2f\n", media);
    printf("Maior: %d em [%d][%d]\n", maior, maiorLin, maiorCol);
    printf("Menor: %d em [%d][%d]\n", menor, menorLin, menorCol);
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 8: MATRIZ - Soma das diagonais
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int i, j, somaPrincipal, somaSecundaria, somaAcima, somaAbaixo;
    
    somaPrincipal = 0;
    somaSecundaria = 0;
    somaAcima = 0;
    somaAbaixo = 0;
    
    printf("Matriz:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) {
                somaPrincipal = somaPrincipal + matriz[i][j];
            }
            if (j == 3 - i) {
                somaSecundaria = somaSecundaria + matriz[i][j];
            }
            if (j > i) {
                somaAcima = somaAcima + matriz[i][j];
            }
            if (i > j) {
                somaAbaixo = somaAbaixo + matriz[i][j];
            }
        }
    }
    
    printf("\nDiagonal principal: %d\n", somaPrincipal);
    printf("Diagonal secundaria: %d\n", somaSecundaria);
    printf("Acima da diagonal: %d\n", somaAcima);
    printf("Abaixo da diagonal: %d\n", somaAbaixo);
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 9: STRING - Validar senha
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char senha[50];
    int i, temMaiuscula, temMinuscula, temNumero, tamanho;
    
    temMaiuscula = 0;
    temMinuscula = 0;
    temNumero = 0;
    
    printf("Digite uma senha: ");
    scanf("%s", senha);
    
    tamanho = strlen(senha);
    
    for (i = 0; senha[i] != '\0'; i++) {
        if (senha[i] >= 'A' && senha[i] <= 'Z') {
            temMaiuscula = 1;
        }
        if (senha[i] >= 'a' && senha[i] <= 'z') {
            temMinuscula = 1;
        }
        if (senha[i] >= '0' && senha[i] <= '9') {
            temNumero = 1;
        }
    }
    
    printf("\n=== VERIFICACAO ===\n");
    printf("Tamanho: %d caracteres\n", tamanho);
    
    if (tamanho >= 8 && temMaiuscula && temMinuscula && temNumero) {
        printf("Senha FORTE!\n");
    } else {
        printf("Senha FRACA!\n");
        if (tamanho < 8) printf("- Precisa ter pelo menos 8 caracteres\n");
        if (!temMaiuscula) printf("- Precisa ter letra maiuscula\n");
        if (!temMinuscula) printf("- Precisa ter letra minuscula\n");
        if (!temNumero) printf("- Precisa ter numero\n");
    }
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 10: MENU COMPLETO com Vetores
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[100];
    int n, i, j, temp, opcao, busca, encontrado;
    int soma, maior, menor;
    float media;
    
    n = 0;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir elementos\n");
        printf("2 - Mostrar vetor\n");
        printf("3 - Calcular soma e media\n");
        printf("4 - Encontrar maior e menor\n");
        printf("5 - Ordenar crescente\n");
        printf("6 - Buscar elemento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Quantos elementos? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Elemento %d: ", i + 1);
                    scanf("%d", &vetor[i]);
                }
                printf("Elementos inseridos!\n");
                break;
                
            case 2:
                if (n == 0) {
                    printf("Vetor vazio!\n");
                } else {
                    printf("Vetor: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", vetor[i]);
                    }
                    printf("\n");
                }
                break;
                
            case 3:
                if (n == 0) {
                    printf("Vetor vazio!\n");
                } else {
                    soma = 0;
                    for (i = 0; i < n; i++) {
                        soma = soma + vetor[i];
                    }
                    media = (float)soma / n;
                    printf("Soma: %d\n", soma);
                    printf("Media: %.2f\n", media);
                }
                break;
                
            case 4:
                if (n == 0) {
                    printf("Vetor vazio!\n");
                } else {
                    maior = vetor[0];
                    menor = vetor[0];
                    for (i = 1; i < n; i++) {
                        if (vetor[i] > maior) maior = vetor[i];
                        if (vetor[i] < menor) menor = vetor[i];
                    }
                    printf("Maior: %d\n", maior);
                    printf("Menor: %d\n", menor);
                }
                break;
                
            case 5:
                if (n == 0) {
                    printf("Vetor vazio!\n");
                } else {
                    for (i = 0; i < n - 1; i++) {
                        for (j = 0; j < n - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                temp = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = temp;
                            }
                        }
                    }
                    printf("Vetor ordenado!\n");
                }
                break;
                
            case 6:
                if (n == 0) {
                    printf("Vetor vazio!\n");
                } else {
                    printf("Digite o elemento a buscar: ");
                    scanf("%d", &busca);
                    encontrado = -1;
                    for (i = 0; i < n; i++) {
                        if (vetor[i] == busca) {
                            encontrado = i;
                            break;
                        }
                    }
                    if (encontrado != -1) {
                        printf("Encontrado na posicao %d\n", encontrado);
                    } else {
                        printf("Nao encontrado\n");
                    }
                }
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 11: Calcular notas de alunos com vetor
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    float notas[50];
    int n, i, aprovados, reprovados, recuperacao;
    float soma, media, mediaGeral, maior, menor;
    
    aprovados = 0;
    reprovados = 0;
    recuperacao = 0;
    soma = 0;
    
    printf("Quantos alunos? ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        do {
            printf("Nota do aluno %d (0-10): ", i + 1);
            scanf("%f", &notas[i]);
            if (notas[i] < 0 || notas[i] > 10) {
                printf("Nota invalida!\n");
            }
        } while (notas[i] < 0 || notas[i] > 10);
    }
    
    maior = notas[0];
    menor = notas[0];
    
    for (i = 0; i < n; i++) {
        soma = soma + notas[i];
        
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
        
        if (notas[i] >= 7) {
            aprovados++;
        } else if (notas[i] >= 5) {
            recuperacao++;
        } else {
            reprovados++;
        }
    }
    
    mediaGeral = soma / n;
    
    printf("\n=== RESULTADO ===\n");
    printf("Media geral: %.2f\n", mediaGeral);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
    printf("Aprovados (>=7): %d\n", aprovados);
    printf("Recuperacao (5-6.9): %d\n", recuperacao);
    printf("Reprovados (<5): %d\n", reprovados);
    
    printf("\nNotas acima da media:\n");
    for (i = 0; i < n; i++) {
        if (notas[i] > mediaGeral) {
            printf("Aluno %d: %.2f\n", i + 1, notas[i]);
        }
    }
    
    system("pause");
    return 0;
}
```

---

## EXERCICIO 12: Merge de dois vetores ordenados
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int v1[5] = {1, 3, 5, 7, 9};
    int v2[5] = {2, 4, 6, 8, 10};
    int resultado[10];
    int i, j, k;
    
    i = 0;
    j = 0;
    k = 0;
    
    printf("Vetor 1: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", v1[i]);
    }
    
    printf("\nVetor 2: ");
    for (j = 0; j < 5; j++) {
        printf("%d ", v2[j]);
    }
    
    i = 0;
    j = 0;
    
    while (i < 5 && j < 5) {
        if (v1[i] < v2[j]) {
            resultado[k] = v1[i];
            i++;
        } else {
            resultado[k] = v2[j];
            j++;
        }
        k++;
    }
    
    while (i < 5) {
        resultado[k] = v1[i];
        i++;
        k++;
    }
    
    while (j < 5) {
        resultado[k] = v2[j];
        j++;
        k++;
    }
    
    printf("\nMerge: ");
    for (k = 0; k < 10; k++) {
        printf("%d ", resultado[k]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}
```

---

## DICAS FINAIS PARA A PROVA

### Checklist antes de compilar:
1. [ ] Todas variaveis declaradas no INICIO da funcao
2. [ ] Includes corretos: `<stdio.h>` e `<stdlib.h>`
3. [ ] `system("pause");` antes do `return 0;`
4. [ ] Usar `/* */` para comentarios
5. [ ] Inicializar contadores e acumuladores com 0 (ou 1 para fatorial)

### Formulas importantes:
- **Media:** `media = soma / quantidade;`
- **Par:** `numero % 2 == 0`
- **Impar:** `numero % 2 != 0`
- **Divisivel:** `a % b == 0`
- **Ultimo digito:** `numero % 10`
- **Remove ultimo digito:** `numero / 10`

### Padroes de codigo:
- **Percorrer vetor:** `for (i = 0; i < n; i++)`
- **Percorrer matriz:** dois for aninhados
- **Buscar maior:** inicializa com primeiro elemento
- **Validacao:** `do { ... } while (condicao_invalida);`
- **Menu:** `do { ... } while (opcao != 0);`

BOA PROVA!

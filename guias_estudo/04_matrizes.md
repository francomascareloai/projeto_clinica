# GUIA COMPLETO DE MATRIZES (ARRAYS 2D) EM C - Dev-C++

## PADRAO DEV-C++
- Declarar TODAS as variaveis no INICIO da funcao
- Usar `system("pause");` antes do return
- Incluir `<stdlib.h>` para system()

---

## 1. O QUE E UMA MATRIZ?

Matriz e um **vetor de vetores** - estrutura bidimensional com linhas e colunas.

```
Matriz 3x4:
        Col 0   Col 1   Col 2   Col 3
Linha 0  [0,0]   [0,1]   [0,2]   [0,3]
Linha 1  [1,0]   [1,1]   [1,2]   [1,3]
Linha 2  [2,0]   [2,1]   [2,2]   [2,3]
```

---

## 2. DECLARACAO E INICIALIZACAO

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Declaracao */
    int matriz[3][4];  /* 3 linhas, 4 colunas */
    
    /* Inicializacao completa */
    int m1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    /* Inicializacao em linha */
    int m2[2][3] = {1, 2, 3, 4, 5, 6};
    
    /* Inicializacao com zeros */
    int m3[3][3] = {0};
    
    system("pause");
    return 0;
}
```

---

## 3. ACESSO AOS ELEMENTOS

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[2][3] = {{1,2,3}, {4,5,6}};
    
    printf("%d\n", matriz[0][0]);  /* 1 */
    printf("%d\n", matriz[0][2]);  /* 3 */
    printf("%d\n", matriz[1][1]);  /* 5 */
    
    /* Escrita */
    matriz[1][2] = 100;
    
    system("pause");
    return 0;
}
```

---

## 4. PERCORRENDO MATRIZES

### 4.1 Preenchimento com FOR Aninhado
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][4];
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            matriz[i][j] = i * 4 + j;
        }
    }
    
    system("pause");
    return 0;
}
```

### 4.2 Leitura do Usuario
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3];
    int i, j;
    
    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    system("pause");
    return 0;
}
```

### 4.3 Impressao Formatada
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int i, j;
    
    printf("Matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

---

## 5. OPERACOES BASICAS

### 5.1 Soma de Todos os Elementos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int soma, i, j;
    
    soma = 0;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            soma = soma + matriz[i][j];
        }
    }
    
    printf("Soma total: %d\n", soma);  /* 45 */
    
    system("pause");
    return 0;
}
```

### 5.2 Media de Todos os Elementos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    float matriz[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    float soma, media;
    int i, j, totalElementos;
    
    soma = 0;
    totalElementos = 2 * 3;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            soma = soma + matriz[i][j];
        }
    }
    
    media = soma / totalElementos;
    printf("Media: %.2f\n", media);
    
    system("pause");
    return 0;
}
```

### 5.3 Maior e Menor Elemento
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3] = {{5, 2, 9}, {1, 8, 3}, {7, 4, 6}};
    int maior, menor, i, j;
    
    maior = matriz[0][0];
    menor = matriz[0][0];
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }
    
    printf("Maior: %d, Menor: %d\n", maior, menor);
    
    system("pause");
    return 0;
}
```

### 5.4 Soma por Linha
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int i, j, somaLinha;
    
    for (i = 0; i < 3; i++) {
        somaLinha = 0;
        for (j = 0; j < 4; j++) {
            somaLinha = somaLinha + matriz[i][j];
        }
        printf("Soma da linha %d: %d\n", i, somaLinha);
    }
    
    system("pause");
    return 0;
}
```

### 5.5 Soma por Coluna
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int i, j, somaColuna;
    
    for (j = 0; j < 4; j++) {
        somaColuna = 0;
        for (i = 0; i < 3; i++) {
            somaColuna = somaColuna + matriz[i][j];
        }
        printf("Soma da coluna %d: %d\n", j, somaColuna);
    }
    
    system("pause");
    return 0;
}
```

---

## 6. MATRIZES QUADRADAS (NxN)

### 6.1 Diagonal Principal (i == j)
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
    int i, somaDiag;
    
    somaDiag = 0;
    
    printf("Diagonal principal: ");
    for (i = 0; i < 4; i++) {
        printf("%d ", matriz[i][i]);
        somaDiag = somaDiag + matriz[i][i];
    }
    /* Saida: 1 6 11 16 */
    
    printf("\nSoma: %d\n", somaDiag);
    
    system("pause");
    return 0;
}
```

### 6.2 Diagonal Secundaria (j = n - 1 - i)
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
    int i, n, somaDiag;
    
    n = 4;
    somaDiag = 0;
    
    printf("Diagonal secundaria: ");
    for (i = 0; i < n; i++) {
        printf("%d ", matriz[i][n - 1 - i]);
        somaDiag = somaDiag + matriz[i][n - 1 - i];
    }
    /* Saida: 4 7 10 13 */
    
    printf("\nSoma: %d\n", somaDiag);
    
    system("pause");
    return 0;
}
```

### 6.3 Elementos ACIMA da Diagonal Principal (j > i)
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
    int i, j;
    
    printf("Acima da diagonal principal: ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j > i) {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    /* Saida: 2 3 4 7 8 12 */
    
    system("pause");
    return 0;
}
```

### 6.4 Elementos ABAIXO da Diagonal Principal (i > j)
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
    int i, j;
    
    printf("Abaixo da diagonal principal: ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i > j) {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    /* Saida: 5 9 10 13 14 15 */
    
    system("pause");
    return 0;
}
```

### 6.5 Matriz Identidade
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int identidade[4][4];
    int i, j;
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) {
                identidade[i][j] = 1;
            } else {
                identidade[i][j] = 0;
            }
        }
    }
    
    printf("Matriz Identidade:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", identidade[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

---

## 7. OPERACOES ENTRE MATRIZES

### 7.1 Soma de Matrizes
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];
    int i, j;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    printf("A + B =\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

### 7.2 Subtracao de Matrizes
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[2][2] = {{5, 6}, {7, 8}};
    int B[2][2] = {{1, 2}, {3, 4}};
    int C[2][2];
    int i, j;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    
    printf("A - B =\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

### 7.3 Multiplicacao por Escalar
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int escalar, i, j;
    
    escalar = 3;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            A[i][j] = A[i][j] * escalar;
        }
    }
    
    printf("A * %d =\n", escalar);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

### 7.4 Multiplicacao de Matrizes
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2];
    int i, j, k;
    
    /* Inicializa C com zeros */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            C[i][j] = 0;
        }
    }
    
    /* C = A * B */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    
    printf("A * B =\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

### 7.5 Transposta de Matriz
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int T[3][2];
    int i, j;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            T[j][i] = A[i][j];
        }
    }
    
    printf("Original:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nTransposta:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%4d", T[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

---

## 8. BUSCA EM MATRIZES

### 8.1 Buscar Elemento
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3] = {{5, 2, 9}, {1, 8, 3}, {7, 4, 6}};
    int busca, i, j, encontrado;
    
    busca = 8;
    encontrado = 0;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] == busca) {
                printf("Encontrado em [%d][%d]\n", i, j);
                encontrado = 1;
            }
        }
    }
    
    if (encontrado == 0) {
        printf("Nao encontrado\n");
    }
    
    system("pause");
    return 0;
}
```

### 8.2 Contar Ocorrencias
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3] = {{5, 2, 5}, {1, 5, 3}, {7, 4, 5}};
    int busca, contador, i, j;
    
    busca = 5;
    contador = 0;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matriz[i][j] == busca) {
                contador++;
            }
        }
    }
    
    printf("%d aparece %d vezes\n", busca, contador);
    
    system("pause");
    return 0;
}
```

---

## 9. EXEMPLO COMPLETO: SISTEMA DE NOTAS
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    float notas[4][3];  /* 4 alunos, 3 provas */
    float somaAluno, mediaAluno;
    int i, j;
    
    /* Leitura das notas */
    for (i = 0; i < 4; i++) {
        printf("Aluno %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf("  Prova %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    
    /* Calcula e exibe medias */
    printf("\n=== RESULTADOS ===\n");
    for (i = 0; i < 4; i++) {
        somaAluno = 0;
        for (j = 0; j < 3; j++) {
            somaAluno = somaAluno + notas[i][j];
        }
        mediaAluno = somaAluno / 3;
        
        printf("Aluno %d - Media: %.2f - ", i + 1, mediaAluno);
        if (mediaAluno >= 7) {
            printf("APROVADO\n");
        } else {
            printf("REPROVADO\n");
        }
    }
    
    system("pause");
    return 0;
}
```

---

## 10. USANDO #define PARA DIMENSOES
```c
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 4

int main() {
    int matriz[LINHAS][COLUNAS];
    int i, j;
    
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            matriz[i][j] = i * COLUNAS + j;
        }
    }
    
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

---

## RESUMO VISUAL

```
MATRIZ 3x4:
              j=0   j=1   j=2   j=3
           +-----+-----+-----+-----+
     i=0   |[0,0]|[0,1]|[0,2]|[0,3]|
           +-----+-----+-----+-----+
     i=1   |[1,0]|[1,1]|[1,2]|[1,3]|
           +-----+-----+-----+-----+
     i=2   |[2,0]|[2,1]|[2,2]|[2,3]|
           +-----+-----+-----+-----+

DIAGONAL PRINCIPAL: i == j
DIAGONAL SECUNDARIA: j == n - 1 - i
ACIMA diagonal: j > i
ABAIXO diagonal: i > j
```

---

## DICAS PARA PROVA

1. **Sempre use dois indices:** `matriz[linha][coluna]`
2. **Dois for aninhados:** externo = linhas, interno = colunas
3. **Diagonal principal:** quando `i == j`
4. **Diagonal secundaria:** quando `j == n - 1 - i`
5. **Declare variaveis no INICIO** da funcao
6. **Use system("pause");** antes do return

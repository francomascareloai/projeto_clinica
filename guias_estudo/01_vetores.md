# GUIA COMPLETO DE VETORES (ARRAYS) EM C - Dev-C++

## PADRAO DEV-C++
- Declarar TODAS as variaveis no INICIO da funcao
- Usar `system("pause");` antes do return para a janela nao fechar
- Incluir `<stdlib.h>` para system()

---

## 1. O QUE E UM VETOR?

Um vetor (array) e uma estrutura que armazena multiplos valores do MESMO TIPO.

**Caracteristicas:**
- Tamanho fixo (definido na declaracao)
- Indices comecam em 0
- Acesso direto por indice

---

## 2. DECLARACAO DE VETORES

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5];        /* Vetor de 5 inteiros */
    float notas[10];       /* Vetor de 10 floats */
    char letras[26];       /* Vetor de 26 caracteres */
    
    system("pause");
    return 0;
}
```

---

## 3. INICIALIZACAO DE VETORES

### 3.1 Inicializacao Completa
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    float notas[4] = {7.5, 8.0, 9.5, 6.0};
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    
    system("pause");
    return 0;
}
```

### 3.2 Inicializacao Parcial (restante fica 0)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[10] = {1, 2, 3};  /* {1, 2, 3, 0, 0, 0, 0, 0, 0, 0} */
    
    system("pause");
    return 0;
}
```

### 3.3 Inicializacao com Zeros
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[100] = {0};  /* Todos os 100 elementos sao 0 */
    
    system("pause");
    return 0;
}
```

### 3.4 Tamanho Implicito
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[] = {5, 10, 15, 20};  /* Tamanho 4 (calculado automaticamente) */
    
    system("pause");
    return 0;
}
```

---

## 4. ACESSO AOS ELEMENTOS

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    
    printf("%d\n", numeros[0]);   /* Imprime: 10 */
    printf("%d\n", numeros[2]);   /* Imprime: 30 */
    printf("%d\n", numeros[4]);   /* Imprime: 50 */
    
    /* CUIDADO: numeros[5] esta FORA do vetor! */
    
    system("pause");
    return 0;
}
```

---

## 5. PERCORRENDO VETORES COM LACOS

### 5.1 Preenchimento com FOR
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5];
    int i;
    
    for (i = 0; i < 5; i++) {
        numeros[i] = i * 10;
    }
    
    /* Resultado: 0, 10, 20, 30, 40 */
    
    system("pause");
    return 0;
}
```

### 5.2 Leitura do Usuario
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5];
    int i;
    
    printf("Digite 5 numeros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    system("pause");
    return 0;
}
```

### 5.3 Impressao
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int i;
    
    printf("Elementos do vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }
    
    system("pause");
    return 0;
}
```

### 5.4 Percorrendo de Tras para Frente
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int i;
    
    for (i = 4; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    /* Imprime: 50 40 30 20 10 */
    
    system("pause");
    return 0;
}
```

---

## 6. OPERACOES COMUNS COM VETORES

### 6.1 Soma de Todos os Elementos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int soma = 0;
    int i;
    
    for (i = 0; i < 5; i++) {
        soma = soma + numeros[i];
    }
    
    printf("Soma: %d\n", soma);  /* Soma: 150 */
    
    system("pause");
    return 0;
}
```

### 6.2 Media dos Elementos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    float notas[4] = {7.5, 8.0, 9.0, 6.5};
    float soma = 0;
    float media;
    int i;
    
    for (i = 0; i < 4; i++) {
        soma = soma + notas[i];
    }
    
    media = soma / 4;
    printf("Media: %.2f\n", media);  /* Media: 7.75 */
    
    system("pause");
    return 0;
}
```

### 6.3 Encontrar o MAIOR Elemento
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {30, 10, 50, 20, 40};
    int maior;
    int i;
    
    maior = numeros[0];  /* Assume que o primeiro e o maior */
    
    for (i = 1; i < 5; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }
    
    printf("Maior: %d\n", maior);  /* Maior: 50 */
    
    system("pause");
    return 0;
}
```

### 6.4 Encontrar o MENOR Elemento
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {30, 10, 50, 20, 40};
    int menor;
    int i;
    
    menor = numeros[0];
    
    for (i = 1; i < 5; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    
    printf("Menor: %d\n", menor);  /* Menor: 10 */
    
    system("pause");
    return 0;
}
```

### 6.5 Maior E Menor Juntos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {30, 10, 50, 20, 40};
    int maior, menor;
    int i;
    
    maior = numeros[0];
    menor = numeros[0];
    
    for (i = 1; i < 5; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    
    printf("Maior: %d, Menor: %d\n", maior, menor);
    
    system("pause");
    return 0;
}
```

### 6.6 Encontrar a POSICAO do Maior
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {30, 10, 50, 20, 40};
    int maior, posicaoMaior;
    int i;
    
    maior = numeros[0];
    posicaoMaior = 0;
    
    for (i = 1; i < 5; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
            posicaoMaior = i;
        }
    }
    
    printf("Maior: %d na posicao %d\n", maior, posicaoMaior);
    
    system("pause");
    return 0;
}
```

### 6.7 Contar Elementos com Condicao
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[10] = {5, 12, 8, 20, 3, 15, 7, 25, 10, 18};
    int contador = 0;
    int i;
    
    /* Contar quantos sao maiores que 10 */
    for (i = 0; i < 10; i++) {
        if (numeros[i] > 10) {
            contador++;
        }
    }
    
    printf("Quantidade maior que 10: %d\n", contador);
    
    system("pause");
    return 0;
}
```

### 6.8 Buscar um Elemento (Busca Linear)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int busca = 30;
    int encontrado = -1;
    int i;
    
    for (i = 0; i < 5; i++) {
        if (numeros[i] == busca) {
            encontrado = i;
            break;
        }
    }
    
    if (encontrado != -1) {
        printf("Encontrado na posicao %d\n", encontrado);
    } else {
        printf("Nao encontrado\n");
    }
    
    system("pause");
    return 0;
}
```

### 6.9 Verificar se Elemento Existe
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int busca = 25;
    int existe = 0;
    int i;
    
    for (i = 0; i < 5; i++) {
        if (numeros[i] == busca) {
            existe = 1;
            break;
        }
    }
    
    if (existe) {
        printf("Elemento existe no vetor\n");
    } else {
        printf("Elemento NAO existe no vetor\n");
    }
    
    system("pause");
    return 0;
}
```

---

## 7. MANIPULACAO DE VETORES

### 7.1 Copiar um Vetor para Outro
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int original[5] = {1, 2, 3, 4, 5};
    int copia[5];
    int i;
    
    for (i = 0; i < 5; i++) {
        copia[i] = original[i];
    }
    
    printf("Copia: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", copia[i]);
    }
    
    system("pause");
    return 0;
}
```

### 7.2 Inverter um Vetor
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[5] = {1, 2, 3, 4, 5};
    int temp;
    int i, j;
    
    i = 0;
    j = 4;
    
    while (i < j) {
        temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
        i++;
        j--;
    }
    
    printf("Invertido: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    /* Imprime: 5 4 3 2 1 */
    
    system("pause");
    return 0;
}
```

### 7.3 Ordenacao Bubble Sort (Crescente)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[5] = {64, 34, 25, 12, 22};
    int i, j, temp;
    int n = 5;
    
    /* Bubble Sort */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    
    printf("Ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    /* Imprime: 12 22 25 34 64 */
    
    system("pause");
    return 0;
}
```

### 7.4 Ordenacao Decrescente
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[5] = {64, 34, 25, 12, 22};
    int i, j, temp;
    int n = 5;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {  /* Muda o sinal para < */
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    
    printf("Decrescente: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    /* Imprime: 64 34 25 22 12 */
    
    system("pause");
    return 0;
}
```

### 7.5 Remover Elemento por Indice
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int posicao = 2;  /* Remover elemento na posicao 2 (valor 30) */
    int i;
    
    for (i = posicao; i < n - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    
    n--;
    
    printf("Resultado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    /* Imprime: 10 20 40 50 */
    
    system("pause");
    return 0;
}
```

### 7.6 Inserir Elemento em Posicao
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[10] = {10, 20, 40, 50};
    int n = 4;
    int posicao = 2;
    int novoValor = 30;
    int i;
    
    for (i = n; i > posicao; i--) {
        vetor[i] = vetor[i - 1];
    }
    
    vetor[posicao] = novoValor;
    n++;
    
    printf("Resultado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    /* Imprime: 10 20 30 40 50 */
    
    system("pause");
    return 0;
}
```

---

## 8. CONTAR PARES E IMPARES
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pares = 0, impares = 0;
    int i;
    
    for (i = 0; i < 10; i++) {
        if (numeros[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    
    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);
    
    system("pause");
    return 0;
}
```

---

## 9. SEPARAR POSITIVOS E NEGATIVOS
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[10] = {-5, 3, -2, 8, -1, 4, 0, -7, 6, 2};
    int positivos[10], negativos[10];
    int contPos = 0, contNeg = 0;
    int i;
    
    for (i = 0; i < 10; i++) {
        if (numeros[i] >= 0) {
            positivos[contPos] = numeros[i];
            contPos++;
        } else {
            negativos[contNeg] = numeros[i];
            contNeg++;
        }
    }
    
    printf("Positivos: ");
    for (i = 0; i < contPos; i++) {
        printf("%d ", positivos[i]);
    }
    
    printf("\nNegativos: ");
    for (i = 0; i < contNeg; i++) {
        printf("%d ", negativos[i]);
    }
    
    system("pause");
    return 0;
}
```

---

## 10. EXEMPLO COMPLETO: LER, SOMA, MEDIA, MAIOR, MENOR
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[10];
    int i, soma, maior, menor;
    float media;
    
    soma = 0;
    
    printf("Digite 10 numeros:\n");
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    maior = numeros[0];
    menor = numeros[0];
    
    for (i = 0; i < 10; i++) {
        soma = soma + numeros[i];
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    
    media = (float)soma / 10;
    
    printf("\n=== RESULTADOS ===\n");
    printf("Soma: %d\n", soma);
    printf("Media: %.2f\n", media);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    
    system("pause");
    return 0;
}
```

---

## 11. USANDO #define PARA TAMANHO
```c
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main() {
    int vetor[TAM];
    int i;
    
    for (i = 0; i < TAM; i++) {
        vetor[i] = i * 10;
    }
    
    for (i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    
    system("pause");
    return 0;
}
```

---

## ERROS COMUNS A EVITAR

1. **Acesso fora dos limites:**
```c
int vetor[5];
vetor[5] = 10;  /* ERRO! Indices validos: 0 a 4 */
```

2. **Esquecer que indice comeca em 0:**
```c
int vetor[5] = {10, 20, 30, 40, 50};
/* vetor[1] e 20, NAO 10! */
/* vetor[0] e 10 */
```

3. **Nao inicializar o vetor:**
```c
int vetor[5];
/* vetor contem LIXO de memoria! */
```

---

## RESUMO RAPIDO

| Operacao | Codigo |
|----------|--------|
| Declarar | `int vet[10];` |
| Inicializar | `int vet[3] = {1, 2, 3};` |
| Acessar | `vet[0]`, `vet[i]` |
| Atribuir | `vet[0] = 10;` |
| Percorrer | `for(i=0; i<n; i++)` |

**LEMBRE-SE:** Indices vao de 0 ate tamanho-1!

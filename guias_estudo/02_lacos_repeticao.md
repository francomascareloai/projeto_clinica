# GUIA COMPLETO DE LACOS DE REPETICAO EM C - Dev-C++

## PADRAO DEV-C++
- Declarar TODAS as variaveis no INICIO da funcao
- Usar `system("pause");` antes do return
- Incluir `<stdlib.h>` para system()
- Usar comentarios /* */ em vez de //

---

## 1. O QUE SAO LACOS DE REPETICAO?

Lacos (loops) permitem executar um bloco de codigo VARIAS VEZES.

**Tipos principais:**
- `for` - quando voce sabe quantas vezes repetir
- `while` - quando depende de uma condicao
- `do-while` - executa pelo menos uma vez

---

## 2. LACO FOR

### 2.1 Sintaxe do FOR
```c
for (inicializacao; condicao; incremento) {
    /* codigo a repetir */
}
```

### 2.2 Exemplo Basico - Contar de 0 a 4
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    for (i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    /* Saida: 0 1 2 3 4 */
    
    system("pause");
    return 0;
}
```

### 2.3 Contar de 1 a 10
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    /* Saida: 1 2 3 4 5 6 7 8 9 10 */
    
    system("pause");
    return 0;
}
```

### 2.4 Contagem Regressiva
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    for (i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("Fogo!\n");
    /* Saida: 10 9 8 7 6 5 4 3 2 1 Fogo! */
    
    system("pause");
    return 0;
}
```

### 2.5 Incremento de 2 em 2 (Numeros Pares)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    printf("Pares de 0 a 10: ");
    for (i = 0; i <= 10; i = i + 2) {
        printf("%d ", i);
    }
    /* Saida: 0 2 4 6 8 10 */
    
    system("pause");
    return 0;
}
```

### 2.6 Numeros Impares
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    printf("Impares de 1 a 10: ");
    for (i = 1; i <= 10; i = i + 2) {
        printf("%d ", i);
    }
    /* Saida: 1 3 5 7 9 */
    
    system("pause");
    return 0;
}
```

### 2.7 Tabuada
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, i;
    
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    printf("\nTabuada do %d:\n", numero);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    
    system("pause");
    return 0;
}
```

### 2.8 Soma de 1 a N
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, soma;
    
    soma = 0;
    
    printf("Digite N: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        soma = soma + i;
    }
    
    printf("Soma de 1 a %d = %d\n", n, soma);
    
    system("pause");
    return 0;
}
```

### 2.9 Fatorial
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    long int fatorial;
    
    fatorial = 1;
    
    printf("Digite N: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        fatorial = fatorial * i;
    }
    
    printf("%d! = %ld\n", n, fatorial);
    /* 5! = 120 */
    
    system("pause");
    return 0;
}
```

### 2.10 Potencia (base elevado ao expoente)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int base, expoente, i;
    long int resultado;
    
    resultado = 1;
    
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    for (i = 1; i <= expoente; i++) {
        resultado = resultado * base;
    }
    
    printf("%d^%d = %ld\n", base, expoente, resultado);
    
    system("pause");
    return 0;
}
```

### 2.11 Sequencia de Fibonacci
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, a, b, proximo;
    
    a = 0;
    b = 1;
    
    printf("Quantos termos? ");
    scanf("%d", &n);
    
    printf("Fibonacci: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a);
        proximo = a + b;
        a = b;
        b = proximo;
    }
    /* n=10: 0 1 1 2 3 5 8 13 21 34 */
    
    system("pause");
    return 0;
}
```

---

## 3. LACO WHILE

### 3.1 Sintaxe do WHILE
```c
while (condicao) {
    /* codigo a repetir */
}
```

### 3.2 Exemplo Basico
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    i = 0;
    
    while (i < 5) {
        printf("%d ", i);
        i++;
    }
    /* Saida: 0 1 2 3 4 */
    
    system("pause");
    return 0;
}
```

### 3.3 Ler ate o usuario digitar 0
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    
    printf("Digite um numero (0 para sair): ");
    scanf("%d", &numero);
    
    while (numero != 0) {
        printf("Voce digitou: %d\n", numero);
        printf("Digite outro numero (0 para sair): ");
        scanf("%d", &numero);
    }
    
    printf("Programa encerrado.\n");
    
    system("pause");
    return 0;
}
```

### 3.4 Soma ate digitar numero negativo
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, soma;
    
    soma = 0;
    
    printf("Digite numeros (negativo para sair):\n");
    printf("Numero: ");
    scanf("%d", &numero);
    
    while (numero >= 0) {
        soma = soma + numero;
        printf("Numero: ");
        scanf("%d", &numero);
    }
    
    printf("Soma total: %d\n", soma);
    
    system("pause");
    return 0;
}
```

### 3.5 Validacao de Entrada
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade;
    
    printf("Digite sua idade (0-120): ");
    scanf("%d", &idade);
    
    while (idade < 0 || idade > 120) {
        printf("Idade invalida! Digite novamente: ");
        scanf("%d", &idade);
    }
    
    printf("Idade valida: %d anos\n", idade);
    
    system("pause");
    return 0;
}
```

### 3.6 Contar Digitos de um Numero
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, temp, digitos;
    
    digitos = 0;
    
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    temp = numero;
    
    if (temp == 0) {
        digitos = 1;
    } else {
        if (temp < 0) {
            temp = -temp;
        }
        
        while (temp > 0) {
            digitos++;
            temp = temp / 10;
        }
    }
    
    printf("%d tem %d digito(s)\n", numero, digitos);
    
    system("pause");
    return 0;
}
```

### 3.7 Somar Digitos de um Numero
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, temp, soma;
    
    soma = 0;
    
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    temp = numero;
    if (temp < 0) {
        temp = -temp;
    }
    
    while (temp > 0) {
        soma = soma + (temp % 10);   /* Pega ultimo digito */
        temp = temp / 10;             /* Remove ultimo digito */
    }
    
    printf("Soma dos digitos de %d = %d\n", numero, soma);
    /* 12345 -> 1+2+3+4+5 = 15 */
    
    system("pause");
    return 0;
}
```

### 3.8 Inverter um Numero
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, temp, invertido;
    
    invertido = 0;
    
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    temp = numero;
    
    while (temp > 0) {
        invertido = invertido * 10 + (temp % 10);
        temp = temp / 10;
    }
    
    printf("Original: %d\n", numero);
    printf("Invertido: %d\n", invertido);
    /* 12345 -> 54321 */
    
    system("pause");
    return 0;
}
```

### 3.9 Verificar Palindromo (Numero)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero, temp, invertido;
    
    invertido = 0;
    
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    temp = numero;
    
    while (temp > 0) {
        invertido = invertido * 10 + (temp % 10);
        temp = temp / 10;
    }
    
    if (numero == invertido) {
        printf("%d e palindromo!\n", numero);
    } else {
        printf("%d NAO e palindromo.\n", numero);
    }
    /* 12321 e palindromo */
    
    system("pause");
    return 0;
}
```

---

## 4. LACO DO-WHILE

### 4.1 Sintaxe do DO-WHILE
```c
do {
    /* codigo a repetir */
} while (condicao);
```

**IMPORTANTE:** Executa pelo menos UMA vez!

### 4.2 Exemplo Basico
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    i = 0;
    
    do {
        printf("%d ", i);
        i++;
    } while (i < 5);
    /* Saida: 0 1 2 3 4 */
    
    system("pause");
    return 0;
}
```

### 4.3 Diferenca: while vs do-while
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    
    x = 10;
    
    /* WHILE - nao executa nada (condicao falsa desde o inicio) */
    while (x < 5) {
        printf("while: %d\n", x);
    }
    
    /* DO-WHILE - executa UMA vez mesmo com condicao falsa */
    do {
        printf("do-while: %d\n", x);
    } while (x < 5);
    
    /* Saida apenas: do-while: 10 */
    
    system("pause");
    return 0;
}
```

### 4.4 Validacao de Entrada (uso classico)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int nota;
    
    do {
        printf("Digite uma nota (0-10): ");
        scanf("%d", &nota);
        
        if (nota < 0 || nota > 10) {
            printf("Nota invalida! Tente novamente.\n");
        }
    } while (nota < 0 || nota > 10);
    
    printf("Nota valida: %d\n", nota);
    
    system("pause");
    return 0;
}
```

### 4.5 Menu com DO-WHILE
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Calcular\n");
        printf("2 - Exibir\n");
        printf("3 - Limpar\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Calculando...\n");
                break;
            case 2:
                printf("Exibindo...\n");
                break;
            case 3:
                printf("Limpando...\n");
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

### 4.6 Calcular Media com Confirmacao
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    float nota, soma, media;
    int quantidade;
    char continuar;
    
    soma = 0;
    quantidade = 0;
    
    do {
        printf("Digite uma nota: ");
        scanf("%f", &nota);
        
        soma = soma + nota;
        quantidade++;
        
        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);  /* Espaco antes de %c ignora enter */
        
    } while (continuar == 's' || continuar == 'S');
    
    media = soma / quantidade;
    printf("Media: %.2f\n", media);
    
    system("pause");
    return 0;
}
```

---

## 5. COMANDOS DE CONTROLE

### 5.1 break - Sai do Laco
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    for (i = 1; i <= 10; i++) {
        if (i == 5) {
            break;  /* Sai do for quando i = 5 */
        }
        printf("%d ", i);
    }
    /* Saida: 1 2 3 4 */
    
    system("pause");
    return 0;
}
```

### 5.2 continue - Pula para Proxima Iteracao
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    for (i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;  /* Pula o 5 */
        }
        printf("%d ", i);
    }
    /* Saida: 1 2 3 4 6 7 8 9 10 */
    
    system("pause");
    return 0;
}
```

### 5.3 Imprimir so Pares (usando continue)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    
    printf("Pares de 1 a 20: ");
    for (i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            continue;  /* Pula impares */
        }
        printf("%d ", i);
    }
    
    system("pause");
    return 0;
}
```

---

## 6. LACOS ANINHADOS

### 6.1 Exemplo Basico
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 4; j++) {
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    
    /*
    (1,1) (1,2) (1,3) (1,4)
    (2,1) (2,2) (2,3) (2,4)
    (3,1) (3,2) (3,3) (3,4)
    */
    
    system("pause");
    return 0;
}
```

### 6.2 Tabela de Multiplicacao
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

### 6.3 Triangulo de Asteriscos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, linhas;
    
    linhas = 5;
    
    for (i = 1; i <= linhas; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    /*
    * 
    * * 
    * * * 
    * * * * 
    * * * * * 
    */
    
    system("pause");
    return 0;
}
```

### 6.4 Triangulo Invertido
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, linhas;
    
    linhas = 5;
    
    for (i = linhas; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    /*
    * * * * * 
    * * * * 
    * * * 
    * * 
    * 
    */
    
    system("pause");
    return 0;
}
```

### 6.5 Piramide
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, espaco, linhas;
    
    linhas = 5;
    
    for (i = 1; i <= linhas; i++) {
        /* Imprime espacos */
        for (espaco = 1; espaco <= linhas - i; espaco++) {
            printf(" ");
        }
        /* Imprime asteriscos */
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    /*
        *
       ***
      *****
     *******
    *********
    */
    
    system("pause");
    return 0;
}
```

### 6.6 Todas as Tabuadas
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    
    for (i = 1; i <= 10; i++) {
        printf("=== Tabuada do %d ===\n", i);
        for (j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}
```

---

## 7. NUMEROS PRIMOS

### 7.1 Verificar se e Primo
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, primo;
    
    primo = 1;
    
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    if (n <= 1) {
        primo = 0;
    } else {
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                primo = 0;
                break;
            }
        }
    }
    
    if (primo) {
        printf("%d e primo!\n", n);
    } else {
        printf("%d NAO e primo.\n", n);
    }
    
    system("pause");
    return 0;
}
```

### 7.2 Listar Primos ate N
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, primo;
    
    printf("Listar primos ate: ");
    scanf("%d", &n);
    
    printf("Primos: ");
    for (i = 2; i <= n; i++) {
        primo = 1;
        
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                primo = 0;
                break;
            }
        }
        
        if (primo) {
            printf("%d ", i);
        }
    }
    
    system("pause");
    return 0;
}
```

---

## 8. MDC E MMC

### 8.1 MDC (Maximo Divisor Comum)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, resto;
    
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);
    
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    
    printf("MDC = %d\n", a);
    
    system("pause");
    return 0;
}
```

### 8.2 MMC (Minimo Multiplo Comum)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, maior, mmc;
    
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);
    
    if (a > b) {
        maior = a;
    } else {
        maior = b;
    }
    
    mmc = maior;
    
    while (1) {
        if (mmc % a == 0 && mmc % b == 0) {
            break;
        }
        mmc++;
    }
    
    printf("MMC = %d\n", mmc);
    
    system("pause");
    return 0;
}
```

---

## 9. EXEMPLOS COMPLETOS DE PROVA

### Exemplo 1: Calculadora com Menu
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    float a, b, resultado;
    
    do {
        printf("\n=== CALCULADORA ===\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        if (opcao >= 1 && opcao <= 4) {
            printf("Digite dois numeros: ");
            scanf("%f %f", &a, &b);
            
            switch (opcao) {
                case 1:
                    resultado = a + b;
                    printf("%.2f + %.2f = %.2f\n", a, b, resultado);
                    break;
                case 2:
                    resultado = a - b;
                    printf("%.2f - %.2f = %.2f\n", a, b, resultado);
                    break;
                case 3:
                    resultado = a * b;
                    printf("%.2f * %.2f = %.2f\n", a, b, resultado);
                    break;
                case 4:
                    if (b != 0) {
                        resultado = a / b;
                        printf("%.2f / %.2f = %.2f\n", a, b, resultado);
                    } else {
                        printf("Erro: divisao por zero!\n");
                    }
                    break;
            }
        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    printf("Fim do programa.\n");
    
    system("pause");
    return 0;
}
```

### Exemplo 2: Notas de Alunos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade, i, aprovados, reprovados;
    float nota, soma, maior, menor, media;
    
    soma = 0;
    aprovados = 0;
    reprovados = 0;
    
    printf("Quantos alunos? ");
    scanf("%d", &quantidade);
    
    for (i = 0; i < quantidade; i++) {
        do {
            printf("Nota do aluno %d (0-10): ", i + 1);
            scanf("%f", &nota);
        } while (nota < 0 || nota > 10);
        
        soma = soma + nota;
        
        if (i == 0) {
            maior = nota;
            menor = nota;
        } else {
            if (nota > maior) {
                maior = nota;
            }
            if (nota < menor) {
                menor = nota;
            }
        }
        
        if (nota >= 7) {
            aprovados++;
        } else {
            reprovados++;
        }
    }
    
    media = soma / quantidade;
    
    printf("\n=== RESULTADO ===\n");
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);
    
    system("pause");
    return 0;
}
```

### Exemplo 3: Sequencia de Numeros
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, soma;
    long int fatorial;
    
    soma = 0;
    fatorial = 1;
    
    printf("Digite N: ");
    scanf("%d", &n);
    
    printf("Numeros de 1 a %d: ", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
        soma = soma + i;
        fatorial = fatorial * i;
    }
    
    printf("\nSoma: %d\n", soma);
    printf("Fatorial: %ld\n", fatorial);
    
    printf("\nPares: ");
    for (i = 2; i <= n; i = i + 2) {
        printf("%d ", i);
    }
    
    printf("\nImpares: ");
    for (i = 1; i <= n; i = i + 2) {
        printf("%d ", i);
    }
    
    printf("\n");
    
    system("pause");
    return 0;
}
```

---

## 10. RESUMO COMPARATIVO

| Caracteristica | for | while | do-while |
|---------------|-----|-------|----------|
| Testa condicao | Antes | Antes | Depois |
| Executa minimo | 0 vezes | 0 vezes | 1 vez |
| Contador | Embutido | Manual | Manual |
| Uso tipico | N conhecido | Condicao | Menu/Validacao |

---

## DICAS PARA PROVA

1. **Sempre inicialize variaveis** (contadores = 0, acumuladores = 0 ou 1)
2. **Cuidado com os limites** (< vs <=, > vs >=)
3. **Nao esqueca de incrementar** em while/do-while
4. **Use {}** mesmo para uma linha
5. **Declare variaveis no INICIO** da funcao (padrao Dev-C++)
6. **Use system("pause");** antes do return para ver a saida

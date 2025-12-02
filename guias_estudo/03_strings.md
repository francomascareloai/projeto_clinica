# GUIA COMPLETO DE STRINGS EM C - Dev-C++

## PADRAO DEV-C++
- Declarar TODAS as variaveis no INICIO da funcao
- Usar `system("pause");` antes do return
- Incluir `<stdlib.h>` para system()
- Incluir `<string.h>` para funcoes de string

---

## 1. O QUE E UMA STRING?

String e um **vetor de caracteres** terminado com `'\0'` (caractere nulo).

```c
char nome[10] = "Joao";
/* Na memoria: ['J']['o']['a']['o']['\0'][?][?][?][?][?] */
```

---

## 2. DECLARACAO E INICIALIZACAO

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Com tamanho fixo */
    char nome[20];
    
    /* Com inicializacao */
    char nome2[] = "Joao";   /* Tamanho 5: 4 letras + '\0' */
    
    /* Caractere por caractere */
    char nome3[5] = {'J', 'o', 'a', 'o', '\0'};
    
    system("pause");
    return 0;
}
```

**IMPORTANTE:** Sempre deixe espaco para '\0'!
```c
char nome[10];  /* Pode armazenar ate 9 caracteres + '\0' */
```

---

## 3. LEITURA DE STRINGS

### 3.1 Com scanf (para palavra unica - para no espaco)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[50];
    
    printf("Digite seu nome: ");
    scanf("%s", nome);  /* SEM & porque nome ja e endereco */
    
    printf("Ola, %s!\n", nome);
    
    system("pause");
    return 0;
}
```

### 3.2 Com fgets (para texto com espacos)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char frase[100];
    int tam;
    
    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);
    
    /* Remove o '\n' do final */
    tam = strlen(frase);
    if (frase[tam - 1] == '\n') {
        frase[tam - 1] = '\0';
    }
    
    printf("Voce digitou: %s\n", frase);
    
    system("pause");
    return 0;
}
```

### 3.3 Limpando o buffer apos scanf de numero
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade;
    char nome[50];
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    getchar();  /* Limpa o enter do buffer */
    
    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);
    
    printf("Nome: %s, Idade: %d\n", nome, idade);
    
    system("pause");
    return 0;
}
```

---

## 4. IMPRESSAO DE STRINGS

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[] = "Maria";
    
    printf("%s\n", nome);           /* Maria */
    printf("Nome: %s\n", nome);     /* Nome: Maria */
    printf("[%10s]\n", nome);       /* [     Maria] direita */
    printf("[%-10s]\n", nome);      /* [Maria     ] esquerda */
    
    puts(nome);  /* Imprime e pula linha */
    
    system("pause");
    return 0;
}
```

---

## 5. FUNCOES DA BIBLIOTECA string.h

### 5.1 strlen - Tamanho da String
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nome[] = "Maria";
    int tamanho;
    
    tamanho = strlen(nome);
    
    printf("Tamanho: %d\n", tamanho);  /* 5 (nao conta '\0') */
    
    system("pause");
    return 0;
}
```

### 5.2 strcpy - Copiar String
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char origem[] = "Hello";
    char destino[20];
    
    strcpy(destino, origem);  /* destino = origem */
    
    printf("Destino: %s\n", destino);
    
    system("pause");
    return 0;
}
```

### 5.3 strcat - Concatenar Strings
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[50] = "Bom ";
    char str2[] = "dia!";
    
    strcat(str1, str2);  /* str1 = str1 + str2 */
    
    printf("%s\n", str1);  /* Bom dia! */
    
    system("pause");
    return 0;
}
```

### 5.4 strcmp - Comparar Strings
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[] = "abc";
    char s2[] = "abc";
    char s3[] = "abd";
    int resultado;
    
    resultado = strcmp(s1, s2);
    printf("s1 vs s2: %d\n", resultado);  /* 0 = iguais */
    
    resultado = strcmp(s1, s3);
    printf("s1 vs s3: %d\n", resultado);  /* < 0 */
    
    /* Verificar igualdade */
    if (strcmp(s1, s2) == 0) {
        printf("Strings iguais!\n");
    }
    
    system("pause");
    return 0;
}
```

---

## 6. MANIPULACAO MANUAL DE STRINGS

### 6.1 Calcular Tamanho (sem strlen)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "Teste";
    int tamanho;
    
    tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    
    printf("Tamanho: %d\n", tamanho);
    
    system("pause");
    return 0;
}
```

### 6.2 Copiar String (sem strcpy)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char origem[] = "Hello";
    char destino[20];
    int i;
    
    i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';  /* NAO ESQUECER! */
    
    printf("Destino: %s\n", destino);
    
    system("pause");
    return 0;
}
```

### 6.3 Concatenar (sem strcat)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[50] = "Bom ";
    char str2[] = "dia!";
    int i, j;
    
    /* Encontra o fim de str1 */
    i = 0;
    while (str1[i] != '\0') {
        i++;
    }
    
    /* Copia str2 para o fim de str1 */
    j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    
    printf("%s\n", str1);
    
    system("pause");
    return 0;
}
```

### 6.4 Comparar (sem strcmp)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[] = "abc";
    char s2[] = "abc";
    int i, iguais;
    
    i = 0;
    iguais = 1;
    
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            iguais = 0;
            break;
        }
        i++;
    }
    
    /* Verifica se ambas terminaram */
    if (s1[i] != s2[i]) {
        iguais = 0;
    }
    
    if (iguais) {
        printf("Iguais!\n");
    } else {
        printf("Diferentes!\n");
    }
    
    system("pause");
    return 0;
}
```

---

## 7. OPERACOES COMUNS COM STRINGS

### 7.1 Contar Caractere Especifico
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char frase[] = "banana";
    char busca;
    int contador, i;
    
    busca = 'a';
    contador = 0;
    
    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == busca) {
            contador++;
        }
    }
    
    printf("'%c' aparece %d vezes\n", busca, contador);
    
    system("pause");
    return 0;
}
```

### 7.2 Contar Vogais e Consoantes
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char frase[] = "Programacao";
    int vogais, consoantes, i;
    char c;
    
    vogais = 0;
    consoantes = 0;
    
    for (i = 0; frase[i] != '\0'; i++) {
        c = frase[i];
        
        /* Converte para minuscula */
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        }
    }
    
    printf("Vogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);
    
    system("pause");
    return 0;
}
```

### 7.3 Contar Palavras
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char frase[] = "Isto e um teste";
    int palavras, i, dentroPalavra;
    
    palavras = 0;
    dentroPalavra = 0;
    
    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ' && dentroPalavra == 0) {
            palavras++;
            dentroPalavra = 1;
        } else if (frase[i] == ' ') {
            dentroPalavra = 0;
        }
    }
    
    printf("Palavras: %d\n", palavras);
    
    system("pause");
    return 0;
}
```

### 7.4 Converter para Maiusculas
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "Hello World";
    int i;
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    
    printf("%s\n", str);  /* HELLO WORLD */
    
    system("pause");
    return 0;
}
```

### 7.5 Converter para Minusculas
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "HELLO WORLD";
    int i;
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    
    printf("%s\n", str);  /* hello world */
    
    system("pause");
    return 0;
}
```

### 7.6 Inverter String
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "Hello";
    int inicio, fim;
    char temp;
    
    inicio = 0;
    fim = strlen(str) - 1;
    
    while (inicio < fim) {
        temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
    
    printf("%s\n", str);  /* olleH */
    
    system("pause");
    return 0;
}
```

### 7.7 Verificar Palindromo
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] = "Ana";
    int inicio, fim, palindromo;
    char c1, c2;
    
    inicio = 0;
    fim = strlen(str) - 1;
    palindromo = 1;
    
    while (inicio < fim) {
        c1 = str[inicio];
        c2 = str[fim];
        
        /* Converte para minuscula */
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + 32;
        
        if (c1 != c2) {
            palindromo = 0;
            break;
        }
        inicio++;
        fim--;
    }
    
    if (palindromo) {
        printf("%s e palindromo!\n", str);
    } else {
        printf("%s NAO e palindromo.\n", str);
    }
    
    system("pause");
    return 0;
}
```

### 7.8 Remover Espacos
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "Ola Mundo";
    char resultado[100];
    int i, j;
    
    j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            resultado[j] = str[i];
            j++;
        }
    }
    resultado[j] = '\0';
    
    printf("Original: %s\n", str);
    printf("Sem espacos: %s\n", resultado);
    
    system("pause");
    return 0;
}
```

### 7.9 Substituir Caractere
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "banana";
    char busca, substituto;
    int i;
    
    busca = 'a';
    substituto = 'o';
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == busca) {
            str[i] = substituto;
        }
    }
    
    printf("%s\n", str);  /* bonono */
    
    system("pause");
    return 0;
}
```

---

## 8. CONVERSAO DE TIPOS

### 8.1 String para Inteiro (atoi)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "123";
    int numero;
    
    numero = atoi(str);
    
    printf("String: %s\n", str);
    printf("Numero: %d\n", numero);
    printf("Dobro: %d\n", numero * 2);
    
    system("pause");
    return 0;
}
```

### 8.2 String para Float (atof)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "3.14";
    float numero;
    
    numero = atof(str);
    
    printf("String: %s\n", str);
    printf("Numero: %.2f\n", numero);
    
    system("pause");
    return 0;
}
```

### 8.3 Inteiro para String (sprintf)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    char str[20];
    
    numero = 42;
    
    sprintf(str, "%d", numero);
    
    printf("Numero: %d\n", numero);
    printf("String: %s\n", str);
    
    system("pause");
    return 0;
}
```

---

## 9. VETOR DE STRINGS

### 9.1 Declaracao e Uso
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomes[3][20] = {
        "Maria",
        "Joao",
        "Pedro"
    };
    int i;
    
    for (i = 0; i < 3; i++) {
        printf("%s\n", nomes[i]);
    }
    
    system("pause");
    return 0;
}
```

### 9.2 Leitura de Varios Nomes
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomes[5][50];
    int i;
    
    for (i = 0; i < 5; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%s", nomes[i]);
    }
    
    printf("\nNomes digitados:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", nomes[i]);
    }
    
    system("pause");
    return 0;
}
```

### 9.3 Ordenar Nomes (Bubble Sort)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nomes[5][50] = {"Pedro", "Ana", "Carlos", "Beatriz", "Daniel"};
    char temp[50];
    int i, j;
    
    /* Bubble Sort para strings */
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (strcmp(nomes[j], nomes[j+1]) > 0) {
                strcpy(temp, nomes[j]);
                strcpy(nomes[j], nomes[j+1]);
                strcpy(nomes[j+1], temp);
            }
        }
    }
    
    printf("Nomes ordenados:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", nomes[i]);
    }
    
    system("pause");
    return 0;
}
```

---

## 10. EXEMPLO COMPLETO: ANALISADOR DE TEXTO
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char texto[200];
    int letras, digitos, espacos, vogais, consoantes;
    int i;
    char c;
    
    letras = 0;
    digitos = 0;
    espacos = 0;
    vogais = 0;
    consoantes = 0;
    
    printf("Digite um texto: ");
    fgets(texto, 200, stdin);
    
    for (i = 0; texto[i] != '\0'; i++) {
        c = texto[i];
        
        /* Verifica se e letra */
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letras++;
            
            /* Converte para minuscula para verificar vogal */
            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }
            
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        }
        /* Verifica se e digito */
        else if (c >= '0' && c <= '9') {
            digitos++;
        }
        /* Verifica se e espaco */
        else if (c == ' ') {
            espacos++;
        }
    }
    
    printf("\n=== ANALISE ===\n");
    printf("Letras: %d\n", letras);
    printf("  - Vogais: %d\n", vogais);
    printf("  - Consoantes: %d\n", consoantes);
    printf("Digitos: %d\n", digitos);
    printf("Espacos: %d\n", espacos);
    printf("Total de caracteres: %d\n", (int)strlen(texto) - 1);
    
    system("pause");
    return 0;
}
```

---

## RESUMO RAPIDO

| Funcao | Descricao | Exemplo |
|--------|-----------|---------|
| `strlen(s)` | Tamanho | `strlen("abc")` = 3 |
| `strcpy(d,s)` | Copia | `strcpy(dest, orig)` |
| `strcat(d,s)` | Concatena | `strcat(str1, str2)` |
| `strcmp(a,b)` | Compara | 0 se iguais |

**LEMBRE-SE:** Strings sempre terminam com `'\0'`!

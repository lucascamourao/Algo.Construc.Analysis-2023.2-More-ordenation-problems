/*
Problema da ordenação raiz de n:
Temos uma lista com n elementos. Queremos ordenar os elememtos por blocos de raiz de n. Sendo assim, o primeiro bloco, que vai das
posições 0 até (raiz_n - 1), vai ser ordenado. Em seguida, o segundo bloco, que vai das posições (raiz_n) até ((2 * raiz_n) - 1) é
ordenado. Dessa forma, os blocos vão sendo ordenados até o último bloco, que vai das posições ((n - 1) * raiz_n) até ((n * raiz_n) - 1). 
Note que, não necessariamente, a lista completa estará ordenada entre si. 

'Square root of n' sorting problem:
We have a list of length 'n'. We want to order the elements by blocks of size square root of n. Therefore, the first block, which goes from
positions 0 to (root_n - 1), will be sorted. Then, the second block, which goes from positions (root_n) to ((2 * root_n) - 1) is
sorted. This way, the blocks are ordered until the last block, which goes from positions ((n - 1) * root_n) to ((n * root_n) - 1).
Note that the complete list will not necessarily be fully ordered.
*/

#include <iostream>
#include <cmath>

// função básica de troca de dois elementos de uma lista
void troca(int L[], int i, int j) {
    int aux = L[i];
    L[i] = L[j];
    L[j] = aux;
}

// passar por toda a lista e, caso o próximo elemento seja menor que o anterior, eles são trocados
// A função funciona assintoticamente com tempo O(n)
void varredura(int L[], int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        if (L[i] > L[i + 1]) {
            troca(L, i, i + 1);
        }
    }
}

// Tempo de execução: O(n^2)
void ordena(int L[], int inicio, int fim) {
    for (int i = 0; i < fim; i++) {
        varredura(L, inicio, fim);
    }
}

int main() {
    int L[] = {6, 4, 13, 51, 9, 11, 2, 1, 10, 45, 23, 12, 76, 4, 0, 16};
    //int L[] = {1, 4, 13, 9, 11, 2, 0, 16, 5};
    int n = sizeof(L) / sizeof(L[0]);
    int raiz_n = sqrt(n);

    int k = 0; // variavel auxiliar para contar o numeros de vezes do 'for loop'
    for (int i = 0; i <= n - 1; i+=raiz_n) {
        int final = (k + 1)*(raiz_n) - 1;
        ordena(L, i, final); // ordena da posiçao i ate final 
        k++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << L[i] << " ";
    }

    return 0;
}

/* Tempo de execução total do algortimo:
A função ordena(...) geralmente executa em tempo O(n), porém cada bloco chamado para ordenar tem tamanho raiz de n. 
Sendo assim, cada chamada do ordena(...) tem tempo de execução igual a O(raiz_n). Isso é chamado no for loop raiz de n vezes.
Total: O(raiz_n) * O(raiz_n) = O(n). */

/*
Problema da ordenação zigue-zague: 
Temos uma lista com n elementos. Queremos ordenar os elememtos da seguinte forma: o primeiro elemento é o menor, o segundo é o maior,
o terceiro elemento é o segundo menor, o quarto elemento é o segundo maior, e por ai vai. 
Note que, não necessariamente, a lista completa estará ordenada entre si. 
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
    for (int i = inicio; i < fim - 1; i++) {
        if (L[i] > L[i + 1]) {
            troca(L, i, i + 1);
        }
    }
}

int main() {
    int L[] = {1, 2, 3, 5, 7, 10};
    //int L[] = {6, 4, 13, 51, 9, 11, 2, 1, 10, 45, 23, 12, 76, 4, 0, 16};
    int n = sizeof(L) / sizeof(L[0]);
    int A[n]; // lista auxiliar

    // Ordenar L usando Bubble Sort
    // tempo de execução: O(n^2)
    for (int i = 0; i < n - 1; i++) {
        varredura(L, 0, n - i);
    }

    // Imprimir L ordenado
    std::cout << "LISTA ORDENADA DE FORMA CRESCENTE:\n";
    for (int aux = 0; aux < n; aux++) {
        std::cout << L[aux] << " ";
    }

    // Criar a lista A com elementos em ordem zigzag
    int i = 0;
    int j = n - 1;
    int k = 0;

    // dois "dedos" (um i na cabeça e um j na cauda da lista)
    while (i <= j) { // loop acaba quando eles se encontram (no caso j < i)
        A[k++] = L[i++];
        // A[k] = L[i]
        // k++; i++;
        if (i <= j) {
            A[k++] = L[j--];
        }
    }
    // tempo do while loop: O(n)

    // Imprimir lista A em ordem zigzag
    std::cout << "\nLISTA ORDENADA DE FORMA ZIGUE-ZAGUE:\n";
    for (int aux = 0; aux < n; aux++) {
        std::cout << A[aux] << " ";
    }

    return 0;
}

// O tempo total do algoritmo é: O(n^2) + O(n) ~= O(n^2).
// Logo, tempo O(n^2).
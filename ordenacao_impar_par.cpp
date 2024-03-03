/*
Problema da ordenação impar-par:
Temos uma lista com n elementos. Queremos ordenar todos os elementos nas posições pares, ou seja, posição 0, 2, ... e os
elementos das posições ímpares 1, 3, ..., separadamente. Ao final, teremos uma só lista, mas as posições pares estarão ordenadas
e as posições ímpares também. Note que, não necessariamente, a lista completa estará ordenada entre si. 
*/

#include <iostream>

// função básica de troca de dois elementos de uma lista
void troca(int L[], int i, int j) {
    int aux = L[i];
    L[i] = L[j];
    L[j] = aux;
}

// Faz uma varredura pela lista, trocando o próximo elemento com o anterior, caso o próximo seja menor
// Nesse caso, a varredura modificada faz a varredura, porém com passo 2 (avança dois em dois) 
// A função funciona assintoticamente com tempo O(n)
void varredura_modif(int L[], int inicio, int fim) {
    for (int i = inicio; i < fim - 1; i += 2) {
        if (L[i] > L[i + 2]) {
            troca(L, i, i + 2); // O(1) cada chamada
        }
    }
}

int main() {
    // Exemplos de teste
    //int L[] = {1, 4, 13, 9, 11, 2, 0};
    //int L[] = {6, 4, 13, 51, 9, 11, 2, 1, 10, 45, 23, 12, 76, 4, 0, 16};
    int L[] = {6, 7, 13, 51, 9, 11, 2, 1, 70, 45, 29, 12, 76, 4, 0, 19, 99};

    int n = sizeof(L) / sizeof(L[0]); 

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            varredura_modif(L, 0, n - i);
        } else {
            varredura_modif(L, 1, n - i);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << L[i] << " ";
    }

    return 0;
}

// O tempo total do algoritmo é de O(n^2) - tempo quadrático com relação ao tamanho da lista
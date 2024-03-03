/*
Problema da ordenação ímpar:
Temos uma lista com n elementos. Queremos ordenar todas as posições da lista cujos elementos são ímpares. Desse modo, se as posições 1, 3, 4, 5 e 10 
são elementos ímpares, estes serão ordenados entre si. O resto das posições permanecem no mesmo lugar. É como se estivessemos ignorando as posições 
com elementos pares.
Note que, não necessariamente, a lista completa estará ordenada entre si. 
*/ 

#include <iostream>

// função básica de troca de dois elementos de uma lista
void troca(int L[], int i, int j) {
    int aux = L[i];
    L[i] = L[j];
    L[j] = aux;
}

// função para achar o menor ímpar da lista, no intervalo [início, fim] 
// tempo O(n)
int menor_impar(int L[], int inicio, int fim) {
    int menor = L[inicio];
    int menor_pos = inicio;
    
    for (int i = inicio + 1; i <= fim - 1; i++) {
        if ((L[i] % 2) != 0 && L[i] < menor) {
            menor = L[i];
            menor_pos = i;
        }
    }

    return menor_pos;
}

int main() {
    //int L[] = {1, 4, 13, 9, 11, 2, 0};
    int L[] = {6, 4, 13, 51, 9, 11, 2, 1, 10, 45, 23, 12, 76, 4, 0, 16};
    int n = sizeof(L) / sizeof(L[0]);

    for (int i = 0; i < n - 1; i++) {
        if (L[i] % 2 != 0) {
            int menor = menor_impar(L, i, n);
            if (L[i] > L[menor]) {
                troca(L, i, menor);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << L[i] << " ";
    }

    return 0;
}

/* Tempo de execução total do algortimo:
No pior caso, a lista é composta inteiramente por elementos pares. Assim, a função menor_impar(...), com tempo O(n), é chamada n vezes.
Total: O(n^2). 
*/
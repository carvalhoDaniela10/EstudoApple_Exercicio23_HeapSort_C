#include <stdio.h>

void heapify(int vetor[], int n, int i) {
    int largest = i; // Raiz
    int l = 2 * i + 1; // Filho esquerdo 
    int r = 2 * i + 2; // Filho direito  

    if (l < n && vetor[l] > vetor[largest])
        largest = l;

    if (r < n && vetor[r] > vetor[largest])
        largest = r;

    if (largest != i) {
        int temp = vetor[i];
        vetor[i] = vetor[largest];
        vetor[largest] = temp;

        heapify(vetor, n, largest);
    }
}

void heapSort(int vetor[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i);
    

    for (int i = n - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
    }
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(vetor) / sizeof(vetor[0]); // n = 28 / 4 -> n == 7
    // está pegando o valor total de bytes do vetor e dividindo pela quantidades de bytes de uma única posição e armazendando em N

    printf("Vetor desordenado: \n");
    for (int i = 0; i < n; i++) // o for está percorrendo o vetor e printando os valores armazenados em cada posição
        printf("%d ", vetor[i]); // saídas: 64 | 34 | 25 | 12 | 22 | 11 | 90
    printf("\n\n");

    heapSort(vetor, n);

    printf("\nVetor ordenado: \n");
    for (int i = 0; i < n; i++) // o for está percorrendo o vetor e printando os valores armazenados em cada posição
        printf("%d ", vetor[i]); // saídas: 11 | 12 | 22 | 25 | 34 | 64 | 90
    printf("\n");

    return 0;
}

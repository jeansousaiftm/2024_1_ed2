#include<stdio.h>
#include<stdlib.h>

void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void troca(int v[], int a, int b) { // O(1)
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
            }
        }
    }
}

int main() {

    int n = 3;
    int v[n], o[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        o[i] = v[i];
    }

    bubbleSort(v, n);
    imprimeVetor(v, n);
    printf("\n");
    imprimeVetor(o, n);

    return 0;
}

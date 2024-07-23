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

void bubbleSortDecrescente(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] < v[j + 1]) {
                troca(v, j, j + 1);
            }
        }
    }
}

int main() {

    int n, x, cp = 0, ci = 0;
    scanf("%d", &n);
    int np[n], ni[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            np[cp++] = x;
        } else {
            ni[ci++] = x;
        }
    }

    bubbleSort(np, cp);
    imprimeVetor(np, cp);
    bubbleSortDecrescente(ni, ci);
    imprimeVetor(ni, ci);

    return 0;
}

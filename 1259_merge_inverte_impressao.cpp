#include<stdio.h>
#include<stdlib.h>

void aleatorio(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10000;
    }
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void imprimirReverso(int v[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", v[i]);
    }
}

void merge(int v[], int s, int m, int e) { //O(n)
    int i = s, j = m + 1, k = 0;
    int tmp[(e - s) + 1];
    while (i <= m && j <= e) {
        if (v[i] < v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    while (i <= m) {
        tmp[k++] = v[i++];
    }
    while (j <= e) {
        tmp[k++] = v[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

void mergeSort(int v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
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

    mergeSort(np, 0, cp - 1);
    imprimir(np, cp);
    mergeSort(ni, 0, ci - 1);
    imprimirReverso(ni, ci);

    return 0;
}

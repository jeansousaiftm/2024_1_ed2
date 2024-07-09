#include<stdio.h>
#include<stdlib.h>

void aleatorio(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10000;
    }
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
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
    /*printf("%d %d\n", s, e);
    for (int i = s; i <= e; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");*/
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
        //imprimir(v, 9);
    }
}

int main() {
    int v[100000];
    aleatorio(v, 100000);

    imprimir(v, 100000);

    mergeSort(v, 0, 99999);

    imprimir(v, 100000);


    return 0;
}

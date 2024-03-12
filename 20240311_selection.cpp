#include<stdio.h>

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}


void troca(int v[], int a, int b) {
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

void selection(int v[], int n) { //O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[i]) {
                troca(v, i, j);
                imprimir(v, n);
            }
        }
    }
}

int main() {
    int n = 5;
    int v[] = { 3, 1, 5, 4, 2 };
    imprimir(v, n);
    selection(v, n);
    imprimir(v, n);

    return 0;
}

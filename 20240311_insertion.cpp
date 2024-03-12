#include<stdio.h>

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void insertion(int v[], int n) { // O(n ^ 2)
    for (int i = 1; i < n; i++) {
        int x = v[i], j;
        for (j = i - 1; j >= 0 && v[j] > x; j--) {
            v[j + 1] = v[j];

        }
        v[j + 1] = x;
        imprimir(v, n);
    }
}

int main() {
    int n = 5;
    int v[] = { 3, 1, 5, 4, 2 };
    imprimir(v, n);
    insertion(v, n);
    imprimir(v, n);

    return 0;
}


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

int bubbleSort(int v[], int n) {
    int t = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                t++;
            }
        }
    }
    return t;
}

int main() {

    int n;
    while (scanf("%d", &n) != EOF) {
        int v[n], t[n], o[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &t[j]);
            for (int i = 0; i < n; i++) {
                if (v[i] == t[j]) {
                    o[i] = j + 1;
                    break;
                }
            }
        }
        printf("%d\n", bubbleSort(o, n));
    }

    return 0;
}



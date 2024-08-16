#include<stdio.h>
#include<string.h>
#include<ctype.h>

void removerMinusculas(char tmp[]) {
    for (int i = 0; i < strlen(tmp); i++) {
        tmp[i] = tolower(tmp[i]);
    }
}

bool iniciaCom(char s1[], char s2[]) {
    if (strlen(s1) < strlen(s2)) return false;
    for (int i = 0; i < strlen(s2); i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

void buscaBinaria(char nomes[][100], int n, char tmp[]) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        //printf("%d %d %d\n", s, m, e);
        //printf("%s %s %d\n", nomes[m], tmp, strcmp(nomes[m], tmp));
        if (iniciaCom(nomes[m], tmp)) {
            printf("%s\n", nomes[m]);
            int x = m - 1;
            while (iniciaCom(nomes[x], tmp) && x >= 0) {
                printf("%s\n", nomes[x]);
                x--;
            }
            x = m + 1;
            while (iniciaCom(nomes[x], tmp) && x < n) {
                printf("%s\n", nomes[x]);
                x++;
            }
            return;
        } else if (strcmp(nomes[m], tmp) > 0) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
}

int main() {

    FILE *f;
    f = fopen("nomes.txt", "r+");

    int i = 0;
    int n = 517;
    char nomes[n][100];
    char tmp[100];

    while (fscanf(f, "%[^\n]%*c", tmp) != EOF) {
        removerMinusculas(tmp);
        strcpy(nomes[i], tmp);
        i++;
    }

    /*for (i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }*/

    scanf("%[^\n]%*c", tmp);

    removerMinusculas(tmp);

    buscaBinaria(nomes, n, tmp);

    return 0;
}

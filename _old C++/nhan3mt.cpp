#include <stdio.h>
int m, n, p, q;
int a[100][100], b[100][100], c[100][100], res[100][100] = { 0 }, ab[100][100] = { 0 };

void init() {
    scanf("%d %d %d %d", &m, &n, &p, &q);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &b[i][j]);
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            scanf("%d", &c[i][j]);
}

void process() {
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < p; k++) {
            for (int j = 0; j < n; j++) {
                ab[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < q; k++) {
            for (int j = 0; j < p; j++) {
                res[i][k] += ab[i][j] * c[j][k];
            }
        }
    }
}

void in() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
}

int main() {
    init();
    process();
    in();
}
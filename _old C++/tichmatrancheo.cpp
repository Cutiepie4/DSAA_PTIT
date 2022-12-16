#include<stdio.h>
int a[20][20] = { 0 };
void taomt(int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        int gt = 1;
        for (int j = 0; j <= x; j++) {
            a[i][j] = gt; gt++;
        }
        x++;
    }
}

void xuly(int a[20][20], int n, int m) {
    int b[20][20], c[20][20], i, j, k;
    for (i = 0;i < m;i++)
        for (j = 0;j < n;j++)
            b[i][j] = a[j][i];

    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            c[i][j] = 0;
            for (k = 0;k < m;k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
        }
    }

    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}
main() {
    int n, m, i, t;
    scanf("%d", &t);
    for (i = 1;i <= t;i++) {
        scanf("%d", &n);
        taomt(n);
        printf("Test %d: \n", i);
        xuly(a, n, n);
    }
}

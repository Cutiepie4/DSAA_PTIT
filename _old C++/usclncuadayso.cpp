#include <stdio.h>

int uscln(int a, int b) {
    if (b == 0) return a;
    return uscln(b, a % b);
}
int bscnn(int a, int b) {
    return (a * b) / uscln(a, b);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        //input
        int n;
        scanf("%d", &n);
        int a[n], b[n + 1];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        //process
        for (int i = 0; i < n - 1; i++) {
            b[i + 1] = bscnn(a[i], a[i + 1]);
        }

        //tim not 2 so con lai
        for (int i = 1; i <= b[1]; i++) {
            if (uscln(i, b[1]) == a[0]) {
                b[0] = i; break;
            }
        }
        for (int i = 1; i <= b[n - 1]; i++) {
            if (uscln(i, b[n - 1]) == a[n - 1]) {
                b[n] = i; break;
            }
        }

        //output
        for (int i = 0; i < n + 1; i++) printf("%d ", b[i]);
        printf("\n");
    }
}
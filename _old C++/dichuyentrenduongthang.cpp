#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != -1) {
        int x = abs(b - a), res = 0;
        int z = sqrt(x);
        res += (z - 1) * 2 + 1;
        int q = x - z * z;
        if (q > z) {
            res += q / z;
            q %= z;
        }
        if (q > 0) res++;
        printf("%d\n", res);
    }
}
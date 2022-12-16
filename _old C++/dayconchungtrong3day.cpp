#include <stdio.h>

void nhap(long long a[], long long n) {
	for (long long i = 0; i < n; i++)
		scanf("%lld", &a[i]);
}

void xuli(long long a[], int d1, long long b[], int d2, long long c[], int d3) {
	int kt1 = 1, e = 0, f = 0;
	for (int i = 0; i < d1; i++) {
		int kt = 1;
		for (int j = e; j < d2; j++) {
			if (kt == 0) break;
			if (a[i] <= b[j]) {
				if (a[i] == b[j]) {
					for (int k = f; k < d3; k++) {
						if (b[j] <= c[k]) {
							if (b[j] == c[k]) {
								b[j] = -1;
								printf("%lld ", c[k]);
								c[k] = -1;
								kt1 = 0;
							}
							f = k;kt = 0; break;
						}
					}
				}
				e = j; break;
			}
		}
	}
	if (kt1) printf("-1");
	printf("\n");
}
main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int d1, d2, d3;
		long long a[100000], b[100000], c[100000];
		scanf("%d %d %d", &d1, &d2, &d3);
		nhap(a, d1); nhap(b, d2); nhap(c, d3);
		xuli(a, d1, b, d2, c, d3);
	}
}

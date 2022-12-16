#include<stdio.h>
main() {
	int length, soden, x, tcs;
	scanf("%d %d %d", &length, &soden, &tcs);
	int a[length + 1];
	for (int i = 1; i <= length; i++) a[i] = i;
	for (int i = 0; i < soden; i++) {
		scanf("%d", &x);
		for (int j = 1; j <= length; j++) {
			if (j == x) {
				for (int k = x - tcs; k <= x + tcs; k++) {
					if (k > 0 && k <= length) a[k] = -1;
				}
			}
		}
	}
	int dem = 0;
	for (int i = 1; i <= length; i++) {
		if (a[i] != -1) {
			for (int j = i; j <= i + 2 * tcs; j++) {
				if (j <= length) a[j] = -1;
				else break;
			}
			dem++;
		}
	}
	printf("%d", dem);
}

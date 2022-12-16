#include<stdio.h>

int a[100][100];
void sxc(int a[], int n) {
	int t, j;
	for (int i = 1; i < n; i++) {
		j = i - 1;
		t = a[i];
		while (j >= 0 && t < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}
void taomang(int n, int b[]) {
	int x = 0, k = 0, hang = n - 1, cot = n - 1;
	while (x <= n / 2) {
		for (int i = x; i <= cot - x; i++) {
			a[x][i] = b[k]; k++;
		}
		for (int i = 1 + x; i <= hang - x; i++) {
			a[i][cot - x] = b[k]; k++;
		}
		for (int i = cot - 1 - x; i >= x; i--) {
			a[hang - x][i] = b[k]; k++;
		}
		for (int i = hang - 1 - x; i > x; i--) {
			a[i][x] = b[k]; k++;
		}
		x++;
	}
}
main() {
	int n, x = 0, y = 1;
	scanf("%d", &n);
	int b[100001];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[x++] = y++;
		}
	}
	sxc(b, x);
	taomang(n, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

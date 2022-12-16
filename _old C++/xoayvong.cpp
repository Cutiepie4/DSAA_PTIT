#include<stdio.h>
#include<string.h>

void xoay(char a[]) {
	int skt = strlen(a);
	char x = a[0];
	for (int i = 0; i < skt; i++) {
		if (i == skt - 1) a[i] = x;
		else a[i] = a[i + 1];
	}
}

main() {
	int n, max = 999;
	char s[51][51], s1[51][51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &s[i]);
	}
	int kt = 1;
	for (int i = 0; i < n; i++) {
		int dem = 0;
		if (kt == 0) break;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else {
				strcpy(s1[j], s[j]);
			}
			for (int k = 0; k < strlen(s[j]); k++) {
				if (strchr(s[i], s[j][k]) == NULL) {
					kt = 0; break;
				}
			}
			if (kt == 0) break;
			while (strcmp(s1[j], s[i]) != 0) {
				xoay(s1[j]);
				dem++;
				if (dem > (n - 1) * strlen(s[i])) {
					kt = 0; break;
				}
			}
		}
		if (dem < max) max = dem;
	}
	if (kt == 0) printf("-1");
	else printf("%d", max);
}

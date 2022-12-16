#include<stdio.h>
struct diem {
	double x, y;
};
main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		struct diem d[n];
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &d[i].x, &d[i].y);
		}
		double tong = 0;
		for (int i = 0; i < n; i++) {
			if (i == n - 1) tong += d[i].x * d[0].y - d[i].y * d[0].x;
			else tong += (d[i].x * d[i + 1].y - d[i].y * d[i + 1].x);
		}
		printf("%.3lf\n", tong / 2);
	}
}

/*
Dòng đầu tiên là số lượng bộ test T (T≤ 20).
Mỗi test bắt đầu bởi hai số nguyên N và M. (3≤N,M≤300).
Kế tiếp là N dòng, mỗi dòng gồm M số nguyên mô tả ma trận ảnh.
3 dòng tiếp theo, mỗi dòng gồm 3 số nguyên mô tả ma trận kernel.
Giá trị các phần tử của hai ma trận có giá trị tuyệt đối không vượt quá 100.
*/
#include<stdio.h>

main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, m, a[301][301] = {}, b[4][4] = {};
		scanf("%lld %lld", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%lld", &a[i][j]);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				scanf("%lld", &b[i][j]);
		long long tong = 0;
		for (int i = 0; i <= n - 3; i++) {
			for (int j = 0; j <= m - 3; j++) {
				int k = 0, r = 0;
				for (int z = i; z < i + 3; z++) {
					for (int t = j; t < j + 3; t++) {
						tong += a[z][t] * b[k][r++];
					}
					k++; r = 0;
				}
			}
		}
		printf("%lld\n", tong);
	}
}

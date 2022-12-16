#include<stdio.h>
long long tinh(long long a[100000], int n) {
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	long long maxsum = 0, amin = 0;
	for (int i = 1; i <= n; i++) {
		if (amin > a[i]) amin = a[i];
		if (maxsum < a[i] - amin) maxsum = a[i] - amin;
	}
	return maxsum;
}
main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long a[100000];
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		printf("%lld\n", tinh(a, n));
	}
}

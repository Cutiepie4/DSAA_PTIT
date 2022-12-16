
#include <bits/stdc++.h>
using namespace std;

int nt(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
	return 1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		if (a == 1) {
			cout << "0" << endl; continue;
		}
		int kt = 0;
		for (int i = 2; i <= a; i++) {
			if (nt(i) && a % i == 0) {
				a /= i; kt++;
			}
			if (kt == 3) break;
		}
		if (a == 1 && kt == 3) cout << "1" << endl;
		else cout << "0" << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;
int nt(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return  1;
}
int main() {
    int n;
    cin >> n;
    int a[n], mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; mx = max(mx, a[i]);
    }
    int b[10000], x = 4;
    b[1] = 1; b[2] = 2; b[3] = 3;
    for (int i = 4; i <= mx; i++) {
        int z = i;
        if (z % 2 == 0) {
            b[x++] = 2; continue;
        }
        if (nt(z)) {
            b[x++] = z; continue;
        }
        for (int j = 2; j <= z; j++) {
            if (nt(j) && z % j == 0) {
                b[x++] = j; break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) cout << b[j] << " ";
        cout << endl;
    }

}